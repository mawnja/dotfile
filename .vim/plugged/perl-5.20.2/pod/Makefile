# pod/Makefile
# This file is derived from pod/Makefile.SH.  Any changes made here will
# be lost the next time you run Configure.

POD = perl.pod perl5004delta.pod perl5005delta.pod perl5100delta.pod perl5101delta.pod perl5120delta.pod perl5121delta.pod perl5122delta.pod perl5123delta.pod perl5124delta.pod perl5125delta.pod perl5140delta.pod perl5141delta.pod perl5142delta.pod perl5143delta.pod perl5144delta.pod perl5160delta.pod perl5161delta.pod perl5162delta.pod perl5163delta.pod perl5180delta.pod perl5181delta.pod perl5182delta.pod perl5184delta.pod perl5200delta.pod perl5201delta.pod perl5202delta.pod perl561delta.pod perl56delta.pod perl581delta.pod perl582delta.pod perl583delta.pod perl584delta.pod perl585delta.pod perl586delta.pod perl587delta.pod perl588delta.pod perl589delta.pod perl58delta.pod perlaix.pod perlamiga.pod perlandroid.pod perlapi.pod perlapio.pod perlartistic.pod perlbook.pod perlboot.pod perlbot.pod perlbs2000.pod perlcall.pod perlce.pod perlcheat.pod perlclib.pod perlcn.pod perlcommunity.pod perlcygwin.pod perldata.pod perldbmfilter.pod perldebguts.pod perldebtut.pod perldebug.pod perldelta.pod perldiag.pod perldos.pod perldsc.pod perldtrace.pod perlebcdic.pod perlembed.pod perlexperiment.pod perlfilter.pod perlfork.pod perlform.pod perlfreebsd.pod perlfunc.pod perlgit.pod perlgpl.pod perlguts.pod perlhack.pod perlhacktips.pod perlhacktut.pod perlhaiku.pod perlhist.pod perlhpux.pod perlhurd.pod perlintern.pod perlinterp.pod perlintro.pod perliol.pod perlipc.pod perlirix.pod perljp.pod perlko.pod perllexwarn.pod perllinux.pod perllocale.pod perllol.pod perlmacos.pod perlmacosx.pod perlmod.pod perlmodinstall.pod perlmodlib.pod perlmodstyle.pod perlmroapi.pod perlnetware.pod perlnewmod.pod perlnumber.pod perlobj.pod perlootut.pod perlop.pod perlopenbsd.pod perlopentut.pod perlos2.pod perlos390.pod perlos400.pod perlpacktut.pod perlperf.pod perlplan9.pod perlpod.pod perlpodspec.pod perlpodstyle.pod perlpolicy.pod perlport.pod perlpragma.pod perlqnx.pod perlre.pod perlreapi.pod perlrebackslash.pod perlrecharclass.pod perlref.pod perlreftut.pod perlreguts.pod perlrepository.pod perlrequick.pod perlreref.pod perlretut.pod perlriscos.pod perlrun.pod perlsec.pod perlsolaris.pod perlsource.pod perlstyle.pod perlsub.pod perlsymbian.pod perlsyn.pod perlsynology.pod perlthrtut.pod perltie.pod perltoc.pod perltodo.pod perltooc.pod perltoot.pod perltrap.pod perltru64.pod perltw.pod perlunicode.pod perlunicook.pod perlunifaq.pod perluniintro.pod perluniprops.pod perlunitut.pod perlutil.pod perlvar.pod perlvms.pod perlvos.pod perlwin32.pod

