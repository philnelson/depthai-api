#pragma once

#include <string>
#include <vector>

#include "../../shared/json_helper.hpp"


struct HostPipelineConfig
{
    struct StreamRequest {
        std::string name;
        std::string data_type;
        float       max_fps   = 0.f;

        StreamRequest(const std::string &name_) : name(name_) {}
    };

    std::vector<StreamRequest> streams;
    std::vector<std::string>   streams_public;

    struct Depth {
        std::string calibration_file;
        std::string type;
        float       padding_factor = 0.3f;
    } depth;

    struct AI
    {
        std::string blob_file;
        std::string blob_file_config;
        bool calc_dist_to_bb = false;
    } ai;

    struct BoardConfig
    {
        bool  clear_eeprom = false;
        bool  store_to_eeprom = false;
        bool  override_eeprom_calib = false;
        bool  swap_left_and_right_cameras = false;
        float left_fov_deg = 69.f;
        float left_to_right_distance_m = 0.035f; // meters, not centimeters
        float left_to_rgb_distance_m = 0;
    } board_config;


    bool initWithJSON(const json &json_obj);
    bool hasStream(const std::string &stream_name) const;
};
