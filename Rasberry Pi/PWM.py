import RPi.GPIO as GPIO
import time

i=0
fq1=1
fq2=1
fqa=1
fqe=1
fqac=1
fqec=1
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

duty_cycle = 0
setup()
p = GPIO.PWM(35, 80)
p.start(0)
while i < 100:
    for duty_cycle in range (0, 101, 1):
        p.ChangeDutyCycle(duty_cycle)
        time.sleep(0.01)
        i=i+1
    for duty_cycle in range (100, 7, -1):
        p.ChangeDutyCycle(duty_cycle)
        desync_cen(15,10)
        time.sleep(0.01)
        p.ChangeFrequency(duty_cycle)
        i=i+1
while i < 300:
    desync_cen(7.5,3)
    p.ChangeFrequency(7.5)
    p.ChangeDutyCycle(50)
    i=i+1
while i < 500:
    desync_full(19.1214, 16.1339)
    i=i+1
while i < 600:
    desync_cen(3,5)
    p.ChangeFrequency(14.5)
    p.ChangeDutyCycle(45.5)
    i=i+1
while i < 700:
    swg(9.1214)
    i=i+1
while i < 1000:
    for duty_cycle in range (9, 101, 1):
        p.ChangeDutyCycle(duty_cycle)
        desync_cen(13,26)
        time.sleep(0.01)
        p.ChangeFrequency(duty_cycle)
        i=i+1
    for duty_cycle in range (100, 9, -1):
        p.ChangeDutyCycle(duty_cycle)
        desync_cen(26,13)
        time.sleep(0.01)
        p.ChangeFrequency(duty_cycle)
        i=i+1
while i < 1100:
    desync_full(9.1214, 8.8339)
    i=i+1
while i < 1200:
    desync_full(16.1214, 7.8339)
    i=i+1
while i < 1400:
    desync_full(12.1214, 11.8339)
    i=i+1
end()
    
