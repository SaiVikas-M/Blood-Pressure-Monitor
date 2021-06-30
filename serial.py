import serial
import time
ser = serial.Serial(
    port='COM6',
    baudrate=9600,
    parity=serial.PARITY_EVEN,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=0)
data =[]                       
cnt = 0
while(1):
    b = ser.read()         
    string_n = b.decode()    
    string = string_n.rstrip() 
    temp = ''
    while bool(string):
        temp = temp+string
        b = ser.read()         
        string_n = b.decode()    
        string = string_n.rstrip() 
    data.append(temp)           
    new_list = list(filter(None, data))
    print(temp)
    if len(new_list)>800:
        break
    time.sleep(0.01)
print(new_list)
file1 = open("Pressure_sensor_output.txt","w+")
file1.write(str(new_list))
file1.close()