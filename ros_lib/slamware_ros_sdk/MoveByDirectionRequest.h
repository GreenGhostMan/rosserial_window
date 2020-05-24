#ifndef _ROS_slamware_ros_sdk_MoveByDirectionRequest_h
#define _ROS_slamware_ros_sdk_MoveByDirectionRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/ActionDirection.h"
#include "slamware_ros_sdk/MoveOptions.h"

namespace slamware_ros_sdk
{

  class MoveByDirectionRequest : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::ActionDirection _direction_type;
      _direction_type direction;
      typedef slamware_ros_sdk::MoveOptions _options_type;
      _options_type options;

    MoveByDirectionRequest():
      direction(),
      options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->direction.serialize(outbuffer + offset);
      offset += this->options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->direction.deserialize(inbuffer + offset);
      offset += this->options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/MoveByDirectionRequest"; };
    const char * getMD5(){ return "22e9e5447206854d91fc9a789fd96577"; };

  };

}
#endif
