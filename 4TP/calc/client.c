#include "calcH.h"
#include "calc.nsmap"

static char server[] = "http://localhost:18083/";

int main(int argc, char**argv) 
{ 
   double sum; 
   struct soap soap;
   soap_init(&soap);
   if (soap_call_calc__add(&soap, server, NULL, 1.0, 2.0, &sum) == SOAP_OK)
     {
       printf("sum = %g\n", sum);
     }
   else 
     {
       soap_print_fault(&soap, stderr); 
     }
   soap_destroy(&soap);
   soap_end(&soap);
   soap_done(&soap);
   return 0; 
}
