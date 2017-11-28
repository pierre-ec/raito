/* Programme pour Arduino Mega (ATMEL 2560) */

#define PROGRAMME_1 1

// Déclaration et mise à zéro des compteurs.

unsigned int i = 0; 
unsigned int compteur_tableau_duree = 0;
unsigned int compteur_tableau_frequence = 0;
unsigned int compteur_tableau_dc = 0;
unsigned int compteur_tableau_lumen = 0;

// Déclaration des différentes broches de sorties. 

const int Led1 = 2, Led2 = 3, Led3 = 4, Led4 = 5, 
Led5 = 6, Led6 = 7, Led7 = 8, Led8 = 9, LedCentrale = 11;

// Déclaration des variables de temps pour la fonction principale. 

float taf, tef;

#ifdef PROGRAMME_1

// Ne sera compilé que si le programme 1 est défini plus haut par le #define. Permet de coder plusieurs programmes en dur en libérant de la mémoire.  

// Déclaration des tableaux de valeurs. 

const unsigned int tableau_duree[] = 
            {100,  300,   500,  700,  900, 1000, 1100, 1200, 1300, 1400,
					   1500, 1700, 1800, 2000, 2100, 2200, 2400, 2600, 2700, 2800, 
					   3000, 3100, 3200, 3300, 3400, 3600, 3700, 3900, 3950, 4000,
					   4100, 4200, 4300, 4350, 4400, 4600, 4700, 4800, 4900, 5000};

const float tableau_frequence[] = 
            {10.5, 13.9, 7.823, 12.1, 9.715, 12.12, 11, 10.5, 8, 9,
             9.5, 8.5, 19, 18, 17, 12, 10, 6, 10, 9.5,
             19, 19.6, 13, 15, 11, 7.3, 8.4, 9, 10, 5,
             7.6, 8.2, 8.5, 9.1, 10.3, 11.4, 13.5, 14.6, 15.3, 25};

const float tableau_dc[] = 
            {0.36, 0.45, 0.55, 0.48, 0.62, 0.39, 0.36, 0.2, 0.4, 0.5,
             0.55, 0.4, 0.5, 0.6, 0.7, 0.8, 0.45, 0.22, 0.4, 0.5,
             0.67, 0.4, 0.5, 0.6, 0.3, 0.76, 0.3, 0.2, 0.44, 0.5,
             0.3, 0.4, 0.5, 0.6, 0.43, 0.8, 0.13, 0.2, 0.64, 0.5};

