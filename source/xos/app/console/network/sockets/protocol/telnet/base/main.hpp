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
///   Date: 10/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TELNET_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TELNET_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/telnet/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace telnet {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::telnet::base::main_opt, 
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

    /// ...portno
    enum {
        accept_portno = 2323,
        connect_portno = 23,
        relay_portno = connect_portno
    };
    
    /// constructor / destructor
    maint()
    : run_(0), 
      accept_port_(accept_portno), 
      connect_port_(connect_portno), 
      relay_port_(relay_portno),
      default_request_("hello\r\n\r\n\r\n"), default_response_(default_request_), 
      request_(default_request_), response_(default_response_), cr_("\r") {
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

    /// ...output_request_run
    virtual int output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->request_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    /// ...output_response_run
    virtual int output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->response_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...recv_request
    virtual int recv_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        request.clear();
        if (!(err = this->recv_cr(request, c, cn, argc, argv, env))) {
            err = this->all_process_request(request, cn, argc, argv, env);
        }
        return err;
    }

    /// ...recv_response
    virtual int recv_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;

        response.clear();
        if (!(err = this->recv_cr(response, c, cn, argc, argv, env))) {
            err = this->all_process_response(response, cn, argc, argv, env);
        }
        return err;
    }

    /// ...process_request
    virtual int process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = request.has_chars(length))) {
            this->outln(chars, length);
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

    /// request / response
    virtual string_t& request() const {
        return (string_t&)request_;
    }
    virtual string_t& response() const {
        return (string_t&)response_;
    }
    virtual string_t& cr() const {
        return (string_t&)cr_;
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

    /// ...request_optarg...
    virtual int on_set_request_optarg
    (string_t& request, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            request.append(optarg);
        } else {
        }
        request.append(this->cr());
        if (!(err = this->on_request_optarg_set(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    virtual int on_request_optarg_set
    (string_t& request, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

protected:
    short accept_port_, connect_port_, relay_port_;
    string_t default_request_, default_response_, request_, response_, cr_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace telnet
} /// namespace protocol
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_TELNET_BASE_MAIN_HPP
