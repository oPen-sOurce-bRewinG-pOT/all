CC = gcc
CFLAGSLIB = -Wall -Wmissing-prototypes -O3 -std=c99 -fPIC -I./include
CFLAGS = -O3 -I./include -L./
OBJS = ./lib/check32.o ./lib/prescr.o ./lib/mt19937.o ./lib/eqdeg.o ./lib/seive.o ./lib/genmtrand.o ./lib/init.o

all : lib generator

lib : $(OBJS)
	ar -crus libdcmt.a $(OBJS)

init.o : /lib/dci.h /lib/init.c
	$(CC) $(CFLAGSLIB) -c ./lib/init.c

check32.o : /lib/dci.h /lib/check32.c
	$(CC) $(CFLAGSLIB) -c ./lib/check32.c

prescr.o : /lib/dci.h /lib/prescr.c
	$(CC) $(CFLAGSLIB) -c ./lib/prescr.c

mt19937.o : /lib/mt19937.c
	$(CC) $(CFLAGSLIB) -c ./lib/mt19937.c

eqdeg.o : /lib/dci.h /lib/eqdeg.c
	$(CC) $(CFLAGSLIB) -c ./lib/eqdeg.c

seive.o : /lib/dci.h /lib/seive.c
	$(CC) $(CFLAGSLIB) -c ./lib/seive.c

genmtrand.o : /lib/dci.h /lib/genmtrand.c
	$(CC) $(CFLAGSLIB) -c ./lib/genmtrand.c
	
generator :  ./src/generator.c ./src/param.h ./src/functions.h ./include/dc.h ./libdcmt.a
	$(CC) $(CFLAGS) -o generator ./src/generator.c -fopenmp -ldcmt -lm
	

	


clean :
	/bin/rm -f ./lib/*.o ./libdcmt.a generator

oclean :
	/bin/rm -f ./lib/*.o

