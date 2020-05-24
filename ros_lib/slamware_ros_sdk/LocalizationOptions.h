#ifndef _ROS_slamware_ros_sdk_LocalizationOptions_h
#define _ROS_slamware_ros_sdk_LocalizationOptions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/OptionalInt32.h"
#include "slamware_ros_sdk/OptionalLocalizationMovement.h"

namespace slamware_ros_sdk
{

  class LocalizationOptions : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::OptionalInt32 _max_time_ms_type;
      _max_time_ms_type max_time_ms;
      typedef slamware_ros_sdk::OptionalLocalizationMovement _mvmt_type_type;
      _mvmt_type_type mvmt_type;

    LocalizationOptions():
      max_time_ms(),
      mvmt_type()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->max_time_ms.serialize(outbuffer + offset);
      offset += this->mvmt_type.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->max_time_ms.deserialize(inbuffer + offset);
      offset += this->mvmt_type.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/LocalizationOptions"; };
    const char * getMD5(){ return "0f22b73404b93416123cd3d791b6768f"; };

  };

}
#endif
