#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>
#include "encode.h"
#include "cp_00_t.h"
#include "eu_01_t.h"
#include "gb_02_t.h"
#include "gb_03_t.h"
#include "ir_04_t.h"
#include "ma_05_t.h"

static void
Encode_XSEncoding(pTHX_ encode_t *enc)
{
 dSP;
 HV *stash = gv_stashpv("Encode::XS", TRUE);
 SV *iv    = newSViv(PTR2IV(enc));
 SV *sv    = sv_bless(newRV_noinc(iv),stash);
 int i = 0;
 /* with the SvLEN() == 0 hack, PVX won't be freed. We cast away name's
 constness, in the hope that perl won't mess with it. */
 assert(SvTYPE(iv) >= SVt_PV); assert(SvLEN(iv) == 0);
 SvFLAGS(iv) |= SVp_POK;
 SvPVX(iv) = (char*) enc->name[0];
 PUSHMARK(sp);
 XPUSHs(sv);
 while (enc->name[i])
  {
   const char *name = enc->name[i++];
   XPUSHs(sv_2mortal(newSVpvn(name,strlen(name))));
  }
 PUTBACK;
 call_pv("Encode::define_encoding",G_DISCARD);
 SvREFCNT_dec(sv);
}

MODULE = Encode::CN	PACKAGE = Encode::CN
PROTOTYPES: DISABLE
BOOT:
{
#include "cp_00_t.exh"
#include "eu_01_t.exh"
#include "gb_02_t.exh"
#include "gb_03_t.exh"
#include "ir_04_t.exh"
#include "ma_05_t.exh"
}
