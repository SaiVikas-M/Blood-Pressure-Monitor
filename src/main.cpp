/*
* Project:    Embedded Challenge
* File:       main.c
* Author:     Sai Vikas Mandadapu
*/

#include <mbed.h>
#include <string.h>

#include <USBSerial.h>
USBSerial serial;

I2C i2c(PB_7, PB_6);  //SCL & SDA Pins

const int add_write = 0x30;      // I2C write address
const int add_read = 0x31;       // I2C read address

char data[4];
u_int32_t pressure_data[4];

int main(){

    char cmd[3];
    while(1){
        
        cmd[0] =0xAA;
        cmd[1] =0x00;
        cmd[2]= 0x00;

        //I2C Communication
        i2c.write(add_write, cmd, 3);
        wait_ms(5);
        i2c.read(add_read,data,1);
        wait_ms(5);
        i2c.read(add_read,data,4);
        
        pressure_data[0]= data[0];
        pressure_data[1]= (u_int32_t)data[1] << 16;
        pressure_data[2]= (u_int32_t)data[2] << 8;
        pressure_data[3]= (u_int32_t)data[3];

        float output = float(pressure_data[1]|pressure_data[2]|pressure_data[3]);

        serial.printf(" %f \r\n", output);
        wait_ms(10);
    }
}