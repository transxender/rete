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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 11/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPT_HPP

#include "xos/app/console/network/sockets/base/main.hpp"
#include "xos/app/console/home/base/main_opt.hpp"

#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_CONNECT_PORT 9999

#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_ACCEPT_PORT \
    XOS_APP_CONSOLE_HOME_CONTROL_KASA_CONNECT_PORT

#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_RELAY_PORT \
    XOS_APP_CONSOLE_HOME_CONTROL_KASA_CONNECT_PORT

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_CHARS_EXTEND \

#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \

#ifdef XOS_APP_CONSOLE_HOME_CONTROL_KASA_CLIENT_MAIN_OPT_HPP
/// client
/// ...
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_CHARS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_CLIENT_MAIN_LOGGING_OPTIONS_OPTIONS
/// ...
/// client
#else /// XOS_APP_CONSOLE_HOME_CONTROL_KASA_CLIENT_MAIN_OPT_HPP
#ifdef XOS_APP_CONSOLE_HOME_CONTROL_KASA_SERVER_MAIN_OPT_HPP
/// server
/// ...
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_CHARS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_SERVER_MAIN_LOGGING_OPTIONS_OPTIONS
/// ...
/// server
#else /// XOS_APP_CONSOLE_HOME_CONTROL_KASA_SERVER_MAIN_OPT_HPP
/// base
/// ...
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_CHARS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_LOGGING_OPTIONS_OPTIONS
/// ...
/// base
#endif /// XOS_APP_CONSOLE_HOME_CONTROL_KASA_SERVER_MAIN_OPT_HPP
#endif /// XOS_APP_CONSOLE_HOME_CONTROL_KASA_CLIENT_MAIN_OPT_HPP

///////////////////////////////////////////////////////////////////////
#ifdef XOS_APP_CONSOLE_HOME_CONTROL_KASA_SERVER_MAIN_OPT_HPP
/// server
/// ...
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_OPTIONS
/// ...
/// server
#else /// XOS_APP_CONSOLE_HOME_CONTROL_KASA_SERVER_MAIN_OPT_HPP
/// base
/// ...
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_HOME_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_HOME_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_WHICH_MAIN_LOGGING_OPTIONS_OPTIONS
/// ...
/// base
#endif /// XOS_APP_CONSOLE_HOME_CONTROL_KASA_SERVER_MAIN_OPT_HPP

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace home {
namespace control {
namespace kasa {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::home::base::main_optt
 <xos::app::console::network::sockets::base::maint
 <xos::app::console::network::sockets::base::main_optt<> > >, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
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
    main_optt()
    : run_(0),
      accept_port_(XOS_APP_CONSOLE_HOME_CONTROL_KASA_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_HOME_CONTROL_KASA_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_HOME_CONTROL_KASA_RELAY_PORT) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
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

    /// ...output_request_run
    virtual int output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::output_request_run(argc, argv, env))) {
            this->outln();
        }
        return err;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...port
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }

protected:
    short accept_port_, connect_port_, relay_port_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace kasa
} /// namespace control
} /// namespace home
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_HOME_CONTROL_KASA_BASE_MAIN_OPT_HPP
