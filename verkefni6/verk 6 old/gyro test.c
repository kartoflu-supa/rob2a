#pragma config(Sensor, in1,    turnAngle,         sensorGyro)
#pragma config(Sensor, in3,    rightLine,         sensorLineFollower)
#pragma config(Sensor, in4,    midLine,           sensorLineFollower)
#pragma config(Sensor, in5,    leftLine,          sensorLineFollower)
#pragma config(Sensor, in7,    clawTurn,          sensorPotentiometer)
#pragma config(Sensor, in8,    lightSensor,       sensorReflection)
#pragma config(Sensor, dgtl1,  bumber,            sensorTouch)
#pragma config(Sensor, dgtl2,  clawStop,          sensorTouch)
#pragma config(Sensor, dgtl4,  sonar,             sensorSONAR_cm)
#pragma config(Sensor, dgtl7,  rightEncoder,      sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftEncoder,       sensorQuadEncoder)
#pragma config(Motor,  port2,  rightMotor,        tmotorServoContinuousRotation, openLoop, encoder, encoderPort, dgtl7, 1000)
#pragma config(Motor,  port6,  clawMotor,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,  verticleClawMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,  leftMotor,         tmotorServoContinuousRotation, openLoop, reversed, encoder, encoderPort, None, 1000)

#include "../Headers/consts.h"
#include "../Functions/funcs.c"
task main()
{
	while(true){
	motor[leftMotor] = 32 + SensorValue[turnAngle];
	motor[rightMotor] = 32 - (SensorValue[turnAngle]);
	if (SensorValue[bumber] == 1) {
		gyro_turn(90);
	}
	}



}
