/*
  This is just a test. This node subscribes to the State topic and receives a
  State message.
 */

#include "ros/ros.h"
#include "irobotcreate2/State.h"

#include <string>
#include <sstream>

void StateReceived(const irobotcreate2::State& q)
{
  std::stringstream ss;
  std::string msg;

  ss << "x: " << q.x << '\t' << "y: " << q.y << '\t' << "theta: " << 
    q.theta << '\t' << "v: " << q.v << '\t' << "desiredV: " << q.desiredV;

  ss >> msg;
  ss.clear();

  ROS_INFO("Received: [%s]", msg.c_str()); 
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("CoordMeas", 1000, StateReceived);

  ros::spin();

  return 0;
}
