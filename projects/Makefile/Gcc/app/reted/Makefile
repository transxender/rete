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
# generic Makefile for framework rete executable reted
########################################################################
# Depends: rostra;nadir;fila;crono

#
# target
#
reted_EXETARGET = reted

########################################################################

#
# user c++ flags
#
reted_USRCXXFLAGS += \
${rete_USRCXXFLAGS} \

#
# user defines
#
reted_USRDEFINES += \
${rete_USRDEFINES} \
-DDEFAULT_LOGGING_LEVELS_ERROR \
-DXOS_CONSOLE_MAIN_MAIN \


#
# user includes
#
reted_USRINCLUDES += \
${rete_USRINCLUDES} \

#
# user libdirs
#
reted_USRLIBDIRS += \
${rete_USRLIBDIRS} \

########################################################################

#
# executable .c sources
#
#reted_EXE_C_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.c \

#
# executable .cc sources
#
#reted_EXE_CC_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.cc \

#
# executable .cxx sources
#
#reted_EXE_CXX_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.cxx \

#
# executable .cpp sources
#
reted_EXE_CPP_SOURCES += \
${RETE_SRC}/xos/network/sockets/os/interfaces.cpp \
\
${RETE_SRC}/xos/app/console/network/sockets/server/main_opt.cpp \
${RETE_SRC}/xos/app/console/network/sockets/server/main.cpp \

#
# executable .m sources
#
#reted_EXE_M_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.m \

#
# executable .mm sources
#
#reted_EXE_MM_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.mm \


########################################################################

#
# executable libraries
#
reted_LIBS += \
${rete_LIBS}

