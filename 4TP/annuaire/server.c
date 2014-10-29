#include "annuaireH.h" 
#include "annuaire.nsmap"

#include <math.h>
#include <string.h>

#define MAX_SIZE 420

static int port = 18083;
static char hostname[] = "localhost";

static entry annuaire[MAX_SIZE];
static int size;

int main(int argc, char**argv)
{ 


   struct soap soap; 
   int m, s;
   size = 0;
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

int annuaire__add(struct soap *soap, entry e, int*result) 
{ 
   //printf("\nAdding new entry: %s ...\n", e.name);
   if (size < MAX_SIZE){
      annuaire[size].name = malloc((1+strlen(e.name))*sizeof(char));
      strcpy(annuaire[size].name, e.name);
      size++;
      *result = 1;
   }
   else
      *result = 0;
   return SOAP_OK; 
} 

int annuaire__search(struct soap *soap, entry e, int*result) 
{ 
   int i;
   *result = 0;
   for (i = 0; i < size; ++i)
   {
      //printf("\nSearching... current entry: %s ...\n", annuaire[i].name);     
      if(strcmp(e.name, annuaire[i].name) == 0)
      {
         *result = 1;
         break;
      }
   }
   return SOAP_OK; 
} 
