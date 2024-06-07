/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.24 from the
 * contents of Unicode.xs. Do not edit this file, edit Unicode.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "Unicode.xs"
/*
 $Id: Unicode.xs,v 2.11 2014/04/29 16:25:06 dankogai Exp dankogai $
 */

#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "../Encode/encode.h"

#define FBCHAR			0xFFFd
#define BOM_BE			0xFeFF
#define BOM16LE			0xFFFe
#define BOM32LE			0xFFFe0000
#define issurrogate(x)		(0xD800 <= (x)  && (x) <= 0xDFFF )
#define isHiSurrogate(x)	(0xD800 <= (x)  && (x) <  0xDC00 )
#define isLoSurrogate(x)	(0xDC00 <= (x)  && (x) <= 0xDFFF )
#define invalid_ucs2(x)         ( issurrogate(x) || 0xFFFF < (x) )

/* For pre-5.14 source compatibility */
#ifndef UNICODE_WARN_ILLEGAL_INTERCHANGE
#   define UNICODE_WARN_ILLEGAL_INTERCHANGE 0
#   define UTF8_DISALLOW_SURROGATE 0
#   define UTF8_WARN_SURROGATE 0
#   define UTF8_DISALLOW_FE_FF 0
#   define UTF8_WARN_FE_FF 0
#   define UTF8_WARN_NONCHAR 0
#endif

#define PERLIO_BUFSIZ 1024 /* XXX value comes from PerlIOEncode_get_base */

/* Avoid wasting too much space in the result buffer */
/* static void */
/* shrink_buffer(SV *result) */
/* { */
/*     if (SvLEN(result) > 42 + SvCUR(result)) { */
/* 	char *buf; */
/* 	STRLEN len = 1 + SvCUR(result); /\* include the NUL byte *\/ */
/* 	New(0, buf, len, char); */
/* 	Copy(SvPVX(result), buf, len, char); */
/* 	Safefree(SvPVX(result)); */
/* 	SvPV_set(result, buf); */
/* 	SvLEN_set(result, len); */
/*     } */
/* } */

#define shrink_buffer(result) { \
    if (SvLEN(result) > 42 + SvCUR(result)) { \
	char *newpv; \
	STRLEN newlen = 1 + SvCUR(result); /* include the NUL byte */ \
	New(0, newpv, newlen, char); \
	Copy(SvPVX(result), newpv, newlen, char); \
	Safefree(SvPVX(result)); \
	SvPV_set(result, newpv); \
	SvLEN_set(result, newlen); \
    } \
}

static UV
enc_unpack(pTHX_ U8 **sp, U8 *e, STRLEN size, U8 endian)
{
    U8 *s = *sp;
    UV v = 0;
    if (s+size > e) {
	croak("Partial character %c",(char) endian);
    }
    switch(endian) {
    case 'N':
	v = *s++;
	v = (v << 8) | *s++;
    case 'n':
	v = (v << 8) | *s++;
	v = (v << 8) | *s++;
	break;
    case 'V':
    case 'v':
	v |= *s++;
	v |= (*s++ << 8);
	if (endian == 'v')
	    break;
	v |= (*s++ << 16);
	v |= ((UV)*s++ << 24);
	break;
    default:
	croak("Unknown endian %c",(char) endian);
	break;
    }
    *sp = s;
    return v;
}

void
enc_pack(pTHX_ SV *result, STRLEN size, U8 endian, UV value)
{
    U8 *d = (U8 *) SvPV_nolen(result);

    switch(endian) {
    case 'v':
    case 'V':
	d += SvCUR(result);
	SvCUR_set(result,SvCUR(result)+size);
	while (size--) {
	    *d++ = (U8)(value & 0xFF);
	    value >>= 8;
	}
	break;
    case 'n':
    case 'N':
	SvCUR_set(result,SvCUR(result)+size);
	d += SvCUR(result);
	while (size--) {
	    *--d = (U8)(value & 0xFF);
	    value >>= 8;
	}
	break;
    default:
	croak("Unknown endian %c",(char) endian);
	break;
    }
}

