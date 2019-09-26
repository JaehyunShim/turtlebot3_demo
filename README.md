# TurtleBot3 Demo

## Usage
- Items: [Turtlebot3](http://emanual.robotis.com/docs/en/platform/turtlebot3/overview/) x 1

### Install ROS Kinetic
```sh
$ sudo apt-get update && sudo apt-get upgrade
$ wget https://raw.githubusercontent.com/rjshim/turtlebot3_demo/master/install_ros_kinetic.sh && chmod 755 ./install_ros_kinetic.sh && bash ./install_ros_kinetic.sh
```

### Install ROS packages and Build
```sh
(Move to your catkin workspace)
$ cd ~/catkin_ws/src/

(Download packages)
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3.git
$ git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
$ git clone https://github.com/rjshim/turtlebot3_demo.git

(Install binary packages)
http://emanual.robotis.com/docs/en/platform/turtlebot3/setup/#setup

(Build)
$ cd ~/catkin_ws && catkin_make

(Copy parameter files to TB3 navigation pkg)
$ rospack profile
$ cp `rospack find turtlebot3_demo`/nav_param/costmap_common_params_waffle_pi.yaml `rospack find turtlebot3_navigation`/param/
$ cp `rospack find turtlebot3_demo`/nav_param/dwa_local_planner_params_waffle_pi.yaml `rospack find turtlebot3_navigation`/param/
```

### Execute ROS packages
- Run below in the terminal window.

```sh
(Remote PC)
$ roscore

(Turtlebot3 PC)
$ roslaunch turtlebot3_bringup turtlebot3_robot.launch

(Remote PC)
$ export TURTLEBOT3_MODEL=${TB3_MODEL}
$ roslaunch turtlebot3_demo turtlebot3_demo.launch 
```

### Reference
- [turtlebot3](https://github.com/ROBOTIS-GIT/turtlebot3)
- [turtlebot3_msgs](https://github.com/ROBOTIS-GIT/turtlebot3_msgs)
- [turtlebot3 eManual](http://emanual.robotis.com/docs/en/platform/turtlebot3/overview/)
