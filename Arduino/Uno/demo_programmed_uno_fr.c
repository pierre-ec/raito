#include <digitalWriteFast.h>
#include <SchedulerARMAVR.h>

unsigned int compteur_tableau = 0;

int led_centrale = 5;
int led_interne  = 3;
int led_milieu   = 2;
int led_externe  = 4;

float dc_base = 0.5;

float tableau_frequence_centrale[] = {1,2,1,1,1,7,10,10,7};   // en hertz
float tableau_frequence_interne[]  = {1,1,3,1,1,7,5,10,7};
float tableau_frequence_milieu[]   = {1,1,1,4,1,7,5,10,7};
float tableau_frequence_externe[]  = {1,1,1,1,5,7,5,10,7};

float tableau_duree[] = {2,2,2,2,5,5,5,10,10};    // en secondes

float taf_centrale, tef_centrale, taf_interne, tef_interne, taf_milieu, tef_milieu, taf_externe, tef_externe;

void blink_centrale(float fqa, float dc)

{

    taf_centrale=(1/fqa)*dc_base*1000;
    tef_centrale=(1/fqa)*(1-dc_base)*1000;
    
    digitalWriteFast(led_centrale, HIGH);
    delay(round(taf_centrale));
    
    digitalWriteFast(led_centrale, LOW);
    delay(round(tef_centrale));

}

void blink_interne(float fqa, float dc)

{

    taf_interne=(1/fqa)*dc_base*1000;
    tef_interne=(1/fqa)*(1-dc_base)*1000;
    
    digitalWriteFast(led_interne, HIGH);
    delay(round(taf_interne));
    
    digitalWriteFast(led_interne, LOW);
    delay(round(tef_interne));
    
}

void blink_milieu(float fqa, float dc)

{

    taf_milieu=(1/fqa)*dc_base*1000;
    tef_milieu=(1/fqa)*(1-dc_base)*1000;
    
    digitalWriteFast(led_milieu, HIGH);
    delay(round(taf_milieu));
    
    digitalWriteFast(led_milieu, LOW);
    delay(round(tef_milieu));
    
}

void blink_externe(float fqa, float dc)

{

    taf_externe=(1/fqa)*dc_base*1000;
    tef_externe=(1/fqa)*(1-dc_base)*1000;
    
    digitalWriteFast(led_externe, HIGH);
    delay(round(taf_externe));
    
    digitalWriteFast(led_externe, LOW);
    delay(round(tef_externe));
    
}

void setup() {

  pinModeFast(led_centrale, OUTPUT);
  pinModeFast(led_interne, OUTPUT);
  pinModeFast(led_milieu, OUTPUT);
  pinModeFast(led_externe, OUTPUT);

  Scheduler.startLoop(loop_interne);
  Scheduler.startLoop(loop_milieu);
  Scheduler.startLoop(loop_externe);
  Scheduler.startLoop(changement_frequence);

}

void loop() 

{

  blink_centrale(tableau_frequence_centrale[compteur_tableau], dc_base);  

}

void loop_interne()

{

  blink_interne(tableau_frequence_interne[compteur_tableau], dc_base);

}

void loop_milieu()

{

  blink_milieu(tableau_frequence_milieu[compteur_tableau], dc_base);

}

void loop_externe()

{

  blink_externe(tableau_frequence_externe[compteur_tableau], dc_base);

}

void changement_frequence()

{

  if (compteur_tableau<9)

  {

    delay(tableau_duree[compteur_tableau]*1000);
    compteur_tableau++;

  }

}