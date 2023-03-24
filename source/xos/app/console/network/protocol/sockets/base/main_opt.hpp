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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 1/9/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPT_HPP

#include "xos/app/console/network/protocol/base/main.hpp"
#include "xos/app/console/network/protocol/client/main.hpp"
#include "xos/app/console/network/protocol/server/main.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG "[{ * | name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_RELAY_HOST_OPTARG \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG

#ifdef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_OPT_HPP
/// client
/// ...
/// ...
/// client
#else /// def XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_OPT_HPP
#ifdef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_SERVER_MAIN_OPT_HPP
/// server
/// ...
/// ...
/// server
#else /// def XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_SERVER_MAIN_OPT_HPP
/// base
/// ...
/// ...
/// base
#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_SERVER_MAIN_OPT_HPP
#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_OPT_HPP

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTUSE "Hostname or address"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTUSE "Port number"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPT "relay-host"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE "Relay hostname or address"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S "O::"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C 'O'
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPT "relay-port"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE "Relay port number"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S "P::"
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C 'P'
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#ifdef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_OPT_HPP
/// client
/// ...
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_CLIENT_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_CLIENT_MAIN_OPTIONS_OPTIONS
/// ...
/// client
#else /// def XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_OPT_HPP
#ifdef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_SERVER_MAIN_OPT_HPP
/// server
/// ...
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SERVER_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SERVER_MAIN_OPTIONS_OPTIONS
/// ...
/// server
#else /// def XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_SERVER_MAIN_OPT_HPP
/// base
/// ...
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS
/// ...
/// base
#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_SERVER_MAIN_OPT_HPP
#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_CLIENT_MAIN_OPT_HPP

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace sockets {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::network::protocol::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
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
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTARG;
        return chars;
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
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTARG;
        return chars;
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
    virtual int on_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_relay_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_relay_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* relay_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG;
        return chars;
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
    virtual int on_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_relay_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_relay_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* relay_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            err = this->on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            err = this->on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = this->host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = this->port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            chars = this->relay_host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            chars = this->relay_port_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...host / ...port
    virtual string_t& set_host(const string_t& to) {
        string_t& host = this->host();
        const char_t* chars = to.has_chars();
        if ((chars)) host.assign(to);
        else host.clear();
        return host;
    }
    virtual const string_t& get_host() const {
        return this->host();
    }
    virtual string_t& host() const {
        static string_t host(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST);
        return host;
    }
    virtual short& set_port(const short& to) {
        short& port = this->port();
        port = to;
        return port;
    }
    virtual const short& get_port() const {
        return this->port();
    }
    virtual short& port() const {
        static short port = XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT;
        return port;
    }

    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        string_t& relay_host = this->relay_host();
        const char_t* chars = to.has_chars();
        if ((chars)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual const string_t& get_relay_host() const {
        return this->relay_host();
    }
    virtual string_t& relay_host() const {
        static string_t relay_host(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST);
        return relay_host;
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
        static short relay_port = XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT;
        return relay_port;
    }

protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace sockets 
} /// namespace protocol 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_SOCKETS_BASE_MAIN_OPT_HPP
