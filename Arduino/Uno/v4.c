#include <SchedulerARMAVR.h>

// DECLARATION DES VARIABLES //

unsigned int compteur_tableau = 0;
unsigned int compteur_tableau_sinusoide = 0;

// BROCHES PWM OBLIGATOIRES CAR UTILISATION DE L'ANALOGWRITE() POUR LES SINUSOIDES //

int led_centrale = 11;
int led_interne  = 10;
int led_milieu   = 6;
int led_externe  = 3;

float dc_base = 0.5;

float periode=0;

float taf_centrale, tef_centrale, taf_interne, tef_interne, taf_milieu, tef_milieu, taf_externe, tef_externe;

float compensation_led_centrale, compensation_led_interne, compensation_led_milieu, compensation_led_externe;


// // DECLARATION DES TABLEAUX // //

// Les fréquences sont en Hertz, les durées sont en secondes, les rapports de cycles sont des réels x avec 0 > x < 1 (pas encore implémentés) //


//////////////////////////////////////////////////////////////////////////


//// TABLEAUX DE FREQUENCES ////

// TABLEAUX POUR LA LED CENTRALE // 

float tableau_frequence_centrale_initiale[] = {1,1,5,1,1,2,1,2,10};   
float tableau_frequence_centrale_finale[]   = {1,10,5,1,1,2,1,2,1};   

// TABLEAUX POUR LE GROUPE DE LED INTERNE //

float tableau_frequence_interne_initiale[]  = {1,1,5,8,10,4,3,2,10};
float tableau_frequence_interne_finale[]    = {1,10,5,8,10,4,3,2,1};

// TABLEAUX POUR LE GROUPE DE LED INTERMEDIAIRE //

float tableau_frequence_milieu_initiale[]   = {1,1,5,8,10,4,1,4,10};
float tableau_frequence_milieu_finale[]     = {1,10,5,8,10,4,1,4,1};

// TABLEAUX POUR LE GROUPE DE LED EXTERNE //

float tableau_frequence_externe_initiale[]  = {1,1,5,8,10,4,3,4,10};
float tableau_frequence_externe_finale[]    = {1,10,5,8,10,4,3,4,1};

//////////////////////////////////////////////////////////////////////////

//// TABLEAUX DE RAPPORTS DE CYCLES ////

// A INSERER // 

// TABLEAU INDIQUANT LA DUREE DES SEQUENCES // 

float tableau_duree[] = {10,20,10,10,10,10,10,15,15};    

// TABLEAU INDIQUANT LA FORME DE L'ONDE (SINUSOIDALE OU CARREE) //

// CHOISIR LA VALEUR 0 POUR L'ONDE SINUSOIDALE //
// CHOISIR LA VALEUR 1 POUR L'ONDE CARREE //

float tableau_forme_onde_centrale[] = {0,0,1,1,0,1,0,0,0};
float tableau_forme_onde_interne[]  = {0,0,1,1,1,0,1,0,0};
float tableau_forme_onde_milieu[]   = {0,0,1,1,1,0,0,1,0};
float tableau_forme_onde_externe[]  = {0,0,1,1,1,0,1,1,0};

// TABLEAU DE DONNES POUR L'ONDE SINUSOIDALE //

byte tableau_sinusoide[] = 
	{0,2,2,3,4,
	6,9,12,16,20,
	24,29,35,40,46,
	53,59,66,73,81,
	88,96,104,112,119,
	128,128,136,143,151,
	159,167,174,182,189,
	196,202,209,215,220,
	226,231,235,239,243,
	246,249,251,253,254,
	255,255,255,255,255,
	251,249,246,243,239,
	235,231,226,220,215,
	209,202,196,189,182,
	174,167,159,151,143,
	136,128,119,112,104,
	96,88,81,73,66,
	59,53,46,40,35,
	29,24,20,16,12,
	9,6,4,2,1};

unsigned int nombre_de_valeurs = sizeof(tableau_sinusoide)/sizeof(byte);

//////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////

////// FONCTIONS CONTROLANT LA LED CENTRALE //////

///////////////////////////////////////////////////

void blink_centrale_sinusoide()

{

    analogWrite(led_centrale, tableau_sinusoide[compteur_tableau_sinusoide]);

    if ((tableau_sinusoide[compteur_tableau_sinusoide]) != 1) 

    {

    	periode = 1/tableau_frequence_centrale_initiale[compteur_tableau];

		  delay( (periode/nombre_de_valeurs) * 1000 );   
    	
      compteur_tableau_sinusoide++; 

    }

    else 

    {
    	compteur_tableau_sinusoide=0;

		if ((tableau_frequence_centrale_finale[compteur_tableau]) != (tableau_frequence_centrale_initiale[compteur_tableau]))

	  	{

	     	tableau_frequence_centrale_initiale[compteur_tableau]=tableau_frequence_centrale_initiale[compteur_tableau]+(compensation_led_centrale);
		    compensation_led_centrale=(tableau_frequence_centrale_finale[compteur_tableau]-tableau_frequence_centrale_initiale[compteur_tableau])/tableau_duree[compteur_tableau];

	 	  }

    }

}

