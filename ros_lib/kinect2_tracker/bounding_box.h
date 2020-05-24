#ifndef _ROS_kinect2_tracker_bounding_box_h
#define _ROS_kinect2_tracker_bounding_box_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"

namespace kinect2_tracker
{

  class bounding_box : public ros::Msg
  {
    public:
      typedef geometry_msgs::PointStamped _min_type;
      _min_type min;
      typedef geometry_msgs::PointStamped _max_type;
      _max_type max;

    bounding_box():
      min(),
      max()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->min.serialize(outbuffer + offset);
      offset += this->max.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->min.deserialize(inbuffer + offset);
      offset += this->max.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "kinect2_tracker/bounding_box"; };
    const char * getMD5(){ return "5a9f041aa663bad83df903fb4bed6c5c"; };

  };

}
#endif
