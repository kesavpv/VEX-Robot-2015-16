#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           rightBack,     tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           intakeHigh,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RightDrive,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           LeftDrive,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           intakeLow,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port9,           leftFront,     tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define Desired_RPM_Motor 107
#define Desired_RPM_FlyWheel 1928

float RPM_Right_Motor, RPM_Right_FlyWheel, RPM_Left_Motor, RPM_Left_FlyWheel;
/*
float AVG_Right[1000000000];

float avg(float a[])
{
	float sum = 0;
	float avg = 0;

	for (int i=0;i<1000000000;i++)
		sum += a[i];

		avg = sum/1000000000;

	return avg;
}*/
/*
fast = 120
med = 80
slow = 70
low = 50
*/

/*
task adjustRPM()
{
	diff = Desired_RPM_Motor - RPM_Right;

	if(abs(diff) < 20)
	{
		if(getRPM1() < RPM)
			med+=change;
		else if(getRPM1() > RPM)
			med-=change;

		if(getRPM2() < RPM)
			med+=change;
		else if(getRPM2() > RPM)
			med-=change;
	}
}
*/
//float fast = 120,
//float med = 90,
float slow = 65;
//float low = 50;

task main()
{
	//int i = 0;
	/*
	float
		fast = 120,
		med = 90,
		slow = 65,
		low = 50,

		diff,
		change = 1;
	*/

	float diff;
	float change = .1;

	resetMotorEncoder(leftBack);
	resetMotorEncoder(rightBack);

	//clearLCDLine(0);
	//displayLCDCenteredString(0, "Motor   FlyWheel");

	while(true)
	{
//	motor[intakeLow] = 127;
//	motor[intakeHigh] = 127;

		motor[rightFront]   = slow;
		motor[rightBack] = slow;
		motor[leftFront]   = slow;
		motor[leftBack] = slow;

		RPM_Right_Motor = getMotorVelocity(rightBack);
		RPM_Right_FlyWheel = RPM_Right_Motor * 18;

		//RPM_Left_Motor = getMotorVelocity(leftBack);
		//RPM_Left_FlyWheel = RPM_Left_Motor * 18;

		diff = Desired_RPM_FlyWheel - RPM_Right_FlyWheel;

		if(abs(diff) < 100)
		{
			if(RPM_Right_FlyWheel < Desired_RPM_FlyWheel)
				slow += change;
			else if(RPM_Right_FlyWheel > Desired_RPM_FlyWheel)
				slow -= change;

//			if(RPM_Left_Motor < Desired_RPM_Motor)
//				slow += change;
//			else if(RPM_Left_Motor > Desired_RPM_Motor)
//				slow -= change;
		}

		SensorValue[LED] = RPM_Right_FlyWheel > Desired_RPM_FlyWheel;

		//AVG_RIGHT[i] = RPM_Right_Motor;
		//i++;

		//clearLCDLine(1);
		//displayLCDNumber(1, 0, RPM_Right);
		//displayLCDNumber(1, 8, RPM_Right_FlyWheel);
	}
}
