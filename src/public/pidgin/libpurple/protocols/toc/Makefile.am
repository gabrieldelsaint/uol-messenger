EXTRA_DIST = \
	PROTOCOL \
	Makefile.mingw

pkgdir = $(libdir)/purple-$(PURPLE_MAJOR_VERSION)

TOCSOURCES = toc.c

AM_CFLAGS = $(st)

libtoc_la_LDFLAGS = -module -avoid-version

if STATIC_TOC

st = -DPURPLE_STATIC_PRPL
noinst_LTLIBRARIES = libtoc.la
libtoc_la_SOURCES  = $(TOCSOURCES)
libtoc_la_CFLAGS   = $(AM_CFLAGS)

else

st =
pkg_LTLIBRARIES   = libtoc.la
libtoc_la_SOURCES = $(TOCSOURCES)

endif

AM_CPPFLAGS = \
	-I$(top_srcdir)/libpurple \
	-I$(top_builddir)/libpurple \
	$(GLIB_CFLAGS) \
	$(DEBUG_CFLAGS)
