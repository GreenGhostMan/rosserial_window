#ifndef _ROS_slamware_ros_sdk_SyncMapRequest_h
#define _ROS_slamware_ros_sdk_SyncMapRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class SyncMapRequest : public ros::Msg
  {
    public:

    SyncMapRequest()
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

    const char * getType(){ return "slamware_ros_sdk/SyncMapRequest"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
