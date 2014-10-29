#include "calcH.h"
#include "calc.nsmap"

static char server[] = "http://localhost:18083/";

int main(int argc, char**argv) 
{ 
   double sum; 
   struct soap soap;
   soap_init(&soap);
   if (soap_call_calc__add(&soap, server, NULL, 200.0, 220.0, &sum) == SOAP_OK)
     {
       printf("sum = %g\n", sum);
     }
   if (soap_call_calc__mul(&soap, server, NULL, 210.0, 2.0, &sum) == SOAP_OK)
     {
       printf("mul = %g\n", sum);
     }
   if (soap_call_calc__div(&soap, server, NULL, 840.0, 2.0, &sum) == SOAP_OK)
     {
       printf("div = %g\n", sum);
     }
   if (soap_call_calc__sqrt(&soap, server, NULL, 176400.0, &sum) == SOAP_OK)
     {
       printf("sqrt = %g\n", sum);
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
