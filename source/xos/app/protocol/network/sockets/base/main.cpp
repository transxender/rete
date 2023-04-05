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
///   Date: 3/24/2023
//////////////////////////////////////////////////////////////////////////
#include "xos/app/protocol/network/sockets/base/main.hpp"
#include "xos/app/protocol/network/base/main.cpp"

#ifndef XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_INSTANCE
/// #define XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 
#else /// ndef XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 
#endif /// ndef XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 

namespace xos {
namespace app {
namespace protocol {
namespace network {
namespace sockets {
namespace base {

/// class 
#ifdef XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_INSTANCE
static main the_main;
#endif /// def XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_INSTANCE 

} /// namespace base 
} /// namespace sockets 
} /// namespace network 
} /// namespace protocol 
} /// namespace app 
} /// namespace xos 
