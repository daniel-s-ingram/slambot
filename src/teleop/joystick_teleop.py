#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

twist_msg = Twist()

def joy_callback(msg):
	twist_msg.linear.x = 2*msg.axes[4]
	twist_msg.angular.z = 2*msg.axes[3]

rospy.init_node('ps4_controller', anonymous=True)
rospy.Subscriber('/joy', Joy, joy_callback)
pub = rospy.Publisher('/slambot/diff_drive_controller/cmd_vel', Twist, queue_size=10)

while not rospy.is_shutdown():
	pub.publish(twist_msg)