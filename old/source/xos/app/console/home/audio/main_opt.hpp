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
///   Date: 10/23/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPT_HPP

#include "xos/app/console/home/base/main_opt.hpp"

#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPT "volume-up"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTARG "[{ 0..100 }]"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTUSE "volume up"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTVAL_S "U::"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTVAL_C 'U'
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTION \
   {XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPT, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPT "volume-down"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTARG "[{ 0..100 }]"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTUSE "volume down"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTVAL_S "D::"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTVAL_C 'D'
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTION \
   {XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPT, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPT "volume"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTARG "[{ 0..100 }]"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTUSE "volume level"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTVAL_S "V::"
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTVAL_C 'V'
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTION \
   {XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPT, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTVAL_S \

#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTION \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTION \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_HOME_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_HOME_BASE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_ARGS 0
#define XOS_APP_CONSOLE_HOME_AUDIO_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace home {
namespace audio {

/// class main_optt
template 
<class TExtends = xos::app::console::home::base::main_optt<>, 
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
    main_optt(const main_optt &copy) {
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

    /// ...volume_up_option...
    virtual int on_set_volume_up_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_volume_up_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_volume_up_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_volume_up_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_volume_up_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* volume_up_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTARG;
        return chars;
    }

    /// ...volume_down_option...
    virtual int on_set_volume_down_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_volume_down_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_volume_down_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_volume_down_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_volume_down_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* volume_down_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTARG;
        return chars;
    }

    /// ...volume_option...
    virtual int on_set_volume_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_volume_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_volume_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_volume_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_volume_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* volume_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTVAL_C:
            err = this->on_volume_up_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTVAL_C:
            err = this->on_volume_down_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTVAL_C:
            err = this->on_volume_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_UP_OPTVAL_C:
            chars = this->volume_up_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_DOWN_OPTVAL_C:
            chars = this->volume_down_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_AUDIO_MAIN_VOLUME_OPTVAL_C:
            chars = this->volume_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_HOME_AUDIO_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_HOME_AUDIO_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

}; /// class main_optt

} /// namespace audio
} /// namespace home
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_HOME_AUDIO_MAIN_OPT_HPP
