#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define I2C1_REG_OFF 0x10161000
#define I2C2_REG_OFF 0x10144000
#define I2C3_REG_OFF 0x10148000

#define I2C_REG_DATA  0
#define I2C_REG_CNT   1
#define I2C_REG_CNTEX 2
#define I2C_REG_SCL   4

#define I2C_DEV_MCU  3
#define I2C_DEV_GYRO 10
#define I2C_DEV_IR   13

uint8_t ctr_core_i2cGetDeviceBusId(uint8_t device_id);
uint8_t ctr_core_i2cGetDeviceRegAddr(uint8_t device_id);

volatile uint8_t* ctr_core_i2cGetDataReg(uint8_t bus_id);
volatile uint8_t* ctr_core_i2cGetCntReg(uint8_t bus_id);

void ctr_core_i2cWaitBusy(uint8_t bus_id);
bool ctr_core_i2cGetResult(uint8_t bus_id);
uint8_t ctr_core_i2cGetData(uint8_t bus_id);
void ctr_core_i2cStop(uint8_t bus_id, uint8_t arg0);

bool ctr_core_i2cSelectDevice(uint8_t bus_id, uint8_t dev_reg);
bool ctr_core_i2cSelectRegister(uint8_t bus_id, uint8_t reg);

uint8_t ctr_core_i2cReadRegister(uint8_t dev_id, uint8_t reg);
bool ctr_core_i2cWriteRegister(uint8_t dev_id, uint8_t reg, uint8_t data);

bool ctr_core_i2cReadRegisterBuffer(uint8_t dev_id, uint8_t reg, uint8_t *buffer, size_t buf_size);
bool ctr_core_i2cWriteRegisterBuffer(uint8_t dev_id, uint8_t reg, const uint8_t *buffer, size_t buf_size);

#ifdef __cplusplus
}
#endif

