#! /usr/bin/env python3
import rospy
from std_msgs.msg import String

def msgCallback(msg):
    rospy.loginfo("New message recieved %s" , msg.data)


if __name__ == '__main__':
    rospy.init_node("simple_subscriber_py" , anonymous=True)
    rospy.Subscriber("Chatter" , String , msgCallback)

    rospy.spin()