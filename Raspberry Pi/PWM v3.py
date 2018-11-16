import RPi.GPIO as GPIO
import time

# DECLARATIONS DES BROCHES #

groupe_led1=8        # LED CENTRALE 
groupe_led2=40       # GROUPE INTERIEUR
groupe_led3=38       # GROUPE INTERMEDIAIRE
groupe_led4=37       # GROUPE EXTERIEUR 

# DECLARATIONS DES COMPTEURS #

i=0

compteur_tableau_duree=0
compteur_tableau_dc=0
compteur_tableau_frequence=0

# DECLARATION DES TABLEAUX #

# # # # # # # # # # # # # # # # # # # # # # # # # # # # 

## TABLEAUX POUR LA LED CENTRALE ##

### FREQUENCE EN HERTZ

tableau_frequence_start1=[1, 2, 1,1,0]
tableau_frequence_end1=[1, 20, 20,1,0]

### RAPPORT DE CYCLE (DUTY CYCLE) NOMBRE REEL > 0 & < 100

tableau_dc_start1=[50.0, 50.0, 50.0,20.0,0.0]
tableau_dc_end1=[40.0, 50.0, 40.0,40.0,0.0]

# # # # # # # # # # # # # # # # # # # # # # # # # # # #

## TABLEAUX POUR LE GROUPE DE LED INTERIEUR ##

### FREQUENCE EN HERTZ

tableau_frequence_start2=[2, 2, 1,9,0]
tableau_frequence_end2=[4, 20, 20,9,0]

### RAPPORT DE CYCLE (DUTY CYCLE) NOMBRE REEL > 0 & < 100

tableau_dc_start2=[50.0, 50.0, 50.0,50.0,0.0]
tableau_dc_end2=[50.0, 10.0, 40.0,50.0,0.0]

# # # # # # # # # # # # # # # # # # # # # # # # # # # #

## TABLEAUX POUR LE GROUPE DE LED INTERMEDIAIRE ##

### FREQUENCE EN HERTZ

tableau_frequence_start3=[2, 2, 8,9,0]
tableau_frequence_end3=[3, 2.5, 8,9.5,0]

### RAPPORT DE CYCLE (DUTY CYCLE) NOMBRE REEL > 0 & < 100

tableau_dc_start3=[50.0, 50.0, 50.0,50.0,0.0]
tableau_dc_end3=[50.0, 50.0, 40.0,50.0,0.0]

# # # # # # # # # # # # # # # # # # # # # # # # # # # #

## TABLEAUX POUR LE GROUPE DE LED EXTERIEUR ##

### FREQUENCE EN HERTZ

tableau_frequence_start4=[2, 8, 1,9,0]
tableau_frequence_end4=[2, 8.5, 20,9,0]

### RAPPORT DE CYCLE (DUTY CYCLE) NOMBRE REEL > 0 & < 100

tableau_dc_start4=[50.0, 50.0, 50.0,50.0,0.0]
tableau_dc_end4=[50.0, 50.0, 35.0,50.0,0.0]

# # # # # # # # # # # # # # # # # # # # # # # # # # # #

## TABLEAUX DES DUREES ##

tableau_duree_sequence=[0,10,20,30,40,0]
duree_totale=40

# DECLARATIONS DES FONCTIONS D'ALLUMAGE / EXTINCTION #

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(groupe_led1, GPIO.OUT)
    GPIO.setup(groupe_led2, GPIO.OUT)
    GPIO.setup(groupe_led3, GPIO.OUT)
    GPIO.setup(groupe_led4, GPIO.OUT)

def end():
    GPIO.output(groupe_led1, GPIO.LOW)
    GPIO.output(groupe_led2, GPIO.LOW)
    GPIO.output(groupe_led3, GPIO.LOW)
    GPIO.output(groupe_led4, GPIO.LOW)
    GPIO.cleanup()

# DEBUT DU PROGRAMME #
    
setup()

p1= GPIO.PWM(groupe_led1, tableau_frequence_start1[compteur_tableau_frequence])
p1.start(tableau_dc_start1[compteur_tableau_dc])

p2= GPIO.PWM(groupe_led2, tableau_frequence_start2[compteur_tableau_frequence])
p2.start(tableau_dc_start2[compteur_tableau_dc])

p3= GPIO.PWM(groupe_led3, tableau_frequence_start3[compteur_tableau_frequence])
p3.start(tableau_dc_start3[compteur_tableau_dc])

