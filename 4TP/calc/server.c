#include "calcH.h" 
#include "calc.nsmap"

static int port = 18083;
static char hostname[] = "localhost";

int main(int argc, char**argv)
{ 
   struct soap soap; 
   int m, s;
   soap_init(&soap); 
   m = soap_bind(&soap, hostname, port, 100); 
   if (m < 0) 
      soap_print_fault(&soap, stderr); 
   else
   { 
     fprintf(stderr, "Socket connection successful: master socket = %d; port = %d\n", m, port); 
      int i;
      for (i = 1; ; i++) 
      {
         s = soap_accept(&soap); 
         if (s < 0) 
         { 
            soap_print_fault(&soap, stderr); 
            break; 
         } 
         fprintf(stderr, "%d: accepted connection from IP=%d.%d.%d.%d socket=%d", i, 
            (soap.ip >> 24)&0xFF, (soap.ip >> 16)&0xFF, (soap.ip >> 8)&0xFF, soap.ip&0xFF, s); 
         if (soap_serve(&soap) != SOAP_OK)
            soap_print_fault(&soap, stderr);
         fprintf(stderr, "request served\n"); 
         soap_destroy(&soap);
         soap_end(&soap);
      } 
   } 
   soap_done(&soap);
} 

int calc__add(struct soap *soap, double a, double b, double*result) 
{ 
   *result = a + b; 
   return SOAP_OK; 
} 

int calc__sub(struct soap *soap, double a, double b, double*result) 
{ 
   *result = a - b; 
   return SOAP_OK; 
} 


