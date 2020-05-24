#ifndef _ROS_slamware_ros_sdk_ClearLinesRequest_h
#define _ROS_slamware_ros_sdk_ClearLinesRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/ArtifactUsage.h"

namespace slamware_ros_sdk
{

  class ClearLinesRequest : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::ArtifactUsage _usage_type;
      _usage_type usage;

    ClearLinesRequest():
      usage()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->usage.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->usage.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/ClearLinesRequest"; };
    const char * getMD5(){ return "f393f6a6d7cf525f9292b0e1f80870fc"; };

  };

}
#endif
