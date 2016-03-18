# Sample makefile for programs that use the ROSE library.
#
# ROSE has a number of configuration details that must be present when
# compiling and linking a user program with ROSE, and some of these
# details are difficult to get right.  The most foolproof way to get
# these details into your own makefile is to use the "rose-config"
# tool.
#
#
# This makefile assumes:
#   1. The ROSE library has been properly installed (refer to the
#      documentation for configuring, building, and installing ROSE).
#
#   2. The top of the installation directory is $(ROSE_HOME). This
#      is the same directory you specified for the "--prefix" argument
#      of the "configure" script, or the "CMAKE_INSTALL_PREFIX" if using
#      cmake. E.g., "/usr/local".
#
# The "rose-config" tool currently only works for ROSE configured with
# GNU auto tools (e.g., you ran "configure" when you built and
# installed ROSE). The "cmake" configuration is not currently
# supported by "rose-config" [September 2015].
##############################################################################

# Standard C++ compiler stuff (see rose-config --help)
CXX      = $(shell $(ROSE_HOME)/bin/rose-config cxx)
CPPFLAGS = $(shell $(ROSE_HOME)/bin/rose-config cppflags)
CFLAGS   = $(shell $(ROSE_HOME)/bin/rose-config cflags)
LDFLAGS  = $(shell $(ROSE_HOME)/bin/rose-config ldflags)
LIBDIRS  = $(shell $(ROSE_HOME)/bin/rose-config libdirs)


##############################################################################

all: BuildIntValTest

check: BuildIntValTest
	LD_LIBRARY_PATH=$(LIBDIRS) ./BuildIntValTest $(TEST_ARG)

.PHONY: clean
clean:
	rm -f BuildIntValTest

