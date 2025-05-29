#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>


int main(int argc, char **argv)
{
    ros::init(argc , argv , "simple_publisher_cpp");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::String>("Chatter" , 10);
    ros::Rate rate(10);
    int counter = 0;

    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello World from CPP " << counter;
        msg.data = ss.str();
        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
        counter++;

    }
    
    return 0;
}
