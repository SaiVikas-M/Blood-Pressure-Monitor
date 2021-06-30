# Blood-Pressure-Monitor
Aim of this project is to semiautomate the blood pressure and heart rate measuring device using an STM microcontroller and an mpr pressure sensor.

# Components used:
1. Stm-32 microcontroller <br /> 
2. Honeywell MPRLS0300YG00001BB pressure sensor <br /> 
3. Manually inflatable blood pressure cuff <br /> 
4. Silicone Tubing <br /> 
5. F-F wire jumpers <br /> 

# Steps to get Blood Pressure and Heart Rate
1. **Measure pressure values from the Honeywell sensor:** Use a 8.3 Kohm pull-up resistor, SCL and SDA are connected to PB-7 and PB-6 respectively("main.cpp"). <br /> 
2. **Read the pressure data:** Read the pressure data from serial using a python code "serial.py" 800 pressure samples are taken.<br /> 
3. **Plot the pressure graph and check for uniform inflation and deflation rate:** Data samples from 150-650 has all the information needed("Embedded_challenge.ipynb").<br /> 
4. **Detect and quantify pulse oscillations:** Create an Oscillometric waveform using detrending.<br /> 
5. **Calculate Diastolic and Systolic values from oscillations:** Pressure sample with the highest frequency is the Mean arterial pressure, 80% of that is the diastolic pressure and 50% frquency gives the Systolic.<br /> 
6. **Calculate Heart Rate from oscillations:** heart rate is the distance between the peaks per minute. I am taking the average distance b/w 5 peaks and converting it to beats per minute <br /> 
