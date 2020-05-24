#ifndef _ROS_slamware_ros_sdk_SensorType_h
#define _ROS_slamware_ros_sdk_SensorType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class SensorType : public ros::Msg
  {
    public:
      typedef int8_t _type_type;
      _type_type type;
      enum { UNKNOWN = -1 };
      enum { BUMPER = 0 };
      enum { CLIFF = 1 };
      enum { SONAR = 2 };
      enum { DEPTH_CAMERA = 3 };
      enum { WALL_SENSOR = 4 };
      enum { MAG_TAPE_DETECTOR = 5 };

    SensorType():
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

    const char * getType(){ return "slamware_ros_sdk/SensorType"; };
    const char * getMD5(){ return "1e839c01d7f45db5c8e57ffcc799cbb1"; };

  };

}
#endif
