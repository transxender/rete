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
///   Date: 10/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_BASE_MAIN_OPT_HPP

#include "xos/app/console/network/sockets/protocol/telnet/base/main.hpp"

#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPT "input-source"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_BRAY "bray"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_HDMI "hdmi"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG "[{ " \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_BRAY " | " \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_HDMI " | ... }]"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTUSE "input source"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTVAL_S "I::"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTVAL_C 'I'
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTION \
   {XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPT, \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPT "repeat-play"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_ALL "all"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_OFF "off"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_RANDOM "random"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_SHUFFLE "shuffle"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG "[{ " \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_ALL " | " \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_OFF " | " \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_RANDOM " | " \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_SHUFFLE " | ... }]"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTUSE "repeat play"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTVAL_S "R::"
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTVAL_C 'R'
#define XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTION \
   {XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPT, \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTVAL_C}, \

namespace xos {
namespace app {
namespace console {
namespace home {
namespace theater {
namespace oppo {
namespace player {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::network::sockets::protocol::telnet::base::main, 
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
    main_optt(): run_(0) {
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

    /// ...input_source_option...
    virtual int on_set_input_source_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_input_source_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_input_source_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_input_source_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_input_source_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* input_source_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_INPUT_SOURCE_OPTARG;
        return chars;
    }

    /// ...repeat_play_option...
    virtual int on_set_repeat_play_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_repeat_play_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_repeat_play_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_repeat_play_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_repeat_play_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* repeat_play_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_MAIN_REPEAT_PLAY_OPTARG;
        return chars;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace player
} /// namespace oppo
} /// namespace theater
} /// namespace home
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_HOME_THEATER_OPPO_PLAYER_BASE_MAIN_OPT_HPP