void blink_centrale_carre(float fqa, float dc)

{

    taf_centrale=(1/fqa)*dc_base*1000;
    tef_centrale=(1/fqa)*(1-dc_base)*1000;
    
    digitalWrite(led_centrale, HIGH);
    delay(round(taf_centrale));
    
    digitalWrite(led_centrale, LOW);
    delay(round(tef_centrale));

}

///////////////////////////////////////////////////////////

////// FONCTIONS CONTROLANT LE GROUPE DE LED INTERNE //////

///////////////////////////////////////////////////////////

void blink_interne_sinusoide()

{

    analogWrite(led_interne, tableau_sinusoide[compteur_tableau_sinusoide]);

    if ((tableau_sinusoide[compteur_tableau_sinusoide]) != 1) 

    {

    	periode = 1/tableau_frequence_interne_initiale[compteur_tableau];

		delay( (periode/nombre_de_valeurs) * 1000 );   
    	
        compteur_tableau_sinusoide++; 

    }

    else 

    {
    	compteur_tableau_sinusoide=0;

		if ((tableau_frequence_interne_finale[compteur_tableau]) != (tableau_frequence_interne_initiale[compteur_tableau]))

	  	{

	   		tableau_frequence_interne_initiale[compteur_tableau]=tableau_frequence_interne_initiale[compteur_tableau]+(compensation_led_interne);
			compensation_led_interne=(tableau_frequence_interne_finale[compteur_tableau]-tableau_frequence_interne_initiale[compteur_tableau])/tableau_duree[compteur_tableau];

	 	}

    }

}

void blink_interne_carre(float fqa, float dc)

{
    taf_interne=(1/fqa)*dc_base*1000;
    tef_interne=(1/fqa)*(1-dc_base)*1000;
    
    digitalWrite(led_interne, HIGH);
    delay(round(taf_interne));
    
    digitalWrite(led_interne, LOW);
    delay(round(tef_interne));
}

/////////////////////////////////////////////////////////////////

////// FONCTIONS CONTROLANT LE GROUPE DE LED INTERMEDIAIRE //////

/////////////////////////////////////////////////////////////////

void blink_milieu_sinusoide()

{

    analogWrite(led_milieu, tableau_sinusoide[compteur_tableau_sinusoide]);

    if ((tableau_sinusoide[compteur_tableau_sinusoide]) != 1) 

    {

    	periode = 1/tableau_frequence_milieu_initiale[compteur_tableau];

		delay( (periode/nombre_de_valeurs) * 1000 );   
    	
        compteur_tableau_sinusoide++; 

    }

    else 

    {
    	compteur_tableau_sinusoide=0;

		if ((tableau_frequence_milieu_finale[compteur_tableau]) != (tableau_frequence_milieu_initiale[compteur_tableau]))

	  	{

	   		tableau_frequence_milieu_initiale[compteur_tableau]=tableau_frequence_milieu_initiale[compteur_tableau]+(compensation_led_milieu);
			compensation_led_milieu=(tableau_frequence_milieu_finale[compteur_tableau]-tableau_frequence_milieu_initiale[compteur_tableau])/tableau_duree[compteur_tableau];

	 	}

    }

}

void blink_milieu_carre(float fqa, float dc)

{

    taf_milieu=(1/fqa)*dc_base*1000;
    tef_milieu=(1/fqa)*(1-dc_base)*1000;
    
    digitalWrite(led_milieu, HIGH);
    delay(round(taf_milieu));
    
    digitalWrite(led_milieu, LOW);
    delay(round(tef_milieu));
    
}

///////////////////////////////////////////////////////////

////// FONCTIONS CONTROLANT LE GROUPE DE LED INTERNE //////

///////////////////////////////////////////////////////////

void blink_externe_sinusoide()

{

    analogWrite(led_externe, tableau_sinusoide[compteur_tableau_sinusoide]);

    if ((tableau_sinusoide[compteur_tableau_sinusoide]) != 1) 

    {

    	periode = 1/tableau_frequence_externe_initiale[compteur_tableau];

		delay( (periode/nombre_de_valeurs) * 1000 );   
    	
        compteur_tableau_sinusoide++; 

    }

    else 

    {
    	compteur_tableau_sinusoide=0;

		if ((tableau_frequence_externe_finale[compteur_tableau]) != (tableau_frequence_externe_initiale[compteur_tableau]))

	  	{

	   		tableau_frequence_externe_initiale[compteur_tableau]=tableau_frequence_externe_initiale[compteur_tableau]+(compensation_led_externe);
			compensation_led_externe=(tableau_frequence_externe_finale[compteur_tableau]-tableau_frequence_externe_initiale[compteur_tableau])/tableau_duree[compteur_tableau];

	 	}

    }

}

