import time
#import Adafruit_DHT

def temperature_humidity():
    while True:
        #sensor = Adafruit_DHT.DHT11
        pin = 4
        #humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
        humidity, temperature = [1, 2] #TEMPORARY
    
        if humidity is not None and temperature is not None:
            # return('Temp={0:0.1f}*  Humidity{1:0.1f}%'.format(temperature,humidity))
            return [1,2]
            # print('Temp={0:0.1f}*  Humidity{1:0.1f}%'.format(temperature,humidity))
        else:
            return('Error')            

        time.sleep(5)

if __name__ == '__main__':
    temperature_humidity()