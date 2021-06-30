# Blood-Pressure-Monitor
Our aim of this project is to semiautomate the blood pressure and heart rate measuring device using an STM microcontroller and an mpr pressure sensor.

# Components used:
Stm-32 microcontroller
Honeywell MPRLS0300YG00001BB pressure sensor
Manually inflatable blood pressure cuff
Silicone Tubing
F-F wire jumpers
# Steps to get BP/HR
measure pressure values from the Honeywell sensor: Use a 8.3 Kohm pull-up resistor, SCL and SDA are connected to PB-7 and PB-6 respectively("main.cpp").
Read the pressure data: Read the pressure data from serial using a python code "PY-serial.py" 800 pressure samples are taken.
Plot the pressure graph and check for uniform inflation and deflation rate.: Data samples from 150-650 has all the information needed("Sys_Dias_from_data.py").
detect and quantify pulse oscillations: Create an Oscillometric waveform using detrending.
Calculate Diastolic and Systolic values from oscillations.: Pressure sample with the highest frequency is the Mean arterial pressure, 80% of that is the diastolic pressure and 50% frquency gives the Systolic.
Calculate Heart Rate from oscillations.: heart rate is the distance between the peaks per minute. I am taking the average distance b/w 5 peaks and converting it to beats per minute