MAN = perl.man perl5004delta.man perl5005delta.man perl5100delta.man perl5101delta.man perl5120delta.man perl5121delta.man perl5122delta.man perl5123delta.man perl5124delta.man perl5125delta.man perl5140delta.man perl5141delta.man perl5142delta.man perl5143delta.man perl5144delta.man perl5160delta.man perl5161delta.man perl5162delta.man perl5163delta.man perl5180delta.man perl5181delta.man perl5182delta.man perl5184delta.man perl5200delta.man perl5201delta.man perl5202delta.man perl561delta.man perl56delta.man perl581delta.man perl582delta.man perl583delta.man perl584delta.man perl585delta.man perl586delta.man perl587delta.man perl588delta.man perl589delta.man perl58delta.man perlaix.man perlamiga.man perlandroid.man perlapi.man perlapio.man perlartistic.man perlbook.man perlboot.man perlbot.man perlbs2000.man perlcall.man perlce.man perlcheat.man perlclib.man perlcn.man perlcommunity.man perlcygwin.man perldata.man perldbmfilter.man perldebguts.man perldebtut.man perldebug.man perldelta.man perldiag.man perldos.man perldsc.man perldtrace.man perlebcdic.man perlembed.man perlexperiment.man perlfilter.man perlfork.man perlform.man perlfreebsd.man perlfunc.man perlgit.man perlgpl.man perlguts.man perlhack.man perlhacktips.man perlhacktut.man perlhaiku.man perlhist.man perlhpux.man perlhurd.man perlintern.man perlinterp.man perlintro.man perliol.man perlipc.man perlirix.man perljp.man perlko.man perllexwarn.man perllinux.man perllocale.man perllol.man perlmacos.man perlmacosx.man perlmod.man perlmodinstall.man perlmodlib.man perlmodstyle.man perlmroapi.man perlnetware.man perlnewmod.man perlnumber.man perlobj.man perlootut.man perlop.man perlopenbsd.man perlopentut.man perlos2.man perlos390.man perlos400.man perlpacktut.man perlperf.man perlplan9.man perlpod.man perlpodspec.man perlpodstyle.man perlpolicy.man perlport.man perlpragma.man perlqnx.man perlre.man perlreapi.man perlrebackslash.man perlrecharclass.man perlref.man perlreftut.man perlreguts.man perlrepository.man perlrequick.man perlreref.man perlretut.man perlriscos.man perlrun.man perlsec.man perlsolaris.man perlsource.man perlstyle.man perlsub.man perlsymbian.man perlsyn.man perlsynology.man perlthrtut.man perltie.man perltoc.man perltodo.man perltooc.man perltoot.man perltrap.man perltru64.man perltw.man perlunicode.man perlunicook.man perlunifaq.man perluniintro.man perluniprops.man perlunitut.man perlutil.man perlvar.man perlvms.man perlvos.man perlwin32.man

# no perltoc.html
HTML = perl.html perl5004delta.html perl5005delta.html perl5100delta.html perl5101delta.html perl5120delta.html perl5121delta.html perl5122delta.html perl5123delta.html perl5124delta.html perl5125delta.html perl5140delta.html perl5141delta.html perl5142delta.html perl5143delta.html perl5144delta.html perl5160delta.html perl5161delta.html perl5162delta.html perl5163delta.html perl5180delta.html perl5181delta.html perl5182delta.html perl5184delta.html perl5200delta.html perl5201delta.html perl5202delta.html perl561delta.html perl56delta.html perl581delta.html perl582delta.html perl583delta.html perl584delta.html perl585delta.html perl586delta.html perl587delta.html perl588delta.html perl589delta.html perl58delta.html perlaix.html perlamiga.html perlandroid.html perlapi.html perlapio.html perlartistic.html perlbook.html perlboot.html perlbot.html perlbs2000.html perlcall.html perlce.html perlcheat.html perlclib.html perlcn.html perlcommunity.html perlcygwin.html perldata.html perldbmfilter.html perldebguts.html perldebtut.html perldebug.html perldelta.html perldiag.html perldos.html perldsc.html perldtrace.html perlebcdic.html perlembed.html perlexperiment.html perlfilter.html perlfork.html perlform.html perlfreebsd.html perlfunc.html perlgit.html perlgpl.html perlguts.html perlhack.html perlhacktips.html perlhacktut.html perlhaiku.html perlhist.html perlhpux.html perlhurd.html perlintern.html perlinterp.html perlintro.html perliol.html perlipc.html perlirix.html perljp.html perlko.html perllexwarn.html perllinux.html perllocale.html perllol.html perlmacos.html perlmacosx.html perlmod.html perlmodinstall.html perlmodlib.html perlmodstyle.html perlmroapi.html perlnetware.html perlnewmod.html perlnumber.html perlobj.html perlootut.html perlop.html perlopenbsd.html perlopentut.html perlos2.html perlos390.html perlos400.html perlpacktut.html perlperf.html perlplan9.html perlpod.html perlpodspec.html perlpodstyle.html perlpolicy.html perlport.html perlpragma.html perlqnx.html perlre.html perlreapi.html perlrebackslash.html perlrecharclass.html perlref.html perlreftut.html perlreguts.html perlrepository.html perlrequick.html perlreref.html perlretut.html perlriscos.html perlrun.html perlsec.html perlsolaris.html perlsource.html perlstyle.html perlsub.html perlsymbian.html perlsyn.html perlsynology.html perlthrtut.html perltie.html  perltodo.html perltooc.html perltoot.html perltrap.html perltru64.html perltw.html perlunicode.html perlunicook.html perlunifaq.html perluniintro.html perluniprops.html perlunitut.html perlutil.html perlvar.html perlvms.html perlvos.html perlwin32.html

