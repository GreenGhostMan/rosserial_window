#ifndef _ROS_slamware_ros_sdk_BasicSensorValueData_h
#define _ROS_slamware_ros_sdk_BasicSensorValueData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/BasicSensorInfo.h"
#include "slamware_ros_sdk/BasicSensorValue.h"

namespace slamware_ros_sdk
{

  class BasicSensorValueData : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::BasicSensorInfo _info_type;
      _info_type info;
      typedef slamware_ros_sdk::BasicSensorValue _value_type;
      _value_type value;

    BasicSensorValueData():
      info(),
      value()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      offset += this->value.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
      offset += this->value.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/BasicSensorValueData"; };
    const char * getMD5(){ return "ac61252b54363621f1c85905419d34d8"; };

  };

}
#endif
