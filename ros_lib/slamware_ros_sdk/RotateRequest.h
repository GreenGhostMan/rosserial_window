#ifndef _ROS_slamware_ros_sdk_RotateRequest_h
#define _ROS_slamware_ros_sdk_RotateRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"
#include "slamware_ros_sdk/MoveOptions.h"

namespace slamware_ros_sdk
{

  class RotateRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Quaternion _rotation_type;
      _rotation_type rotation;
      typedef slamware_ros_sdk::MoveOptions _options_type;
      _options_type options;

    RotateRequest():
      rotation(),
      options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->rotation.serialize(outbuffer + offset);
      offset += this->options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->rotation.deserialize(inbuffer + offset);
      offset += this->options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/RotateRequest"; };
    const char * getMD5(){ return "aa2d0c148e6527d63b857be9ac778eb8"; };

  };

}
#endif
