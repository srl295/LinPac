## Process this file with automake to produce Makefile.in

SUBDIRS = liblinpac lpapi libaxmail mailer mailmsg

s_crc = crc.cc
s_dostime = dostime.cc
s_autobin = autobin.cc
s_bell = bell.cc
s_compose = compose.cc
s_lpbck = lpbck.cc
s_name = name.cc
s_rawio = rawio.cc
s_rtt = rtt.cc
s_save7pl = save7pl.cc
s_testapp = testapp.c
s_yapp = yapp.cc
s_logbook = logbook.cc
s_flexpwd = flexpwd.cc
s_md2pwd = md2pwd.cc md2.cc
s_md5pwd = md5pwd.cc md5.cc
s_tnpwd = tnpwd.cc
s_catch = catch.cc
s_join = join.c

LDADD = ./liblinpac/liblinpac.la
AM_LDFLAGS = @LINPACLINK@

pkglibexec_PROGRAMS = autobin bell compose logbook lpbck \
               name rawio rtt save7pl testapp yapp flexpwd md2pwd \
               tnpwd md5pwd catch join

install-exec-hook: 
	cd $(DESTDIR)$(pkglibexecdir) && \
	    rm -f autotx && \
	    $(LN_S) autobin autotx
	cd $(DESTDIR)$(pkglibexecdir) && \
	    rm -f rawtx && \
	    $(LN_S) rawio rawtx
	cd $(DESTDIR)$(pkglibexecdir) && \
	    rm -f yapptx && \
	    $(LN_S) yapp yapptx

autobin_SOURCES = $(s_crc) $(s_autobin)
bell_SOURCES = $(s_bell)
compose_SOURCES = $(s_compose)
logbook_SOURCES = $(s_logbook)
lpbck_SOURCES = $(s_lpbck)
name_SOURCES = $(s_name)
rawio_SOURCES = $(s_rawio) 
rtt_SOURCES = $(s_rtt)
save7pl_SOURCES = $(s_crc) $(s_save7pl)
testapp_SOURCES = $(s_testapp)
yapp_SOURCES = $(s_yapp)
flexpwd_SOURCES = $(s_flexpwd)
md2pwd_SOURCES = $(s_md2pwd)
md5pwd_SOURCES = $(s_md5pwd)
tnpwd_SOURCES = $(s_tnpwd)
catch_SOURCES = $(s_catch)
join_SOURCES = $(s_join)

dist_pkgdata_DATA = commands
dist_pkglibexec_SCRIPTS = mheard shell w kill_chn pack sendfile

EXTRA_DIST = crc.h doorbl.h dostime.h hash.h\
             lpapp.h lpcalls.h lpwin.h md2.h md5.h tevent.h version.h
