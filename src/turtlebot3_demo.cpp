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
}

Turtlebot3Demo::~Turtlebot3Demo()
{
}

bool Turtlebot3Demo::init()
{
  // ROS publishers and subscribers
  goal_pose_pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 10);
  result_sub_ = nh_.subscribe("/move_base/result", 10, &Turtlebot3Demo::result_callback, this);

  return true;
}

void Turtlebot3Demo::result_callback(const move_base_msgs::MoveBaseActionResult::ConstPtr msg)
{
  if(msg->status.text == "Goal reached.")
  {
    geometry_msgs::PoseStamped msg;
    msg.pose.position.x = 0.5;
    msg.pose.position.y = 0.5;
    msg.pose.position.z = 0.0;
    msg.pose.orientation.w = 1.0;
    msg.pose.orientation.x = 0.0;
    msg.pose.orientation.y = 0.0;
    msg.pose.orientation.z = 0.0;

    goal_pose_pub_.publish(msg);
  }
}

void Turtlebot3Demo::goal_pose_callback(const ros::TimerEvent&)
{
}

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "turtlebot3_demo");

  Turtlebot3Demo tb3demo;
  
  ros::spin();

  return 0;
}
