#ifndef _ROS_kinect2_tracker_user_IDs_h
#define _ROS_kinect2_tracker_user_IDs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kinect2_tracker
{

  class user_IDs : public ros::Msg
  {
    public:
      uint32_t users_length;
      typedef uint8_t _users_type;
      _users_type st_users;
      _users_type * users;

    user_IDs():
      users_length(0), users(NULL)
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
     return offset;
    }

    const char * getType(){ return "kinect2_tracker/user_IDs"; };
    const char * getMD5(){ return "0370fea64fb82134b7a78a66cb25797c"; };

  };

}
#endif
