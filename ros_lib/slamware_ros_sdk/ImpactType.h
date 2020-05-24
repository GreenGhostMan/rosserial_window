#ifndef _ROS_slamware_ros_sdk_ImpactType_h
#define _ROS_slamware_ros_sdk_ImpactType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class ImpactType : public ros::Msg
  {
    public:
      typedef int8_t _type_type;
      _type_type type;
      enum { UNKNOWN = -1 };
      enum { DIGITAL = 0 };
      enum { ANALOG = 1 };

    ImpactType():
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

    const char * getType(){ return "slamware_ros_sdk/ImpactType"; };
    const char * getMD5(){ return "cb0559087c3cc3accc5934b2c315c9a4"; };

  };

}
#endif
