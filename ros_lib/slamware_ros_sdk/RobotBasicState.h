#ifndef _ROS_slamware_ros_sdk_RobotBasicState_h
#define _ROS_slamware_ros_sdk_RobotBasicState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class RobotBasicState : public ros::Msg
  {
    public:
      typedef bool _is_map_building_enabled_type;
      _is_map_building_enabled_type is_map_building_enabled;
      typedef bool _is_localization_enabled_type;
      _is_localization_enabled_type is_localization_enabled;
      typedef int32_t _localization_quality_type;
      _localization_quality_type localization_quality;
      typedef int32_t _board_temperature_type;
      _board_temperature_type board_temperature;
      typedef int32_t _battery_percentage_type;
      _battery_percentage_type battery_percentage;
      typedef bool _is_dc_in_type;
      _is_dc_in_type is_dc_in;
      typedef bool _is_charging_type;
      _is_charging_type is_charging;

    RobotBasicState():
      is_map_building_enabled(0),
      is_localization_enabled(0),
      localization_quality(0),
      board_temperature(0),
      battery_percentage(0),
      is_dc_in(0),
      is_charging(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_map_building_enabled;
      u_is_map_building_enabled.real = this->is_map_building_enabled;
      *(outbuffer + offset + 0) = (u_is_map_building_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_map_building_enabled);
      union {
        bool real;
        uint8_t base;
      } u_is_localization_enabled;
      u_is_localization_enabled.real = this->is_localization_enabled;
      *(outbuffer + offset + 0) = (u_is_localization_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_localization_enabled);
      union {
        int32_t real;
        uint32_t base;
      } u_localization_quality;
      u_localization_quality.real = this->localization_quality;
      *(outbuffer + offset + 0) = (u_localization_quality.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_localization_quality.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_localization_quality.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_localization_quality.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->localization_quality);
      union {
        int32_t real;
        uint32_t base;
      } u_board_temperature;
      u_board_temperature.real = this->board_temperature;
      *(outbuffer + offset + 0) = (u_board_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_board_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_board_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_board_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->board_temperature);
      union {
        int32_t real;
        uint32_t base;
      } u_battery_percentage;
      u_battery_percentage.real = this->battery_percentage;
      *(outbuffer + offset + 0) = (u_battery_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_percentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_percentage);
      union {
        bool real;
        uint8_t base;
      } u_is_dc_in;
      u_is_dc_in.real = this->is_dc_in;
      *(outbuffer + offset + 0) = (u_is_dc_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_dc_in);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.real = this->is_charging;
      *(outbuffer + offset + 0) = (u_is_charging.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_charging);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_map_building_enabled;
      u_is_map_building_enabled.base = 0;
      u_is_map_building_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_map_building_enabled = u_is_map_building_enabled.real;
      offset += sizeof(this->is_map_building_enabled);
      union {
        bool real;
        uint8_t base;
      } u_is_localization_enabled;
      u_is_localization_enabled.base = 0;
      u_is_localization_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_localization_enabled = u_is_localization_enabled.real;
      offset += sizeof(this->is_localization_enabled);
      union {
        int32_t real;
        uint32_t base;
      } u_localization_quality;
      u_localization_quality.base = 0;
      u_localization_quality.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_localization_quality.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_localization_quality.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_localization_quality.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->localization_quality = u_localization_quality.real;
      offset += sizeof(this->localization_quality);
      union {
        int32_t real;
        uint32_t base;
      } u_board_temperature;
      u_board_temperature.base = 0;
      u_board_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_board_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_board_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_board_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->board_temperature = u_board_temperature.real;
      offset += sizeof(this->board_temperature);
      union {
        int32_t real;
        uint32_t base;
      } u_battery_percentage;
      u_battery_percentage.base = 0;
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_percentage = u_battery_percentage.real;
      offset += sizeof(this->battery_percentage);
      union {
        bool real;
        uint8_t base;
      } u_is_dc_in;
      u_is_dc_in.base = 0;
      u_is_dc_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_dc_in = u_is_dc_in.real;
      offset += sizeof(this->is_dc_in);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.base = 0;
      u_is_charging.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_charging = u_is_charging.real;
      offset += sizeof(this->is_charging);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/RobotBasicState"; };
    const char * getMD5(){ return "9be82c50d81e99092b7127a543694749"; };

  };

}
#endif
