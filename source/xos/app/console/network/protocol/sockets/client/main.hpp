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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/9/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_HPP

#include "xos/app/console/network/protocol/sockets/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace sockets {
namespace client {

//// class maint
template 
<class TExtends = xos::app::console::network::protocol::sockets::client::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    virtual int connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->connect_host();
        const xos::network::sockets::sockport_t& port = this->connect_port();
        xos::network::sockets::endpoint& ep = this->connect_ep();
        xos::network::sockets::transport& tp = this->connect_tp();
        xos::network::sockets::interface &cn = this->connect_iface();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        if (!(ep.attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...failed on ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        } else {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")");

            LOGGER_IS_LOGGED_INFO("cn.open(tp)...");
            if (!(cn.open(tp))) {
                LOGGER_IS_LOGGED_ERROR("...failed on ");
            } else {
                LOGGER_IS_LOGGED_INFO("...cn.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("cn.connect(ep)...");
                if (!(cn.connect(ep))) {
                    LOGGER_IS_LOGGED_ERROR("...failed on ");
                } else {
                    LOGGER_IS_LOGGED_INFO("...cn.connect(ep)");
                    
                    if (!(err = this->all_connect_run(cn, argc, argv, env))) {
                    }
                }
                LOGGER_IS_LOGGED_INFO("cn.close()...");
                cn.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }

    /// ...ep
    xos::network::sockets::endpoint& (derives::*connect_ep_)() const;
    virtual xos::network::sockets::endpoint& connect_ep() const {
        if ((this->connect_ep_)) {
            return (this->*connect_ep_)();
        }
        return this->default_connect_ep();
    }
    virtual xos::network::sockets::endpoint& default_connect_ep() const {
        return this->connect_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& connect_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& connect_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*connect_tp_)() const;
    virtual xos::network::sockets::transport& connect_tp() const {
        if ((this->connect_tp_)) {
            return (this->*connect_tp_)();
        }
        return this->default_connect_tp();
    }
    virtual xos::network::sockets::transport& default_connect_tp() const {
        return this->connect_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& connect_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& connect_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

protected:
}; /// class maint 
typedef maint<> main;

} /// namespace client 
} /// namespace sockets 
} /// namespace protocol 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_HPP
