import RPi.GPIO as GPIO
import time

# DECLARATIONS DES BROCHES #

groupe_led1=40

# DECLARATIONS DES COMPTEURS #

i=0

compteur_tableau_duree=0
compteur_tableau_dc=0
compteur_tableau_frequence=0

# DECLARATION DES TABLEAUX #

# # # # # # # # # # # # # # # # # # # # # # # # # # # # 

## TABLEAUX POUR LE PREMIER GROUPE DE LED ##

### FREQUENCE EN HERTZ

tableau_frequence_start1=[15, 1, 8,0]
tableau_frequence_end1=[1, 15, 8,0]

### RAPPORT DE CYCLE (DUTY CYCLE) NOMBRE REEL > 0 & < 100

tableau_dc_start1=[80.0, 10.0, 10.0,0.0]
tableau_dc_end1=[10.0, 80.0, 90.0,0.0]

# # # # # # # # # # # # # # # # # # # # # # # # # # # # 

## TABLEAUX DES DUREES ##

tableau_duree_sequence=[0,8,12,15,0]
duree_totale=15

# DECLARATIONS DES FONCTIONS D'ALLUMAGE / EXTINCTION #

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(groupe_led1, GPIO.OUT)

def end():
    GPIO.output(groupe_led1, GPIO.LOW)
    GPIO.cleanup()

# DEBUT DU PROGRAMME #
    
setup()

p1= GPIO.PWM(groupe_led1, tableau_frequence_start1[compteur_tableau_frequence])
p1.start(tableau_dc_start1[compteur_tableau_dc])

## CALCUL DES COMPENSATIONS ##

compensation_frequence=(tableau_frequence_end1[compteur_tableau_frequence]-tableau_frequence_start1[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
compensation_dc=(tableau_dc_end1[compteur_tableau_dc]-tableau_dc_start1[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000

## BOUCLE PRINCIPALE 

while i<duree_totale:

    while i<tableau_duree_sequence[compteur_tableau_duree+1]:

        tableau_frequence_start1[compteur_tableau_frequence]=tableau_frequence_start1[compteur_tableau_frequence]+compensation_frequence
        tableau_dc_start1[compteur_tableau_dc]=tableau_dc_start1[compteur_tableau_dc]+compensation_dc
   
        p1.ChangeFrequency(tableau_frequence_start1[compteur_tableau_frequence])
        p1.ChangeDutyCycle(tableau_dc_start1[compteur_tableau_dc])

        time.sleep(0.001)

        i=i+0.001

    compteur_tableau_duree=compteur_tableau_duree+1
    compteur_tableau_dc=compteur_tableau_dc+1
    compteur_tableau_frequence=compteur_tableau_frequence+1

    compensation_frequence=(tableau_frequence_end1[compteur_tableau_frequence]-tableau_frequence_start1[compteur_tableau_frequence])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    compensation_dc=(tableau_dc_end1[compteur_tableau_dc]-tableau_dc_start1[compteur_tableau_dc])/(tableau_duree_sequence[compteur_tableau_duree+1]-tableau_duree_sequence[compteur_tableau_duree])/1000
    
end()

print("Le programme s'est terminé correctement")