#line 132 "Unicode.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 274 "Unicode.c"
#define attr(k, l)  (hv_exists((HV *)SvRV(obj),k,l) ? \
    *hv_fetch((HV *)SvRV(obj),k,l,0) : &PL_sv_undef)

XS_EUPXS(XS_Encode__Unicode_decode_xs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Encode__Unicode_decode_xs)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "obj, str, check = 0");
    {
	SV *	obj = ST(0)
;
	SV *	str = ST(1)
;
	IV	check;

	if (items < 3)
	    check = 0;
	else {
	    check = (IV)SvIV(ST(2))
;
	}
#line 135 "Unicode.xs"
{
    U8 endian    = *((U8 *)SvPV_nolen(attr("endian", 6)));
    int size     = SvIV(attr("size", 4));
    int ucs2     = -1; /* only needed in the event of surrogate pairs */
    SV *result   = newSVpvn("",0);
    STRLEN usize = (size > 0 ? size : 1); /* protect against rogue size<=0 */
    STRLEN ulen;
    STRLEN resultbuflen;
    U8 *resultbuf;
    U8 *s = (U8 *)SvPVbyte(str,ulen);
    U8 *e = (U8 *)SvEND(str);
    /* Optimise for the common case of being called from PerlIOEncode_fill()
       with a standard length buffer. In this case the result SV's buffer is
       only used temporarily, so we can afford to allocate the maximum needed
       and not care about unused space. */
    const bool temp_result = (ulen == PERLIO_BUFSIZ);

    ST(0) = sv_2mortal(result);
    SvUTF8_on(result);

    if (!endian && s+size <= e) {
	UV bom;
	endian = (size == 4) ? 'N' : 'n';
	bom = enc_unpack(aTHX_ &s,e,size,endian);
	if (bom != BOM_BE) {
	    if (bom == BOM16LE) {
		endian = 'v';
	    }
	    else if (bom == BOM32LE) {
		endian = 'V';
	    }
	    else {
		croak("%"SVf":Unrecognised BOM %"UVxf,
		      *hv_fetch((HV *)SvRV(obj),"Name",4,0),
		      bom);
	    }
	}
#if 1
	/* Update endian for next sequence */
	if (SvTRUE(attr("renewed", 7))) {
	    hv_store((HV *)SvRV(obj),"endian",6,newSVpv((char *)&endian,1),0);
	}
#endif
    }

    if (temp_result) {
	resultbuflen = 1 + ulen/usize * UTF8_MAXLEN;
    } else {
	/* Preallocate the buffer to the minimum possible space required. */
	resultbuflen = ulen/usize + UTF8_MAXLEN + 1;
    }
    resultbuf = (U8 *) SvGROW(result, resultbuflen);

    while (s < e && s+size <= e) {
	UV ord = enc_unpack(aTHX_ &s,e,size,endian);
	U8 *d;
	if (issurrogate(ord)) {
	    if (ucs2 == -1) {
		ucs2 = SvTRUE(attr("ucs2", 4));
	    }
	    if (ucs2 || size == 4) {
		if (check) {
		    croak("%"SVf":no surrogates allowed %"UVxf,
			  *hv_fetch((HV *)SvRV(obj),"Name",4,0),
			  ord);
		}
		ord = FBCHAR;
	    }
	    else {
		UV lo;
		if (!isHiSurrogate(ord)) {
		    if (check) {
			croak("%"SVf":Malformed HI surrogate %"UVxf,
			      *hv_fetch((HV *)SvRV(obj),"Name",4,0),
			      ord);
		    }
		    else {
			ord = FBCHAR;
		    }
		}
		else if (s+size > e) {
		    if (check) {
		        if (check & ENCODE_STOP_AT_PARTIAL) {
		             s -= size;
		             break;
		        }
		        else {
		             croak("%"SVf":Malformed HI surrogate %"UVxf,
				   *hv_fetch((HV *)SvRV(obj),"Name",4,0),
				   ord);
		        }
		    }
		    else {
		        ord = FBCHAR;
		    }
		}
		else {
		    lo = enc_unpack(aTHX_ &s,e,size,endian);
		    if (!isLoSurrogate(lo)) {
			if (check) {
			    croak("%"SVf":Malformed LO surrogate %"UVxf,
				  *hv_fetch((HV *)SvRV(obj),"Name",4,0),
				  ord);
			}
			else {
			    s -= size;
			    ord = FBCHAR;
			}
		    }
		    else {
			ord = 0x10000 + ((ord - 0xD800) << 10) + (lo - 0xDC00);
		    }
		}
	    }
	}

	if ((ord & 0xFFFE) == 0xFFFE || (ord >= 0xFDD0 && ord <= 0xFDEF)) {
	    if (check) {
		croak("%"SVf":Unicode character %"UVxf" is illegal",
		      *hv_fetch((HV *)SvRV(obj),"Name",4,0),
		      ord);
	    } else {
		ord = FBCHAR;
	    }
	}

	if (resultbuflen < SvCUR(result) + UTF8_MAXLEN + 1) {
	    /* Do not allocate >8Mb more than the minimum needed.
	       This prevents allocating too much in the rogue case of a large
	       input consisting initially of long sequence uft8-byte unicode
	       chars followed by single utf8-byte chars. */
            /* +1 
               fixes  Unicode.xs!decode_xs n-byte heap-overflow
              */
	    STRLEN remaining = (e - s)/usize + 1; /* +1 to avoid the leak */
	    STRLEN max_alloc = remaining + (8*1024*1024);
	    STRLEN est_alloc = remaining * UTF8_MAXLEN;
	    STRLEN newlen = SvLEN(result) + /* min(max_alloc, est_alloc) */
		(est_alloc > max_alloc ? max_alloc : est_alloc);
	    resultbuf = (U8 *) SvGROW(result, newlen);
	    resultbuflen = SvLEN(result);
	}

	d = uvuni_to_utf8_flags(resultbuf+SvCUR(result), ord,
                                            UNICODE_WARN_ILLEGAL_INTERCHANGE);
	SvCUR_set(result, d - (U8 *)SvPVX(result));
    }

    if (s < e) {
	/* unlikely to happen because it's fixed-length -- dankogai */
	if (check & ENCODE_WARN_ON_ERR) {
	    Perl_warner(aTHX_ packWARN(WARN_UTF8),"%"SVf":Partial character",
			*hv_fetch((HV *)SvRV(obj),"Name",4,0));
	}
    }
    if (check && !(check & ENCODE_LEAVE_SRC)) {
	if (s < e) {
	    Move(s,SvPVX(str),e-s,U8);
	    SvCUR_set(str,(e-s));
	}
	else {
	    SvCUR_set(str,0);
	}
	*SvEND(str) = '\0';
    }

    if (!temp_result) shrink_buffer(result);
    if (SvTAINTED(str)) SvTAINTED_on(result); /* propagate taintedness */
    XSRETURN(1);
}
#line 468 "Unicode.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Encode__Unicode_encode_xs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Encode__Unicode_encode_xs)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "obj, utf8, check = 0");
    {
	SV *	obj = ST(0)
;
	SV *	utf8 = ST(1)
;
	IV	check;

	if (items < 3)
	    check = 0;
	else {
	    check = (IV)SvIV(ST(2))
;
	}
#line 312 "Unicode.xs"
{
    U8 endian = *((U8 *)SvPV_nolen(attr("endian", 6)));
    const int size = SvIV(attr("size", 4));
    int ucs2 = -1; /* only needed if there is invalid_ucs2 input */
    const STRLEN usize = (size > 0 ? size : 1);
    SV *result = newSVpvn("", 0);
    STRLEN ulen;
    U8 *s = (U8 *) SvPVutf8(utf8, ulen);
    const U8 *e = (U8 *) SvEND(utf8);
    /* Optimise for the common case of being called from PerlIOEncode_flush()
       with a standard length buffer. In this case the result SV's buffer is
       only used temporarily, so we can afford to allocate the maximum needed
       and not care about unused space. */
    const bool temp_result = (ulen == PERLIO_BUFSIZ);

    ST(0) = sv_2mortal(result);

    /* Preallocate the result buffer to the maximum possible size.
       ie. assume each UTF8 byte is 1 character.
       Then shrink the result's buffer if necesary at the end. */
    SvGROW(result, ((ulen+1) * usize));

    if (!endian) {
	endian = (size == 4) ? 'N' : 'n';
	enc_pack(aTHX_ result,size,endian,BOM_BE);
#if 1
	/* Update endian for next sequence */
	if (SvTRUE(attr("renewed", 7))) {
	    hv_store((HV *)SvRV(obj),"endian",6,newSVpv((char *)&endian,1),0);
	}
#endif
    }
    while (s < e && s+UTF8SKIP(s) <= e) {
	STRLEN len;
	UV ord = utf8n_to_uvuni(s, e-s, &len, (UTF8_DISALLOW_SURROGATE
                                               |UTF8_WARN_SURROGATE
                                               |UTF8_DISALLOW_FE_FF
                                               |UTF8_WARN_FE_FF
                                               |UTF8_WARN_NONCHAR));
	s += len;
	if (size != 4 && invalid_ucs2(ord)) {
	    if (!issurrogate(ord)) {
		if (ucs2 == -1) {
		    ucs2 = SvTRUE(attr("ucs2", 4));
		}
		if (ucs2 || ord > 0x10FFFF) {
		    if (check) {
			croak("%"SVf":code point \"\\x{%"UVxf"}\" too high",
				  *hv_fetch((HV *)SvRV(obj),"Name",4,0),ord);
		    }
		    enc_pack(aTHX_ result,size,endian,FBCHAR);
		} else {
		    UV hi = ((ord - 0x10000) >> 10)   + 0xD800;
		    UV lo = ((ord - 0x10000) & 0x3FF) + 0xDC00;
		    enc_pack(aTHX_ result,size,endian,hi);
		    enc_pack(aTHX_ result,size,endian,lo);
		}
	    }
	    else {
		/* not supposed to happen */
		enc_pack(aTHX_ result,size,endian,FBCHAR);
	    }
	}
	else {
	    enc_pack(aTHX_ result,size,endian,ord);
	}
    }
    if (s < e) {
	/* UTF-8 partial char happens often on PerlIO.
	   Since this is okay and normal, we do not warn.
	   But this is critical when you choose to LEAVE_SRC
	   in which case we die */
	if (check & (ENCODE_DIE_ON_ERR|ENCODE_LEAVE_SRC)) {
	    Perl_croak(aTHX_ "%"SVf":partial character is not allowed "
		       "when CHECK = 0x%" UVuf,
		       *hv_fetch((HV *)SvRV(obj),"Name",4,0), check);
	}
    }
    if (check && !(check & ENCODE_LEAVE_SRC)) {
	if (s < e) {
	    Move(s,SvPVX(utf8),e-s,U8);
	    SvCUR_set(utf8,(e-s));
	}
	else {
	    SvCUR_set(utf8,0);
	}
	*SvEND(utf8) = '\0';
    }

    if (!temp_result) shrink_buffer(result);
    if (SvTAINTED(utf8)) SvTAINTED_on(result); /* propagate taintedness */

    SvSETMAGIC(utf8);

    XSRETURN(1);
}
#line 590 "Unicode.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Encode__Unicode); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Encode__Unicode)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("Encode::Unicode::decode_xs", XS_Encode__Unicode_decode_xs, file);
        newXS("Encode::Unicode::encode_xs", XS_Encode__Unicode_encode_xs, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

