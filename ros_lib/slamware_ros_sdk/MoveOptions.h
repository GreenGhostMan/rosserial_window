#ifndef _ROS_slamware_ros_sdk_MoveOptions_h
#define _ROS_slamware_ros_sdk_MoveOptions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/MoveOptionFlag.h"
#include "slamware_ros_sdk/OptionalFlt64.h"

namespace slamware_ros_sdk
{

  class MoveOptions : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::MoveOptionFlag _opt_flags_type;
      _opt_flags_type opt_flags;
      typedef slamware_ros_sdk::OptionalFlt64 _speed_ratio_type;
      _speed_ratio_type speed_ratio;

    MoveOptions():
      opt_flags(),
      speed_ratio()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->opt_flags.serialize(outbuffer + offset);
      offset += this->speed_ratio.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->opt_flags.deserialize(inbuffer + offset);
      offset += this->speed_ratio.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/MoveOptions"; };
    const char * getMD5(){ return "1e9be980ef594e7453a8d9bbbda54e01"; };

  };

}
#endif
