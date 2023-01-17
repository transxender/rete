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
#   File: oppod.pri
#
# Author: $author$
#   Date: 10/22/2022
#
# generic QtCreator project .pri file for framework rete executable oppod
########################################################################

########################################################################
# oppod

# oppod TARGET
#
oppod_TARGET = oppod

# oppod INCLUDEPATH
#
oppod_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# oppod DEFINES
#
oppod_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# oppod OBJECTIVE_HEADERS
#
#oppod_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/console/oppod/main.hh \

# oppod OBJECTIVE_SOURCES
#
#oppod_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/console/oppod/main.mm \

########################################################################
# oppod HEADERS
#
oppod_HEADERS += \
$${RETE_SRC}/xos/network/sockets/interfaces.hpp \
$${RETE_SRC}/xos/network/sockets/os/interfaces.hpp \
\
$${RETE_SRC}/xos/app/console/network/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/base/main.hpp \
$${RETE_SRC}/xos/app/console/network/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/client/main.hpp \
$${RETE_SRC}/xos/app/console/network/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/server/main.hpp \
\
$${RETE_SRC}/xos/app/console/network/sockets/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/base/main.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/client/main.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/server/main.hpp \
\
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/base/main.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/client/main.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/server/main.hpp \

# oppod SOURCES
#
oppod_SOURCES += \
$${RETE_SRC}/xos/network/sockets/os/interfaces.cpp \
\
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/server/main_opt.cpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/telnet/server/main.cpp \

########################################################################
# oppod FRAMEWORKS
#
oppod_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# oppod LIBS
#
oppod_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core

