#ifndef _ROS_slamware_ros_sdk_MoveOptionFlag_h
#define _ROS_slamware_ros_sdk_MoveOptionFlag_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class MoveOptionFlag : public ros::Msg
  {
    public:
      typedef uint32_t _flags_type;
      _flags_type flags;
      enum { NONE = 0 };
      enum { APPENDING = 1 };
      enum { MILESTONE = 2 };
      enum { NO_SMOOTH = 4 };
      enum { KEY_POINTS = 8 };
      enum { PRECISE = 16 };
      enum { WITH_YAW = 32 };
      enum { RETURN_UNREACHABLE_DIRECTLY = 64 };
      enum { KEY_POINTS_WITH_OA = 128 };

    MoveOptionFlag():
      flags(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flags >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->flags >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->flags >> (8 * 3)) & 0xFF;
      offset += sizeof(this->flags);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->flags =  ((uint32_t) (*(inbuffer + offset)));
      this->flags |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->flags |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/MoveOptionFlag"; };
    const char * getMD5(){ return "6a049fc03ba102569fc7d6e34f883c22"; };

  };

}
#endif
