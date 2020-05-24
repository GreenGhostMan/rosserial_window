#ifndef _ROS_slamware_ros_sdk_ClearMapRequest_h
#define _ROS_slamware_ros_sdk_ClearMapRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/MapKind.h"

namespace slamware_ros_sdk
{

  class ClearMapRequest : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::MapKind _kind_type;
      _kind_type kind;

    ClearMapRequest():
      kind()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->kind.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->kind.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/ClearMapRequest"; };
    const char * getMD5(){ return "f72328e91181466c30c2e2df2871f6a6"; };

  };

}
#endif
