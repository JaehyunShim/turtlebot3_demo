/*******************************************************************************
* Copyright 2019 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Ryan Shim */

#include "turtlebot3_demo/turtlebot3_demo.hpp"


Turtlebot3Demo::Turtlebot3Demo()
{
  bool init_result = init();
  ROS_ASSERT(init_result);

  state_ = 1;
}

Turtlebot3Demo::~Turtlebot3Demo()
{
}

bool Turtlebot3Demo::init()
{
  goal_pose_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 10);
  result_sub_ = nh_.subscribe("/move_base/result", 10, &Turtlebot3Demo::result_callback, this);

  return true;
}

void Turtlebot3Demo::result_callback(const move_base_msgs::MoveBaseActionResult::ConstPtr result)
{
  if(!strcmp(result->status.text.c_str(), "Goal reached."))
  {
    geometry_msgs::PoseStamped msg;
    tf2::Quaternion q;

    // Header
    msg.header.frame_id = "map";
    msg.header.stamp = ros::Time::now();

    // Pose
    if (state_ == 1)
    {
      msg.pose.position.x = 0.0;  
      msg.pose.position.y = -0.8;
      msg.pose.position.z = 0.0;
      q.setRPY(0, 0, 1.57);  // roll, pitch, yaw
      msg.pose.orientation.x = q[0];
      msg.pose.orientation.y = q[1];
      msg.pose.orientation.z = q[2];
      msg.pose.orientation.w = q[3];
      state_++;
    }
    else if (state_ == 2)
    {
      msg.pose.position.x = 0.0;  
      msg.pose.position.y = -0.8;
      msg.pose.position.z = 0.0;
      q.setRPY(0, 0, -1.57);  // roll, pitch, yaw
      msg.pose.orientation.x = q[0];
      msg.pose.orientation.y = q[1];
      msg.pose.orientation.z = q[2];
      msg.pose.orientation.w = q[3];
      state_++;
    }
    else if (state_ == 3)
    {
      msg.pose.position.x = 0.0;  
      msg.pose.position.y = 0.0;  
      msg.pose.position.z = 0.0;
      q.setRPY(0, 0, 3.14);  // roll, pitch, yaw
      msg.pose.orientation.x = q[0];
      msg.pose.orientation.y = q[1];
      msg.pose.orientation.z = q[2];
      msg.pose.orientation.w = q[3];
      state_++;
    }
    else
    {
      msg.pose.position.x = 0.0;  
      msg.pose.position.y = 0.0;  
      msg.pose.position.z = 0.0;
      q.setRPY(0, 0, 0);  // roll, pitch, yaw
      msg.pose.orientation.x = q[0];
      msg.pose.orientation.y = q[1];
      msg.pose.orientation.z = q[2];
      msg.pose.orientation.w = q[3];
      state_ = 1;
    }

    ros::Duration(2.0).sleep(); 
    goal_pose_pub_.publish(msg);
  }
}

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "turtlebot3_demo");

  Turtlebot3Demo tb3demo;
  
  ros::spin();

  return 0;
}
