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
#   File: reted.pri
#
# Author: $author$
#   Date: 3/24/2023
#
# generic QtCreator project file for nuasteraede framework rete executable reted
########################################################################

########################################################################
# reted

# reted TARGET
#
reted_TARGET = reted

# reted INCLUDEPATH
#
reted_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# reted DEFINES
#
reted_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# reted OBJECTIVE_HEADERS
#
#reted_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/console/reted/main.hh \

# reted OBJECTIVE_SOURCES
#
#reted_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/console/reted/main.mm \

########################################################################
# reted HEADERS
#
reted_HEADERS += \
$${NADIR_SRC}/xos/app/console/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/base/main.hpp \
\
$${NADIR_SRC}/xos/app/console/protocol/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/base/main.hpp \
$${NADIR_SRC}/xos/app/console/protocol/server/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/protocol/server/main.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/network/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/network/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/network/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/network/server/main.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/network/sockets/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/network/sockets/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/network/sockets/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/network/sockets/server/main.hpp \
\
$${RETE_SRC}/xos/app/console/framework/version/main_opt.hpp \
$${RETE_SRC}/xos/app/console/framework/version/main.hpp \
$${RETE_SRC}/xos/app/console/rete/version/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/version/main.hpp \
$${RETE_SRC}/xos/app/console/rete/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/main.hpp \

# reted SOURCES
#
reted_SOURCES += \
$${RETE_SRC}/xos/app/console/protocol/network/sockets/server/main_opt.cpp \
$${RETE_SRC}/xos/app/console/protocol/network/sockets/server/main.cpp \

########################################################################
# reted FRAMEWORKS
#
reted_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# reted LIBS
#
reted_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core
