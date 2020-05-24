#ifndef _ROS_slamware_ros_sdk_RemoveLineRequest_h
#define _ROS_slamware_ros_sdk_RemoveLineRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/ArtifactUsage.h"

namespace slamware_ros_sdk
{

  class RemoveLineRequest : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::ArtifactUsage _usage_type;
      _usage_type usage;
      typedef uint32_t _id_type;
      _id_type id;

    RemoveLineRequest():
      usage(),
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->usage.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->usage.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/RemoveLineRequest"; };
    const char * getMD5(){ return "155e65283140a49f08b2e1d08d692dc4"; };

  };

}
#endif
