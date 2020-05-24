#ifndef _ROS_slamware_ros_sdk_OptionalLocalizationMovement_h
#define _ROS_slamware_ros_sdk_OptionalLocalizationMovement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/LocalizationMovement.h"

namespace slamware_ros_sdk
{

  class OptionalLocalizationMovement : public ros::Msg
  {
    public:
      typedef bool _is_valid_type;
      _is_valid_type is_valid;
      typedef slamware_ros_sdk::LocalizationMovement _value_type;
      _value_type value;

    OptionalLocalizationMovement():
      is_valid(0),
      value()
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
      offset += this->value.serialize(outbuffer + offset);
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
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/OptionalLocalizationMovement"; };
    const char * getMD5(){ return "1ea9ff9b6a63b93c5b837059a53c8137"; };

  };

}
#endif
