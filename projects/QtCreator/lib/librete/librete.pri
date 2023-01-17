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
#   File: librete.pri
#
# Author: $author$
#   Date: 9/3/2022
#
# generic QtCreator project .pri file for framework rete static library librete
########################################################################

########################################################################
# librete
XOS_LIB_RETE_VERSION_BUILD_DATE = 9/3/2022 #$$system(~/bin/utility/tdate)

# librete TARGET
#
librete_TARGET = rete
librete_TEMPLATE = lib
librete_CONFIG += staticlib

# librete INCLUDEPATH
#
librete_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# librete DEFINES
#
librete_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_RETE_VERSION_BUILD_DATE=$${XOS_LIB_RETE_VERSION_BUILD_DATE} \

########################################################################
# librete OBJECTIVE_HEADERS
#
#librete_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/lib/rete/version.hh \

# librete OBJECTIVE_SOURCES
#
#librete_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/lib/rete/version.mm \

########################################################################
# librete HEADERS
#
librete_HEADERS += \
$${RETE_SRC}/xos/lib/rete/version.hpp \

# librete SOURCES
#
librete_SOURCES += \
$${RETE_SRC}/xos/lib/rete/version.cpp \

########################################################################

