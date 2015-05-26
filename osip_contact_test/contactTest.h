#ifndef CONTACT_TEST_H_
#define CONTACT_TEST_H_

#include <osip2/osip.h>
#include <osipparser2/osip_parser.h>

class contact_t
{
 public :
	osip_contact_t *contact ;
	char *path ;
	int  when ;
 public :
	contact_t ( osip_contact_t *con ) ;
	contact_t ( char *          con ) ;
	contact_t ( contact_t *	    con ) ;
	~contact_t( ) ;

} ;


#endif
