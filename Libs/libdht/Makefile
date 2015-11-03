144INSTALL_DIR=/usr/local/lib/
RM= /bin/rm -vf
CC=gcc
PYTHON=python
ARCH=UNDEFINED
PWD=pwd
CDR=$(shell pwd)

EDCFLAGS:= $(CFLAGS)
EDLDFLAGS:= $(LDFLAGS)

ifeq ($(ARCH),UNDEFINED)
	ARCH=$(shell uname -m)
endif

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	LIBEXT= dylib
	EDCFLAGS:= -arch $(ARCH) $(EDCFLAGS)
	EDLDFLAGS:= -arch $(ARCH) $(EDLDFLAGS)
	LINKOPTIONS:= -dynamiclib -W1 -single_module
	RMDIR=rmdir
	ECHO=echo
	TRUE=TRUE
else
	LIBEXT= so
	LINKOPTIONS:= -shared
	RMDIR=rmdir -v
	ECHO=/bin/echo -e
	TRUE=true
endif
TARGETLIB= libdht.$(LIBEXT)


lib_dht_objects = src/dht.o


all: build/$(TARGETLIB)

build:
	mkdir build

build/$(TARGETLIB): $(lib_dht_objects) build
	$(CC) $(LINKOPTIONS) -o $@ \
	 $(EDLDFLAGS)\
	 -L/usr/lib -L/usr/local/lib \
	 $(lib_dht_objects) -lm -lgsl

%.o: %.c
	$(CC) -O3 -fPIC -Wall -c $< -o $@ -I src/ -I include/


install: build/$(TARGETLIB)
	cp $< $(INSTALL_DIR)$(TARGETLIB)


# INSTALL THE PYTHON WRAPPER
pywrapper:
	(ls $(INSTALL_DIR)$(TARGETLIB) || ($(ECHO) "Cannot find library '$(INSTALL_DIR)$(TARGETLIB)', run again with 'INSTALL_DIR=' set to the directory you installed the library in" && exit -1))
	(ls py/d_hankel_t/.d_hankel_t.py || mv py/d_hankel_t/d_hankel_t.py py/d_hankel_t/.d_hankel_t.py)
	sed "s#TEMPLATE_LIBRARY_PATH#'$(INSTALL_DIR)'#g" py/d_hankel_t_TEMPLATE.py > py/d_hankel_t/d_hankel_t.py
	((cd py/d_hankel_t && $(ECHO) 'import d_hankel_t' | $(PYTHON)) && $(ECHO) 'Successfully installed Python wrapper' || ($(ECHO) 'Something went wrong installing Python wrapper' && exit -1))
	(cd py && $(PYTHON) setup.py install)


#
# TEST THE INSTALLATION
#

testpy:
	(cd py/d_hankel_t && $(PYTHON) d_hankel_t.py)


.PHONY: clean spotless

clean:
	$(RM) $(lib_d_hankel_t_objects)

spotless: clean rmbuild
	$(RM) src/*.o
	$(RM) py/*.pyc
	$(RM) py/d_hankel_t/*.pyc
	(ls py/d_hankel_t/.d_hankel_t.py && mv py/d_hankel_t/.d_hankel_t.py py/d_hankel_t/d_hankel_t.py || $(TRUE))

rmbuild: build/
	$(RM) build/$(TARGETLIB)
	($(RMDIR) -R build || $(ECHO) "Could not remove 'build/' directory, manually remove it")
