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
#ifndef XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_BASE_MAIN_HPP

#include "xos/app/console/home/theater/marantz/audio/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace home {
namespace theater {
namespace marantz {
namespace audio {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::home::theater::marantz::audio::base::main_opt, 
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
      cd_input_("SICD"), dvd_input_("SIDVD"), bd_input_("SIBD"), select_input_("SI"), input_("SI?"),
      surround_sound_("MSDOLBY DIGITAL"), stereo_sound_("MSSTEREO"), select_sound_("MS"), sound_("MS?"),
      volume_up_("MVUP"), volume_down_("MVDOWN"), volume_level_("MV"), volume_("MV?"),
      power_off_("PWSTANDBY"), power_on_("PWON"), power_state_("PW"), power_("PW?") {
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

    //// ...cd_input_option...
    virtual int on_set_cd_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->cd_input_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...dvd_input_option...
    virtual int on_set_dvd_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->dvd_input_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...bd_input_option...
    virtual int on_set_bd_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->bd_input_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...input_option...
    virtual int on_set_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        if ((optarg) && (optarg[0])) {
            const char_t* null_optarg = 0;
            string_t opt(optarg);
            if ((0 == opt.uncased_compare(XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_MAIN_INPUT_OPTARG_CD))) {
                return on_set_cd_input_option(null_optarg, optind, argc, argv, env);
            } else {
                if ((0 == opt.uncased_compare(XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_MAIN_INPUT_OPTARG_DVD))) {
                    return on_set_dvd_input_option(null_optarg, optind, argc, argv, env);
                } else {
                    if ((0 == opt.uncased_compare(XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_MAIN_INPUT_OPTARG_BD))) {
                        return on_set_bd_input_option(null_optarg, optind, argc, argv, env);
                    } else {
                    }
                }
            }
            request.assign(this->select_input_);
        } else {
            request.assign(this->input_);
        }
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }

    //// ...surround_sound_option...
    virtual int on_set_surround_sound_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->surround_sound_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...stereo_sound_option...
    virtual int on_set_stereo_sound_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->stereo_sound_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...sound_option...
    virtual int on_set_sound_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        if ((optarg) && (optarg[0])) {
            const char_t* null_optarg = 0;
            string_t opt(optarg);
            if ((0 == opt.uncased_compare(XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_MAIN_SOUND_OPTARG_STEREO))) {
                return on_set_stereo_sound_option(null_optarg, optind, argc, argv, env);
            } else {
                if ((0 == opt.uncased_compare(XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_MAIN_SOUND_OPTARG_SURROUND))) {
                    return on_set_surround_sound_option(null_optarg, optind, argc, argv, env);
                } else {
                }
            }
            request.assign(this->select_sound_);
        } else {
            request.assign(this->sound_);
        }
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }

    /// ...volume_up_option...
    virtual int on_set_volume_up_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->volume_up_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...volume_down_option...
    virtual int on_set_volume_down_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        request.assign(this->volume_down_);
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }
    /// ...volume_option...
    virtual int on_set_volume_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        if ((optarg) && (optarg[0])) {
            request.assign(this->volume_level_);
        } else {
            request.assign(this->volume_);
        }
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }

    /// ...power_on_option...
    virtual int on_set_power_on_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            string_t& request = this->request();
            request.assign(this->power_on_);
            if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
            }
        }
        return err;
    }
    /// ...power_off_option...
    virtual int on_set_power_off_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            string_t& request = this->request();
            request.assign(this->power_off_);
            if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
            }
        }
        return err;
    }
    /// ...power_option...
    virtual int on_set_power_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        string_t& request = this->request();
        if ((optarg) && (optarg[0])) {
            request.assign(this->power_state_);
        } else {
            request.assign(this->power_);
        }
        if (!(err = this->on_set_request_optarg(request, optarg, optind, argc, argv, env))) {
        }
        return err;
    }

protected:
    string_t cd_input_, dvd_input_, bd_input_, select_input_, input_;
    string_t surround_sound_, stereo_sound_, select_sound_, sound_;
    string_t volume_up_, volume_down_, volume_level_, volume_;
    string_t power_off_, power_on_, power_state_, power_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace audio
} /// namespace marantz
} /// namespace theater
} /// namespace home
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_HOME_THEATER_MARANTZ_AUDIO_BASE_MAIN_HPP
