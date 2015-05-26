#include <cstdio>
#include <iostream>
#include <cstring>

#include "uriTest.h"

using namespace std ;

int main ( int argc , char **argv )
{
   char line[19] = "sip:aimer@si2p.com" ;
   uri_t myUri( line ) ;
   
   cout << "osip_uri.scheme   : " << myUri.uri->scheme  << endl ;
   cout << "osip_uri.username : " << myUri.uri->username << endl ;
//   cout << "osip_uri.password : " << myUri.uri->password << endl ;
   cout << "osip_uri.host     : " << myUri.uri->host     << endl ;
//   cout << "osip_uri.port     : " << myUri.uri->port     << endl ;
 
   return 0 ;
}
