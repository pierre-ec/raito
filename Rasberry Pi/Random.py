import RPi.GPIO as GPIO
import time
import random

i=0
fqa=1
fqe=1
leds = 35
led_centrale = 12

def setup():
	
  GPIO.setmode(GPIO.BOARD)  
  
  GPIO.setup(leds, GPIO.OUT) 
  GPIO.setup(led_centrale, GPIO.OUT)
 
  GPIO.output(leds, GPIO.LOW)
  GPIO.output(led_centrale, GPIO.LOW)

def swg(frequence):
	
    temps=(1/frequence)/2
    
    GPIO.output(leds, GPIO.HIGH)
    GPIO.output(led_centrale, GPIO.HIGH)
    time.sleep(temps)
     
    GPIO.output(leds, GPIO.LOW)
    GPIO.output(led_centrale, GPIO.LOW)
    time.sleep(temps)
    
def desync_full(fqa, fqe):
    taf=(1/fqa)
    tef=(1/fqe)
     
    GPIO.output(leds, GPIO.HIGH)
    GPIO.output(led_centrale, GPIO.HIGH)
    time.sleep(taf)
      
    GPIO.output(leds, GPIO.LOW)
    GPIO.output(led_centrale, GPIO.LOW)
    time.sleep(tef)

def desync_cen(fqa, fqe):

    taf=(1/fqa)/2;
    tef=(1/fqe)/2;
    
    GPIO.output(led_centrale, GPIO.HIGH);
    time.sleep(taf);
    
    GPIO.output(led_centrale, GPIO.LOW);
    time.sleep(tef);

def extcen(fqa, fqe):

    taf=(1/fqa)/2;
    tef=(1/fqe)/2;
    
    GPIO.output(leds, GPIO.HIGH);
    GPIO.output(led_centrale, GPIO.LOW);
    time.sleep(taf);
    
    GPIO.output(leds, GPIO.LOW);
    GPIO.output(led_centrale, GPIO.HIGH);
    time.sleep(tef);

def end():
  GPIO.output(leds, GPIO.LOW)
  GPIO.output(led_centrale, GPIO.LOW)  
  GPIO.cleanup()                 

setup()
while i < 200:
    ran=random.randrange(5,20,1)
    swg(ran)
    i=i+1
ran1=random.randrange(8,15,1)
ran2=random.randrange(8,15,1)    
while i < 400:
    desync_full(ran1, ran2)
    i=i+1
while i < 600:
    ran1=random.randrange(8,15,1)
    ran2=random.randrange(8,15,1)
    desync_full(ran1, ran2)
    i=i+1
while i < 800:
    ran=random.randrange(4,30,1)
    swg(ran)
    i=i+1
ran=random.randrange(8,20,1)
while i < 1000:
    swg(ran)
    i=i+1
ran=random.randrange(8,20,1)
while i < 1200:
    swg(ran)
    i=i+1
while i < 1400:
    ran=random.randrange(8,20,1)
    swg(ran)
    i=i+1
ran1=random.randrange(8,15,1)
ran2=random.randrange(8,15,1)    
while i < 1600:
    desync_full(ran1, ran2)
    i=i+1
ran=random.randrange(8,20,1)
while i < 1800:
    swg(ran)
    i=i+1
while i < 2000:
    ran=random.randrange(8,20,1)
    swg(ran)
    i=i+1
ran1=random.randrange(12,20,1)
ran2=random.randrange(12,20,1)    
while i < 2200:
    desync_full(ran1, ran2)
    i=i+1  
while i < 2400:
    ran1=random.randrange(18,30,1)
    ran2=random.randrange(18,30,1)  
    desync_full(ran1, ran2)
    i=i+1
end()
    

