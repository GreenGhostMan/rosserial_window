#ifndef _ROS_slamware_ros_sdk_MoveToLocationsRequest_h
#define _ROS_slamware_ros_sdk_MoveToLocationsRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "slamware_ros_sdk/MoveOptions.h"

namespace slamware_ros_sdk
{

  class MoveToLocationsRequest : public ros::Msg
  {
    public:
      uint32_t locations_length;
      typedef geometry_msgs::Point _locations_type;
      _locations_type st_locations;
      _locations_type * locations;
      typedef slamware_ros_sdk::MoveOptions _options_type;
      _options_type options;
      typedef float _yaw_type;
      _yaw_type yaw;

    MoveToLocationsRequest():
      locations_length(0), locations(NULL),
      options(),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->locations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->locations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->locations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->locations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locations_length);
      for( uint32_t i = 0; i < locations_length; i++){
      offset += this->locations[i].serialize(outbuffer + offset);
      }
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
      uint32_t locations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      locations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      locations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      locations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->locations_length);
      if(locations_lengthT > locations_length)
        this->locations = (geometry_msgs::Point*)realloc(this->locations, locations_lengthT * sizeof(geometry_msgs::Point));
      locations_length = locations_lengthT;
      for( uint32_t i = 0; i < locations_length; i++){
      offset += this->st_locations.deserialize(inbuffer + offset);
        memcpy( &(this->locations[i]), &(this->st_locations), sizeof(geometry_msgs::Point));
      }
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

    const char * getType(){ return "slamware_ros_sdk/MoveToLocationsRequest"; };
    const char * getMD5(){ return "6f33f6579602c04837318e79ebcc71bf"; };

  };

}
#endif
