CC = icc
CFLAGS = -Wall -Wmissing-prototypes -O3 -std=c99 -fPIC -I./include
DFLAGS = -O3 -I./include -L./lib
OBJS = ./lib/check32.o ./lib/prescr.o ./lib/mt19937.o ./lib/eqdeg.o ./lib/seive.o ./lib/genmtrand.o ./lib/init.o

all : lib generator

lib : $(OBJS)
	ar -crus ./lib/libdcmt.a $(OBJS)

init.o : /lib/dci.h /lib/init.c
	$(CC) $(CFLAGS) -c ./lib/init.c

check32.o : /lib/dci.h /lib/check32.c
	$(CC) $(CFLAGS) -c ./lib/check32.c

prescr.o : /lib/dci.h /lib/prescr.c
	$(CC) $(CFLAGS) -c ./lib/prescr.c

mt19937.o : /lib/mt19937.c
	$(CC) $(CFLAGS) -c ./lib/mt19937.c

eqdeg.o : /lib/dci.h /lib/eqdeg.c
	$(CC) $(CFLAGS) -c ./lib/eqdeg.c

seive.o : /lib/dci.h /lib/seive.c
	$(CC) $(CFLAGS) -c ./lib/seive.c

genmtrand.o : /lib/dci.h /lib/genmtrand.c
	$(CC) $(CFLAGS) -c ./lib/genmtrand.c
	
generator :  ./src/generator.c ./src/param.h ./src/functions.h ./include/dc.h ./lib/libdcmt.a
	$(CC) $(DFLAGS) -o generator ./src/generator.c -openmp -ldcmt -lm
	

	


clean :
	/bin/rm -f ./lib/*.o ./lib/libdcmt.a generator

oclean :
	/bin/rm -f ./lib/*.o

