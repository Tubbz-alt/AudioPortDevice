#include "AudioPortDevice_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the device class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

AudioPortDevice_base::AudioPortDevice_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl)
{
    construct();
}

AudioPortDevice_base::AudioPortDevice_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, char *compDev) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl, compDev)
{
    construct();
}

AudioPortDevice_base::AudioPortDevice_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, CF::Properties capacities) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl, capacities)
{
    construct();
}

AudioPortDevice_base::AudioPortDevice_base(char *devMgr_ior, char *id, char *lbl, char *sftwrPrfl, CF::Properties capacities, char *compDev) :
    Device_impl(devMgr_ior, id, lbl, sftwrPrfl, capacities, compDev)
{
    construct();
}

AudioPortDevice_base::~AudioPortDevice_base()
{
    audio_alertalarm_wf_provides_port->_remove_ref();
    audio_alertalarm_wf_provides_port = 0;
    audio_sample_stream_ctrl_provides_port->_remove_ref();
    audio_sample_stream_ctrl_provides_port = 0;
    audio_sample_stream_provides_port->_remove_ref();
    audio_sample_stream_provides_port = 0;
    audio_sample_msg_ctrl_provides_port->_remove_ref();
    audio_sample_msg_ctrl_provides_port = 0;
    audio_ptt_uses_port->_remove_ref();
    audio_ptt_uses_port = 0;
    audio_sample_stream_ctrl_uses_port->_remove_ref();
    audio_sample_stream_ctrl_uses_port = 0;
    audio_sample_stream_uses_port->_remove_ref();
    audio_sample_stream_uses_port = 0;
}

void AudioPortDevice_base::construct()
{
    loadProperties();

    audio_alertalarm_wf_provides_port = new Audio_AudibleAlertsAndAlarms_In_i("audio_alertalarm_wf_provides_port", this);
    addPort("audio_alertalarm_wf_provides_port", "Is provided by the Audio Port Device to control the alert and alarm tones by waveform.", audio_alertalarm_wf_provides_port);
    audio_sample_stream_ctrl_provides_port = new Audio_SampleStreamControl_In_i("audio_sample_stream_ctrl_provides_port", this);
    addPort("audio_sample_stream_ctrl_provides_port", "Is provided by the Audio Port Device to set the payload size by the Device User.", audio_sample_stream_ctrl_provides_port);
    audio_sample_stream_provides_port = new Audio_SampleStream_In_i("audio_sample_stream_provides_port", this);
    addPort("audio_sample_stream_provides_port", "Is provided by the Audio Port Device to consume packets through the pushPacket operation.", audio_sample_stream_provides_port);
    audio_sample_msg_ctrl_provides_port = new Audio_SampleMessageControl_In_i("audio_sample_msg_ctrl_provides_port", this);
    addPort("audio_sample_msg_ctrl_provides_port", "Is provided by the Audio Port Device to manage the message flows.", audio_sample_msg_ctrl_provides_port);
    audio_ptt_uses_port = new Audio_AudioPTT_Signal_Out_i("audio_ptt_uses_port", this);
    addPort("audio_ptt_uses_port", "Is used to by the Audio Port Device to notify the Device User of PTT signal.", audio_ptt_uses_port);
    audio_sample_stream_ctrl_uses_port = new Audio_SampleStreamControl_Out_i("audio_sample_stream_ctrl_uses_port", this);
    addPort("audio_sample_stream_ctrl_uses_port", "is used by the Audio Port Device to set the payload size of the incoming packets from the Device User.", audio_sample_stream_ctrl_uses_port);
    audio_sample_stream_uses_port = new Audio_SampleStream_Out_i("audio_sample_stream_uses_port", this);
    addPort("audio_sample_stream_uses_port", "Is used by the Audio Port Device to push packets to the Device User.", audio_sample_stream_uses_port);

}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void AudioPortDevice_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Device_impl::start();
}

void AudioPortDevice_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Device_impl::stop();
}

void AudioPortDevice_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the device running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Device_impl::releaseObject();
}

void AudioPortDevice_base::loadProperties()
{
    addProperty(device_kind,
                "AUDIO",
                "DCE:cdc5ee18-7ceb-4ae6-bf4c-31f983179b4d",
                "device_kind",
                "readonly",
                "",
                "eq",
                "allocation");

    addProperty(device_model,
                "ALSA",
                "DCE:0f99b2e4-9903-4631-9846-ff349d18ecfb",
                "device_model",
                "readonly",
                "",
                "eq",
                "allocation");

    addProperty(ptt_device,
                "/dev/input/event2",
                "ptt_device",
                "ptt_device",
                "readonly",
                "",
                "external",
                "property");

    addProperty(capture_sample_rate,
                16000,
                "capture_sample_rate",
                "capture_sample_rate",
                "readwrite",
                "Hz",
                "external",
                "property");

    addProperty(capture_card,
                "capture_card",
                "capture_card",
                "readonly",
                "",
                "external",
                "property");

    addProperty(capture_volume,
                75,
                "capture_volume",
                "capture_volume",
                "readwrite",
                "%",
                "external",
                "property");

    addProperty(capture_mixer_control,
                "capture_mixer_control",
                "capture_mixer_control",
                "readwrite",
                "",
                "external",
                "property");

    addProperty(playback_sample_rate,
                16000,
                "playback_sample_rate",
                "playback_sample_rate",
                "readwrite",
                "Hz",
                "external",
                "property");

    addProperty(playback_card,
                "playback_card",
                "playback_card",
                "readonly",
                "",
                "external",
                "property");

    addProperty(playback_volume,
                75,
                "playback_volume",
                "playback_volume",
                "readwrite",
                "%",
                "external",
                "property");

    addProperty(playback_mixer_control,
                "playback_mixer_control",
                "playback_mixer_control",
                "readwrite",
                "",
                "external",
                "property");

}


