import RPi.GPIO as GPIO
import time

i=0
fqa=1
fqe=1
fqac=1
fqec=1
led1 = 29
led2 = 8
led3 = 31
led4 = 33
led5 = 40
led6 = 38
led7 = 35
led8 = 37
led_centrale = 12

def setup():
	
  GPIO.setmode(GPIO.BOARD)  
 
  GPIO.setup(led1, GPIO.OUT)
  GPIO.setup(led2, GPIO.OUT) 
  GPIO.setup(led3, GPIO.OUT) 
  GPIO.setup(led4, GPIO.OUT) 
  GPIO.setup(led5, GPIO.OUT) 
  GPIO.setup(led6, GPIO.OUT) 
  GPIO.setup(led7, GPIO.OUT) 
  GPIO.setup(led8, GPIO.OUT) 
  GPIO.setup(led_centrale, GPIO.OUT)

  GPIO.output(led1, GPIO.HIGH)
  GPIO.output(led2, GPIO.HIGH)
  GPIO.output(led3, GPIO.HIGH)
  GPIO.output(led4, GPIO.HIGH)
  GPIO.output(led5, GPIO.HIGH)
  GPIO.output(led6, GPIO.HIGH)  
  GPIO.output(led7, GPIO.HIGH)
  GPIO.output(led8, GPIO.HIGH)
  GPIO.output(led_centrale, GPIO.HIGH)

def swg(frequence):
	
    temps=(1/frequence)/2
    
    GPIO.output(led1, GPIO.HIGH)
    GPIO.output(led2, GPIO.HIGH)
    GPIO.output(led3, GPIO.HIGH)
    GPIO.output(led4, GPIO.HIGH)
    GPIO.output(led5, GPIO.HIGH)
    GPIO.output(led6, GPIO.HIGH)  
    GPIO.output(led7, GPIO.HIGH)
    GPIO.output(led8, GPIO.HIGH)
    GPIO.output(led_centrale, GPIO.HIGH)
    time.sleep(temps)
    
    GPIO.output(led1, GPIO.LOW)
    GPIO.output(led2, GPIO.LOW)
    GPIO.output(led3, GPIO.LOW)
    GPIO.output(led4, GPIO.LOW)
    GPIO.output(led5, GPIO.LOW)
    GPIO.output(led6, GPIO.LOW)  
    GPIO.output(led7, GPIO.LOW)
    GPIO.output(led8, GPIO.LOW)
    GPIO.output(led_centrale, GPIO.LOW)
    time.sleep(temps)
    
def desync_full(fqa, fqe):

    taf=(1/fqa)/2
    tef=(1/fqe)/2
    
    GPIO.output(led1, GPIO.HIGH)
    GPIO.output(led2, GPIO.HIGH)
    GPIO.output(led3, GPIO.HIGH)
    GPIO.output(led4, GPIO.HIGH)
    GPIO.output(led5, GPIO.HIGH)
    GPIO.output(led6, GPIO.HIGH)  
    GPIO.output(led7, GPIO.HIGH)
    GPIO.output(led8, GPIO.HIGH)
    GPIO.output(led_centrale, GPIO.HIGH)
    time.sleep(taf)
    
    GPIO.output(led1, GPIO.LOW)
    GPIO.output(led2, GPIO.LOW)
    GPIO.output(led3, GPIO.LOW)
    GPIO.output(led4, GPIO.LOW)
    GPIO.output(led5, GPIO.LOW)
    GPIO.output(led6, GPIO.LOW)  
    GPIO.output(led7, GPIO.LOW)
    GPIO.output(led8, GPIO.LOW)
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
    
    GPIO.output(led1, GPIO.HIGH);
    GPIO.output(led2, GPIO.HIGH);
    GPIO.output(led3, GPIO.HIGH);
    GPIO.output(led4, GPIO.HIGH);
    GPIO.output(led5, GPIO.HIGH);
    GPIO.output(led6, GPIO.HIGH);
    GPIO.output(led7, GPIO.HIGH);
    GPIO.output(led8, GPIO.HIGH);
    GPIO.output(led_centrale, GPIO.LOW);
    time.sleep(taf);
    
    GPIO.output(led1, GPIO.LOW);
    GPIO.output(led2, GPIO.LOW);
    GPIO.output(led3, GPIO.LOW);
    GPIO.output(led4, GPIO.LOW);
    GPIO.output(led5, GPIO.LOW);
    GPIO.output(led6, GPIO.LOW);
    GPIO.output(led7, GPIO.LOW);
    GPIO.output(led8, GPIO.LOW);
    GPIO.output(led_centrale, GPIO.HIGH);
    time.sleep(tef);


