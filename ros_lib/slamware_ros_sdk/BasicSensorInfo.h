#ifndef _ROS_slamware_ros_sdk_BasicSensorInfo_h
#define _ROS_slamware_ros_sdk_BasicSensorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/SensorType.h"
#include "slamware_ros_sdk/ImpactType.h"
#include "geometry_msgs/Pose.h"

namespace slamware_ros_sdk
{

  class BasicSensorInfo : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;
      typedef slamware_ros_sdk::SensorType _sensor_type_type;
      _sensor_type_type sensor_type;
      typedef slamware_ros_sdk::ImpactType _impact_type_type;
      _impact_type_type impact_type;
      typedef geometry_msgs::Pose _install_pose_type;
      _install_pose_type install_pose;
      typedef float _refresh_freq_type;
      _refresh_freq_type refresh_freq;

    BasicSensorInfo():
      id(0),
      sensor_type(),
      impact_type(),
      install_pose(),
      refresh_freq(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->sensor_type.serialize(outbuffer + offset);
      offset += this->impact_type.serialize(outbuffer + offset);
      offset += this->install_pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_refresh_freq;
      u_refresh_freq.real = this->refresh_freq;
      *(outbuffer + offset + 0) = (u_refresh_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_refresh_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_refresh_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_refresh_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->refresh_freq);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += this->sensor_type.deserialize(inbuffer + offset);
      offset += this->impact_type.deserialize(inbuffer + offset);
      offset += this->install_pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_refresh_freq;
      u_refresh_freq.base = 0;
      u_refresh_freq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_refresh_freq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_refresh_freq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_refresh_freq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->refresh_freq = u_refresh_freq.real;
      offset += sizeof(this->refresh_freq);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/BasicSensorInfo"; };
    const char * getMD5(){ return "05838254be5dbe0f7db9c42aa9056515"; };

  };

}
#endif
