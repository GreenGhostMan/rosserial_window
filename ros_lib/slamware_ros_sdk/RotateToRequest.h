#ifndef _ROS_slamware_ros_sdk_RotateToRequest_h
#define _ROS_slamware_ros_sdk_RotateToRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"
#include "slamware_ros_sdk/MoveOptions.h"

namespace slamware_ros_sdk
{

  class RotateToRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      typedef slamware_ros_sdk::MoveOptions _options_type;
      _options_type options;

    RotateToRequest():
      orientation(),
      options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->orientation.serialize(outbuffer + offset);
      offset += this->options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->orientation.deserialize(inbuffer + offset);
      offset += this->options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/RotateToRequest"; };
    const char * getMD5(){ return "cbdd4d0a412f6b5be904f5dec1c282b4"; };

  };

}
#endif