def extcen_2(fqa, fqe):

    taf=(1/fqa)/2;
    tef=(1/fqe)/2;
    
    GPIO.output(led1, GPIO.LOW);
    GPIO.output(led2, GPIO.HIGH);
    GPIO.output(led3, GPIO.LOW);
    GPIO.output(led4, GPIO.HIGH);
    GPIO.output(led5, GPIO.HIGH);
    GPIO.output(led6, GPIO.LOW);
    GPIO.output(led7, GPIO.LOW);
    GPIO.output(led8, GPIO.HIGH);
    GPIO.output(led_centrale, GPIO.LOW);
    time.sleep(taf);
    
    GPIO.output(led1, GPIO.HIGH);
    GPIO.output(led2, GPIO.LOW);
    GPIO.output(led3, GPIO.HIGH);
    GPIO.output(led4, GPIO.LOW);
    GPIO.output(led5, GPIO.LOW);
    GPIO.output(led6, GPIO.HIGH);
    GPIO.output(led7, GPIO.HIGH);
    GPIO.output(led8, GPIO.LOW);
    GPIO.output(led_centrale, GPIO.HIGH);
    time.sleep(tef);


def extcen_3(fqa, fqe):

    taf=(1/fqa)/2;
    tef=(1/fqe)/2;
    
    GPIO.output(led1, GPIO.HIGH);
    GPIO.output(led2, GPIO.LOW);
    GPIO.output(led3, GPIO.HIGH);
    GPIO.output(led4, GPIO.LOW);
    GPIO.output(led5, GPIO.LOW);
    GPIO.output(led6, GPIO.HIGH);
    GPIO.output(led7, GPIO.HIGH);
    GPIO.output(led8, GPIO.LOW);
    GPIO.output(led_centrale, GPIO.LOW);
    time.sleep(taf);
    
    GPIO.output(led1, GPIO.LOW);
    GPIO.output(led2, GPIO.HIGH);
    GPIO.output(led3, GPIO.LOW);
    GPIO.output(led4, GPIO.HIGH);
    GPIO.output(led5, GPIO.HIGH);
    GPIO.output(led6, GPIO.LOW);
    GPIO.output(led7, GPIO.LOW);
    GPIO.output(led8, GPIO.HIGH);
    GPIO.output(led_centrale, GPIO.HIGH);
    time.sleep(tef);

def end():
  GPIO.output(led1, GPIO.LOW)
  GPIO.output(led2, GPIO.LOW)
  GPIO.output(led3, GPIO.LOW)
  GPIO.output(led4, GPIO.LOW)
  GPIO.output(led5, GPIO.LOW)
  GPIO.output(led6, GPIO.LOW)
  GPIO.output(led7, GPIO.LOW)
  GPIO.output(led8, GPIO.LOW)
  GPIO.output(led_centrale, GPIO.LOW)  
  GPIO.cleanup()                 

setup()

while i<10:

  desync_cen(fqac, fqec)
  i=i+1
  fqac=fqac+0.2
  fqec=fqec+0.3

while i<14:

  extcen_3(fqac, fqec)
  i=i+1
  fqac=fqac+0.2
  fqec=fqec+0.1

while i<200:

  extcen_2(fqac, fqec)
  i=i+1
  fqac=fqac+0.2
  fqec=fqec+0.2

while i<400:

  swg(12.1)
  i=i+1

while i<600:

  desync_full(13.975,14.021)
  i=i+1

while i<800:

  swg(9.915)
  i=i+1

while i<1200:

  desync_full(10.321,8.512)
  i=i+1

while i<1400:

  swg(11.118)
  i=i+1

while i<1550:

  extcen_2(13.6,12.6)
  i=i+1

while i<1700:

  extcen_2(13.2456,13.1237)
  i=i+1

while i<1800:

  desync_full(11.3,8.2)
  i=i+1

while i<2000:

  swg(11.7)
  i=i+1

while i<2200:

  swg(11.75)
  i=i+1

while i<2400:

  desync_full(11.77,22.77)
  i=i+1

while i<2600:

  swg(11.9121457)
  i=i+1

while i<2610:

  swg(3.14159)
  i=i+1

while i<2700:

  extcen(6.454,13.14159)
  i=i+1

while i<2725:

  swg(7.14159)
  i=i+1

while i<2755:

  swg(9.14159)
  i=i+1

while i<3200:

  swg(14.14159)
  i=i+1

while i<3500:

  desync_full(14.14159,26)
  i=i+1

while i<3700:

  desync_full(18.14159,46)
  i=i+1

while i<3900:

  extcen_3(15.14159,12.871)
  i=i+1

while i<4100:

  extcen_2(13.14159,25.871)
  i=i+1

while i<4300:

  desync_full(17.14159,5.871)
  i=i+1

while i<4400:

  desync_full(19.14159,5.871)
  i=i+1

while i<4600:

  desync_full(25.14159,5.871)
  i=i+1

while i<5000:

  fqe=4
  desync_full(31.14159,fqe)
  i=i+1
  fqe=fqe+0.5

end()
    
