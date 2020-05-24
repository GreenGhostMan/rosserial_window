#ifndef _ROS_slamware_ros_sdk_ActionDirection_h
#define _ROS_slamware_ros_sdk_ActionDirection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class ActionDirection : public ros::Msg
  {
    public:
      typedef int8_t _direction_type;
      _direction_type direction;
      enum { UNKNOWN = -1 };
      enum { FORWARD = 0 };
      enum { BACKWARD = 1 };
      enum { TURNRIGHT = 2 };
      enum { TURNLEFT = 3 };

    ActionDirection():
      direction(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/ActionDirection"; };
    const char * getMD5(){ return "95481d0530f4a91605c39c394a5f9aa2"; };

  };

}
#endif
