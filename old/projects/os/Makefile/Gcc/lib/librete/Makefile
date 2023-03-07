########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 10/15/2022
#
# os specific Makefile for framework rete library librete
########################################################################
# Depends: rostra;nadir;fila;crono

PKG = ../../../../../..

BMK = build/Makefile/Gcc
MAK = projects/Makefile/Gcc
PRJ = projects/os/Makefile/Gcc
SRC = source

include $(PKG)/$(BMK)/Makedefines
include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(BMK)/Makefile
include $(PKG)/$(MAK)/lib/librete/Makefile

#
# target
#
LIBTARGET = ${librete_LIBTARGET}

########################################################################

#
# user defines
#
USRDEFINES += \
${librete_USRDEFINES}

#
# user includes
#
USRINCLUDES += \
${librete_USRINCLUDES}

#
# user libdirs
#
USRLIBDIRS += \
${librete_USRLIBDIRS}

#
# user c++ flags
#
USRCXXFLAGS += \
${librete_USRCXXFLAGS}

#
# user c flags
#
USRCFLAGS += \
${librete_USRCFLAGS}

#
# user ld flags
#
USRLDFLAGS += \
${librete_USRLDFLAGS}

########################################################################

#
# library C sources
#
LIB_C_SOURCES += \
${librete_LIB_C_SOURCES}

#
# library C++ .cc sources
#
LIB_CC_SOURCES += \
${librete_LIB_CC_SOURCES}

#
# library C++ .cxx sources
#
LIB_CXX_SOURCES += \
${librete_LIB_CXX_SOURCES}

#
# library C++ .cpp sources
#
LIB_CPP_SOURCES += \
${librete_LIB_CPP_SOURCES}

#
# library Objective C .m sources
#
LIB_M_SOURCES += \
${librete_LIB_M_SOURCES}

#
# library Objective C++ .mm sources
#
LIB_MM_SOURCES += \
${librete_LIB_MM_SOURCES}

########################################################################

#
# library depends
#
#LIBDEP += \
#$(PKG)/$(BLD)/libsomelib \
#
LIBDEP += \

#
# library depend dirs
#
#LIBDEP_DIRS += \
#../libsomelib
#
LIBDEP_DIRS += \

include $(PKG)/$(MAK)/Makerules

#
# library depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#
