#ifndef _ROS_slamware_ros_sdk_AddLineRequest_h
#define _ROS_slamware_ros_sdk_AddLineRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/ArtifactUsage.h"
#include "slamware_ros_sdk/Line2DFlt32.h"

namespace slamware_ros_sdk
{

  class AddLineRequest : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::ArtifactUsage _usage_type;
      _usage_type usage;
      typedef slamware_ros_sdk::Line2DFlt32 _line_type;
      _line_type line;

    AddLineRequest():
      usage(),
      line()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->usage.serialize(outbuffer + offset);
      offset += this->line.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->usage.deserialize(inbuffer + offset);
      offset += this->line.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/AddLineRequest"; };
    const char * getMD5(){ return "7cf38560b548912a4639543a301c6d6b"; };

  };

}
#endif
