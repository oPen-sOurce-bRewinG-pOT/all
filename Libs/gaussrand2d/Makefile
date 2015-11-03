INSTALL_DIR=/usr/local/lib/
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
TARGETLIB= libgaussrand2d.$(LIBEXT)


lib_gauss_rand_2d_objects = src/gauss_fn.o


all: build/$(TARGETLIB)

build:
	mkdir build

build/$(TARGETLIB): $(lib_gauss_rand_2d_objects) build
	$(CC) $(LINKOPTIONS) -o $@ \
	 $(EDLDFLAGS)\
	 $(lib_gauss_rand_2d_objects) -lm -lfftw3

%.o: %.c
	$(CC) -O3 -fPIC -Wall -c $< -o $@ -I src/ -I include/


install: build/$(TARGETLIB)
	cp $< $(INSTALL_DIR)$(TARGETLIB)


# INSTALL THE PYTHON WRAPPER
pywrapper:
	(ls $(INSTALL_DIR)$(TARGETLIB) || ($(ECHO) "Cannot find library '$(INSTALL_DIR)$(TARGETLIB)', run again with 'INSTALL_DIR=' set to the directory you installed the library in" && exit -1))
	(ls py/gauss_rand_2d/.gauss_rand_2d.py || mv py/gauss_rand_2d/gauss_rand_2d.py py/gauss_rand_2d/.gauss_rand_2d.py)
	sed "s#TEMPLATE_LIBRARY_PATH#'$(INSTALL_DIR)'#g" py/gauss_rand_2d_TEMPLATE.py > py/gauss_rand_2d/gauss_rand_2d.py
	((cd py/gauss_rand_2d && $(ECHO) 'import gauss_rand_2d' | $(PYTHON)) && $(ECHO) 'Successfully installed Python wrapper' || ($(ECHO) 'Something went wrong installing Python wrapper' && exit -1))
	(cd py && $(PYTHON) setup.py install)


#
# TEST THE INSTALLATION
#

testpy:
	(cd py/gauss_rand_2d && $(PYTHON) gauss_rand_2d.py)


.PHONY: clean spotless

clean:
	$(RM) $(lib_gauss_rand_2d_objects)

spotless: clean rmbuild
	$(RM) src/*.o
	$(RM) py/*.pyc
	$(RM) py/gauss_rand_2d/*.pyc
	(ls py/gauss_rand_2d/.gauss_rand_2d.py && mv py/gauss_rand_2d/.gauss_rand_2d.py py/gauss_rand_2d/gauss_rand_2d.py || $(TRUE))

rmbuild: build/
	$(RM) build/$(TARGETLIB)
	($(RMDIR) -R build || $(ECHO) "Could not remove 'build/' directory, manually remove it")
