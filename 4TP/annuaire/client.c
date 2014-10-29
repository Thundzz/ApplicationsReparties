#include "annuaireH.h"
#include "annuaire.nsmap"

static char server[] = "http://localhost:18083/";

int main(int argc, char**argv) 
{ 
   int sum; 
   struct soap soap;
   soap_init(&soap);
   entry e1, e2;
   e1.name = malloc(30* sizeof(char));
   e2.name = malloc(30* sizeof(char));
   strcpy (e1.name, "Thundzz");
   strcpy (e2.name,"Karma");
   if (soap_call_annuaire__add(&soap, server, NULL, e1, &sum) == SOAP_OK)
     {
       printf("add Thundzz = %d\n", sum);
     }
   if (soap_call_annuaire__search(&soap, server, NULL, e1, &sum) == SOAP_OK)
     {
       printf("search Thundzz = %d\n", sum);
     }
   if (soap_call_annuaire__search(&soap, server, NULL, e2, &sum) == SOAP_OK)
     {
       printf("Karmaoutai = %d\n", sum);
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
