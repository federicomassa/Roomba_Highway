/*
  This is just a test. This node subscribes to the State topic and receives a
  State message.
 */

#include "ros/ros.h"
#include "irobotcreate2/SensingVector.h"

#include <string>
#include <sstream>

void StateReceived(const irobotcreate2::SensingVector& sv)
{
  std::string msg;

  msg = std::to_string(sv.sList.size()) + " states.\n";

  for (int i = 0; i < sv.sList.size(); i++)
    {
      msg += "[ID: " + std::to_string(sv.sList[i].id) + "\tx: " + std::to_string(sv.sList[i].x) + "\ty: " + std::to_string(sv.sList[i].y) + "\ttheta: " + 
	std::to_string(sv.sList[i].theta) + "\tv: " + std::to_string(sv.sList[i].v) + "]\n";
    }

  ROS_INFO("Received: %s", msg.c_str()); 
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("CoordMeas", 1000, StateReceived);

  ros::spin();

  return 0;
}
