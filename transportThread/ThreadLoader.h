#ifndef THREAD_BASE_H__
#define THREAD_BASE_H__

#include "my_pipe.h"

class ThreadLoader
{
public :
	void *thread ;
	myPipe wakeup ;
public :
	ThreadLoader () ; 
	~ThreadLoader () ;
	
	int ThreadRelease () ;
	int ThreadStart ( void *(*loader)(void*) , void *arg_list) ;
	int ThreadWakeUp () ; 
	
	int ThreadPrintState () ;

} ;



#endif
