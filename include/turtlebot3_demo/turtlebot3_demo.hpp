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
#include <move_base_msgs/MoveBaseActionResult.h>
#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>

class Turtlebot3Demo
{
 public:
  Turtlebot3Demo();
  ~Turtlebot3Demo();
  bool init();

 private:
  // ROS nodehandle
  ros::NodeHandle nh_;
  uint8_t step_;

  // ROS publisher and subscribers
  ros::Publisher goal_pose_pub_;
  ros::Subscriber result_sub_;

  // Init and callback functions
  void result_callback(const move_base_msgs::MoveBaseActionResult::ConstPtr msg);
  void goal_pose_callback(const ros::TimerEvent&);
};
#endif //TURTLEBOT3_DEMO_HPP