## Process this file with automake to produce Makefile.in

s_mail = mail.cc mail_call.cc mail_comp.cc mail_data.cc \
         mail_edit.cc mail_files.cc mail_filt.cc \
         mail_help.cc mail_input.cc mail_list.cc mail_route.cc \
         mail_screen.cc

LDADD = ../liblinpac/liblinpac.la ../libaxmail/libaxmail.la
AM_LDFLAGS = @LINPACLINK@

pkglibexec_PROGRAMS = mail

mail_SOURCES = $(s_mail) 

EXTRA_DIST = axmail.h lpapp.h mail_call.h \
	    mail_comp.h mail_data.h mail_edit.h mail_files.h mail_filt.h \
	    mail_help.h mail_input.h mail_list.h mail_route.h mail_screen.h \
	    tevent.h version.h
