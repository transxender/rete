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
#   File: control.pri
#
# Author: $author$
#   Date: 12/1/2022
#
# generic QtCreator project .pri file for framework rete executable control
########################################################################

########################################################################
# control

# control TARGET
#
control_TARGET = control

# control INCLUDEPATH
#
control_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# control DEFINES
#
control_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# control OBJECTIVE_HEADERS
#
#control_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/console/control/main.hh \

# control OBJECTIVE_SOURCES
#
#control_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/console/control/main.mm \

########################################################################
# control HEADERS
#
control_HEADERS += \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/base/main.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/client/main.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/server/main.hpp \

# control SOURCES
#
control_SOURCES += \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/client/main_opt.cpp \
$${RETE_SRC}/xos/app/console/network/sockets/protocol/home/control/client/main.cpp \

########################################################################
# control FRAMEWORKS
#
control_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# control LIBS
#
control_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core

