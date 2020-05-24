#ifndef _ROS_slamware_ros_sdk_RecoverLocalizationRequest_h
#define _ROS_slamware_ros_sdk_RecoverLocalizationRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/RectFlt32.h"
#include "slamware_ros_sdk/LocalizationOptions.h"

namespace slamware_ros_sdk
{

  class RecoverLocalizationRequest : public ros::Msg
  {
    public:
      typedef slamware_ros_sdk::RectFlt32 _area_type;
      _area_type area;
      typedef slamware_ros_sdk::LocalizationOptions _options_type;
      _options_type options;

    RecoverLocalizationRequest():
      area(),
      options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->area.serialize(outbuffer + offset);
      offset += this->options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->area.deserialize(inbuffer + offset);
      offset += this->options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/RecoverLocalizationRequest"; };
    const char * getMD5(){ return "23b8ad43efcddaa451d7f46385bf8b37"; };

  };

}
#endif
