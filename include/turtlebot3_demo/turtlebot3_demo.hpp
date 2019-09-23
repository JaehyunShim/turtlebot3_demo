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

#ifndef TURTLEBOT3_DEMO_HPP
#define TURTLEBOT3_DEMO_HPP

#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <ros/ros.h>


class Turtlebot3Demo
{
 private:
  // ROS publisher and subscribers
  ros::Publisher goal_pose_pub_;
  ros::Subscriber result_sub_;

  bool moving_state_;

 public:

  Turtlebot3Demo();
  ~Turtlebot3Demo();

  void publishCallback(const ros::TimerEvent&);
  void openManipulatorOptionCallback(const std_msgs::String::ConstPtr &msg);
};
#endif //TURTLEBOT3_DEMO_HPP