p4= GPIO.PWM(groupe_led4, tableau_frequence_start4[compteur_tableau_frequence])
p4.start(tableau_dc_start4[compteur_tableau_dc])

## CALCUL DES COMPENSATIONS ##

compensation_frequence=(tableau_frequence_end1[compteur_tableau_frequence]-tableau_frequence_start1[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
compensation_dc=(tableau_dc_end1[compteur_tableau_dc]-tableau_dc_start1[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

compensation_frequence2=(tableau_frequence_end2[compteur_tableau_frequence]-tableau_frequence_start2[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
compensation_dc2=(tableau_dc_end2[compteur_tableau_dc]-tableau_dc_start2[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

compensation_frequence3=(tableau_frequence_end3[compteur_tableau_frequence]-tableau_frequence_start3[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
compensation_dc3=(tableau_dc_end3[compteur_tableau_dc]-tableau_dc_start3[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

compensation_frequence4=(tableau_frequence_end4[compteur_tableau_frequence]-tableau_frequence_start4[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
compensation_dc4=(tableau_dc_end4[compteur_tableau_dc]-tableau_dc_start4[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

## BOUCLE PRINCIPALE 

while i<duree_totale:

    while i<tableau_duree_sequence[compteur_tableau_duree+1]:

        tableau_frequence_start1[compteur_tableau_frequence]=tableau_frequence_start1[compteur_tableau_frequence]+compensation_frequence
        tableau_dc_start1[compteur_tableau_dc]=tableau_dc_start1[compteur_tableau_dc]+compensation_dc
        
        tableau_frequence_start2[compteur_tableau_frequence]=tableau_frequence_start2[compteur_tableau_frequence]+compensation_frequence2
        tableau_dc_start2[compteur_tableau_dc]=tableau_dc_start2[compteur_tableau_dc]+compensation_dc2

        tableau_frequence_start3[compteur_tableau_frequence]=tableau_frequence_start3[compteur_tableau_frequence]+compensation_frequence3
        tableau_dc_start3[compteur_tableau_dc]=tableau_dc_start3[compteur_tableau_dc]+compensation_dc3

        tableau_frequence_start4[compteur_tableau_frequence]=tableau_frequence_start4[compteur_tableau_frequence]+compensation_frequence4
        tableau_dc_start4[compteur_tableau_dc]=tableau_dc_start4[compteur_tableau_dc]+compensation_dc4                
   
        p1.ChangeFrequency(tableau_frequence_start1[compteur_tableau_frequence])
        p1.ChangeDutyCycle(tableau_dc_start1[compteur_tableau_dc])
        
        p2.ChangeFrequency(tableau_frequence_start2[compteur_tableau_frequence])
        p2.ChangeDutyCycle(tableau_dc_start2[compteur_tableau_dc])

        p3.ChangeFrequency(tableau_frequence_start3[compteur_tableau_frequence])
        p3.ChangeDutyCycle(tableau_dc_start3[compteur_tableau_dc])

        p4.ChangeFrequency(tableau_frequence_start4[compteur_tableau_frequence])
        p4.ChangeDutyCycle(tableau_dc_start4[compteur_tableau_dc])

        time.sleep(0.001)

        i=i+0.001

    compteur_tableau_duree=compteur_tableau_duree+1
    compteur_tableau_dc=compteur_tableau_dc+1
    compteur_tableau_frequence=compteur_tableau_frequence+1

    compensation_frequence=(tableau_frequence_end1[compteur_tableau_frequence]-tableau_frequence_start1[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    compensation_dc=(tableau_dc_end1[compteur_tableau_dc]-tableau_dc_start1[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

    compensation_frequence2=(tableau_frequence_end2[compteur_tableau_frequence]-tableau_frequence_start2[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    compensation_dc2=(tableau_dc_end2[compteur_tableau_dc]-tableau_dc_start2[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

    compensation_frequence3=(tableau_frequence_end3[compteur_tableau_frequence]-tableau_frequence_start3[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    compensation_dc3=(tableau_dc_end3[compteur_tableau_dc]-tableau_dc_start3[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

    compensation_frequence4=(tableau_frequence_end4[compteur_tableau_frequence]-tableau_frequence_start4[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    compensation_dc4=(tableau_dc_end4[compteur_tableau_dc]-tableau_dc_start4[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    
end()

print("Le programme s'est terminé correctement")
