#include <cstdio>
#include <iostream>
#include <string>
#include <pthread.h>

#include "ThreadLoader.h"

using namespace std ;

void* sayHi ( void *name )
{
  
  cout << "hi "<< (const char*)name << endl ;
  return NULL ;
}

void* sayHello ( void* name )
{
   cout << "hi " << (const char*)name << endl ;
   return NULL ;
}

typedef void*(*func_ptr_t )(void*)  ;


int main ( int argc , char **argv )
{
  string name ;
  ThreadLoader loader1 , loader2 ;
  
  func_ptr_t hello_ptr ,hi_ptr ; 

  hello_ptr = sayHello ;
  hi_ptr    = sayHi ;

  cout << "test start method "<< endl ;

  cout << "name" << endl ;
  cin >> name ;
  
  loader1.ThreadStart (hi_ptr, (void*)name.c_str()) ; 

  sleep (2) ;


  cout << "\n\nname" << endl ;
  cin >> name ;
  loader2.ThreadStart ( hello_ptr , (void*)name.c_str()) ;
  sleep (2) ;
 

  cout << "here we test wake up method" << endl ;
  loader1.ThreadWakeUp () ;
  loader2.ThreadWakeUp () ;

//  cout << "print pipe pair contents tests "<< endl ;
//  loader1.ThreadPrintState () ;
//  loader2.ThreadPrintState () ;

  cout << "test release method "<< endl ;
  loader1.ThreadRelease () ;
  loader2.ThreadRelease () ;

  cout << "print pipe pair contents tests "<< endl ;
  loader1.ThreadPrintState () ;
  loader2.ThreadPrintState () ;

  
  return 0 ;
}
