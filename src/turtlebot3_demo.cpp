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
  log::info("Initialise the turtlebot3 demo");
}

Turtlebot3Demo::~Turtlebot3Demo()
{
  log::info("Shutdown the turtlebot3 demo");
  ros::shutdown();
}

void Turtlebot3Demo::result_callback(const move_base_msgs::MoveBaseActionGoal::ConstPtr &msg)
{
  if(msg->status.text == "Goal reached.")
    moving_state_ = false
}

void Turtlebot3Demo::goal_pose_callback(const ros::TimerEvent&)
{
  if (moving_state_ == true) 
  {
    geometry_msgs::PoseStamped msg;
    msg.pose.position.x = 0.5;
    msg.pose.position.y = 0.5;
    msg.pose.position.z = 0.0;
    msg.pose.orientation.w = 1.0;
    msg.pose.orientation.x = 0.0;
    msg.pose.orientation.y = 0.0;
    msg.pose.orientation.z = 0.0;

    goal_pose_pub_.at(index).publish(msg);
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtlebot3_demo");
  ros::NodeHandle node_handle("");

  // ROS publishers and subscribers
  goal_pose_pub_ = node_handle.advertise<geometry_msgs/PoseStamped>("/move_base_simple/goal", 10);
  result_sub_ = node_handle.subscribe("option", 10, &Turtlebot3Demo::result_callback, this);

  ros::Timer publish_timer = node_handle.createTimer(ros::Duration(10ms), &Turtlebot3Demo::goal_pose_callback);

  ros::Rate loop_rate(100);
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
} `