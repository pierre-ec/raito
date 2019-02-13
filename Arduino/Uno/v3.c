#include <digitalWriteFast.h>
#include <SchedulerARMAVR.h>

// DECLARATION DES VARIABLES //

unsigned int compteur_tableau = 0;

int led_centrale = 5;
int led_interne  = 3;
int led_milieu   = 2;
int led_externe  = 4;

float dc_base = 0.5;

float taf_centrale, tef_centrale, taf_interne, tef_interne, taf_milieu, tef_milieu, taf_externe, tef_externe;

float compensation_led_centrale, compensation_led_interne, compensation_led_milieu, compensation_led_externe;

// // DECLARATION DES TABLEAUX // //

// Les fréquences sont en Hertz, les durées sont en secondes, les rapports de cycles sont des réels x avec 0 > x < 1 (pas encore implémentés) //

// TABLEAUX POUR LA LED CENTRALE // 

float tableau_frequence_centrale_initiale[] = {1,1,2,3,1,7,1,2,1};   
float tableau_frequence_centrale_finale[] = {10,1,2,3,1,7,1,2,10};   

// TABLEAUX POUR LE GROUPE DE LED INTERNE //

float tableau_frequence_interne_initiale[]  = {1,1,2,3,1,7,1,2,1};
float tableau_frequence_interne_finale[]  = {1,1,2,3,1,7,1,2,10};

// TABLEAUX POUR LE GROUPE DE LED INTERMEDIAIRE //

float tableau_frequence_milieu_initiale[]   = {1,1,2,3,1,7,1,4,1};
float tableau_frequence_milieu_finale[]   = {1,1,2,3,1,7,1,4,10};

// TABLEAUX POUR LE GROUPE DE LED EXTERNE //

float tableau_frequence_externe_initiale[]  = {1,1,2,3,5,7,1,4,1};
float tableau_frequence_externe_finale[]  = {10,1,2,3,5,7,1,4,10};

// TABLEAU INDIQUANT LA DUREE DES SEQUENCES // 

float tableau_duree[] = {20,5,20,2,5,5,20,10,20};    


//////////////////////////////////////////////////////////////////////////


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

// LANCEMENT DU SETUP (UNE SEULE FOIS)

void setup() {

//  Serial.begin(9600);

  pinModeFast(led_centrale, OUTPUT);
  pinModeFast(led_interne, OUTPUT);
  pinModeFast(led_milieu, OUTPUT);
  pinModeFast(led_externe, OUTPUT);

  Scheduler.startLoop(loop_interne);
  Scheduler.startLoop(loop_milieu);
  Scheduler.startLoop(loop_externe);
  Scheduler.startLoop(changement_frequence);

}

// LANCEMENT DES BOUCLES

void loop() 

{

  blink_centrale(tableau_frequence_centrale_initiale[compteur_tableau], dc_base);  
//  Serial.println(tableau_frequence_centrale_initiale[compteur_tableau]);

  if ((tableau_frequence_centrale_finale) != (tableau_frequence_centrale_initiale))

  {

    compensation_led_centrale=(tableau_frequence_centrale_finale[compteur_tableau]-tableau_frequence_centrale_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
    tableau_frequence_centrale_initiale[compteur_tableau]=tableau_frequence_centrale_initiale[compteur_tableau]+compensation_led_centrale;
//    Serial.println(compensation_led_centrale);

  }

}

void loop_interne()

{

  blink_interne(tableau_frequence_interne_initiale[compteur_tableau], dc_base);

  if ((tableau_frequence_interne_finale) != (tableau_frequence_interne_initiale))

  {

    compensation_led_interne=(tableau_frequence_interne_finale[compteur_tableau]-tableau_frequence_interne_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
    tableau_frequence_interne_initiale[compteur_tableau]=tableau_frequence_interne_initiale[compteur_tableau]+compensation_led_interne;

  }

}

void loop_milieu()

{

  blink_milieu(tableau_frequence_milieu_initiale[compteur_tableau], dc_base);

  if ((tableau_frequence_milieu_finale) != (tableau_frequence_milieu_initiale))

  {

    compensation_led_milieu=(tableau_frequence_milieu_finale[compteur_tableau]-tableau_frequence_milieu_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
    tableau_frequence_milieu_initiale[compteur_tableau]=tableau_frequence_milieu_initiale[compteur_tableau]+compensation_led_milieu;

  }

}

void loop_externe()

{

  blink_externe(tableau_frequence_externe_initiale[compteur_tableau], dc_base);

  if ((tableau_frequence_externe_finale) != (tableau_frequence_externe_initiale))

  {

    compensation_led_externe=(tableau_frequence_externe_finale[compteur_tableau]-tableau_frequence_externe_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
    tableau_frequence_externe_initiale[compteur_tableau]=tableau_frequence_externe_initiale[compteur_tableau]+compensation_led_externe;

  }

}

void changement_frequence()

{

  if (compteur_tableau<9)

  {

    delay(tableau_duree[compteur_tableau]*1000);
    digitalWriteFast(led_centrale, LOW);
    digitalWriteFast(led_interne, LOW);
    digitalWriteFast(led_milieu, LOW);
    digitalWriteFast(led_externe, LOW);
    
    compteur_tableau++;

    compensation_led_centrale=0;
    compensation_led_interne=0;
    compensation_led_milieu=0;
    compensation_led_externe=0;

  }

}
