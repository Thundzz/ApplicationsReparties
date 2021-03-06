/* calcServer.c
   Generated by gSOAP 2.8.18 from calc.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "calcH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) calcServer.c ver 2.8.18 2014-10-29 09:43:50 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "calc:add"))
		return soap_serve_calc__add(soap);
	if (!soap_match_tag(soap, soap->tag, "calc:sub"))
		return soap_serve_calc__sub(soap);
	if (!soap_match_tag(soap, soap->tag, "calc:sqrt"))
		return soap_serve_calc__sqrt(soap);
	if (!soap_match_tag(soap, soap->tag, "calc:div"))
		return soap_serve_calc__div(soap);
	if (!soap_match_tag(soap, soap->tag, "calc:mul"))
		return soap_serve_calc__mul(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__add(struct soap *soap)
{	struct calc__add soap_tmp_calc__add;
	struct calc__addResponse soap_tmp_calc__addResponse;
	double soap_tmp_double;
	soap_default_calc__addResponse(soap, &soap_tmp_calc__addResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_calc__addResponse.result = &soap_tmp_double;
	soap_default_calc__add(soap, &soap_tmp_calc__add);
	if (!soap_get_calc__add(soap, &soap_tmp_calc__add, "calc:add", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = calc__add(soap, soap_tmp_calc__add.a, soap_tmp_calc__add.b, soap_tmp_calc__addResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_calc__addResponse(soap, &soap_tmp_calc__addResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_calc__addResponse(soap, &soap_tmp_calc__addResponse, "calc:addResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_calc__addResponse(soap, &soap_tmp_calc__addResponse, "calc:addResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__sub(struct soap *soap)
{	struct calc__sub soap_tmp_calc__sub;
	struct calc__subResponse soap_tmp_calc__subResponse;
	double soap_tmp_double;
	soap_default_calc__subResponse(soap, &soap_tmp_calc__subResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_calc__subResponse.result = &soap_tmp_double;
	soap_default_calc__sub(soap, &soap_tmp_calc__sub);
	if (!soap_get_calc__sub(soap, &soap_tmp_calc__sub, "calc:sub", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = calc__sub(soap, soap_tmp_calc__sub.a, soap_tmp_calc__sub.b, soap_tmp_calc__subResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_calc__subResponse(soap, &soap_tmp_calc__subResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_calc__subResponse(soap, &soap_tmp_calc__subResponse, "calc:subResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_calc__subResponse(soap, &soap_tmp_calc__subResponse, "calc:subResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__sqrt(struct soap *soap)
{	struct calc__sqrt soap_tmp_calc__sqrt;
	struct calc__sqrtResponse soap_tmp_calc__sqrtResponse;
	double soap_tmp_double;
	soap_default_calc__sqrtResponse(soap, &soap_tmp_calc__sqrtResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_calc__sqrtResponse.result = &soap_tmp_double;
	soap_default_calc__sqrt(soap, &soap_tmp_calc__sqrt);
	if (!soap_get_calc__sqrt(soap, &soap_tmp_calc__sqrt, "calc:sqrt", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = calc__sqrt(soap, soap_tmp_calc__sqrt.a, soap_tmp_calc__sqrtResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_calc__sqrtResponse(soap, &soap_tmp_calc__sqrtResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_calc__sqrtResponse(soap, &soap_tmp_calc__sqrtResponse, "calc:sqrtResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_calc__sqrtResponse(soap, &soap_tmp_calc__sqrtResponse, "calc:sqrtResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__div(struct soap *soap)
{	struct calc__div soap_tmp_calc__div;
	struct calc__divResponse soap_tmp_calc__divResponse;
	double soap_tmp_double;
	soap_default_calc__divResponse(soap, &soap_tmp_calc__divResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_calc__divResponse.result = &soap_tmp_double;
	soap_default_calc__div(soap, &soap_tmp_calc__div);
	if (!soap_get_calc__div(soap, &soap_tmp_calc__div, "calc:div", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = calc__div(soap, soap_tmp_calc__div.a, soap_tmp_calc__div.b, soap_tmp_calc__divResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_calc__divResponse(soap, &soap_tmp_calc__divResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_calc__divResponse(soap, &soap_tmp_calc__divResponse, "calc:divResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_calc__divResponse(soap, &soap_tmp_calc__divResponse, "calc:divResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_calc__mul(struct soap *soap)
{	struct calc__mul soap_tmp_calc__mul;
	struct calc__mulResponse soap_tmp_calc__mulResponse;
	double soap_tmp_double;
	soap_default_calc__mulResponse(soap, &soap_tmp_calc__mulResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_calc__mulResponse.result = &soap_tmp_double;
	soap_default_calc__mul(soap, &soap_tmp_calc__mul);
	if (!soap_get_calc__mul(soap, &soap_tmp_calc__mul, "calc:mul", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = calc__mul(soap, soap_tmp_calc__mul.a, soap_tmp_calc__mul.b, soap_tmp_calc__mulResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize_calc__mulResponse(soap, &soap_tmp_calc__mulResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_calc__mulResponse(soap, &soap_tmp_calc__mulResponse, "calc:mulResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_calc__mulResponse(soap, &soap_tmp_calc__mulResponse, "calc:mulResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of calcServer.c */
