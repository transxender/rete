########################################################################
# Copyright (c) 1988-2023 $organization$
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
#   File: main.pri
#
# Author: $author$
#   Date: 3/21/2023
#
# generic QtCreator project file for nuasteraede framework rete executable main
########################################################################

########################################################################
# main

# main TARGET
#
main_TARGET = main

# main INCLUDEPATH
#
main_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# main DEFINES
#
main_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# main OBJECTIVE_HEADERS
#
#main_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/rete/main.hh \

# main OBJECTIVE_SOURCES
#
#main_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/rete/main.mm \

########################################################################
# main HEADERS
#
main_HEADERS += \
\
$${NADIR_SRC}/xos/app/nadir/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/nadir/base/main.hpp \
$${NADIR_SRC}/xos/app/nadir/client/main_opt.hpp \
$${NADIR_SRC}/xos/app/nadir/client/main.hpp \
$${NADIR_SRC}/xos/app/nadir/main_opt.hpp \
$${NADIR_SRC}/xos/app/nadir/main.hpp \
\
$${RETE_SRC}/xos/app/console/framework/version/main_opt.hpp \
$${RETE_SRC}/xos/app/console/framework/version/main.hpp \
\
$${RETE_SRC}/xos/app/protocol/network/base/main.hpp \
$${RETE_SRC}/xos/app/protocol/network/client/main.hpp \
\
$${RETE_SRC}/xos/app/protocol/network/sockets/base/main.hpp \
$${RETE_SRC}/xos/app/protocol/network/sockets/client/main.hpp \
\
$${RETE_SRC}/xos/app/rete/base/main_opt.hpp \
$${RETE_SRC}/xos/app/rete/base/main.hpp \
$${RETE_SRC}/xos/app/rete/client/main_opt.hpp \
$${RETE_SRC}/xos/app/rete/client/main.hpp \
$${RETE_SRC}/xos/app/rete/main_opt.hpp \
$${RETE_SRC}/xos/app/rete/main.hpp \

# main SOURCES
#
main_SOURCES += \
$${RETE_SRC}/xos/app/rete/client/main_opt.cpp \
$${RETE_SRC}/xos/app/rete/client/main.cpp \

########################################################################
# main FRAMEWORKS
#
main_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# main LIBS
#
main_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core
