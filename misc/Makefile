SSOBJ=ss.o ssfilter.o
LNSTATOBJ=lnstat.o lnstat_util.o

TARGETS=ss nstat ifstat rtacct arpd lnstat

include ../Config

all: $(TARGETS)

ss: $(SSOBJ)

nstat: nstat.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o nstat nstat.c -lm

ifstat: ifstat.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o ifstat ifstat.c $(LIBNETLINK) -lm

rtacct: rtacct.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o rtacct rtacct.c $(LIBNETLINK) -lm

# Don't bother with this when cross-compiling...DBM_INCLUDE goes poking
# in host includes most likely...which causes all sorts of problems.
ifeq ($(CC),gcc)
arpd: arpd.c
	$(CC) $(CFLAGS) -I$(DBM_INCLUDE) $(LDFLAGS) -o arpd arpd.c $(LIBNETLINK) -ldb -lpthread
else
arpd:
	echo "Not building ardp when cross-compiling."
	true
endif

ssfilter.c: ssfilter.y
	bison ssfilter.y -o ssfilter.c

lnstat: $(LNSTATOBJ)

install: all
	install -m 0755 $(TARGETS) $(DESTDIR)$(SBINDIR)
	ln -sf lnstat $(DESTDIR)$(SBINDIR)/rtstat
	ln -sf lnstat $(DESTDIR)$(SBINDIR)/ctstat

clean:
	rm -f *.o $(TARGETS) ssfilter.c
