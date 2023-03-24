//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.cpp
///
/// Author: $author$
///   Date: 1/15/2023
//////////////////////////////////////////////////////////////////////////
#include "xos/app/console/network/universal/unique/identifier/main.hpp"

#ifdef XOS_CONSOLE_MAIN_MAIN
#include "xos/console/main_main.cpp"
#ifndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE
#else /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE 
#endif /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE 
#else /// def XOS_CONSOLE_MAIN_MAIN 
#endif /// def XOS_CONSOLE_MAIN_MAIN 

#ifndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE
/// #define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE 
#else /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE 
#endif /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE 

namespace xos {
namespace app {
namespace console {
namespace network {
namespace universal {
namespace unique {
namespace identifier {

/// class 
#ifdef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE
static main the_main;
#endif /// def XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_INSTANCE 

} /// namespace identifier 
} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 
