///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   Date: 9/13/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_HPP

#include "xos/app/console/network/sockets/server/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::server::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
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
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
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

    /// ...accept_run
    virtual int accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accept_restart = false;
        do {
            this->set_accept_done(false);
            if (!(err = this->all_accept(argc, argv, env))) {
                if (!(this->accept_one())) {
                    accept_restart = this->accept_restart();
                }
                this->set_accept_restart(false);
            }
        } while (accept_restart);
        return err;
    }

    ///
    /// ...accept
    /// ...
    /// ...accept(int argc, ...)
    virtual int accept(int argc, char_t** argv, char_t**env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->accept_host();
        const xos::network::sockets::sockport_t& port = this->accept_port();
        xos::network::sockets::endpoint& ep = this->accept_ep();
        xos::network::sockets::transport& tp = this->accept_tp();
        xos::network::sockets::interface &ac = this->accept_iface(), 
                                         &cn = this->connect_iface();
        xos::network::sockets::sockaddr_t& ad = this->connect_addr();
        xos::network::sockets::socklen_t& al = this->connect_addrlen();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")...");
        if ((ep.attach(host, port))) {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")");

            LOGGER_IS_LOGGED_INFO("ac.open(tp)...");
            if ((ac.open(tp))) {
                LOGGER_IS_LOGGED_INFO("...ac.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("ac.listen(ep)...");
                if ((ac.listen(ep))) {
                    LOGGER_IS_LOGGED_INFO("...ac.listen(ep)");
                    
                    do {
                        LOGGER_IS_LOGGED_INFO("ac.accept(cn, &ad, al)...");
                        if ((ac.accept(cn, &ad, al))) {
                            LOGGER_IS_LOGGED_INFO("...ac.accept(cn, &ad, al)");
                            
                            this->all_accept(cn, argc, argv, env);
                            LOGGER_IS_LOGGED_INFO("cn.close()...");
                            cn.close();
                        }
                    } while (!(this->accept_one() || this->accept_done() || this->accept_restart()));
                }
                LOGGER_IS_LOGGED_INFO("ac.close()...");
                ac.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }
    virtual int before_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_accept(argc, argv, env))) {
            int err2 = 0;
            err = accept(argc, argv, env);
            if ((err2 = after_accept(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...accept(xos::network::sockets::interface& cn, ...)
    virtual int accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_recv_request(cn, argc, argv, env))) {
            err = this->all_send_response(cn, argc, argv, env);
        }
        return err;
    }
    virtual int before_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_accept(cn, argc, argv, env))) {
            int err2 = 0;
            err = accept(cn, argc, argv, env);
            if ((err2 = after_accept(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...accept
    /// 

    /// ...ep
    xos::network::sockets::endpoint& (derives::*accept_ep_)() const;
    virtual xos::network::sockets::endpoint& accept_ep() const {
        if ((this->accept_ep_)) {
            return (this->*accept_ep_)();
        }
        return this->default_accept_ep();
    }
    virtual xos::network::sockets::endpoint& default_accept_ep() const {
        return this->accept_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& accept_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& accept_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*accept_tp_)() const;
    virtual xos::network::sockets::transport& accept_tp() const {
        if ((this->accept_tp_)) {
            return (this->*accept_tp_)();
        }
        return this->default_accept_tp();
    }
    virtual xos::network::sockets::transport& default_accept_tp() const {
        return this->accept_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& accept_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& accept_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...ep
    xos::network::sockets::endpoint& (derives::*relay_ep_)() const;
    virtual xos::network::sockets::endpoint& relay_ep() const {
        if ((this->relay_ep_)) {
            return (this->*relay_ep_)();
        }
        return this->default_relay_ep();
    }
    virtual xos::network::sockets::endpoint& default_relay_ep() const {
        return this->relay_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& relay_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& relay_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*relay_tp_)() const;
    virtual xos::network::sockets::transport& relay_tp() const {
        if ((this->relay_tp_)) {
            return (this->*relay_tp_)();
        }
        return this->default_relay_tp();
    }
    virtual xos::network::sockets::transport& default_relay_tp() const {
        return this->relay_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& relay_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& relay_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

protected:
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_HPP
