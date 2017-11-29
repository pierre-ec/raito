import RPi.GPIO as GPIO
import time

i=0

groupe_led1=33
groupe_led2=35

compteur_tableau_duree=0
compteur_tableau_dc=0
compteur_tableau_frequence=0

tableau_duree=[60,120,180]

tableau_dc1=[50.0, 20.0, 80.0]
tableau_dc2=[20.0, 80.0, 50.0]

tableau_frequence1=[10, 1, 20]
tableau_frequence2=[1, 20, 10]

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(groupe_led1, GPIO.OUT)
    GPIO.setup(groupe_led2, GPIO.OUT)
    
def end():
    GPIO.output(groupe_led1, GPIO.LOW)
    GPIO.output(groupe_led2, GPIO.LOW)
    GPIO.cleanup()
    
setup()

p1= GPIO.PWM(groupe_led1, tableau_frequence1[compteur_tableau_frequence])
p2= GPIO.PWM(groupe_led2, tableau_frequence2[compteur_tableau_frequence])

p1.start(tableau_dc1[compteur_tableau_dc])
p2.start(tableau_dc2[compteur_tableau_dc])

while i<180:

    while i<tableau_duree[compteur_tableau_duree]:

        p1.ChangeDutyCycle(tableau_dc1[compteur_tableau_dc])
        p2.ChangeDutyCycle(tableau_dc2[compteur_tableau_dc])
        
        p1.ChangeFrequency(tableau_frequence1[compteur_tableau_frequence])
        p2.ChangeFrequency(tableau_frequence2[compteur_tableau_frequence])
        
        i=i+1
        time.sleep(1)
        
    compteur_tableau_duree=compteur_tableau_duree+1
    compteur_tableau_dc=compteur_tableau_dc+1
    compteur_tableau_frequence=compteur_tableau_frequence+1
    
end()


