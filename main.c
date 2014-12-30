/* Example of usage MPU6050 Library */
#include <stdbool.h>
#include "MPU6050.h"

int16_t ax,ay,az; // Accelerometer data
int16_t rx,ry,rz; // Gyroscope data

int main(void)
{
	MPU_I2C_ClockToggling();// I2C lockup prevernt
	
	MPU6050_I2C_Init();
	MPU6050_Initialize();
	//bool result = MPU6050_TestConnection(); // Uncomment if you want to test connection
    while(1)
    {
    	int16_t buffer[6];
    	MPU6050_GetRawAccelGyro(&buffer);
    	ax = buffer[0];
    	ay = buffer[1];
    	az = buffer[2];

    	rx = buffer[3];
    	ry = buffer[4];
    	rz = buffer[5];
    	for (int j = 0; j < 1000000; j++);
    }
}