const byte tableau_lumen_cen[] = 
            {20, 255, 80, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen1[] = 
            {20, 80, 255, 0, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen2[] = 
            {20, 80, 80, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen3[] = 
            {20, 80, 255, 0, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen4[] = 
            {20, 80, 80, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen5[] = 
            {20, 80, 80, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen6[] = 
            {20, 80, 255, 0, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen7[] = 
            {20, 80, 255, 0, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen8[] = 
            {20, 80, 80, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 
             255, 255, 255, 255, 255, 255, 255, 255, 255, 255};

const byte tableau_lumen_cen_off[] = 
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen1_off[] = 
            {0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen2_off[] = 
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen3_off[] = 
            {0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen4_off[] = 
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen5_off[] = 
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen6_off[] = 
            {0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen7_off[] = 
            {0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const byte tableau_lumen8_off[] = 
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
             0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


#endif

// Mise en place du feu vert : un booléen est soit vrai, soit faux. Initialisation à "vrai". 
boolean flag = 1;

void setup() 

{               
  // Initialisation de la communication avec le port série (à décommenter si besoin)
  // Serial.begin(9600);

  // Initialisation des différentes broches de sortie en mode "OUTPUT"
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
  pinMode(LedCentrale, OUTPUT);

  // Mise à zéro de toutes les broches de sortie
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(LedCentrale, LOW);

}

void dc_dim_desync_full(float fqa, float dc, byte lumen_cen, byte lumen1, byte lumen2, byte lumen3, byte lumen4, byte lumen5, byte lumen6, byte lumen7, byte lumen8, byte lumen_cen_off, byte lumen1_off, byte lumen2_off, byte lumen3_off, byte lumen4_off, byte lumen5_off, byte lumen6_off, byte lumen7_off, byte lumen8_off)

{
  // Définition de la fonction principale 
  // Le rapport de cycle (dc pour duty cycle en anglais) est le rapport entre le temps à l'état haut divisé sur la période de l'onde

  // On calcule le temps à attendre pour chaque évenement
    taf=(1/fqa)*dc*1000;
    tef=(1/fqa)*(1-dc)*1000;
    
  // On allume les LED, au pourcentage de luminosité défini dans les tableaux "lumen".  
    analogWrite(Led1, lumen1);
    analogWrite(Led2, lumen2);
    analogWrite(Led3, lumen3);
    analogWrite(Led4, lumen4);
    analogWrite(Led5, lumen5);
    analogWrite(Led6, lumen6);
    analogWrite(Led7, lumen7);
    analogWrite(Led8, lumen8);
    analogWrite(LedCentrale, lumen_cen);

  // On attend le temps précédemment calculé. Correspondra à la durée de l'état haut. 
    delay(taf); 
    
  // On éteint les LED (ou pas! tout est modulable avec les tableaux).    
    analogWrite(Led1, lumen1_off);
    analogWrite(Led2, lumen2_off);
    analogWrite(Led3, lumen3_off);
    analogWrite(Led4, lumen4_off);
    analogWrite(Led5, lumen5_off);
    analogWrite(Led6, lumen6_off);
    analogWrite(Led7, lumen7_off);
    analogWrite(Led8, lumen8_off);
    analogWrite(LedCentrale, lumen_cen_off);

  // On attend le temps précédemment calculé. Correspondra à la durée de l'état bas.   
    delay(tef);
}

void loop() 

{

// Vérification : le feu est-il au vert (le drapeau est-il "vrai" ou "faux") ? 

if (flag != 0)

// Si le feu est vert :   

/* Section à décommenter pour communiquer avec l'ordinateur par le port série, à une vitesse de 9600 bauds.

// Affichage de la fréquence en Hertz
  Serial.print("Fréquence : ");
  Serial.print(tableau_frequence[compteur_tableau_frequence]);
  Serial.println(" Hz");

// Affichage du rapport de cycle en pourcentage
  Serial.print("Rapport de cycle : ");
  Serial.print(tableau_dc[compteur_tableau_dc]*100);
  Serial.println(" %");

// Affichage de la luminosité des différentes leds en pourcentage
  Serial.print("Luminosité de la LED centrale : ");
  Serial.print((tableau_lumen_cen[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 1 : ");
  Serial.print((tableau_lumen1[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 2 : ");
  Serial.print((tableau_lumen2[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 3 : ");
  Serial.print((tableau_lumen3[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 4 : ");
  Serial.print((tableau_lumen4[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 5 : ");
  Serial.print((tableau_lumen5[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 6 : ");
  Serial.print((tableau_lumen6[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 7 : ");
  Serial.print((tableau_lumen7[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");

  Serial.print("Luminosité de la LED 8 : ");
  Serial.print((tableau_lumen8[compteur_tableau_lumen]*100)/255);
  Serial.println(" %");
  Serial.println("");

  */

    {

      while ((i<tableau_duree[compteur_tableau_duree]) & (flag!=0)) 

        {
            dc_dim_desync_full(tableau_frequence[compteur_tableau_frequence], tableau_dc[compteur_tableau_dc], tableau_lumen_cen[compteur_tableau_lumen], tableau_lumen1[compteur_tableau_lumen], tableau_lumen2[compteur_tableau_lumen], tableau_lumen3[compteur_tableau_lumen], tableau_lumen4[compteur_tableau_lumen], tableau_lumen5[compteur_tableau_lumen], tableau_lumen6[compteur_tableau_lumen], tableau_lumen7[compteur_tableau_lumen], tableau_lumen8[compteur_tableau_lumen], tableau_lumen_cen_off[compteur_tableau_lumen], tableau_lumen1_off[compteur_tableau_lumen], tableau_lumen2_off[compteur_tableau_lumen], tableau_lumen3_off[compteur_tableau_lumen], tableau_lumen4_off[compteur_tableau_lumen], tableau_lumen5_off[compteur_tableau_lumen], tableau_lumen6_off[compteur_tableau_lumen], tableau_lumen7_off[compteur_tableau_lumen], tableau_lumen8_off[compteur_tableau_lumen]);
            i++;
        }

      if ((i==5000) & (flag !=0))

        // Quand on arrive à la fin du tableau de durée, et que le feu est toujours vert, on passe au feu rouge (on met le drapeau à 0).

        {
        //  Serial.println("****** Arrêt du programme ******");
            flag=0;
        }

      else 

        // Tant que l'on est pas à la fin du tableau de durée, on passe à la valeur suivante dans chacun des tableaux.

        {
            compteur_tableau_duree++;
            compteur_tableau_frequence++;
            compteur_tableau_dc++;
            compteur_tableau_lumen++;
        }


    }

}


