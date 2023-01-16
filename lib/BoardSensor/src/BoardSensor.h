/* The register map is provided at
 * https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf
 *
 * Mapping of the different gyro and accelero configurations:
 *
 * GYRO_CONFIG_[0,1,2,3] range = +- [250, 500,1000,2000] deg/s
 *                       sensi =    [131,65.5,32.8,16.4] bit/(deg/s)
 *
 * ACC_CONFIG_[0,1,2,3] range = +- [    2,   4,   8,  16] times the gravity (9.81 m/s^2)
 *                      sensi =    [16384,8192,4096,2048] bit/gravity
*/

#ifndef BoardSensor_H
#define BoardSensor_H

#include "Arduino.h"
#include "Wire.h"

#define BoardSensor_ADDR                  0x68
#define BoardSensor_SMPLRT_DIV_REGISTER   0x19
#define BoardSensor_CONFIG_REGISTER       0x1a
#define BoardSensor_GYRO_CONFIG_REGISTER  0x1b
#define BoardSensor_ACCEL_CONFIG_REGISTER 0x1c
#define BoardSensor_PWR_MGMT_1_REGISTER   0x6b

#define BoardSensor_GYRO_OUT_REGISTER     0x43
#define BoardSensor_ACCEL_OUT_REGISTER    0x3B

#define RAD_2_DEG             57.29578 // [deg/rad]
#define CALIB_OFFSET_NB_MES   500
#define TEMP_LSB_2_DEGREE     340.0    // [bit/celsius]
#define TEMP_LSB_OFFSET       12412.0

#define DEFAULT_GYRO_COEFF    0.98

class BoardSensor{
  public:
    // INIT and BASIC FUNCTIONS
	BoardSensor(TwoWire &w);
    byte begin(int gyro_config_num=1, int acc_config_num=0);
	
	byte writeData(byte reg, byte data);
    byte readData(byte reg);
	
	void calcOffsets(bool is_calc_gyro=true, bool is_calc_acc=true);
	void calcGyroOffsets(){ calcOffsets(true,false); }; // retro-compatibility with v1.0.0
	void calcAccOffsets(){ calcOffsets(false,true); }; // retro-compatibility with v1.0.0
	
	void setAddress(uint8_t addr){ address = addr; };
	uint8_t getAddress(){ return address; };
	
	// MPU CONFIG SETTER
	byte setGyroConfig(int config_num);
	byte setAccConfig(int config_num);
	
    void setGyroOffsets(float x, float y, float z);
	void setAccOffsets(float x, float y, float z);
	
	void setFilterGyroCoef(float gyro_coeff);
	void setFilterAccCoef(float acc_coeff);

	// MPU CONFIG GETTER
	float getGyroXoffset(){ return gyroXoffset; };
    float getGyroYoffset(){ return gyroYoffset; };
    float getGyroZoffset(){ return gyroZoffset; };
	
	float getAccXoffset(){ return accXoffset; };
	float getAccYoffset(){ return accYoffset; };
	float getAccZoffset(){ return accZoffset; };
	
	float getFilterGyroCoef(){ return filterGyroCoef; };
	float getFilterAccCoef(){ return 1.0-filterGyroCoef; };
	
	// DATA GETTER
    float Temperature(){ return temp; };

    float AccX(){ return accX; };
    float AccY(){ return accY; };
    float AccZ(){ return accZ; };

    float GyroX(){ return gyroX; };
    float GyroY(){ return gyroY; };
    float GyroZ(){ return gyroZ; };
	
	float AccAngleX(){ return angleAccX; };
    float AccAngleY(){ return angleAccY; };

    float AngleX(){ return angleX; };
    float AngleY(){ return angleY; };
    float AngleZ(){ return angleZ; };

	// ESP 32 Sensors
	int Hall();
	int Touch(int TouchPin);
	int Resistance(int ModPin,int R_board);
	//int ChargeLevel(int addressPin, double convFactor, int reads);  

	// INLOOP UPDATE
	void fetchData(); // user should better call 'update' that includes 'fetchData'
    void update();
	
	// UPSIDE DOWN MOUNTING
	bool upsideDownMounting = false;

  private:
    TwoWire *wire;
	uint8_t address = BoardSensor_ADDR;
	float gyro_lsb_to_degsec, acc_lsb_to_g;
    float gyroXoffset, gyroYoffset, gyroZoffset;
	float accXoffset, accYoffset, accZoffset;
    float temp, accX, accY, accZ, gyroX, gyroY, gyroZ;
    float angleAccX, angleAccY;
    float angleX, angleY, angleZ;
    long preInterval;
    float filterGyroCoef; 
	int HallVal,TouchVal;
	int ADC = 0; 
	float Vin = 3.3;
	float V;
    float R;        
};

#endif

