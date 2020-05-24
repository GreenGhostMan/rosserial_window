#ifndef _ROS_slamware_ros_sdk_Line2DFlt32Array_h
#define _ROS_slamware_ros_sdk_Line2DFlt32Array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/Line2DFlt32.h"

namespace slamware_ros_sdk
{

  class Line2DFlt32Array : public ros::Msg
  {
    public:
      uint32_t lines_length;
      typedef slamware_ros_sdk::Line2DFlt32 _lines_type;
      _lines_type st_lines;
      _lines_type * lines;

    Line2DFlt32Array():
      lines_length(0), lines(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->lines_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lines_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lines_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lines_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lines_length);
      for( uint32_t i = 0; i < lines_length; i++){
      offset += this->lines[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t lines_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      lines_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      lines_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      lines_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->lines_length);
      if(lines_lengthT > lines_length)
        this->lines = (slamware_ros_sdk::Line2DFlt32*)realloc(this->lines, lines_lengthT * sizeof(slamware_ros_sdk::Line2DFlt32));
      lines_length = lines_lengthT;
      for( uint32_t i = 0; i < lines_length; i++){
      offset += this->st_lines.deserialize(inbuffer + offset);
        memcpy( &(this->lines[i]), &(this->st_lines), sizeof(slamware_ros_sdk::Line2DFlt32));
      }
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/Line2DFlt32Array"; };
    const char * getMD5(){ return "fb4ce31f862e9d16d4eea0d3a52a6bf5"; };

  };

}
#endif
