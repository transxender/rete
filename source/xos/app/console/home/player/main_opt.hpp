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
#ifndef XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPT_HPP

#include "xos/app/console/home/base/main_opt.hpp"

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPT "next-track"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTARG "[{ 0..n }]"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTUSE "next track"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTVAL_S "X::"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTVAL_C 'X'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPT "previous-track"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTARG "[{ 0..n }]"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTUSE "previous track"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTVAL_S "E::"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTVAL_C 'E'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPT "track"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTARG "[{ 0..n }]"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTUSE "track"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTVAL_S "K::"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTVAL_C 'K'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPT "start-play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTARG ""
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTUSE "start play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTVAL_S "S"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTVAL_C 'S'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPT "stop-play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTARG ""
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTUSE "stop play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTVAL_S "T"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTVAL_C 'T'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPT "pause-play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTARG ""
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTUSE "pause play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTVAL_S "A"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTVAL_C 'A'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPT "resume-play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTARG ""
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTUSE "resume play"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTVAL_S "U"
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTVAL_C 'U'
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTION \
   {XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTVAL_S \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTVAL_S \

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTION \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTION \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTION \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTION \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTION \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTION \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_HOME_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_HOME_BASE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_HOME_PLAYER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace home {
namespace player {

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

    /// ...next_track_option...
    virtual int on_set_next_track_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_next_track_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_next_track_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_next_track_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_next_track_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* next_track_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTARG;
        return chars;
    }

    /// ...previous_track_option...
    virtual int on_set_previous_track_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_previous_track_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_previous_track_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_previous_track_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_previous_track_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* previous_track_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTARG;
        return chars;
    }

    /// ...track_option...
    virtual int on_set_track_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_track_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_track_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_track_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_track_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* track_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTARG;
        return chars;
    }

    /// ...start_play_option...
    virtual int on_set_start_play_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_start_play_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_start_play_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_start_play_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_start_play_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* start_play_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTARG;
        return chars;
    }

    /// ...stop_play_option...
    virtual int on_set_stop_play_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_stop_play_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_stop_play_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_stop_play_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_stop_play_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* stop_play_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTARG;
        return chars;
    }

    /// ...pause_play_option...
    virtual int on_set_pause_play_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_pause_play_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_pause_play_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_pause_play_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_pause_play_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* pause_play_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTARG;
        return chars;
    }

    /// ...resume_play_option...
    virtual int on_set_resume_play_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_resume_play_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_resume_play_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_resume_play_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_resume_play_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* resume_play_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTUSE;
        optarg = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTVAL_C:
            err = this->on_next_track_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTVAL_C:
            err = this->on_previous_track_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTVAL_C:
            err = this->on_track_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTVAL_C:
            err = this->on_start_play_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTVAL_C:
            err = this->on_stop_play_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTVAL_C:
            err = this->on_pause_play_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTVAL_C:
            err = this->on_resume_play_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_NEXT_TRACK_OPTVAL_C:
            chars = this->next_track_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PREVIOUS_TRACK_OPTVAL_C:
            chars = this->previous_track_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_TRACK_OPTVAL_C:
            chars = this->track_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_START_PLAY_OPTVAL_C:
            chars = this->start_play_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_STOP_PLAY_OPTVAL_C:
            chars = this->stop_play_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_PAUSE_PLAY_OPTVAL_C:
            chars = this->pause_play_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_HOME_PLAYER_MAIN_RESUME_PLAY_OPTVAL_C:
            chars = this->resume_play_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_HOME_PLAYER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_HOME_PLAYER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

}; /// class main_optt

} /// namespace player
} /// namespace home
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_HOME_PLAYER_MAIN_OPT_HPP
