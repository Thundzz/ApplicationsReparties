
#GSOAP_ROOT := $(HOME)/soft/gSOAP/x86_64
GSOAP_ROOT := /net/autre/aldenis/soft/x86_64
GSOAP_CPP  := $(GSOAP_ROOT)/bin/soapcpp2

CC      := gcc
CFLAGS  := -I. -I$(GSOAP_ROOT)/include 
LDFLAGS := -L$(GSOAP_ROOT)/lib -lm
LIBS    := -lgsoap

all: server client

annuaire.wsdl: annuaire.h
	$(GSOAP_CPP) -pannuaire -c annuaire.h

server: annuaire.wsdl server.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o server server.c annuaireServer.c annuaireC.c $(LIBS)

client: annuaire.wsdl client.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o client client.c annuaireClient.c annuaireC.c $(LIBS)

clean:
	rm client server annuaire.wsdl annuaire.nsmap annuaire.xsd annuaireH.h annuaireC.c annuaireClient.c annuaireClientLib.c annuaireServer.c annuaireServerLib.c annuaireStub.h annuaire.*.res.xml annuaire.*.req.xml
