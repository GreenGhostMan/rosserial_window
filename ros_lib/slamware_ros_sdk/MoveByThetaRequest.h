#ifndef _ROS_slamware_ros_sdk_MoveByThetaRequest_h
#define _ROS_slamware_ros_sdk_MoveByThetaRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/MoveOptions.h"

namespace slamware_ros_sdk
{

  class MoveByThetaRequest : public ros::Msg
  {
    public:
      typedef float _theta_type;
      _theta_type theta;
      typedef slamware_ros_sdk::MoveOptions _options_type;
      _options_type options;

    MoveByThetaRequest():
      theta(0),
      options()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.real = this->theta;
      *(outbuffer + offset + 0) = (u_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta);
      offset += this->options.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.base = 0;
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theta = u_theta.real;
      offset += sizeof(this->theta);
      offset += this->options.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/MoveByThetaRequest"; };
    const char * getMD5(){ return "3f4151e8ecd474b3a0e237c25b3dfbd7"; };

  };

}
#endif
