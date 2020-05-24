#ifndef _ROS_slamware_ros_sdk_GoHomeRequest_h
#define _ROS_slamware_ros_sdk_GoHomeRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class GoHomeRequest : public ros::Msg
  {
    public:

    GoHomeRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/GoHomeRequest"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
