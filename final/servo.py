#!/bin/python3

import RPi.GPIO as GPIO
import time

def toAng(angle):
	return angle*(12.0 - 2.5)/180.0 + 2.5

def main():
	servoPin = 4
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(servoPin, GPIO.OUT)
	servo = GPIO.PWM(servoPin, 50) 
	servo.start(toAng(90))
	try:
		while True:
			servo.ChangeDutyCycle(toAng(0))
			time.sleep(0.5)
			servo.ChangeDutyCycle(toAng(90))
			time.sleep(0.5)
			servo.ChangeDutyCycle(toAng(180))
			time.sleep(0.5)
			servo.ChangeDutyCycle(toAng(90))
			time.sleep(0.5)
	except KeyboardInterrupt:
		pass 
	GPIO.cleanup()

main()
