import RPi.GPIO as GPIO
import time
from tkinter import *
from threading import Thread

i = 0

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

    taf=(1/fqa)
    tef=(1/fqe)
    
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

    taf=(1/fqa)/2
    tef=(1/fqe)/2
    
    GPIO.output(led_centrale, GPIO.HIGH)
    delay(taf)
    
    GPIO.output(led_centrale, GPIO.LOW)
    delay(tef)

def extcen(fqa, fqe):

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
    GPIO.output(led_centrale, GPIO.LOW)
    delay(taf)
    
    GPIO.output(led1, GPIO.LOW)
    GPIO.output(led2, GPIO.LOW)
    GPIO.output(led3, GPIO.LOW)
    GPIO.output(led4, GPIO.LOW)
    GPIO.output(led5, GPIO.LOW)
    GPIO.output(led6, GPIO.LOW)
    GPIO.output(led7, GPIO.LOW)
    GPIO.output(led8, GPIO.LOW)
    GPIO.output(led_centrale, GPIO.HIGH)
    delay(tef)

def extcen_2(fqa, fqe):

    taf=(1/fqa)/2
    tef=(1/fqe)/2
    
    GPIO.output(led1, GPIO.LOW)
    GPIO.output(led2, GPIO.HIGH)
    GPIO.output(led3, GPIO.LOW)
    GPIO.output(led4, GPIO.HIGH)
    GPIO.output(led5, GPIO.HIGH)
    GPIO.output(led6, GPIO.LOW)
    GPIO.output(led7, GPIO.LOW)
    GPIO.output(led8, GPIO.HIGH)
    GPIO.output(led_centrale, GPIO.LOW)
    delay(taf)
    
    GPIO.output(led1, GPIO.HIGH)
    GPIO.output(led2, GPIO.LOW)
    GPIO.output(led3, GPIO.HIGH)
    GPIO.output(led4, GPIO.LOW)
    GPIO.output(led5, GPIO.LOW)
    GPIO.output(led6, GPIO.HIGH)
    GPIO.output(led7, GPIO.HIGH)
    GPIO.output(led8, GPIO.LOW)
    GPIO.output(led_centrale, GPIO.HIGH)
    delay(tef)

def extcen_3(fqa, fqe):

    taf=(1/fqa)/2
    tef=(1/fqe)/2
    
    GPIO.output(led1, GPIO.HIGH)
    GPIO.output(led2, GPIO.LOW)
    GPIO.output(led3, GPIO.HIGH)
    GPIO.output(led4, GPIO.LOW)
    GPIO.output(led5, GPIO.LOW)
    GPIO.output(led6, GPIO.HIGH)
    GPIO.output(led7, GPIO.HIGH)
    GPIO.output(led8, GPIO.LOW)
    GPIO.output(led_centrale, GPIO.LOW)
    delay(taf)
    
    GPIO.output(led1, GPIO.LOW)
    GPIO.output(led2, GPIO.HIGH)
    GPIO.output(led3, GPIO.LOW)
    GPIO.output(led4, GPIO.HIGH)
    GPIO.output(led5, GPIO.HIGH)
    GPIO.output(led6, GPIO.LOW)
    GPIO.output(led7, GPIO.LOW)
    GPIO.output(led8, GPIO.HIGH)
    GPIO.output(led_centrale, GPIO.HIGH)
    delay(tef)

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

def tstart():
    thread = led_thread()
    thread.start()

def running():
#  selection = "L'allumage est à " + str(scale_fqa.get()) + " Hz et l'extinction à " + str(scale_fqe.get()) + " Hz"
#  label.config(text = selection)
   setup()
   tstart()

class led_thread(Thread):

    def __init__(self):
        super(led_thread, self).__init__()
        self._run = True

    def run(self):
        while (self._run):
            input1=scale_fqa.get()
            input2=scale_fqe.get()
            desync_full(input1, input2)
            
    def stop(self):
        self._run = False
        end()
      
root = Tk()
root.title("Magnifique interface de contrôle")
root.geometry("1200x200+500+400")

scale_fqa = DoubleVar()
scale_fqe = DoubleVar()

scale = Scale(root, from_= 1, to = 100, length = 1200, bd=5,resolution = 0.0001, variable = scale_fqa, orient = HORIZONTAL, label = "Fréquence Allumage")
scale.pack(anchor = CENTER)

scale = Scale(root, from_= 1, to = 100, length = 1200, bd=5,resolution = 0.0001, variable = scale_fqe, orient = HORIZONTAL, label = "Fréquence Extinction")
scale.pack(anchor = CENTER)

button = Button(root, text="Let's go !", command=running)
button.pack(anchor = CENTER)

button = Button(root, text="Stop !", command=end)
button.pack(anchor = CENTER)

label = Label(root)
label.pack()

root.mainloop()
