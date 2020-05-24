#ifndef _ROS_slamware_ros_sdk_RobotDeviceInfo_h
#define _ROS_slamware_ros_sdk_RobotDeviceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace slamware_ros_sdk
{

  class RobotDeviceInfo : public ros::Msg
  {
    public:
      typedef const char* _device_id_type;
      _device_id_type device_id;
      typedef int32_t _model_id_type;
      _model_id_type model_id;
      typedef const char* _model_name_type;
      _model_name_type model_name;
      typedef int32_t _manufacturer_id_type;
      _manufacturer_id_type manufacturer_id;
      typedef const char* _manufacturer_name_type;
      _manufacturer_name_type manufacturer_name;
      typedef const char* _hardware_version_type;
      _hardware_version_type hardware_version;
      typedef const char* _software_version_type;
      _software_version_type software_version;
      typedef const char* _sdp_version_type;
      _sdp_version_type sdp_version;
      typedef const char* _sdk_version_type;
      _sdk_version_type sdk_version;

    RobotDeviceInfo():
      device_id(""),
      model_id(0),
      model_name(""),
      manufacturer_id(0),
      manufacturer_name(""),
      hardware_version(""),
      software_version(""),
      sdp_version(""),
      sdk_version("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_device_id = strlen(this->device_id);
      varToArr(outbuffer + offset, length_device_id);
      offset += 4;
      memcpy(outbuffer + offset, this->device_id, length_device_id);
      offset += length_device_id;
      union {
        int32_t real;
        uint32_t base;
      } u_model_id;
      u_model_id.real = this->model_id;
      *(outbuffer + offset + 0) = (u_model_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_model_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_model_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_model_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->model_id);
      uint32_t length_model_name = strlen(this->model_name);
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
      union {
        int32_t real;
        uint32_t base;
      } u_manufacturer_id;
      u_manufacturer_id.real = this->manufacturer_id;
      *(outbuffer + offset + 0) = (u_manufacturer_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_manufacturer_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_manufacturer_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_manufacturer_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->manufacturer_id);
      uint32_t length_manufacturer_name = strlen(this->manufacturer_name);
      varToArr(outbuffer + offset, length_manufacturer_name);
      offset += 4;
      memcpy(outbuffer + offset, this->manufacturer_name, length_manufacturer_name);
      offset += length_manufacturer_name;
      uint32_t length_hardware_version = strlen(this->hardware_version);
      varToArr(outbuffer + offset, length_hardware_version);
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_version, length_hardware_version);
      offset += length_hardware_version;
      uint32_t length_software_version = strlen(this->software_version);
      varToArr(outbuffer + offset, length_software_version);
      offset += 4;
      memcpy(outbuffer + offset, this->software_version, length_software_version);
      offset += length_software_version;
      uint32_t length_sdp_version = strlen(this->sdp_version);
      varToArr(outbuffer + offset, length_sdp_version);
      offset += 4;
      memcpy(outbuffer + offset, this->sdp_version, length_sdp_version);
      offset += length_sdp_version;
      uint32_t length_sdk_version = strlen(this->sdk_version);
      varToArr(outbuffer + offset, length_sdk_version);
      offset += 4;
      memcpy(outbuffer + offset, this->sdk_version, length_sdk_version);
      offset += length_sdk_version;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_device_id;
      arrToVar(length_device_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_id-1]=0;
      this->device_id = (char *)(inbuffer + offset-1);
      offset += length_device_id;
      union {
        int32_t real;
        uint32_t base;
      } u_model_id;
      u_model_id.base = 0;
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_model_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->model_id = u_model_id.real;
      offset += sizeof(this->model_id);
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      union {
        int32_t real;
        uint32_t base;
      } u_manufacturer_id;
      u_manufacturer_id.base = 0;
      u_manufacturer_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_manufacturer_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_manufacturer_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_manufacturer_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->manufacturer_id = u_manufacturer_id.real;
      offset += sizeof(this->manufacturer_id);
      uint32_t length_manufacturer_name;
      arrToVar(length_manufacturer_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_manufacturer_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_manufacturer_name-1]=0;
      this->manufacturer_name = (char *)(inbuffer + offset-1);
      offset += length_manufacturer_name;
      uint32_t length_hardware_version;
      arrToVar(length_hardware_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_version-1]=0;
      this->hardware_version = (char *)(inbuffer + offset-1);
      offset += length_hardware_version;
      uint32_t length_software_version;
      arrToVar(length_software_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_software_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_software_version-1]=0;
      this->software_version = (char *)(inbuffer + offset-1);
      offset += length_software_version;
      uint32_t length_sdp_version;
      arrToVar(length_sdp_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sdp_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sdp_version-1]=0;
      this->sdp_version = (char *)(inbuffer + offset-1);
      offset += length_sdp_version;
      uint32_t length_sdk_version;
      arrToVar(length_sdk_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sdk_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sdk_version-1]=0;
      this->sdk_version = (char *)(inbuffer + offset-1);
      offset += length_sdk_version;
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/RobotDeviceInfo"; };
    const char * getMD5(){ return "147111817e23218ad3ebe9575ab38f3d"; };

  };

}
#endif
