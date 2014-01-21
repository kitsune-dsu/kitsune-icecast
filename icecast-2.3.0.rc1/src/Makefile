
LASTVERSION=2.2.0
VERSION=2.3.0.rc1

# Kitsune
ifdef KITSUNE_PATH
KITSUNE_INCLUDE = -I $(KITSUNE_PATH)/include
KITSUNE_LIB = -L $(KITSUNE_PATH)/lib
KITSUNE_BIN = $(KITSUNE_PATH)/bin
else
KITSUNE_INCLUDE =
KITSUNE_LIB =
KITSUNE_BIN =
endif
KTLIB  = $(KITSUNE_LIB) -lkitsune-threads
CFLAGS_SHARED  = -ggdb3 -Wall -ldl -shared -fPIC -u kitsune_init_inplace $(KITSUNE_INCLUDE)
CFLAGS = -ggdb3 -Wall -ldl -fPIC $(KITSUNE_INCLUDE) $(KTLIB)
EKDRV = $(KITSUNE_BIN)/driver
EKCC = $(KITSUNE_BIN)/ktcc --dostackvars --doglobalreg --automigrate --keepunused -include config.h -include compat.h -include ktthreads.h
EKJOIN = $(KITSUNE_BIN)/kttjoin
EKGEN = $(KITSUNE_BIN)/xfgen

APP=icecast
USER_XFORM=$(APP).xf
GENERATED_XFORM=dsu.c

LIBS = -pthread -lvorbis -logg -lxml2 -lxslt

IFLAGS  = -idirafter dummyinc -I /usr/include/libxml2/ -I . -I /usr/local/include

# ICECAST CFLAGS
CFLAGS += -DHAVE_CONFIG_H -ffast-math -fsigned-char   

SRCS = admin.c auth.c auth_htpasswd.c cfgfile.c client.c connection.c	\
event.c format.c format_flac.c format_midi.c format_mp3.c				\
format_ogg.c format_vorbis.c fserve.c global.c logging.c main.c md5.c	\
refbuf.c sighandler.c slave.c source.c stats.c util.c xslt.c			\
avl/avl.c httpp/httpp.c log/log.c net/resolver.c net/sock.c thread/thread.c	\
timing/timing.c

all: $(APP).so

OBJS = $(patsubst %.c,%.o,$(SRCS))

.PHONEY: subdirs
subdirs:
	$(MAKE) -C avl 
	$(MAKE) -C httpp 
	$(MAKE) -C log 
	$(MAKE) -C net 
	$(MAKE) -C thread
	$(MAKE) -C timing

.c.o:
	$(EKCC) $(CFLAGS) $(IFLAGS) -c $*.c --doktsavetypes --typesfile-out=$*.ktt

$(APP)-$(VERSION).ktt: $(OBJS) subdirs
	$(EKJOIN) $@ $(patsubst %.o,%.ktt,$(OBJS))

$(GENERATED_XFORM): $(APP)-$(VERSION).ktt $(USER_XFORM)
	$(EKGEN) $@ ../../$(APP)-$(LASTVERSION)/src/$(APP)-$(LASTVERSION).ktt $(APP)-$(VERSION).ktt $(USER_XFORM)

$(APP).so: $(OBJS) $(GENERATED_XFORM) subdirs
	$(CC) $(CFLAGS_SHARED) -ggdb3 -o $(APP).so $(OBJS) $(GENERATED_XFORM) $(EKINC) $(KTLIB) $(LINK) $(LIBS)
	cp $(APP).so $(APP)-2.so 

clean:
	rm -f *.o *.swp *.so *.cil.c *.cil.i *.i *.ktt dsu.c
	$(MAKE) clean -C avl 
	$(MAKE) clean -C httpp 
	$(MAKE) clean -C log 
	$(MAKE) clean -C net 
	$(MAKE) clean -C thread
	$(MAKE) clean -C timing
