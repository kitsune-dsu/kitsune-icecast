
# EKIDEN
ifdef KITSUNE_PATH
KITSUNE_INCLUDE = -I $(KITSUNE_PATH)/include
KITSUNE_LIB = -L $(KITSUNE_PATH)/lib
KITSUNE_BIN = $(KITSUNE_PATH)/bin
else
KITSUNE_INCLUDE =
KITSUNE_LIB =
KITSUNE_BIN =
endif
CFLAGS = -ggdb3 -Wall -ldl -fPIC 
EKCC = $(KITSUNE_BIN)/ktcc --dostackvars --doglobalreg --automigrate --keepunused $(KITSUNE_INCLUDE) -include ktthreads.h

IFLAGS  = -idirafter dummyinc -I /usr/include/libxml2/ -I . -I .. -I /usr/local/include

# ICECAST CFLAGS
CFLAGS += -DHAVE_CONFIG_H -ffast-math -fsigned-char   

SRCS = httpp.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(OBJS)

.c.o:
	$(EKCC) $(CFLAGS) $(IFLAGS) -c $*.c --doktsavetypes --typesfile-out=$*.ktt

clean:
	rm -f *.o *.cil.c *.cil.i *.i *.ktt

