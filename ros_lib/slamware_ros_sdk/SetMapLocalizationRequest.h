#ifndef _ROS_slamware_ros_sdk_SetMapLocalizationRequest_h
#define _ROS_slamware_ros_sdk_SetMapLocalizationRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class SetMapLocalizationRequest : public ros::Msg
  {
    public:
      typedef bool _enabled_type;
      _enabled_type enabled;

    SetMapLocalizationRequest():
      enabled(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/SetMapLocalizationRequest"; };
    const char * getMD5(){ return "2815464f55ab63684cc1bc38072d0b9b"; };

  };

}
#endif
