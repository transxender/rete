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
# generic Makefile for framework rete executable rete
########################################################################
# Depends: rostra;nadir;fila;crono

#
# target
#
rete_exe_EXETARGET = rete

########################################################################

#
# user c++ flags
#
rete_exe_USRCXXFLAGS += \
${rete_USRCXXFLAGS} \

#
# user defines
#
rete_exe_USRDEFINES += \
${rete_USRDEFINES} \
-DDEFAULT_LOGGING_LEVELS_ERROR \
-DXOS_CONSOLE_MAIN_MAIN \


#
# user includes
#
rete_exe_USRINCLUDES += \
${rete_USRINCLUDES} \

#
# user libdirs
#
rete_exe_USRLIBDIRS += \
${rete_USRLIBDIRS} \

########################################################################

#
# executable .c sources
#
#rete_exe_EXE_C_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.c \

#
# executable .cc sources
#
#rete_exe_EXE_CC_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.cc \

#
# executable .cxx sources
#
#rete_exe_EXE_CXX_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.cxx \

#
# executable .cpp sources
#
rete_exe_EXE_CPP_SOURCES += \
${RETE_SRC}/xos/network/sockets/os/interfaces.cpp \
\
${RETE_SRC}/xos/app/console/network/sockets/main_opt.cpp \
${RETE_SRC}/xos/app/console/network/sockets/main.cpp \

#
# executable .m sources
#
#rete_exe_EXE_M_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.m \

#
# executable .mm sources
#
#rete_exe_EXE_MM_SOURCES += \
#${RETE_SRC}/xos/app/console/rete/main.mm \


########################################################################

#
# executable libraries
#
rete_exe_LIBS += \
${rete_LIBS}

