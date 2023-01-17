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
# generic Makefile for framework rete library librete
########################################################################
# Depends: rostra;nadir;fila;crono

#
# target
#
librete_LIBTARGET = librete.${LIBEXT}

########################################################################

#
# user c++ flags
#
librete_USRCXXFLAGS += \
${rete_USRCXXFLAGS} \

#
# user defines
#
librete_USRDEFINES += \
${rete_USRDEFINES} \
-DDEFAULT_LOGGING_LEVELS_ERROR \
-DXOS_LIB_RETE_VERSION_BUILD_DATE=10/15/2022 #${shell tdate} \


#
# user includes
#
librete_USRINCLUDES += \
${rete_USRINCLUDES} \

#
# user libdirs
#
librete_USRLIBDIRS += \
${rete_USRLIBDIRS} \

########################################################################

#
# library .c sources
#
#librete_LIB_C_SOURCES += \
#${RETE_SRC}/xos/lib/rete/version.c \

#
# library .cc sources
#
#librete_LIB_CC_SOURCES += \
#${RETE_SRC}/xos/lib/rete/version.cc \

#
# library .cxx sources
#
#librete_LIB_CXX_SOURCES += \
#${RETE_SRC}/xos/lib/rete/version.cxx \

#
# library .cpp sources
#
librete_LIB_CPP_SOURCES += \
${RETE_SRC}/xos/lib/rete/version.cpp \

#
# library .m sources
#
#librete_LIB_M_SOURCES += \
#${RETE_SRC}/xos/lib/rete/version.m \

#
# library .mm sources
#
#librete_LIB_MM_SOURCES += \
#${RETE_SRC}/xos/lib/rete/version.mm \


########################################################################


