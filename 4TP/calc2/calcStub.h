/* calcStub.h
   Generated by gSOAP 2.8.18 from calc.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef calcStub_H
#define calcStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 20818
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_calc__addResponse
#define SOAP_TYPE_calc__addResponse (10)
/* calc:addResponse */
struct calc__addResponse
{
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__add
#define SOAP_TYPE_calc__add (11)
/* calc:add */
struct calc__add
{
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__subResponse
#define SOAP_TYPE_calc__subResponse (13)
/* calc:subResponse */
struct calc__subResponse
{
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__sub
#define SOAP_TYPE_calc__sub (14)
/* calc:sub */
struct calc__sub
{
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__sqrtResponse
#define SOAP_TYPE_calc__sqrtResponse (16)
/* calc:sqrtResponse */
struct calc__sqrtResponse
{
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__sqrt
#define SOAP_TYPE_calc__sqrt (17)
/* calc:sqrt */
struct calc__sqrt
{
	double a;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__divResponse
#define SOAP_TYPE_calc__divResponse (19)
/* calc:divResponse */
struct calc__divResponse
{
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__div
#define SOAP_TYPE_calc__div (20)
/* calc:div */
struct calc__div
{
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__mulResponse
#define SOAP_TYPE_calc__mulResponse (22)
/* calc:mulResponse */
struct calc__mulResponse
{
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_calc__mul
#define SOAP_TYPE_calc__mul (23)
/* calc:mul */
struct calc__mul
{
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (24)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (25)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (27)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (30)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (31)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 calc__add(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 calc__sub(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 calc__sqrt(struct soap*, double a, double *result);

SOAP_FMAC5 int SOAP_FMAC6 calc__div(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 calc__mul(struct soap*, double a, double b, double *result);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__add(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__sub(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__sqrt(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__div(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__mul(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_calc__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_calc__sub(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_calc__sqrt(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_calc__div(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_calc__mul(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

#ifdef __cplusplus
}
#endif

#endif

/* End of calcStub.h */