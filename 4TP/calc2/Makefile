
#GSOAP_ROOT := $(HOME)/soft/gSOAP/x86_64
GSOAP_ROOT := /net/autre/aldenis/soft/x86_64
GSOAP_CPP  := $(GSOAP_ROOT)/bin/soapcpp2

CC      := gcc
CFLAGS  := -I. -I$(GSOAP_ROOT)/include 
LDFLAGS := -L$(GSOAP_ROOT)/lib -lm
LIBS    := -lgsoap

all: server client

calc.wsdl: calc.h
	$(GSOAP_CPP) -pcalc -c calc.h

server: calc.wsdl server.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o server server.c calcServer.c calcC.c $(LIBS)

client: calc.wsdl client.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o client client.c calcClient.c calcC.c $(LIBS)

clean:
	rm client server calc.wsdl calc.nsmap calc.xsd calcH.h calcC.c calcClient.c calcClientLib.c calcServer.c calcServerLib.c calcStub.h calc.*.res.xml calc.*.req.xml