TEX  = perl.tex perl5004delta.tex perl5005delta.tex perl5100delta.tex perl5101delta.tex perl5120delta.tex perl5121delta.tex perl5122delta.tex perl5123delta.tex perl5124delta.tex perl5125delta.tex perl5140delta.tex perl5141delta.tex perl5142delta.tex perl5143delta.tex perl5144delta.tex perl5160delta.tex perl5161delta.tex perl5162delta.tex perl5163delta.tex perl5180delta.tex perl5181delta.tex perl5182delta.tex perl5184delta.tex perl5200delta.tex perl5201delta.tex perl5202delta.tex perl561delta.tex perl56delta.tex perl581delta.tex perl582delta.tex perl583delta.tex perl584delta.tex perl585delta.tex perl586delta.tex perl587delta.tex perl588delta.tex perl589delta.tex perl58delta.tex perlaix.tex perlamiga.tex perlandroid.tex perlapi.tex perlapio.tex perlartistic.tex perlbook.tex perlboot.tex perlbot.tex perlbs2000.tex perlcall.tex perlce.tex perlcheat.tex perlclib.tex perlcn.tex perlcommunity.tex perlcygwin.tex perldata.tex perldbmfilter.tex perldebguts.tex perldebtut.tex perldebug.tex perldelta.tex perldiag.tex perldos.tex perldsc.tex perldtrace.tex perlebcdic.tex perlembed.tex perlexperiment.tex perlfilter.tex perlfork.tex perlform.tex perlfreebsd.tex perlfunc.tex perlgit.tex perlgpl.tex perlguts.tex perlhack.tex perlhacktips.tex perlhacktut.tex perlhaiku.tex perlhist.tex perlhpux.tex perlhurd.tex perlintern.tex perlinterp.tex perlintro.tex perliol.tex perlipc.tex perlirix.tex perljp.tex perlko.tex perllexwarn.tex perllinux.tex perllocale.tex perllol.tex perlmacos.tex perlmacosx.tex perlmod.tex perlmodinstall.tex perlmodlib.tex perlmodstyle.tex perlmroapi.tex perlnetware.tex perlnewmod.tex perlnumber.tex perlobj.tex perlootut.tex perlop.tex perlopenbsd.tex perlopentut.tex perlos2.tex perlos390.tex perlos400.tex perlpacktut.tex perlperf.tex perlplan9.tex perlpod.tex perlpodspec.tex perlpodstyle.tex perlpolicy.tex perlport.tex perlpragma.tex perlqnx.tex perlre.tex perlreapi.tex perlrebackslash.tex perlrecharclass.tex perlref.tex perlreftut.tex perlreguts.tex perlrepository.tex perlrequick.tex perlreref.tex perlretut.tex perlriscos.tex perlrun.tex perlsec.tex perlsolaris.tex perlsource.tex perlstyle.tex perlsub.tex perlsymbian.tex perlsyn.tex perlsynology.tex perlthrtut.tex perltie.tex perltoc.tex perltodo.tex perltooc.tex perltoot.tex perltrap.tex perltru64.tex perltw.tex perlunicode.tex perlunicook.tex perlunifaq.tex perluniintro.tex perluniprops.tex perlunitut.tex perlutil.tex perlvar.tex perlvms.tex perlvos.tex perlwin32.tex  

# The following is used to include the current directory in
# the dynamic loader path you are building a shared libperl.
LDLIBPTH = 


HTMLROOT = /	# Change this to fix cross-references in HTML
POD2HTML_ARGS = --htmlroot=$(HTMLROOT) --podroot=.. --podpath=pod:lib:ext:vms
POD2HTML = ../ext/Pod-Html/pod2html
POD2MAN = ../cpan/podlators/pod2man
PODCHECKER =  ../cpan/Pod-Parser/podchecker

PERL = ../miniperl
PERLILIB = $(PERL) -I../lib
REALPERL = ../perl

all: man

man:	$(POD2MAN) $(MAN)

html:	$(POD2HTML) $(HTML)

toc perltoc.pod:	buildtoc
	$(PERLILIB) buildtoc

.SUFFIXES: .pm .pod

.SUFFIXES: .man

.pm.man:     $(POD2MAN)
	$(REALPERL) -I../lib $(POD2MAN) $*.pm >$*.man

.pod.man:     $(POD2MAN)
	$(REALPERL) -I../lib $(POD2MAN) $*.pod >$*.man

.SUFFIXES: .html

.pm.html:    $(POD2HTML)
	$(PERL) -I../lib $(POD2HTML) $(POD2HTML_ARGS) --infile=$*.pm --outfile=$*.html

.pod.html:    $(POD2HTML)
	$(PERL) -I../lib $(POD2HTML) $(POD2HTML_ARGS) --infile=$*.pod --outfile=$*.html

clean:
	rm -f $(MAN)
	rm -f $(HTML)
	rm -f $(TEX)
	rm -f pod2html-*cache
	rm -f *.aux *.log *.exe

realclean:	clean

distclean:	realclean

veryclean:	distclean
	-rm -f *~ *.orig

check:	$(PODCHECKER)
	@echo "checking..."; \
	$(PERL) -I../lib $(PODCHECKER) $(POD)
