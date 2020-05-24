#ifndef _ROS_slamware_ros_sdk_BasicSensorValueDataArray_h
#define _ROS_slamware_ros_sdk_BasicSensorValueDataArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/BasicSensorValueData.h"

namespace slamware_ros_sdk
{

  class BasicSensorValueDataArray : public ros::Msg
  {
    public:
      uint32_t values_data_length;
      typedef slamware_ros_sdk::BasicSensorValueData _values_data_type;
      _values_data_type st_values_data;
      _values_data_type * values_data;

    BasicSensorValueDataArray():
      values_data_length(0), values_data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->values_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->values_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->values_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->values_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values_data_length);
      for( uint32_t i = 0; i < values_data_length; i++){
      offset += this->values_data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t values_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      values_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->values_data_length);
      if(values_data_lengthT > values_data_length)
        this->values_data = (slamware_ros_sdk::BasicSensorValueData*)realloc(this->values_data, values_data_lengthT * sizeof(slamware_ros_sdk::BasicSensorValueData));
      values_data_length = values_data_lengthT;
      for( uint32_t i = 0; i < values_data_length; i++){
      offset += this->st_values_data.deserialize(inbuffer + offset);
        memcpy( &(this->values_data[i]), &(this->st_values_data), sizeof(slamware_ros_sdk::BasicSensorValueData));
      }
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/BasicSensorValueDataArray"; };
    const char * getMD5(){ return "4f5614e15bb39e1233d6a3c6460058fa"; };

  };

}
#endif
