#ifndef _ROS_slamware_ros_sdk_BasicSensorValue_h
#define _ROS_slamware_ros_sdk_BasicSensorValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class BasicSensorValue : public ros::Msg
  {
    public:
      typedef bool _is_in_impact_type;
      _is_in_impact_type is_in_impact;
      typedef float _value_type;
      _value_type value;

    BasicSensorValue():
      is_in_impact(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_in_impact;
      u_is_in_impact.real = this->is_in_impact;
      *(outbuffer + offset + 0) = (u_is_in_impact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_in_impact);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_in_impact;
      u_is_in_impact.base = 0;
      u_is_in_impact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_in_impact = u_is_in_impact.real;
      offset += sizeof(this->is_in_impact);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/BasicSensorValue"; };
    const char * getMD5(){ return "74a8c68fc77f36ccc19ff403f5d53170"; };

  };

}
#endif
