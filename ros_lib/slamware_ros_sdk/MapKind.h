#ifndef _ROS_slamware_ros_sdk_MapKind_h
#define _ROS_slamware_ros_sdk_MapKind_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class MapKind : public ros::Msg
  {
    public:
      typedef int8_t _kind_type;
      _kind_type kind;
      enum { UNKNOWN = -1 };
      enum { EXPLORERMAP = 0 };
      enum { SWEEPERMAP = 1 };
      enum { UWBMAP = 2 };
      enum { SLAMMAP = 3 };
      enum { LOCALSLAMMAP = 4 };

    MapKind():
      kind(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_kind;
      u_kind.real = this->kind;
      *(outbuffer + offset + 0) = (u_kind.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kind);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_kind;
      u_kind.base = 0;
      u_kind.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->kind = u_kind.real;
      offset += sizeof(this->kind);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/MapKind"; };
    const char * getMD5(){ return "f669b590664c371d1174e6a57069c534"; };

  };

}
#endif