void blink_externe_carre(float fqa, float dc)

{

    taf_externe=(1/fqa)*dc_base*1000;
    tef_externe=(1/fqa)*(1-dc_base)*1000;
    
    digitalWrite(led_externe, HIGH);
    delay(round(taf_externe));
    
    digitalWrite(led_externe, LOW);
    delay(round(tef_externe));
    
}

// LANCEMENT DU SETUP (UNE SEULE FOIS)

void setup() {

  pinMode(led_centrale, OUTPUT);
  pinMode(led_interne, OUTPUT);
  pinMode(led_milieu, OUTPUT);
  pinMode(led_externe, OUTPUT);

  Scheduler.startLoop(loop_interne);
  Scheduler.startLoop(loop_milieu);
  Scheduler.startLoop(loop_externe);
  Scheduler.startLoop(changement_frequence);

}

// LANCEMENT DES BOUCLES //

void loop() 

{

  if (tableau_forme_onde_centrale[compteur_tableau]==0)

  {

 	 blink_centrale_sinusoide(); 

  }

  if (tableau_forme_onde_centrale[compteur_tableau]==1)

  {

	  blink_centrale_carre(tableau_frequence_centrale_initiale[compteur_tableau], dc_base); 

	  if ((tableau_frequence_centrale_finale) != (tableau_frequence_centrale_initiale))

	  {

	    compensation_led_centrale=(tableau_frequence_centrale_finale[compteur_tableau]-tableau_frequence_centrale_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
	    tableau_frequence_centrale_initiale[compteur_tableau]=tableau_frequence_centrale_initiale[compteur_tableau]+compensation_led_centrale;

	  }

  }

}

void loop_interne()

{

  if (tableau_forme_onde_interne[compteur_tableau]==0)

  {

 	 blink_interne_sinusoide(); 

  }

  if (tableau_forme_onde_interne[compteur_tableau]==1)

  {

	  blink_interne_carre(tableau_frequence_interne_initiale[compteur_tableau], dc_base); 

	  if ((tableau_frequence_interne_finale) != (tableau_frequence_interne_initiale))

	  {

	    compensation_led_interne=(tableau_frequence_interne_finale[compteur_tableau]-tableau_frequence_interne_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
	    tableau_frequence_interne_initiale[compteur_tableau]=tableau_frequence_interne_initiale[compteur_tableau]+compensation_led_interne;

	  }

  }

}

void loop_milieu()

{

  if (tableau_forme_onde_milieu[compteur_tableau]==0)

  {

 	 blink_milieu_sinusoide(); 

  }

  if (tableau_forme_onde_milieu[compteur_tableau]==1)

  {

	  blink_milieu_carre(tableau_frequence_milieu_initiale[compteur_tableau], dc_base); 

	  if ((tableau_frequence_milieu_finale) != (tableau_frequence_milieu_initiale))

	  {

	    compensation_led_milieu=(tableau_frequence_milieu_finale[compteur_tableau]-tableau_frequence_milieu_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
	    tableau_frequence_milieu_initiale[compteur_tableau]=tableau_frequence_milieu_initiale[compteur_tableau]+compensation_led_milieu;

	  }

  }

}

void loop_externe()

{

  if (tableau_forme_onde_externe[compteur_tableau]==0)

  {

 	 blink_externe_sinusoide(); 

  }

  if (tableau_forme_onde_externe[compteur_tableau]==1)

  {

	  blink_externe_carre(tableau_frequence_externe_initiale[compteur_tableau], dc_base); 

	  if ((tableau_frequence_externe_finale) != (tableau_frequence_externe_initiale))

	  {

	    compensation_led_externe=(tableau_frequence_externe_finale[compteur_tableau]-tableau_frequence_externe_initiale[compteur_tableau])/tableau_duree[compteur_tableau];
	    tableau_frequence_externe_initiale[compteur_tableau]=tableau_frequence_externe_initiale[compteur_tableau]+compensation_led_externe;

	  }

  }

}

void changement_frequence()

{

  if (compteur_tableau<9)

  {

    delay(tableau_duree[compteur_tableau]*1000);
    analogWrite(led_centrale, 0);
    analogWrite(led_interne, 0);
    analogWrite(led_milieu, 0);
    analogWrite(led_externe, 0);
    
    compteur_tableau++;

    compensation_led_centrale=0;
    compensation_led_interne=0;
    compensation_led_milieu=0;
    compensation_led_externe=0;

  }

}
