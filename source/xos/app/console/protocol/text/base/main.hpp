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
///   Date: 9/16/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TEXT_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TEXT_BASE_MAIN_HPP

#include "xos/app/console/protocol/text/base/main_opt.hpp"
#include "xos/io/crt/file/reader.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_TEXT_DEFAULT_MESSAGE \
    "GET / HTTP/1.0\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n"

#define XOS_APP_CONSOLE_PROTOCOL_TEXT_DEFAULT_REPLY \
    "HTTP/1.0 200 Ok\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace text {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::text::base::main_opt, 
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
      crlf2_endof_message_("\r\n\r\n"),
      default_message_(XOS_APP_CONSOLE_PROTOCOL_TEXT_DEFAULT_MESSAGE),
      message_(default_message_), 
      default_reply_(XOS_APP_CONSOLE_PROTOCOL_TEXT_DEFAULT_REPLY),
      reply_(default_reply_) {
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

    /// ...output_message_run
    virtual int output_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->message_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    /// ...output_reply_run
    virtual int output_reply_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        if ((chars = this->reply_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }

    /// ...option...
    int (derives::*on_set_message_option_)(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_message_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& message = this->message();
            if (on_set_message_option_) {
                err = (this->*on_set_message_option_)(message, optarg, optind, argc, argv, env);
            } else {
                err = file_on_set_string_text_message_option(message, optarg, optind, argc, argv, env);
            }
        }
        return err;
    }

    /// ...option...
    int (derives::*on_set_reply_option_)(string_t& reply, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_reply_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& reply = this->reply();
            if (on_set_reply_option_) {
                err = (this->*on_set_reply_option_)(reply, optarg, optind, argc, argv, env);
            } else {
                err = file_on_set_string_text_message_option(reply, optarg, optind, argc, argv, env);
            }
        }
        return err;
    }

    /// ...on_set_string_text_message_option
    virtual int file_on_set_string_text_message_option
    (string_t& message, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            xos::io::crt::file::char_reader file;

            LOGGER_IS_LOGGED_INFO("file.open(\""<< optarg <<"\")...");
            if ((file.open(optarg))) {
                xos::io::crt::file::char_reader::char_t c = 0;
                ssize_t amount = 0, count = 0;
                if (0 < (amount = file.read(&c, 1))) {
                    message.clear();
                    do {
                        char_t message_c = ((char_t)c);
                        message.append(&message_c, 1);
                        count += amount;
                    } while (0 < (amount = file.read(&c, 1)));
                }
                LOGGER_IS_LOGGED_INFO("...file.close(\""<< optarg <<"\")...");
                file.close();
            }
        }
        return err;
    }
    virtual int string_on_set_string_text_message_option
    (string_t& message, const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            message.assign(optarg);
        }
        return err;
    }

    /// set...on_set_message_option
    virtual int set_file_on_set_message_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_message_option_ = &derives::file_on_set_string_text_message_option;
        return err;
    }
    virtual int set_string_on_set_message_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_message_option_ = &derives::string_on_set_string_text_message_option;
        return err;
    }

    /// set...on_set_reply_option
    virtual int set_file_on_set_reply_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_reply_option_ = &derives::file_on_set_string_text_message_option;
        return err;
    }
    virtual int set_string_on_set_reply_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_reply_option_ = &derives::string_on_set_string_text_message_option;
        return err;
    }

    /// ...option...
    virtual int on_file_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_file_input_option_set(optarg, optind, argc, argv, env))) {
            if (!(err = set_file_on_set_message_option(argc, argv, env))) {
                if (!(err = set_file_on_set_reply_option(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_string_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_string_input_option_set(optarg, optind, argc, argv, env))) {
            if (!(err = set_string_on_set_message_option(argc, argv, env))) {
                if (!(err = set_string_on_set_reply_option(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    
    /// ...message...
    virtual const char_t* crlf2_endof_message_chars(size_t& length) const {
        string_t& message = this->crlf2_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars(length);
        return message_chars;
    }
    virtual const char_t* crlf2_endof_message_chars() const {
        string_t& message = this->crlf2_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars();
        return message_chars;
    }
    virtual string_t& crlf2_endof_message() const {
        string_t& message = (string_t&)crlf2_endof_message_;
        return message;
    }
    virtual const char_t* default_message_chars(size_t& length) const {
        string_t& message = this->default_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars(length);
        return message_chars;
    }
    virtual const char_t* default_message_chars() const {
        string_t& message = this->default_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars();
        return message_chars;
    }
    virtual string_t& default_message() const {
        string_t& message = (string_t&)default_message_;
        return message;
    }
    virtual string_t& set_message(const string_t& to) {
        string_t& message = this->message();
        message.assign(to);
        return message;
    }
    virtual string_t& set_message(const char_t* to) {
        string_t& message = this->message();
        message.assign(to);
        return message;
    }
    virtual string_t& set_message(const char_t* to, size_t length) {
        string_t& message = this->message();
        message.assign(to, length);
        return message;
    }
    virtual const char_t* message_chars(size_t& length) const {
        string_t& message = this->message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars(length);
        return message_chars;
    }
    virtual const char_t* message_chars() const {
        string_t& message = this->message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars();
        return message_chars;
    }
    virtual string_t& message() const {
        string_t& message = (string_t&)message_;
        return message;
    }

    /// ...reply...
    virtual const char_t* default_reply_chars(size_t& length) const {
        string_t& reply = this->default_reply();
        const char_t* reply_chars = 0;
        reply_chars = reply.has_chars(length);
        return reply_chars;
    }
    virtual const char_t* default_reply_chars() const {
        string_t& reply = this->default_reply();
        const char_t* reply_chars = 0;
        reply_chars = reply.has_chars();
        return reply_chars;
    }
    virtual string_t& default_reply() const {
        string_t& reply = (string_t&)default_reply_;
        return reply;
    }
    virtual string_t& set_reply(const string_t& to) {
        string_t& reply = this->reply();
        reply.assign(to);
        return reply;
    }
    virtual string_t& set_reply(const char_t* to) {
        string_t& reply = this->reply();
        reply.assign(to);
        return reply;
    }
    virtual string_t& set_reply(const char_t* to, size_t length) {
        string_t& reply = this->reply();
        reply.assign(to, length);
        return reply;
    }
    virtual const char_t* reply_chars(size_t& length) const {
        string_t& reply = this->reply();
        const char_t* reply_chars = 0;
        reply_chars = reply.has_chars(length);
        return reply_chars;
    }
    virtual const char_t* reply_chars() const {
        string_t& reply = this->reply();
        const char_t* reply_chars = 0;
        reply_chars = reply.has_chars();
        return reply_chars;
    }
    virtual string_t& reply() const {
        string_t& reply = (string_t&)reply_;
        return reply;
    }

protected:
    string_t crlf2_endof_message_, default_message_, message_, default_reply_, reply_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace text
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TEXT_BASE_MAIN_HPP
