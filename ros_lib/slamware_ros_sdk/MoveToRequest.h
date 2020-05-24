#ifndef _ROS_slamware_ros_sdk_MoveToRequest_h
#define _ROS_slamware_ros_sdk_MoveToRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "slamware_ros_sdk/MoveOptions.h"

namespace slamware_ros_sdk
{

  class MoveToRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _location_type;
      _location_type location;
      typedef slamware_ros_sdk::MoveOptions _options_type;
      _options_type options;
      typedef float _yaw_type;
      _yaw_type yaw;

    MoveToRequest():
      location(),
      options(),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->location.serialize(outbuffer + offset);
      offset += this->options.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->location.deserialize(inbuffer + offset);
      offset += this->options.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/MoveToRequest"; };
    const char * getMD5(){ return "6d7d1ef4f0dba270fe0e38669f83096c"; };

  };

}
#endif
