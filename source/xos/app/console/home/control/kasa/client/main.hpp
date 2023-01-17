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
///   Date: 11/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_HOME_CONTROL_KASA_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_HOME_CONTROL_KASA_CLIENT_MAIN_HPP

#include "xos/app/console/home/control/kasa/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace home {
namespace control {
namespace kasa {
namespace client {

/// class maint
template 
<class TExtends = xos::app::console::home::control::kasa::client::main_opt, 
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

    /// ...send_request
    virtual int before_send_request
    (xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t**env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        const string_t &plain_text = request;

        LOGGER_IS_LOGGED_INFO("(chars = plain_text.has_chars(length))...");
        if ((chars = plain_text.has_chars(length))) {
            string_t &encrypt_text = this->encrypt_text(plain_text);
            
            LOGGER_IS_LOGGED_INFO("...(chars = plain_text.has_chars(length = " << unsigned_to_string(length) << ")) = \"" << chars << "\"");
            LOGGER_IS_LOGGED_INFO("(chars = encrypt_text.has_chars(length))...");
            if ((chars = encrypt_text.has_chars(length))) {

                LOGGER_IS_LOGGED_INFO("...(chars = encrypt_text.has_chars(length = " << unsigned_to_string(length) << "))...");
                LOGGER_IS_LOGGED_INFO("request.assign(chars, length = " << unsigned_to_string(length) << ")...");
                request.assign(chars, length);
            }
        }
        return err;
    }

    /// ...process_response
    virtual int before_process_response
    (string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        const string_t &cipher_text = response;

        LOGGER_IS_LOGGED_INFO("(chars = cipher_text.has_chars(length))...");
        if ((chars = cipher_text.has_chars(length))) {
            const string_t& decrypt_text = this->decrypt_text(cipher_text);

            LOGGER_IS_LOGGED_INFO("...(chars = cipher_text.has_chars(length = " << unsigned_to_string(length) << "))");
            LOGGER_IS_LOGGED_INFO("(chars = decrypt_text.has_chars(length))...");
            if ((chars = decrypt_text.has_chars(length))) {

                LOGGER_IS_LOGGED_INFO("(chars = decrypt_text.has_chars(length = " << unsigned_to_string(length) << ")) = \"" << chars << "\"");
                LOGGER_IS_LOGGED_INFO("response.assign(chars, length = " << unsigned_to_string(length) << ")...");
                response.assign(chars, length);
                LOGGER_IS_LOGGED_INFO("response.appendln()...");
                response.appendln();
            }
        }
        return err;
    }

    /// ...recv_response
    virtual int recv_response
    (string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        char_t c = 0;

        response.clear();
        if (!(err = this->recv_sizeof_sized_crlf2(4, response, c, cn, argc, argv, env))) {
            err = this->all_process_response(response, cn, argc, argv, env);
        }
        return err;
    }

protected:
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace kasa
} /// namespace control
} /// namespace home
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_HOME_CONTROL_KASA_CLIENT_MAIN_HPP
