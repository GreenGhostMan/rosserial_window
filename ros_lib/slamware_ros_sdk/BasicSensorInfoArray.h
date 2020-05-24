#ifndef _ROS_slamware_ros_sdk_BasicSensorInfoArray_h
#define _ROS_slamware_ros_sdk_BasicSensorInfoArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/BasicSensorInfo.h"

namespace slamware_ros_sdk
{

  class BasicSensorInfoArray : public ros::Msg
  {
    public:
      uint32_t sensors_info_length;
      typedef slamware_ros_sdk::BasicSensorInfo _sensors_info_type;
      _sensors_info_type st_sensors_info;
      _sensors_info_type * sensors_info;

    BasicSensorInfoArray():
      sensors_info_length(0), sensors_info(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sensors_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensors_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensors_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensors_info_length);
      for( uint32_t i = 0; i < sensors_info_length; i++){
      offset += this->sensors_info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t sensors_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sensors_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sensors_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sensors_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sensors_info_length);
      if(sensors_info_lengthT > sensors_info_length)
        this->sensors_info = (slamware_ros_sdk::BasicSensorInfo*)realloc(this->sensors_info, sensors_info_lengthT * sizeof(slamware_ros_sdk::BasicSensorInfo));
      sensors_info_length = sensors_info_lengthT;
      for( uint32_t i = 0; i < sensors_info_length; i++){
      offset += this->st_sensors_info.deserialize(inbuffer + offset);
        memcpy( &(this->sensors_info[i]), &(this->st_sensors_info), sizeof(slamware_ros_sdk::BasicSensorInfo));
      }
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/BasicSensorInfoArray"; };
    const char * getMD5(){ return "f2091030b7ab5ae719573c70a4242996"; };

  };

}
#endif
