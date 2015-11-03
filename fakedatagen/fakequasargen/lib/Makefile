CC = gcc
CFLAGSLIB = -Wall -Wmissing-prototypes -O3 -std=c99 -fPIC -I./include
OBJS = .lib/check32.o .lib/prescr.o .lib/mt19937.o .lib/eqdeg.o .lib/seive.o .lib/genmtrand.o .lib/init.o

lib : $(OBJS)
	ar -crus libdcmt.a $(OBJS)

init.o : dci.h init.c
	$(CC) $(CFLAGSLIB) -c ./lib/init.c

check32.o : dci.h check32.c
	$(CC) $(CFLAGSLIB) -c ./lib/check32.c

prescr.o : dci.h prescr.c
	$(CC) $(CFLAGSLIB) -c ./lib/prescr.c

mt19937.o : mt19937.c
	$(CC) $(CFLAGSLIB) -c ./lib/mt19937.c

eqdeg.o : dci.h eqdeg.c
	$(CC) $(CFLAGSLIB) -c ./lib/eqdeg.c

seive.o : dci.h seive.c
	$(CC) $(CFLAGSLIB) -c ./lib/seive.c

genmtrand.o : dci.h genmtrand.c
	$(CC) $(CFLAGSLIB) -c ./lib/genmtrand.c

clean :
	/bin/rm -f ./lib/*.o ./lib/libdcmt.a

oclean :
	/bin/rm -f ./lib/*.o

