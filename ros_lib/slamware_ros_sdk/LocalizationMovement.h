#ifndef _ROS_slamware_ros_sdk_LocalizationMovement_h
#define _ROS_slamware_ros_sdk_LocalizationMovement_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class LocalizationMovement : public ros::Msg
  {
    public:
      typedef int8_t _type_type;
      _type_type type;
      enum { UNKNOWN = -1 };
      enum { NO_MOVE = 0 };
      enum { ROTATE_ONLY = 1 };
      enum { ANY = 2 };

    LocalizationMovement():
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/LocalizationMovement"; };
    const char * getMD5(){ return "790758c07b34c0bcc241ae63a161ceff"; };

  };

}
#endif
