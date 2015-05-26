#include "uriTest.h"

uri_t::uri_t ( osip_uri_t * osip_u )
{
   uri = NULL ;
   osip_uri_t *temp_uri ;
   
   int i = osip_uri_clone ( osip_u , &temp_uri ) ;
   
   if ( i != 0 )
   {
	perror ("osip_uri_clone goes wrong") ;
	return ;
   }
	
   uri = temp_uri ;
     
}

uri_t::uri_t ( char * c_u )
{
	osip_uri_t *temp_uri ;
   	
	osip_uri_init ( &temp_uri ) ;
	osip_uri_parse ( temp_uri , c_u ) ;
	
	uri = temp_uri ;
}

uri_t::uri_t ( uri_t * src_u )
{
    if ( src_u != NULL )
    {
	osip_uri_t *temp_uri ;
	
	int i = osip_uri_clone ( src_u->uri , &temp_uri ) ;
	if ( i != 0 )
	{
		perror ("osip_uri_clone method goes wrong") ;
		return ;
	}
	
	uri = temp_uri ;
    }
}


uri_t::~uri_t ()
{
	osip_uri_free ( uri ) ;
}
