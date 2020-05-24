#ifndef _ROS_slamware_ros_sdk_SetMapUpdateRequest_h
#define _ROS_slamware_ros_sdk_SetMapUpdateRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/MapKind.h"

namespace slamware_ros_sdk
{

  class SetMapUpdateRequest : public ros::Msg
  {
    public:
      typedef bool _enabled_type;
      _enabled_type enabled;
      typedef slamware_ros_sdk::MapKind _kind_type;
      _kind_type kind;

    SetMapUpdateRequest():
      enabled(0),
      kind()
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
      offset += this->kind.serialize(outbuffer + offset);
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
      offset += this->kind.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/SetMapUpdateRequest"; };
    const char * getMD5(){ return "c52ca05137725a8c1db88bf912fafeb8"; };

  };

}
#endif
