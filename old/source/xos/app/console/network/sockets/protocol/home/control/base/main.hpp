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
///   Date: 12/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/home/control/base/main_opt.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_CONNECT_PORT 3223

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_ACCEPT_PORT \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_CONNECT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_RELAY_PORT \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_CONNECT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_ENDOF_MESSAGE "\n\r\n\r\n"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace home {
namespace control {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::home::control::base::main_opt, 
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
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_RELAY_PORT),
      endof_message_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_ENDOF_MESSAGE) {
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

    /// ...sockets_run
    virtual int this_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::all_sockets_run(argc, argv, env))) {} else {}
        return err;
    }
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_sockets_run;
        return err;
    }
    virtual int unset_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }

    /// ...output_request_run
    virtual int this_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::all_output_request_run(argc, argv, env))) {} else {}
        return err;
    }
    virtual int set_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_output_request_run;
        return err;
    }
    virtual int unset_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }

    /// ...output_response_run
    virtual int this_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::all_output_response_run(argc, argv, env))) {} else {}
        return err;
    }
    virtual int set_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::this_output_response_run;
        return err;
    }
    virtual int unset_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }

    /// ...send_request
    virtual int before_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = this->endof_message();
        request.append(endof_message);
        return err;
    }
    /// ...recv_request
    virtual int recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        request.clear();
        if (!(err = this->recv_before_lf(request, c, cn, argc, argv, env))) {
            err = this->all_process_request(request, cn, argc, argv, env);
        }
        return err;
    }

    /// ...send_response
    virtual int before_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = this->endof_message();
        response.append(endof_message);
        return err;
    }
    /// ...recv_response
    virtual int recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        response.clear();
        if (!(err = this->recv_before_lf(response, c, cn, argc, argv, env))) {
            err = this->all_process_response(response, cn, argc, argv, env);
        }
        return err;
    }
    /// ...process_response
    virtual int process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = response.has_chars(length))) {
            this->outln(chars, length);
        }
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

    virtual string_t& set_endof_message(const string_t& to) {
        string_t& endof_message = this->endof_message();
        endof_message.assign(to);
        return endof_message;
    }
    virtual string_t& endof_message() const {
        return (string_t&)endof_message_;
    }

protected:
    short accept_port_, connect_port_, relay_port_;
    string_t endof_message_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_HOME_CONTROL_BASE_MAIN_HPP
