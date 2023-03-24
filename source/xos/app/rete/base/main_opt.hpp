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
///   Date: 3/23/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_RETE_BASE_MAIN_OPT_HPP
#define XOS_APP_RETE_BASE_MAIN_OPT_HPP

#include "xos/app/nadir/base/main.hpp"
#include "xos/app/protocol/network/sockets/base/main.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG "[{ * | name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_MAIN_RELAY_HOST_OPTARG \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG

//////////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE "Hostname or address"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG "[{ 0..2^16-1 }]"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE "Port number"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT "relay-host"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE "Relay hostname or address"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S "O::"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C 'O'
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT "relay-port"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE "Relay port number"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S "P::"
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C 'P'
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_CLIENT_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_CLIENT_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_SERVER_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_SERVER_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_RETE_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_CLIENT_OPTIONS_CHARS_EXTEND \

#define XOS_APP_RETE_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_CLIENT_OPTIONS_OPTIONS_EXTEND \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_RETE_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_RETE_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_NADIR_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_RETE_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_RETE_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_NADIR_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_RETE_BASE_MAIN_ARGS 0
#define XOS_APP_RETE_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace rete {
namespace base {

/// class main_optt
template 
<class TMain = xos::app::protocol::network::sockets::base::maint<>,
 class TExtends = xos::app::nadir::base::maint<TMain>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::main_t main_t;
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

    /// ...host_option...
    virtual int on_get_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_host_option_get(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_host_option_get(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_host_option_get(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_host_option_get(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_set_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_set_host_option(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_set_host_option(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_set_host_option(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_set_host_option(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_host_option_set(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_host_option_set(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_host_option_set(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_host_option_set(optarg, optind, argc, argv, env)");
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
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG;
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
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_port_option_get(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_port_option_get(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_port_option_get(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_port_option_get(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_set_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_set_port_option(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_set_port_option(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_set_port_option(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_set_port_option(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_port_option_set(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_port_option_set(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_port_option_set(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_port_option_set(optarg, optind, argc, argv, env)");
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
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG;
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
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_relay_host_option_get(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_relay_host_option_get(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_relay_host_option_get(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_relay_host_option_get(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_set_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_set_relay_host_option(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_set_relay_host_option(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_set_relay_host_option(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_set_relay_host_option(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_relay_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_relay_host_option_set(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_relay_host_option_set(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_relay_host_option_set(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_relay_host_option_set(optarg, optind, argc, argv, env)");
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
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG;
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
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_relay_port_option_get(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_relay_port_option_get(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_relay_port_option_get(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_relay_port_option_get(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_set_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_set_relay_port_option(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_set_relay_port_option(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_set_relay_port_option(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_set_relay_port_option(optarg, optind, argc, argv, env)");
        }
        return err;
    }
    virtual int on_relay_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        main_t& main = this->main();

        LOGGER_IS_LOGGED_INFO("main.on_relay_port_option_set(optarg, optind, argc, argv, env)...");
        if (!(err = main.on_relay_port_option_set(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("..."<< err << " = main.on_relay_port_option_set(optarg, optind, argc, argv, env)");
            if (!(err = this->set_main_run(argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed "<< err << " = main.on_relay_port_option_set(optarg, optind, argc, argv, env)");
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
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            err = this->on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            err = this->on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = this->host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = this->port_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            chars = this->relay_host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            chars = this->relay_port_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_RETE_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_RETE_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_RETE_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_RETE_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace rete 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_RETE_BASE_MAIN_OPT_HPP
