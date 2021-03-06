#ifndef _ROS_slamware_ros_sdk_OptionalInt16_h
#define _ROS_slamware_ros_sdk_OptionalInt16_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class OptionalInt16 : public ros::Msg
  {
    public:
      typedef bool _is_valid_type;
      _is_valid_type is_valid;
      typedef int16_t _value_type;
      _value_type value;

    OptionalInt16():
      is_valid(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_valid;
      u_is_valid.real = this->is_valid;
      *(outbuffer + offset + 0) = (u_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_valid);
      union {
        int16_t real;
        uint16_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_valid;
      u_is_valid.base = 0;
      u_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_valid = u_is_valid.real;
      offset += sizeof(this->is_valid);
      union {
        int16_t real;
        uint16_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/OptionalInt16"; };
    const char * getMD5(){ return "fc7d4307404f0f0784482a8b8af47a30"; };

  };

}
#endif
