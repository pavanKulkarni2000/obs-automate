#include <QApplication>
#include <QPushButton>
#include <string>
#include <unistd.h>
#include "Trace.hpp"
#include "obs/obs.h"
#include "ObsUtils.hpp"
#include "Encoder.hpp"
#include "Show.hpp"
#include "Scene.hpp"
#include "Source.hpp"

#define app_output_file "/data/sample/app3.mkv"

using namespace std;

int gTraceLevel = TRACE_LEVEL_TRACE;
int gTraceFormat = TRACE_FORMAT_TEXT;

int main(int argc, char *argv[]) {
    // if(argc < 3) {
    //     cout << "Usage: ./scene_switch_app <file1> <file2>";
    //     exit(1);
    // }
    string url="https://www.google.com/";
    string show_name="browserSource";
    obs_output_t*   output;
	obs_data_t*     ffmpeg_mux_settings;
    
	QApplication app(argc, argv);
	ObsInit();

    // Create a file source
    SourceParams sourceParams = {
        .name = "browser_source",
        .sourceType = BrowserUrl,
        .url = url
    };
    SceneParams  sceneParams = {
        .name = "scene"
    };
    Source *source = new Source(&sourceParams); 
    Scene *scene = new Scene(&sceneParams);

    Show *show = new Show(show_name);
    struct vec2 bounds = {1920, 1080};
    scene->AddSource(source,  &bounds);
    show->AddScene(scene);
    show->SetActiveScene("scene");



    // //============= Create encoders ========================
    Encoder *encoder = new Encoder();
    VideoEncParams videoParams = {
        .encoder_type = "obs_x264",
        .bitrate = 4000,
        .keyint_sec = 1,
        .rate_control = "CBR",
        .width = 1920,
        .height = 1080,
        .fps_num = 25,
        .fps_den = 1,
        .preset = "ultrafast",
        .profile = "high",
        .tune = "zerolatency",
        .x264opts = ""
    };
    encoder->CreateVideoEncoder(&videoParams);

    AudioEncParams audioParams = {
        .encoder_type = "libfdk_aac",
        .bitrate = 192
    };
    encoder->CreateAudioEncoder(&audioParams);

    ffmpeg_mux_settings = obs_data_create();
	if (!ffmpeg_mux_settings) {
		return -1;
	}

	obs_data_set_string(ffmpeg_mux_settings, "path", app_output_file );
	

    output = obs_output_create("ffmpeg_muxer", "Ffmpeg Muxer", ffmpeg_mux_settings, nullptr);
	if (!output) {
        trace_error("Couldn't create output")
        return -1;
	}

	obs_data_release(ffmpeg_mux_settings);


    obs_set_output_source(0, show->GetShowSource());
    //obs_set_output_source(1, scene2->GetSceneSource());
	obs_encoder_set_video(encoder->GetVideoEncoder(), obs_get_video());
	obs_encoder_set_audio(encoder->GetAudioEncoder(), obs_get_audio());
	obs_output_set_video_encoder(output, encoder->GetVideoEncoder());
	obs_output_set_audio_encoder(output, encoder->GetAudioEncoder(), 0);
	
    // obs_output_set_service(output, service);

	if(obs_output_start(output) != true) {
		trace_error("obs_output_start failed");
	}

	// SLeep for 10 seconds
	for(int i = 0; i < 10; i++) {
		usleep(1000000);
	}

}