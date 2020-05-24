#ifndef _ROS_SERVICE_SyncSetStcm_h
#define _ROS_SERVICE_SyncSetStcm_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace slamware_ros_sdk
{

static const char SYNCSETSTCM[] = "slamware_ros_sdk/SyncSetStcm";

  class SyncSetStcmRequest : public ros::Msg
  {
    public:
      uint32_t raw_stcm_length;
      typedef uint8_t _raw_stcm_type;
      _raw_stcm_type st_raw_stcm;
      _raw_stcm_type * raw_stcm;
      typedef geometry_msgs::Pose _robot_pose_type;
      _robot_pose_type robot_pose;

    SyncSetStcmRequest():
      raw_stcm_length(0), raw_stcm(NULL),
      robot_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->raw_stcm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->raw_stcm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->raw_stcm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->raw_stcm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_stcm_length);
      for( uint32_t i = 0; i < raw_stcm_length; i++){
      *(outbuffer + offset + 0) = (this->raw_stcm[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->raw_stcm[i]);
      }
      offset += this->robot_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t raw_stcm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      raw_stcm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      raw_stcm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      raw_stcm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->raw_stcm_length);
      if(raw_stcm_lengthT > raw_stcm_length)
        this->raw_stcm = (uint8_t*)realloc(this->raw_stcm, raw_stcm_lengthT * sizeof(uint8_t));
      raw_stcm_length = raw_stcm_lengthT;
      for( uint32_t i = 0; i < raw_stcm_length; i++){
      this->st_raw_stcm =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_raw_stcm);
        memcpy( &(this->raw_stcm[i]), &(this->st_raw_stcm), sizeof(uint8_t));
      }
      offset += this->robot_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SYNCSETSTCM; };
    const char * getMD5(){ return "bf6e85150212bf18415ddb0faf371f8b"; };

  };

  class SyncSetStcmResponse : public ros::Msg
  {
    public:

    SyncSetStcmResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SYNCSETSTCM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SyncSetStcm {
    public:
    typedef SyncSetStcmRequest Request;
    typedef SyncSetStcmResponse Response;
  };

}
#endif
