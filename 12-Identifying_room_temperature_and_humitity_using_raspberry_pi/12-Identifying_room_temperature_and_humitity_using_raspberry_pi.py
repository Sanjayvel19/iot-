import Adafruit_DHT
SENSOR=Adafruit_DHT.DHT11
PIN=4
while True:
    humidity,temperature=Adafruit_DHT.read(SENSOR,PIN)
    if humidity is not None and temperature is not None:
        print('Temp={0:0.1f}*C Humidity={1:0.1f}%'.format(temperature,humidity))
    else:
        print('connection failed')



import time
import Adafruit_DHT
import requests
channel_id=1521416
write_key='WND956XF9P9OX5IS'
read_key='YSSKCVIKZDZRHIYS'
PIN=4
SENSOR=Adafruit_DHT.DHT11
def measure(channel):
    try:
        humidity,temperature=Adafruit_DHT.read_retry(SENSOR,PIN)
        response=channel.update({'field1': temperature,'field2': humidity})
        read=channel.get({})
        print("Read:",read)
    except:
        print("connection failed")


if __name__== "__main__":
    while True:
        measure(channel)
        time.sleep(15)
          
