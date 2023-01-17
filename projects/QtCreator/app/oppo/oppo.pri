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
#   File: oppo.pri
#
# Author: $author$
#   Date: 10/22/2022
#
# generic QtCreator project .pri file for framework rete executable oppo
########################################################################

########################################################################
# oppo

# oppo TARGET
#
oppo_TARGET = oppo

# oppo INCLUDEPATH
#
oppo_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# oppo DEFINES
#
oppo_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# oppo OBJECTIVE_HEADERS
#
#oppo_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/console/oppo/main.hh \

# oppo OBJECTIVE_SOURCES
#
#oppo_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/console/oppo/main.mm \

########################################################################
# oppo HEADERS
#
oppo_HEADERS += \
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
\
$${RETE_SRC}/xos/app/console/home/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/home/player/main_opt.hpp \
\
$${RETE_SRC}/xos/app/console/home/theater/oppo/player/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/home/theater/oppo/player/base/main.hpp \
$${RETE_SRC}/xos/app/console/home/theater/oppo/player/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/home/theater/oppo/player/client/main.hpp \

# oppo SOURCES
#
oppo_SOURCES += \
$${RETE_SRC}/xos/network/sockets/os/interfaces.cpp \
\
$${RETE_SRC}/xos/app/console/home/theater/oppo/player/client/main_opt.cpp \
$${RETE_SRC}/xos/app/console/home/theater/oppo/player/client/main.cpp \

########################################################################
# oppo FRAMEWORKS
#
oppo_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# oppo LIBS
#
oppo_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core

