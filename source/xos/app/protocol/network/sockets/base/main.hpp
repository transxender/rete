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
///   Date: 3/24/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HPP
#define XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HPP

#include "xos/app/protocol/network/base/main.hpp"

#include "xos/network/sockets/os/interfaces.hpp"
#include "xos/network/sockets/os/interface.hpp"
#include "xos/network/sockets/interface.hpp"
#include "xos/network/sockets/reader.hpp"
#include "xos/network/sockets/writer.hpp"

#include "xos/network/sockets/ip/v4/endpoint.hpp"
#include "xos/network/sockets/ip/v4/tcp/transport.hpp"
#include "xos/network/sockets/ip/v4/udp/transport.hpp"

#if !defined(WINSOCK_1)
#include "xos/network/sockets/ip/v6/endpoint.hpp"
#include "xos/network/sockets/ip/v6/tcp/transport.hpp"
#include "xos/network/sockets/ip/v6/udp/transport.hpp"
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_ACCEPT_PORT

namespace xos {
namespace app {
namespace protocol {
namespace network {
namespace sockets {
namespace base {

/// class maint
template 
<class TExtends = xos::app::protocol::network::base::maint<>,  class TImplements = typename TExtends::implements>

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
    maint()
    : run_(0), 
      
      accept_host_(XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_CONNECT_HOST), 
      relay_host_(XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_RELAY_HOST),

      accept_port_(XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_CONNECT_PORT), 
      relay_port_(XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_RELAY_PORT) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }
public:

