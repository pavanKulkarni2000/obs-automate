
#include "Source.hpp"
#include "Trace.hpp"


obs_source_t* Source::localFileSourceCreate(std::string name, std::string url, bool looping) {
	obs_data_t	*obs_data;
    obs_data = obs_data_create();
	if (!obs_data) {
		trace_error("Failed to create obs_data",);
		return NULL;
	}

	trace_debug("create ffmpeg src");

	obs_data_set_string(obs_data, "local_file", url.c_str());
	obs_data_set_bool(obs_data, "is_local_file", true);
	obs_data_set_bool(obs_data, "looping", looping);
	obs_data_set_bool(obs_data, "hw_decode", false);

	obs_source_ = obs_source_create("ffmpeg_source", name.c_str(), obs_data, nullptr);

	printf("WIDTH %d HEIGHT %d\n" ,(obs_source_get_width(obs_source_)), (obs_source_get_height(obs_source_)));

	obs_data_release(obs_data);
	if (!obs_source_) {
		trace_error("Failed to create obs_source");
		return NULL;
	}
    return obs_source_;
}

obs_source_t* Source::browserUrlSourceCreate(std::string name, std::string url, bool is_local) {
	obs_data_t	*obs_data;
    obs_data = obs_data_create();
	if (!obs_data) {
		trace_error("Failed to create obs_data",);
		return NULL;
	}

	trace_debug("create browser src");

	obs_data_set_string(obs_data, "url", url.c_str());

	//is false by default
	obs_data_set_bool(obs_data, "is_local_file", is_local);
	

	obs_source_ = obs_source_create("browser_source", name.c_str(), obs_data, nullptr);

	switch(obs_source_get_type(obs_source_)){
		case OBS_SOURCE_TYPE_INPUT:  trace_debug("OBS_SOURCE_TYPE_INPUT");break;
		case	OBS_SOURCE_TYPE_FILTER :  trace_debug("OBS_SOURCE_TYPE_FILTER");break;
		case	OBS_SOURCE_TYPE_TRANSITION :  trace_debug("OBS_SOURCE_TYPE_TRANSITION");break;
		case	OBS_SOURCE_TYPE_SCENE:  trace_debug("OBS_SOURCE_TYPE_TRANSITION");break;
		default: trace_debug("unknown type");
	}

	obs_data_release(obs_data);
	if (!obs_source_) {
		trace_error("Failed to create obs_source");
		return NULL;
	}
    return obs_source_;
}



Source::Source(SourceParams  *params) {
    switch(params->sourceType) {
        case LocalFile:
        localFileSourceCreate(params->name, params->url, true);
        break;
		case BrowserUrl:
		browserUrlSourceCreate(params->name,params->url, false);
		break;
        default:
        trace_error("Unknown SourceType received");
    } 
}