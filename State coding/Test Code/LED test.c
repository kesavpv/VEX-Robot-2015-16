#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  LED,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  limit,          sensorTouch)
#pragma config(Sensor, I2C_1,  rightFlywheel,  sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftFlywheel,   sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           rightFront,    tmotorVex393HighSpeed_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           rightBack,     tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           intakeHigh,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightDrive,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           leftDrive,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           intakeLow,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           leftFront,     tmotorVex393HighSpeed_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port9,           leftBack,      tmotorVex393HighSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float encoder, rpm;

const int leftButton = 1;
const int centerButton = 2;
const int rightButton = 4;

/*
encoder
rpm
battery
*/
task main()
{
	resetMotorEncoder(rightFront);
	resetMotorEncoder(leftFront);

	clearLCDLine(0);
	displayLCDCenteredString(0, "Encoder RPM");

	while(true)
	{
		motor[rightFront] = 127;

		encoder = nMotorEncoder[rightFront];
		rpm = getMotorVelocity(rightFront);

		if(nLCDButtons == centerButton)
		{
			//
		}
		if(nLCDButtons == centerButton)
		{
			//
		}
		if(nLCDButtons == centerButton)
		{
			//
		}

		clearLCDLine(1);
		displayLCDNumber(1, 0, encoder);
		displayLCDNumber(1, 8, rpm);
	}
}
