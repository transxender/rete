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
#   File: kasa.pro
#
# Author: $author$
#   Date: 11/22/2022
#
# os specific QtCreator project .pro file for framework rete executable kasa
########################################################################
#
# Debug: rete/build/os/QtCreator/Debug/bin/kasa
# Release: rete/build/os/QtCreator/Release/bin/kasa
# Profile: rete/build/os/QtCreator/Profile/bin/kasa
#
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/kasa/kasa.pri)

TARGET = $${kasa_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${kasa_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${kasa_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${kasa_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${kasa_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${kasa_HEADERS} \
$${kasa_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${kasa_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${kasa_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${kasa_LIBS} \
$${FRAMEWORKS} \

########################################################################

