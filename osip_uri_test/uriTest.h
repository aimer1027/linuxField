#ifndef URI_TEST_H_
#define URI_TEST_H_
#include <osip2/osip.h>
#include <osipparser2/osip_parser.h>


class uri_t 
{
 public :
	osip_uri_t *uri ;
 public :
	uri_t ( osip_uri_t * osip_u ) ;
	uri_t ( char *       c_u ) ;
	uri_t ( uri_t *      src_u ) ;
	~uri_t () ;
} ;	

#endif
