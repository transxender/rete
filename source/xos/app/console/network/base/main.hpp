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
///   Date: 9/5/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP

#include "xos/app/console/network/base/main_opt.hpp"
#include "xos/io/crt/file/reader.hpp"

#define XOS_APP_CONSOLE_NETWORK_DEFAULT_REQUEST \
    "GET /hello HTTP/1.0\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n"

#define XOS_APP_CONSOLE_NETWORK_DEFAULT_RESPONSE \
    "HTTP/1.0 200 Ok\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::base::main_opt, 
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
      default_request_(XOS_APP_CONSOLE_NETWORK_DEFAULT_REQUEST),
      request_(default_request_), 
      default_response_(XOS_APP_CONSOLE_NETWORK_DEFAULT_RESPONSE),
      response_(default_response_), 
      accept_one_(false), accept_done_(false), accept_restart_(false) {
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
            this->out(chars, length);
        }
        return err;
    }
    /// ...output_response_run
    virtual int output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->response_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }

    /// ...on_set_request_option
    int (derives::*on_set_request_option_)(string_t& request, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_request_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& request = this->request();
            if (on_set_request_option_) {
                err = (this->*on_set_request_option_)(request, optarg, optind, argc, argv, env);
            } else {
                err = this->file_on_set_message_string_option(request, optarg, optind, argc, argv, env);
            }
        }
        return err;
    }

    /// ...on_set_response_option
    int (derives::*on_set_response_option_)(string_t& response, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_response_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& response = this->response();
            if (on_set_response_option_) {
                err = (this->*on_set_response_option_)(response, optarg, optind, argc, argv, env);
            } else {
                err = this->file_on_set_message_string_option(response, optarg, optind, argc, argv, env);
            }
        }
        return err;
    }

    /// ...on_set_message_string_option
    virtual int file_on_set_message_string_option
    (string_t& string, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            xos::io::crt::file::char_reader file;

            LOGGER_IS_LOGGED_INFO("file.open(\""<< optarg <<"\")...");
            if ((file.open(optarg))) {
                xos::io::crt::file::char_reader::char_t c = 0;
                ssize_t amount = 0, count = 0;
                if (0 < (amount = file.read(&c, 1))) {
                    string.clear();
                    do {
                        char_t string_c = ((char_t)c);
                        string.append(&string_c, 1);
                        count += amount;
                    } while (0 < (amount = file.read(&c, 1)));
                }
                LOGGER_IS_LOGGED_INFO("...file.close(\""<< optarg <<"\")...");
                file.close();
            }
        } else {
        }
        return err;
    }
    virtual int string_on_set_message_string_option
    (string_t& string, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string.assign(optarg);
        } else {
        }
        return err;
    }

    /// 
    /// ...request... / ...response...
    /// ...
    /// ...request...
    virtual string_t& set_request(const string_t& to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to, size_t length) {
        string_t& request = this->request();
        request.assign(to, length);
        return request;
    }
    virtual const char_t* request_chars(size_t& length) const {
        string_t& request = this->request();
        const char_t* request_chars = 0;
        request_chars = request.has_chars(length);
        return request_chars;
    }
    virtual const char_t* request_chars() const {
        string_t& request = this->request();
        const char_t* request_chars = 0;
        request_chars = request.has_chars();
        return request_chars;
    }
    virtual string_t& request() const {
        string_t& request = (string_t&)request_;
        return request;
    }
    virtual const char_t* default_request_chars() const {
        string_t& request = this->default_request();
        const char_t* request_chars = 0;
        request_chars = request.has_chars();
        return request_chars;
    }
    virtual string_t& default_request() const {
        string_t& request = (string_t&)default_request_;
        return request;
    }
    /// ...response...
    virtual string_t& set_response(const string_t& to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response(const char_t* to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response(const char_t* to, size_t length) {
        string_t& response = this->response();
        response.assign(to, length);
        return response;
    }
    virtual const char_t* response_chars(size_t& length) const {
        string_t& response = this->response();
        const char_t* response_chars = 0;
        response_chars = response.has_chars(length);
        return response_chars;
    }
    virtual const char_t* response_chars() const {
        string_t& response = this->response();
        const char_t* response_chars = 0;
        response_chars = response.has_chars();
        return response_chars;
    }
    virtual string_t& response() const {
        string_t& response = (string_t&)response_;
        return response;
    }
    virtual const char_t* default_response_chars() const {
        string_t& response = this->default_response();
        const char_t* response_chars = 0;
        response_chars = response.has_chars();
        return response_chars;
    }
    virtual string_t& default_response() const {
        string_t& response = (string_t&)default_response_;
        return response;
    }
    /// ...
    /// ...request... / ...response...
    /// 

    /// ...accept...
    virtual bool& set_accept_many(bool to = false) {
        bool& is_true = this->accept_one();
        is_true = to;
        return is_true;
    }
    virtual bool& set_accept_one(bool to = true) {
        bool& is_true = this->accept_one();
        is_true = to;
        return is_true;
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }
    
    /// ...accept...
    virtual bool& set_accept_continue(bool to = true) {
        accept_done_ = !to;
        return (bool&)accept_done_;
    }
    virtual bool& set_accept_done(bool to = true) {
        accept_done_ = to;
        return (bool&)accept_done_;
    }
    virtual bool& accept_done() const {
        return (bool&)accept_done_;
    }

    /// ...accept...
    virtual bool& set_accept_stop(bool to = true) {
        accept_restart_ = !to;
        return (bool&)accept_restart_;
    }
    virtual bool& set_accept_restart(bool to = true) {
        accept_restart_ = to;
        return (bool&)accept_restart_;
    }
    virtual bool& accept_restart() const {
        return (bool&)accept_restart_;
    }

protected:
    string_t default_request_, request_, default_response_, response_;
    bool accept_one_, accept_done_, accept_restart_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_BASE_MAIN_HPP
