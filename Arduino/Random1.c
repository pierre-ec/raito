unsigned int i = 0; 
unsigned int compteur_tableau = 0;

const int Led1 = 2, Led2 = 3, Led3 = 4, Led4 = 5, 
Led5 = 6, Led6 = 7, Led7 = 8, Led8 = 9, LedCentrale = 11;

float taf, tef;

float dc_prog = 0.1;

float nombre_aleatoire = 0;
float nombre_aleatoire2 = 0;

float frequence_aleatoire;
float dc_aleatoire;

int tableau_duree[] = {100, 200, 300, 500, 700, 900, 1000, 1100, 1200, 1400,
					   1500, 1700, 1800, 2000, 2100, 2200, 2400, 2600, 2800, 
					   3000, 3100, 3200, 3300, 3400, 3600, 3700, 3900, 4000,
					   4100, 4200, 4300, 4350, 4400, 4600, 4700, 4800, 5000};

boolean flag = 1;

void setup() 

{               
  Serial.begin(9600);

  randomSeed(analogRead(0));

  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  pinMode(Led6, OUTPUT);
  pinMode(Led7, OUTPUT);
  pinMode(Led8, OUTPUT);
  pinMode(LedCentrale, OUTPUT);

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


void dc_desync_full(float fqa, float dc)

{

    taf=(1/fqa)*dc*1000;
    tef=(1/fqa)*(1-dc)*1000;
    
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    digitalWrite(Led5, HIGH);
    digitalWrite(Led6, HIGH);
    digitalWrite(Led7, HIGH);
    digitalWrite(Led8, HIGH);
    digitalWrite(LedCentrale, HIGH);
    delay(taf);
    
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    digitalWrite(Led6, LOW);
    digitalWrite(Led7, LOW);
    digitalWrite(Led8, LOW);
    digitalWrite(LedCentrale, LOW);
    delay(tef);

}

void rng()

{
  nombre_aleatoire=random(600, 2100);
  nombre_aleatoire2=random(200, 800);  
  frequence_aleatoire=(nombre_aleatoire)/100;
  dc_aleatoire=(nombre_aleatoire2)/1000;

  Serial.print("Fréquence : ");
  Serial.print(frequence_aleatoire);
  Serial.println(" Hz");
  Serial.print("Rapport de cycle : ");
  Serial.println(dc_aleatoire);
  Serial.println("");
}

void loop() 

{

if (flag != 0)

    {

      if ((i<tableau_duree[compteur_tableau]) & (flag!=0)) 

        {
              Serial.println("*** Lancement du générateur de nombres aléatoires ***");
              Serial.println("");
              rng();
        }


      while ((i<tableau_duree[compteur_tableau]) & (flag!=0)) 

        {
            dc_desync_full(frequence_aleatoire, dc_aleatoire);
            i++;
        }

      if ((i==5000) & (flag !=0))

        {
            Serial.println("****** Arrêt du programme ******");
            flag=0;
        }

      else 

        {
            compteur_tableau++;
        }


    }

}


