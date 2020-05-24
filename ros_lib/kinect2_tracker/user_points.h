#ifndef _ROS_kinect2_tracker_user_points_h
#define _ROS_kinect2_tracker_user_points_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "kinect2_tracker/bounding_box.h"

namespace kinect2_tracker
{

  class user_points : public ros::Msg
  {
    public:
      uint32_t users_length;
      typedef uint8_t _users_type;
      _users_type st_users;
      _users_type * users;
      uint32_t people_points_length;
      typedef geometry_msgs::PointStamped _people_points_type;
      _people_points_type st_people_points;
      _people_points_type * people_points;
      uint32_t boxes_length;
      typedef kinect2_tracker::bounding_box _boxes_type;
      _boxes_type st_boxes;
      _boxes_type * boxes;

    user_points():
      users_length(0), users(NULL),
      people_points_length(0), people_points(NULL),
      boxes_length(0), boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->users_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->users_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->users_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->users_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->users_length);
      for( uint32_t i = 0; i < users_length; i++){
      *(outbuffer + offset + 0) = (this->users[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->users[i]);
      }
      *(outbuffer + offset + 0) = (this->people_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->people_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->people_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->people_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->people_points_length);
      for( uint32_t i = 0; i < people_points_length; i++){
      offset += this->people_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->boxes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->boxes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->boxes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->boxes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boxes_length);
      for( uint32_t i = 0; i < boxes_length; i++){
      offset += this->boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t users_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      users_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      users_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      users_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->users_length);
      if(users_lengthT > users_length)
        this->users = (uint8_t*)realloc(this->users, users_lengthT * sizeof(uint8_t));
      users_length = users_lengthT;
      for( uint32_t i = 0; i < users_length; i++){
      this->st_users =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_users);
        memcpy( &(this->users[i]), &(this->st_users), sizeof(uint8_t));
      }
      uint32_t people_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      people_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      people_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      people_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->people_points_length);
      if(people_points_lengthT > people_points_length)
        this->people_points = (geometry_msgs::PointStamped*)realloc(this->people_points, people_points_lengthT * sizeof(geometry_msgs::PointStamped));
      people_points_length = people_points_lengthT;
      for( uint32_t i = 0; i < people_points_length; i++){
      offset += this->st_people_points.deserialize(inbuffer + offset);
        memcpy( &(this->people_points[i]), &(this->st_people_points), sizeof(geometry_msgs::PointStamped));
      }
      uint32_t boxes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      boxes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->boxes_length);
      if(boxes_lengthT > boxes_length)
        this->boxes = (kinect2_tracker::bounding_box*)realloc(this->boxes, boxes_lengthT * sizeof(kinect2_tracker::bounding_box));
      boxes_length = boxes_lengthT;
      for( uint32_t i = 0; i < boxes_length; i++){
      offset += this->st_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->boxes[i]), &(this->st_boxes), sizeof(kinect2_tracker::bounding_box));
      }
     return offset;
    }

    const char * getType(){ return "kinect2_tracker/user_points"; };
    const char * getMD5(){ return "6624cab0be89cfdee984fa8acaafad2a"; };

  };

}
#endif
