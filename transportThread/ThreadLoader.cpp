#ifndef OSIP_MT
#define OSIP_MT
#endif

#include <osip2/osip_mt.h>
#include <osip2/osip_condv.h>
#include <osip2/osip.h>
#include <osipparser2/osip_port.h>

#include <stdio.h>
#include <stdlib.h>

#include "ThreadLoader.h"
#include "my_pipe.h"

//--------------------------

ThreadLoader::ThreadLoader () : wakeup()
{
  thread = NULL ;
}

ThreadLoader::~ThreadLoader ()
{
  if ( thread != NULL )
  {
	ThreadRelease () ;
	perror ("release method always called before free method") ;
	return ;
  }
}


int ThreadLoader::ThreadRelease ()
{
   char c_exit[19] = "thread obj release";
   int len ;
	
   if ( thread == NULL )
	return 0 ; 
 
   len = wakeup.write_in_pipe (&c_exit, 18) ;
  
   if ( len != 18 )
   {
	perror ("write_in_pipe method goes error ") ;
	return -1 ;
   }

   len = osip_thread_join (( struct osip_thread*)thread ) ;
 
   if ( len != 0 )
   {
	perror ("osip_thread_join method goes wrong") ;
	return -1 ;
   }
   
   free ( thread ) ;
   thread = NULL ;
	
   return 0 ;
}

int ThreadLoader::ThreadStart ( void *(*loader)(void *) , void *arg_list ) 
{
   if ( loader == NULL )
	return -1 ;
   thread = (void*)osip_thread_create ( 20000 , loader , arg_list ) ;
	
   if ( thread == NULL )
	return -1 ;
   
   return 0 ;
}


int ThreadLoader::ThreadWakeUp ()
{
	int ret ;
	char c_wake[15] = "thread wake up" ;
	
	ret = wakeup.write_in_pipe( &c_wake, 14 ) ;
	
 	if ( ret != 14 )
	{
	   perror ("write_in_pipe method goes wrong") ;
 	   return -1 ;
	}
	
	return 0 ;
}

int ThreadLoader::ThreadPrintState ()
{
	int ret ;
	char c_contents [1024] ;
	
	ret = wakeup.read_from_pipe ( &c_contents , 1024) ;
	
        c_contents[ret] = '\0' ;

	if ( ret <= 0  )
	{
		perror ("read_from_pipe method goes wrong") ;
		return -1 ;
	}
	
	printf("pipe contents : %s \n\n",c_contents ) ;
	
 	return 0 ;
}