    /// ...host_option...
    virtual int on_get_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_host_run(argc, argv, env))) {
            if (!(err = host_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_host(optarg);
        } else {
        }
        return err;
    }
    virtual int on_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_host_run(argc, argv, env))) {
                if (!(err = host_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    /// ...port_option...
    virtual int on_get_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_port_run(argc, argv, env))) {
            if (!(err = port_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned port = arg.to_unsigned();
            if ((0 < port)) {
                this->set_port(port);
            }
        } else {
        }
        return err;
    }
    virtual int on_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_port_run(argc, argv, env))) {
                if (!(err = port_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }

    /// ...relay_host_option...
    virtual int on_get_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_relay_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_relay_host_run(argc, argv, env))) {
            if (!(err = relay_host_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_relay_host(optarg);
        } else {
        }
        return err;
    }
    virtual int on_relay_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_relay_host_run(argc, argv, env))) {
                if (!(err = relay_host_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    /// ...relay_port_option...
    virtual int on_get_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_relay_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_relay_port_run(argc, argv, env))) {
            if (!(err = relay_port_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned port = arg.to_unsigned();
            if ((0 < port)) {
                this->set_relay_port(port);
            }
        } else {
        }
        return err;
    }
    virtual int on_relay_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_relay_port_run(argc, argv, env))) {
                if (!(err = relay_port_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }

    /// ...host / ...port
    virtual string_t& set_host(const string_t& to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& set_host(const char_t* to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual short& set_port(const short& to) {
        this->set_accept_port(to);
        this->set_connect_port(to);
        return this->port();
    }

    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_accept_host(chars);
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual short& set_accept_port(const short& to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }

    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_connect_host(chars);
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual short& set_connect_port(const short& to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
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

    /// ...sockets_run
    int (derives::*sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((sockets_run_)) {
            err = (this->*sockets_run_)(argc, argv, env);
        } else {
            err = this->default_sockets_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::sockets::os::interfaces sockets;
        LOGGER_IS_LOGGED_INFO("sockets.startup()...");
        if (!(sockets.startup())) {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.startup()");
            err = 1;
        } else {
            LOGGER_IS_LOGGED_INFO("...sockets.startup()");
        }
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::sockets::os::interfaces sockets;
        LOGGER_IS_LOGGED_INFO("sockets.cleanup()...");
        if (!(sockets.cleanup())) {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.cleanup()");
            err = 1;
        } else {
            LOGGER_IS_LOGGED_INFO("...sockets.cleanup()");
        }
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_run(argc, argv, env);
            if ((err2 = after_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_run;
        return err;
    }
    virtual int sockets_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int sockets_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...connect_run
    virtual int connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_connect_run(argc, argv, env))) {
            int err2 = 0;
            err = connect_run(argc, argv, env);
            if ((err2 = after_connect_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_connect_run;
            }
        }
        return err;
    }
    virtual int connect_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            sockets_run_ = 0;
        }
        return err;
    }
    virtual int connect_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...accept_run
    virtual int accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_run(argc, argv, env);
            if ((err2 = after_accept_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_accept_run;
            }
        }
        return err;
    }
    virtual int accept_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            sockets_run_ = 0;
        }
        return err;
    }
    virtual int accept_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...accept_one_run
    virtual int accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_accept_run(argc, argv, env))) {
        }
        return err;
    }
    virtual int before_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->set_accept_one(true);
        return err;
    }
    virtual int after_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->set_accept_one(false);
        return err;
    }
    virtual int all_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_one_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_one_run(argc, argv, env);
            if ((err2 = after_accept_one_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_accept_one_run;
            }
        }
        return err;
    }
    virtual int accept_one_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            sockets_run_ = 0;
        }
        return err;
    }
    virtual int accept_one_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...accept_connections_run
    virtual int accept_connections_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_accept_connections_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_connections_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_connections_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_connections_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_connections_run(argc, argv, env);
            if ((err2 = after_accept_connections_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...connect_run
    virtual int connect_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_send_request_run(cn, argc, argv, env))) {
            if (!(err = all_recv_response_run(cn, argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int before_connect_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_connect_run(cn, argc, argv, env))) {
            int err2 = 0;
            err = connect_run(cn, argc, argv, env);
            if ((err2 = after_connect_run(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...accept_run
    virtual int accept_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_recv_request_run(cn, argc, argv, env))) {
            if (!(err = all_send_response_run(cn, argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int before_accept_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_run(cn, argc, argv, env))) {
            int err2 = 0;
            err = accept_run(cn, argc, argv, env);
            if ((err2 = after_accept_run(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...send_request_run
    virtual int send_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        if (!(err = all_send_request_run(cn, request, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_send_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request_run(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_request_run(cn, argc, argv, env);
            if ((err2 = after_send_request_run(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...send_request_run
    virtual int send_request_run(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("send(cn, request, argc, argv, env)...");
        if (!(err = send(cn, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...send(cn, request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_send_request_run(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->all_prepare_request_to_send_run(request, argc, argv, env)...");
        if (!(err = this->all_prepare_request_to_send_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...this->all_prepare_request_to_send_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int after_send_request_run(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request_run(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request_run(cn, request, argc, argv, env))) {
            int err2 = 0;
            err = send_request_run(cn, request, argc, argv, env);
            if ((err2 = after_send_request_run(cn, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...recv_response_run
    virtual int recv_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();

        LOGGER_IS_LOGGED_INFO("all_recv_response_run(response, cn, argc, argv, env)...");
        if (!(err = all_recv_response_run(response, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_recv_response_run(response, cn, argc, argv, env)");

            LOGGER_IS_LOGGED_INFO("all_process_response_run(response, cn, argc, argv, env)...");
            if (!(err = all_process_response_run(response, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...all_process_response_run(response, cn, argc, argv, env)");
            }
        }
        return err;
    }
    virtual int before_recv_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_response_run(cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_response_run(cn, argc, argv, env);
            if ((err2 = after_recv_response_run(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_response_run
    virtual int recv_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;

        LOGGER_IS_LOGGED_INFO("response.clear()...");
        response.clear();
        LOGGER_IS_LOGGED_INFO("...response.clear()");

        LOGGER_IS_LOGGED_INFO("all_recv_message_run(response, cn, argc, argv, env)...");
        if (!(err = all_recv_message_run(response, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_recv_message_run(response, cn, argc, argv, env))");
        }
        return err;
    }
    virtual int before_recv_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->all_process_message_received_run(response, argc, argv, env)...");
        if (!(err = this->all_process_message_received_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...this->all_process_message_received_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int all_recv_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_response_run(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_response_run(response, cn, argc, argv, env);
            if ((err2 = after_recv_response_run(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_run
    using extends::all_process_response_run;
    virtual int process_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->all_process_response_run(response, argc, argv, env)...");
        if (!(err = this->all_process_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...this->all_process_response_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_process_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_run(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_run(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_response_run(response, cn, argc, argv, env);
            if ((err2 = after_process_response_run(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...recv_request_run
    virtual int recv_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();

        LOGGER_IS_LOGGED_INFO("all_recv_request_run(request, cn, argc, argv, env)...");
        if (!(err = all_recv_request_run(request, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_recv_request_run(request, cn, argc, argv, env)");

            LOGGER_IS_LOGGED_INFO("all_process_request_run(request, cn, argc, argv, env)...");
            if (!(err = all_process_request_run(request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...all_process_request_run(request, cn, argc, argv, env)");
            }
        }
        return err;
    }
    virtual int before_recv_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_request_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_request_run(cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_request_run(cn, argc, argv, env);
            if ((err2 = after_recv_request_run(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...recv_request_run
    virtual int recv_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;

        LOGGER_IS_LOGGED_INFO("request.clear()...");
        request.clear();
        LOGGER_IS_LOGGED_INFO("...request.clear()");

        LOGGER_IS_LOGGED_INFO("all_recv_message_run(request, cn, argc, argv, env)...");
        if (!(err = all_recv_message_run(request, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_recv_message_run(request, cn, argc, argv, env))");
        }
        return err;
    }
    virtual int before_recv_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->all_process_message_received_run(request, argc, argv, env)...");
        if (!(err = this->all_process_message_received_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...this->all_process_message_received_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int all_recv_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_request_run(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_request_run(request, cn, argc, argv, env);
            if ((err2 = after_recv_request_run(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_request_run
    using extends::all_process_request_run;
    virtual int process_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_process_request_run(request, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_process_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_run(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request_run(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_request_run(request, cn, argc, argv, env);
            if ((err2 = after_process_request_run(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...send_response_run
    virtual int send_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        if (!(err = all_send_response_run(cn, response, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_send_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response_run(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response_run(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_response_run(cn, argc, argv, env);
            if ((err2 = after_send_response_run(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...send_response_run
    virtual int send_response_run(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = send(cn, response, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_send_response_run(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_prepare_message_to_send_run(response, argc, argv, env))) {
        }
        return err;
    }
    virtual int after_send_response_run(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response_run(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response_run(cn, response, argc, argv, env))) {
            int err2 = 0;
            err = send_response_run(cn, response, argc, argv, env);
            if ((err2 = after_send_response_run(cn, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...recv_message_run
    virtual int recv_message_run(string_t& message, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        LOGGER_IS_LOGGED_INFO("recv_crlf2(message, c, cn, argc, argv, env)...");
        if (!(err = recv_crlf2(message, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...recv_crlf2(message, c, cn, argc, argv, env))");
        }
        return err;
    }
    virtual int before_recv_message_run(string_t& message, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_recv_message_run(string_t& message, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_recv_message_run(string_t& message, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_recv_message_run(message, cn, argc, argv, env))) {
            int err2 = 0;
            err = recv_message_run(message, cn, argc, argv, env);
            if ((err2 = after_recv_message_run(message, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...host_run
    virtual int host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& host = this->get_host();
        const char_t* chars = 0; size_t length = 0;
        if ((chars = host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_host_run(argc, argv, env))) {
            int err2 = 0;
            err = host_run(argc, argv, env);
            if ((err2 = after_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_host_run;
        return err;
    }
    virtual int host_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int host_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...relay_host_run
    virtual int relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& relay_host = this->get_relay_host();
        const char_t* chars = 0; size_t length = 0;
        if ((chars = relay_host.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_host_run(argc, argv, env))) {
            int err2 = 0;
            err = relay_host_run(argc, argv, env);
            if ((err2 = after_relay_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_relay_host_run;
        return err;
    }
    virtual int relay_host_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int relay_host_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...port_run
    virtual int port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const short& port = this->get_port();
        if (0 < (port)) {
            this->outln(unsigned_to_string(port).chars());
        }
        return err;
    }
    virtual int before_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_port_run(argc, argv, env))) {
            int err2 = 0;
            err = port_run(argc, argv, env);
            if ((err2 = after_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_port_run;
        return err;
    }
    virtual int port_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int port_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...relay_port_run
    virtual int relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const short& relay_port = this->get_relay_port();
        if (0 < (relay_port)) {
            this->outln(unsigned_to_string(relay_port).chars());
        }
        return err;
    }
    virtual int before_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_port_run(argc, argv, env))) {
            int err2 = 0;
            err = relay_port_run(argc, argv, env);
            if ((err2 = after_relay_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_relay_port_run;
        return err;
    }
    virtual int relay_port_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int relay_port_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// send
    /// ...
    /// send...
    /// ...
    virtual int send(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        LOGGER_IS_LOGGED_INFO("if ((chars = s.has_chars(length)))...");
        if ((chars = s.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...if ((chars = s.has_chars(length = " << length << ")))");

            LOGGER_IS_LOGGED_INFO("cn.send(chars, length = " << length << ")...");
            cn.send(chars, length);
            LOGGER_IS_LOGGED_INFO("...cn.send(chars, length = " << length << ")");
        }
        return err;
    }
    /// send_lf...
    /// ...<lf>
    virtual int send_lf(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t lf_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        lf_s.appendlf();
        if ((chars = lf_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// send_cr...
    /// ...<cr>
    virtual int send_cr(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int send_crlf(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        cr_s.appendlf();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int send_crlf2(xos::network::sockets::interface& cn, const string_t& s, int argc, char_t** argv, char_t**env) {
        string_t cr_s(s);
        int err = 0;
        size_t length = 0;
        const char_t *chars = 0;

        cr_s.appendcr();
        cr_s.appendlf();
        cr_s.appendcr();
        cr_s.appendlf();
        if ((chars = cr_s.has_chars(length))) {
            cn.send(chars, length);
        }
        return err;
    }
    /// ...
    /// send
    ///

    /// recv
    /// ...
    /// recv_before_lf...
    /// ...<lf>
    virtual int recv_before_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            switch (c) {
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                return err = 0;
            default:
                r.append(&c, 1);
            }
        }
        return err;
    }
    /// recv_lf...
    /// ...<lf>
    virtual int recv_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                return err = 0;
            }
        }
        return err;
    }
    /// recv_before_cr...
    /// ...<cr>
    virtual int recv_before_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                return err = 0;
            default:
                r.append(&c, 1);
            }
        }
        return err;
    }
    /// recv_cr...
    /// ...<cr>
    virtual int recv_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                return err = 0;
            }
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int recv_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;
        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                    s = ch;
                    break;
                case cr:
                    return err = 0;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int on_recv_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int recv_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;

        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                case lf:
                    s = lfcr;
                    break;
                case lfcr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                case lf:
                    s = ch;
                    break;
                case cr:
                    s = lf;
                    break;
                case lfcr:
                    err = on_recv_crlf2(r, c, cn, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    /// <d>[1..n]...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sizeof_sized_crlf2(size_t size_of, string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        size_t size = 0;

        for (size_t remain = size_of; remain; --remain) {
            if  (1 > (amount = cn.recv(&c, 1))) {
                return err;
            }
            r.append(&c, 1);
            size = (size << 8) | ((uint8_t)c);
        }
        err = recv_sized_crlf2(size, r, c, cn, argc, argv, env);
        return err;
    }
    /// ...[1..n] | <cr><lf><cr><lf>
    virtual int recv_sized_crlf2(size_t size, string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;
        for (; size; --size) {
            if (1 > (amount = cn.recv(&c, 1))) {
                break;
            } else {
                r.append(&c, 1);
                switch (c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        break;
                    case lf:
                        s = lfcr;
                        break;
                    case lfcr:
                        s = cr;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                case '\n':
                    LOGGER_IS_LOGGED_INFO("...case '\\n':");
                    switch (s) {
                    case ch:
                        s = ch;
                        break;
                    case cr:
                        s = lf;
                        break;
                    case lf:
                        s = ch;
                        break;
                    case lfcr:
                        return err = 0;
                        break;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    s = ch;
                    break;
                }
            }
        }
        return err;
    }
    /// ...
    /// recv
    /// 

    ///
    /// ..host / ..port
    /// ...
    /// host / port
    virtual const string_t& get_host() const {
        return this->host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual const short& get_port() const {
        return this->port();
    }
    virtual short& port() const {
        return this->connect_port();
    }

    /// ...accept_host / ...accept_port
    virtual const string_t& get_accept_host() const {
        return this->accept_host();
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual const short& get_accept_port() const {
        return this->accept_port();
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }

    /// ...connect_host / ...connect_port
    virtual const string_t& get_connect_host() const {
        return this->connect_host();
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual const short& get_connect_port() const {
        return this->connect_port();
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }

    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_relay_host(chars);
    }
    virtual string_t& set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual const string_t& get_relay_host() const {
        return this->relay_host();
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }
    virtual short& set_relay_port(const short& to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual const short& get_relay_port() const {
        return this->relay_port();
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }
    /// ...
    /// ..host / ..port
    /// 

    ///
    /// ...iface / ...addr / ...ep/ ...tp
    /// ...
    /// ...os_iface
    virtual xos::network::sockets::os::interface& accept_os_iface() const {
        return (xos::network::sockets::os::interface&)accept_os_iface_;
    }
    virtual xos::network::sockets::os::interface& connect_os_iface() const {
        return (xos::network::sockets::os::interface&)connect_os_iface_;
    }
    virtual xos::network::sockets::os::interface& relay_os_iface() const {
        return (xos::network::sockets::os::interface&)relay_os_iface_;
    }

    /// ...iface
    virtual xos::network::sockets::interface& accept_iface() const {
        return (xos::network::sockets::interface&)accept_os_iface();
    }
    virtual xos::network::sockets::interface& connect_iface() const {
        return (xos::network::sockets::interface&)connect_os_iface();
    }
    virtual xos::network::sockets::interface& relay_iface() const {
        return (xos::network::sockets::interface&)relay_os_iface();
    }

    /// ...addr /  ...addrlen
    virtual xos::network::sockets::sockaddr_t& accept_addr() const {
        return (xos::network::sockets::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::sockets::socklen_t& accept_addrlen() const {
        return (xos::network::sockets::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& connect_addr() const {
        return (xos::network::sockets::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::sockets::socklen_t& connect_addrlen() const {
        return (xos::network::sockets::socklen_t&)connect_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& relay_addr() const {
        return (xos::network::sockets::sockaddr_t&)relay_addr_;
    }
    virtual xos::network::sockets::socklen_t& relay_addrlen() const {
        return (xos::network::sockets::socklen_t&)relay_addrlen_;
    }

    /// ...ep
    xos::network::sockets::endpoint& (derives::*ep_)() const;
    virtual xos::network::sockets::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::sockets::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& ip_v4_ep() const {
        return (xos::network::sockets::endpoint&)ip_v4_ep_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& ip_v6_ep() const {
        return (xos::network::sockets::endpoint&)ip_v6_ep_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

    /// ...tp
    xos::network::sockets::transport& (derives::*tp_)() const;
    virtual xos::network::sockets::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::sockets::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& ip_v4_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v4_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_udp_tp_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& ip_v6_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v6_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    /// ...
    /// ...iface / ...addr / ...ep/ ...tp
    /// 

protected:
    string_t accept_host_, connect_host_, relay_host_;
    short accept_port_, connect_port_, relay_port_;

    xos::network::sockets::os::interface accept_os_iface_, connect_os_iface_, relay_os_iface_;
 
    xos::network::sockets::interface accept_iface_, connect_iface_, relay_iface_;

    xos::network::sockets::sockaddr_t accept_addr_, connect_addr_, relay_addr_;
    xos::network::sockets::socklen_t accept_addrlen_, connect_addrlen_, relay_addrlen_;

    xos::network::sockets::ip::v4::endpoint ip_v4_ep_;
    xos::network::sockets::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::sockets::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(WINSOCK_1)
    xos::network::sockets::ip::v6::endpoint ip_v6_ep_;
    xos::network::sockets::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::sockets::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace sockets 
} /// namespace network 
} /// namespace protocol 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HPP
