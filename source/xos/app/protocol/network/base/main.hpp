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
///   Date: 3/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_PROTOCOL_NETWORK_BASE_MAIN_HPP
#define XOS_APP_PROTOCOL_NETWORK_BASE_MAIN_HPP

#include "xos/app/protocol/base/main.hpp"

namespace xos {
namespace app {
namespace protocol {
namespace network {
namespace base {

/// class maint
template 
<class TExtends = xos::app::protocol::base::maint<>,  class TImplements = typename TExtends::implements>

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
      accept_one_(false), accept_restart_(false), accept_stop_(false), 
      cr_endof_message_("\r"), lf_endof_message_("\n"), 
      crlf_endof_message_("\r\n"), crlf2_endof_message_("\r\n\r\n") {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }
public:

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

    //////////////////////////////////////////////////////////////////////////

    /// ...send_request_run
    virtual int send_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &request = this->request();

        LOGGER_IS_LOGGED_INFO("all_send_request_run(request, argc, argv, env)...");
        if (!(err = all_send_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_send_request_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_send_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request_run(argc, argv, env))) {
            int err2 = 0;
            err = send_request_run(argc, argv, env);
            if ((err2 = after_send_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_send_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_send_request_run;
        return err;
    }
    virtual int send_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_send_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int send_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...receive_request_run
    virtual int receive_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &request = this->request();

        LOGGER_IS_LOGGED_INFO("all_receive_request_run(request, argc, argv, env)...");
        if (!(err = all_receive_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_receive_request_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_receive_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_request_run(argc, argv, env))) {
            int err2 = 0;
            err = receive_request_run(argc, argv, env);
            if ((err2 = after_receive_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_receive_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_receive_request_run;
        return err;
    }
    virtual int receive_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_receive_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int receive_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...send_response_run
    virtual int send_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &response = this->response();

        LOGGER_IS_LOGGED_INFO("all_send_response_run(response, argc, argv, env)...");
        if (!(err = all_send_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_send_response_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_send_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response_run(argc, argv, env))) {
            int err2 = 0;
            err = send_response_run(argc, argv, env);
            if ((err2 = after_send_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_send_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_send_response_run;
        return err;
    }
    virtual int send_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_send_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int send_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...receive_response_run
    virtual int receive_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &response = this->response();

        LOGGER_IS_LOGGED_INFO("all_receive_response_run(response, argc, argv, env)...");
        if (!(err = all_receive_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_receive_response_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_receive_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_response_run(argc, argv, env))) {
            int err2 = 0;
            err = receive_response_run(argc, argv, env);
            if ((err2 = after_receive_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_receive_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_receive_response_run;
        return err;
    }
    virtual int receive_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_receive_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int receive_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...send_request_run
    virtual int send_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_output_request_run(request, argc, argv, env)...");
        if (!(err = all_output_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_output_request_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_send_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_request_to_send_run(request, argc, argv, env)...");
        if (!(err = all_prepare_request_to_send_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_request_to_send_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int after_send_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = send_request_run(request, argc, argv, env);
            if ((err2 = after_send_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...receive_request_run
    virtual int receive_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_request_received_run(request, argc, argv, env)...");
        if (!(err = all_prepare_request_received_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_request_received_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_receive_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_received_request_run(request, argc, argv, env)...");
        if (!(err = all_received_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_received_request_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int all_receive_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = receive_request_run(request, argc, argv, env);
            if ((err2 = after_receive_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...received_request_run
    virtual int received_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->all_process_request_run(request, argc, argv, env)...");
        if (!(err = this->all_process_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...this->all_process_request_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_received_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_received_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_request_received_run(request, argc, argv, env)...");
        if (!(err = all_process_request_received_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_request_received_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int all_received_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_received_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = received_request_run(request, argc, argv, env);
            if ((err2 = after_received_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...output_request_run
    virtual int output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_output_message_run(request, argc, argv, env)...");
        if (!(err = all_output_message_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_output_message_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int before_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_request_to_output_run(request, argc, argv, env)...");
        if (!(err = all_prepare_request_to_output_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_request_to_output_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int after_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = output_request_run(request, argc, argv, env);
            if ((err2 = after_output_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...send_response_run
    virtual int send_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_output_response_run(response, argc, argv, env)...");
        if (!(err = all_output_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_output_response_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_send_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_response_to_send_run(response, argc, argv, env)...");
        if (!(err = all_prepare_response_to_send_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_response_to_send_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int after_send_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = send_response_run(response, argc, argv, env);
            if ((err2 = after_send_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...receive_response_run
    virtual int receive_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_response_received_run(response, argc, argv, env)...");
        if (!(err = all_prepare_response_received_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_response_received_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_receive_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_received_response_run(response, argc, argv, env)...");
        if (!(err = all_received_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_received_response_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int all_receive_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = receive_response_run(response, argc, argv, env);
            if ((err2 = after_receive_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...received_response_run
    virtual int received_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->all_process_response_run(response, argc, argv, env)...");
        if (!(err = this->all_process_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...this->all_process_response_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_received_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_response_received_run(response, argc, argv, env)...");
        if (!(err = all_process_response_received_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_response_received_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int after_received_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_received_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_received_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = received_response_run(response, argc, argv, env);
            if ((err2 = after_received_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...output_response_run
    virtual int output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_output_message_run(response, argc, argv, env)...");
        if (!(err = all_output_message_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_output_message_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int before_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_response_to_output_run(response, argc, argv, env)...");
        if (!(err = all_prepare_response_to_output_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_response_to_output_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int after_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = output_response_run(response, argc, argv, env);
            if ((err2 = after_output_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...prepare_request_to_send_run
    virtual int prepare_request_to_send_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request_to_send_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_to_send_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_message_to_send_run(request, argc, argv, env)...");
        if (!(err = all_prepare_message_to_send_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_message_to_send_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int all_prepare_request_to_send_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_to_send_run(request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_to_send_run(request, argc, argv, env);
            if ((err2 = after_prepare_request_to_send_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...prepare_request_received_run
    virtual int prepare_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_message_received_run(request, argc, argv, env)...");
        if (!(err = all_prepare_message_received_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_message_received_run(request, argc, argv, env)");
        }
        return err;
    }
    virtual int all_prepare_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_received_run(request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_received_run(request, argc, argv, env);
            if ((err2 = after_prepare_request_received_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_request_received_run
    virtual int process_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_message_received_run...");
        if (!(err = all_process_message_received_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_message_received_run");
        }
        return err;
    }
    virtual int after_process_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_received_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request_received_run(request, argc, argv, env))) {
            int err2 = 0;
            err = process_request_received_run(request, argc, argv, env);
            if ((err2 = after_process_request_received_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...prepare_request_to_output_run
    virtual int prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_to_output_run(request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_to_output_run(request, argc, argv, env);
            if ((err2 = after_prepare_request_to_output_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...prepare_response_to_send_run
    virtual int prepare_response_to_send_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_send_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_send_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_message_to_send_run(response, argc, argv, env)...");
        if (!(err = all_prepare_message_to_send_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_message_to_send_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int all_prepare_response_to_send_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_send_run(response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_send_run(response, argc, argv, env);
            if ((err2 = after_prepare_response_to_send_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...prepare_response_received_run
    virtual int prepare_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_message_received_run(response, argc, argv, env)...");
        if (!(err = all_prepare_message_received_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_message_received_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int all_prepare_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_received_run(response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_received_run(response, argc, argv, env);
            if ((err2 = after_prepare_response_received_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_response_received_run
    virtual int process_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_message_received_run(response, argc, argv, env)...");
        if (!(err = all_process_message_received_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_message_received_run(response, argc, argv, env)");
        }
        return err;
    }
    virtual int after_process_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_received_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_received_run(response, argc, argv, env))) {
            int err2 = 0;
            err = process_response_received_run(response, argc, argv, env);
            if ((err2 = after_process_response_received_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...prepare_response_to_output_run
    virtual int prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_output_run(response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_output_run(response, argc, argv, env);
            if ((err2 = after_prepare_response_to_output_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...send_message_run
    virtual int send_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_send_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_message_to_send_run(message, argc, argv, env)...");
        if (!(err = all_prepare_message_to_send_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_message_to_send_run(message, argc, argv, env)");
        }
        return err;
    }
    virtual int after_send_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_message_run(message, argc, argv, env))) {
            int err2 = 0;
            err = send_message_run(message, argc, argv, env);
            if ((err2 = after_send_message_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...receive_message_run
    virtual int receive_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_receive_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_message_received_run(message, argc, argv, env)...");
        if (!(err = all_process_message_received_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_message_received_run(message, argc, argv, env)");
        }
        return err;
    }
    virtual int all_receive_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_message_run(message, argc, argv, env))) {
            int err2 = 0;
            err = receive_message_run(message, argc, argv, env);
            if ((err2 = after_receive_message_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...prepare_message_to_send_run
    virtual int prepare_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_crlf2_message_to_send_run(message, argc, argv, env)...");
        if (!(err = all_prepare_crlf2_message_to_send_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_crlf2_message_to_send_run(message, argc, argv, env)");
        }
        return err;
    }
    virtual int all_prepare_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_to_send_run(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_to_send_run(message, argc, argv, env);
            if ((err2 = after_prepare_message_to_send_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...prepare_message_received_run
    virtual int prepare_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_prepare_crlf2_message_received_run(message, argc, argv, env)...");
        if (!(err = all_prepare_crlf2_message_received_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_prepare_crlf2_message_received_run(message, argc, argv, env)");
        }
        return err;
    }
    virtual int before_prepare_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_received_run(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_received_run(message, argc, argv, env);
            if ((err2 = after_prepare_message_received_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_message_sent_run
    virtual int process_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_crlf2_message_sent_run(message, argc, argv, env)...");
        if (!(err = all_process_crlf2_message_sent_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_crlf2_message_sent_run(message, argc, argv, env)");
        }
        return err;
    }
    virtual int before_process_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_message_sent_run(message, argc, argv, env))) {
            int err2 = 0;
            err = process_message_sent_run(message, argc, argv, env);
            if ((err2 = after_process_message_sent_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_message_received_run
    virtual int process_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("all_process_crlf2_message_received_run(message, argc, argv, env)...");
        if (!(err = all_process_crlf2_message_received_run(message, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...all_process_crlf2_message_received_run(message, argc, argv, env)");
        }
        return err;
    }
    virtual int after_process_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_message_received_run(message, argc, argv, env))) {
            int err2 = 0;
            err = process_message_received_run(message, argc, argv, env);
            if ((err2 = after_process_message_received_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// append crlf2_endof_message
    /// ...
    /// ...prepare_crlf2_message_to_send_run
    virtual int prepare_crlf2_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& crlf2_endof_message = this->crlf2_endof_message();
        string_t& message_to_send =  message;

        LOGGER_IS_LOGGED_INFO("message.append(crlf2_endof_message = \"" << crlf2_endof_message << "\")...");
        message_to_send.append(crlf2_endof_message);
        LOGGER_IS_LOGGED_INFO("...\"" << message_to_send << "\" = message.append(crlf2_endof_message = \"" << crlf2_endof_message << "\")");
        return err;
    }
    virtual int before_prepare_crlf2_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_crlf2_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_crlf2_message_to_send_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_crlf2_message_to_send_run(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_crlf2_message_to_send_run(message, argc, argv, env);
            if ((err2 = after_prepare_crlf2_message_to_send_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...prepare_crlf2_message_received_run
    virtual int prepare_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_prepare_crlf2_message_to_send_run(message, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_prepare_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_crlf2_message_received_run(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_crlf2_message_received_run(message, argc, argv, env);
            if ((err2 = after_prepare_crlf2_message_received_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// append crlf2_endof_message
    
    /// remove crlf2_endof_message
    /// ...
    /// ...process_crlf2_message_sent_run
    virtual int process_crlf2_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_process_crlf2_message_received_run(message, argc, argv, env))) {
        }
        return err;
    }
    virtual int before_process_crlf2_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_crlf2_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_crlf2_message_sent_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_crlf2_message_sent_run(message, argc, argv, env))) {
            int err2 = 0;
            err = process_crlf2_message_sent_run(message, argc, argv, env);
            if ((err2 = after_process_crlf2_message_sent_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...process_crlf2_message_received_run
    virtual int process_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& crlf2_endof_message = this->crlf2_endof_message();
        size_t crlf2_endof_message_length = crlf2_endof_message.length(), message_length = message.length();

        if ((message_length > crlf2_endof_message_length)) {
            const char_t* message_chars = message.chars();
            string_t endof_message(message_chars + (message_length - crlf2_endof_message_length));
            int unequal = 0;
            
            LOGGER_IS_LOGGED_INFO("!(unequal = crlf2_endof_message.compare(endof_message = \"" << endof_message << "\"))...");
            if (!(unequal = crlf2_endof_message.compare(endof_message))) {
                string_t process_message(message_chars, message_length - crlf2_endof_message_length);
                
                LOGGER_IS_LOGGED_INFO("...!(" << unequal << " = crlf2_endof_message.compare(endof_message = \"" << endof_message << "\"))");
                message.assign(process_message);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << unequal << " = crlf2_endof_message.compare(endof_message = \"" << endof_message << "\"))");                
            }

        }
        return err;
    }
    virtual int before_process_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_crlf2_message_received_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_crlf2_message_received_run(message, argc, argv, env))) {
            int err2 = 0;
            err = process_crlf2_message_received_run(message, argc, argv, env);
            if ((err2 = after_process_crlf2_message_received_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// remove crlf2_endof_message

    //////////////////////////////////////////////////////////////////////////

    /// ...output_message_run
    virtual int output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        
        if ((chars = message.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int before_output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_run(message, argc, argv, env))) {
            int err2 = 0;
            err = output_message_run(message, argc, argv, env);
            if ((err2 = after_output_message_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...output_message_hex_run
    virtual int output_message_hex_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = message.has_chars(length))) {
            this->outxln(chars, length);
        }
        return err;
    }
    virtual int before_output_message_hex_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_message_hex_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_hex_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_hex_run(message, argc, argv, env))) {
            int err2 = 0;
            err = output_message_hex_run(message, argc, argv, env);
            if ((err2 = after_output_message_hex_run(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////

    /// ...accept_one
    virtual bool& set_accept_one(const bool& to) {
        bool& accept_one = this->accept_one();
        accept_one = to;
        return accept_one;
    }
    virtual const bool& get_accept_one() const {
        return this->accept_one();
    }
    virtual bool& accept_one() const {
        bool& accept_one = (bool&)accept_one_;
        return accept_one;
    }

    /// ...accept_restart
    virtual bool& set_accept_restart(const bool& to) {
        bool& accept_restart = this->accept_restart();
        accept_restart = to;
        return accept_restart;
    }
    virtual const bool& get_accept_restart() const {
        return this->accept_restart();
    }
    virtual bool& accept_restart() const {
        bool& accept_restart = (bool&)accept_restart_;
        return accept_restart;
    }

    /// ...accept_stop
    virtual bool& set_accept_stop(const bool& to) {
        bool& accept_stop = this->accept_stop();
        accept_stop = to;
        return accept_stop;
    }
    virtual const bool& get_accept_stop() const {
        return this->accept_stop();
    }
    virtual bool& accept_stop() const {
        bool& accept_stop = (bool&)accept_stop_;
        return accept_stop;
    }

    /// ...restart...
    virtual bool& restart_set(const bool& to) {
        bool& restart = accept_restart();
        if ((to)) {
            if ((set_accept_stop(true))) {
                if ((set_accept_restart(true))) {
                }
            }
        }
        return restart;
    }
    /// ...stop...
    virtual bool& stop_set(const bool& to) {
        bool& stop = accept_stop();
        if ((to)) {
            if ((set_accept_stop(true))) {
                if (!(set_accept_restart(false))) {
                }
            }
        }
        return stop;
    }

    /// ...endof_message...
    virtual const char_t* cr_endof_message_chars(size_t& length) const {
        string_t& message = this->cr_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars(length);
        return message_chars;
    }
    virtual const char_t* cr_endof_message_chars() const {
        string_t& message = this->cr_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars();
        return message_chars;
    }
    virtual string_t& cr_endof_message() const {
        string_t& message = (string_t&)cr_endof_message_;
        return message;
    }

    /// ...endof_message...
    virtual const char_t* lf_endof_message_chars(size_t& length) const {
        string_t& message = this->lf_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars(length);
        return message_chars;
    }
    virtual const char_t* lf_endof_message_chars() const {
        string_t& message = this->lf_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars();
        return message_chars;
    }
    virtual string_t& lf_endof_message() const {
        string_t& message = (string_t&)lf_endof_message_;
        return message;
    }

    /// ...endof_message...
    virtual const char_t* crlf_endof_message_chars(size_t& length) const {
        string_t& message = this->crlf_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars(length);
        return message_chars;
    }
    virtual const char_t* crlf_endof_message_chars() const {
        string_t& message = this->crlf_endof_message();
        const char_t* message_chars = 0;
        message_chars = message.has_chars();
        return message_chars;
    }
    virtual string_t& crlf_endof_message() const {
        string_t& message = (string_t&)crlf_endof_message_;
        return message;
    }

    /// ...endof_message...
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

protected:
    bool accept_one_, accept_restart_, accept_stop_;
    string_t cr_endof_message_, lf_endof_message_, 
             crlf_endof_message_, crlf2_endof_message_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace network 
} /// namespace protocol 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_PROTOCOL_NETWORK_BASE_MAIN_HPP
