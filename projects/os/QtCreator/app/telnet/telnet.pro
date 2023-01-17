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
#   File: telnet.pro
#
# Author: $author$
#   Date: 10/24/2022
#
# os specific QtCreator project .pro file for framework rete executable telnet
########################################################################
#
# Debug: rete/build/os/QtCreator/Debug/bin/telnet
# Release: rete/build/os/QtCreator/Release/bin/telnet
# Profile: rete/build/os/QtCreator/Profile/bin/telnet
#
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/telnet/telnet.pri)

TARGET = $${telnet_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${telnet_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${telnet_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${telnet_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${telnet_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${telnet_HEADERS} \
$${telnet_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${telnet_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${telnet_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${telnet_LIBS} \
$${FRAMEWORKS} \

########################################################################

