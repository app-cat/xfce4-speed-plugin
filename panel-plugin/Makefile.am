plugindir = $(libdir)/xfce4/panel/plugins
plugin_LTLIBRARIES = libspeed.la

LIBS = @LIBS@ @SOLLIBS@

libspeed_la_SOURCES =							\
	speed.c							\
	monitor-label.c							\
	monitor-label.h							\
	utils.c								\
	utils.h								\
	net.h								\
	net.c								\
	os.h								\
	wormulon.h							\
	slurm.h

libspeed_la_CFLAGS =							\
	-DPACKAGE_LOCALE_DIR=\"$(localedir)\"				\
	@LIBXFCE4PANEL_CFLAGS@						\
	@LIBXFCE4UI_CFLAGS@

libspeed_la_LDFLAGS =							\
	-avoid-version							\
	-module								\
	-no-undefined							\
	-export-symbols-regex '^xfce_panel_module_(preinit|init|construct)' \
	$(PLATFORM_LDFLAGS)

libspeed_la_LIBADD =							\
	@SOLLIBS@							\
	@LIBXFCE4PANEL_LIBS@						\
	@LIBXFCE4UI_LIBS@

check_PROGRAMS = commandline
commandline_SOURCES = commandline.c utils.c utils.h net.c net.h
commandline_CFLAGS = @LIBXFCE4PANEL_CFLAGS@
commandline_LDADD = @LIBXFCE4PANEL_LIBS@

# .desktop file
#
# Some automake trickery here. Because we cannot use $(libexecdir) in the
# automake stage, we'll use sed to get the full path into the .desktop file.
# We also need to let intltool merge the translated fields, so we add an
# additional level of indirection: a <name>.desktop.in.in file.
# 
desktop_in_in_files = speed.desktop.in.in
desktop_in_files = $(desktop_in_in_files:.desktop.in.in=.desktop.in)
	
desktopdir = $(datadir)/xfce4/panel/plugins
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST = 								\
	wormulon commandline.c						\
	$(desktop_in_in_files)

DISTCLEANFILES =							\
	$(desktop_DATA) $(desktop_in_files)
	
# get full path into .desktop file
%.desktop.in: %.desktop.in.in
	sed -e "s^@PLUGIN_PATH@^$(libexecdir)/xfce4/panel/plugins^" \
		$< > $@

