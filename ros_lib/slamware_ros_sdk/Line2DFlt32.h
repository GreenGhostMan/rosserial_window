#ifndef _ROS_slamware_ros_sdk_Line2DFlt32_h
#define _ROS_slamware_ros_sdk_Line2DFlt32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "slamware_ros_sdk/Vec2DFlt32.h"

namespace slamware_ros_sdk
{

  class Line2DFlt32 : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef slamware_ros_sdk::Vec2DFlt32 _start_type;
      _start_type start;
      typedef slamware_ros_sdk::Vec2DFlt32 _end_type;
      _end_type end;

    Line2DFlt32():
      id(0),
      start(),
      end()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      offset += this->start.serialize(outbuffer + offset);
      offset += this->end.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->end.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "slamware_ros_sdk/Line2DFlt32"; };
    const char * getMD5(){ return "5fb32a1fe2c48724cf93b623d4a93c15"; };

  };

}
#endif
