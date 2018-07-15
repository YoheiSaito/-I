#!/usr/bin/python3

import os
import sys
import RPi.GPIO as GPIO
import pigpio

def toAng(angle):
	if (angle < 0):
		angle = 0
	if (angle > 180):
		angle = 180
	return int(angle/180.0*2000)+500

servo = pigpio.pi()
servo.set_servo_pulsewidth(18, toAng(int(sys.argv[1])))
