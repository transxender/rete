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
///   Date: 9/17/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/text/base/main_opt.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_CONNECT_PORT 2323

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_ACCEPT_PORT \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_CONNECT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_RELAY_PORT \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_CONNECT_PORT

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace text {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::text::base::main_opt, 
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
    maint()
    : run_(0),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_RELAY_PORT) {
        set_request_from_message();
        set_response_from_reply();
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

    typedef typename extends::message_t message_t;
    typedef typename extends::reply_t reply_t;

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

    /// ...sockets_run
    virtual int this_all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::all_sockets_run(argc, argv, env))) {
        }
        return err;
    }
    virtual int set_this_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_all_sockets_run;
        return err;
    }
    virtual int on_set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::on_set_sockets_run(argc, argv, env))) {
            if (!(err = set_this_sockets_run(argc, argv, env))) {
            }
        }
        return err;
    }

    /// ...output_request_run
    virtual int this_all_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::all_output_request_run(argc, argv, env))) {
        }
        return err;
    }
    virtual int set_this_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_all_output_request_run;
        return err;
    }
    virtual int on_set_output_request_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_set_output_request_run(argc, argv, env))) {
            if (!(err = set_this_output_request_run(argc, argv, env))) {
            }
        }
        return err;
    }

    /// ...output_response_run
    virtual int this_all_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::all_output_response_run(argc, argv, env))) {
        }
        return err;
    }
    virtual int set_this_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_all_output_response_run;
        return err;
    }
    virtual int on_set_output_response_run(int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_set_output_response_run(argc, argv, env))) {
            if (!(err = set_this_output_response_run(argc, argv, env))) {
            }
        }
        return err;
    }

    /// set...from...()
    virtual int set_request_from_message() {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = this->message_chars(length))) {
            string_t& request = this->request();

            request.assign(chars, length);
            if ((chars = this->crlf2_endof_message_chars(length))) {
                request.append(chars, length);
            }
        }
        return err;
    }
    virtual int set_response_from_reply() {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = this->reply_chars(length))) {
            string_t& response = this->response();

            response.assign(chars, length);
            if ((chars = this->crlf2_endof_message_chars(length))) {
                response.append(chars, length);
            }
        }
        return err;
    }

    /// ...option...
    virtual int on_message_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = set_request_from_message();
        return err;
    }
    virtual int on_reply_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = set_response_from_reply();
        return err;
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
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace text
} /// namespace protocol
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TEXT_BASE_MAIN_HPP
