#ifndef _ROS_slamware_ros_sdk_ArtifactUsage_h
#define _ROS_slamware_ros_sdk_ArtifactUsage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class ArtifactUsage : public ros::Msg
  {
    public:
      typedef int8_t _usage_type;
      _usage_type usage;
      enum { UNKNOWN = -1 };
      enum { VIRTUAL_WALL = 0 };
      enum { VIRTUAL_TRACK = 1 };

    ArtifactUsage():
      usage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_usage;
      u_usage.real = this->usage;
      *(outbuffer + offset + 0) = (u_usage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->usage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_usage;
      u_usage.base = 0;
      u_usage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->usage = u_usage.real;
      offset += sizeof(this->usage);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/ArtifactUsage"; };
    const char * getMD5(){ return "09a92f9c3f6f43e89519652dba70246f"; };

  };

}
#endif
