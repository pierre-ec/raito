#include <digitalWriteFast.h>

int i = 0; 

const int Led1 = 2, Led2 = 3, Led3 = 4, Led4 = 5, 
Led5 = 6, Led6 = 7, Led7 = 8, Led8 = 9, LedCentrale = 11;

const int Bouton1 = 10, Bouton2 = 12;

float fq = 1, fqa, fqe, fqac, fqec, taf, tef, frequence, lumen = 0;

void setup() 

{               

  pinMode(Bouton1, INPUT_PULLUP);
  pinMode(Bouton2, INPUT_PULLUP);

  pinModeFast(Led1, OUTPUT);
  pinModeFast(Led2, OUTPUT);
  pinModeFast(Led3, OUTPUT);
  pinModeFast(Led4, OUTPUT);
  pinModeFast(Led5, OUTPUT);
  pinModeFast(Led6, OUTPUT);
  pinModeFast(Led7, OUTPUT);
  pinModeFast(Led8, OUTPUT);
  pinModeFast(LedCentrale, OUTPUT);

  digitalWriteFast(Led1, LOW);
  digitalWriteFast(Led2, LOW);
  digitalWriteFast(Led3, LOW);
  digitalWriteFast(Led4, LOW);
  digitalWriteFast(Led5, LOW);
  digitalWriteFast(Led6, LOW);
  digitalWriteFast(Led7, LOW);
  digitalWriteFast(Led8, LOW);
  digitalWriteFast(LedCentrale, LOW);

}

void swg(float frequence) 

{

  float temps;

  temps = (1/frequence)*500;

  digitalWriteFast(Led1, HIGH);
  digitalWriteFast(Led2, HIGH);
  digitalWriteFast(Led3, HIGH);
  digitalWriteFast(Led4, HIGH);
  digitalWriteFast(Led5, HIGH);
  digitalWriteFast(Led6, HIGH);
  digitalWriteFast(Led7, HIGH);
  digitalWriteFast(Led8, HIGH);
  digitalWriteFast(LedCentrale, HIGH);
  delay(temps);
  
  digitalWriteFast(Led1, LOW);
  digitalWriteFast(Led2, LOW);
  digitalWriteFast(Led3, LOW);
  digitalWriteFast(Led4, LOW);
  digitalWriteFast(Led5, LOW);
  digitalWriteFast(Led6, LOW);
  digitalWriteFast(Led7, LOW);
  digitalWriteFast(Led8, LOW);
  digitalWriteFast(LedCentrale, LOW);
  delay(temps);

}

void desync_full(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWriteFast(Led1, HIGH);
    digitalWriteFast(Led2, HIGH);
    digitalWriteFast(Led3, HIGH);
    digitalWriteFast(Led4, HIGH);
    digitalWriteFast(Led5, HIGH);
    digitalWriteFast(Led6, HIGH);
    digitalWriteFast(Led7, HIGH);
    digitalWriteFast(Led8, HIGH);
    digitalWriteFast(LedCentrale, HIGH);
    delay(taf);
    
    digitalWriteFast(Led1, LOW);
    digitalWriteFast(Led2, LOW);
    digitalWriteFast(Led3, LOW);
    digitalWriteFast(Led4, LOW);
    digitalWriteFast(Led5, LOW);
    digitalWriteFast(Led6, LOW);
    digitalWriteFast(Led7, LOW);
    digitalWriteFast(Led8, LOW);
    digitalWriteFast(LedCentrale, LOW);
    delay(tef);

}

void desync_cen(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    analogWrite(LedCentrale, lumen);
    delay(taf);
    
    analogWrite(LedCentrale, lumen);
    delay(tef);

}


void extcen(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWriteFast(Led1, HIGH);
    digitalWriteFast(Led2, HIGH);
    digitalWriteFast(Led3, HIGH);
    digitalWriteFast(Led4, HIGH);
    digitalWriteFast(Led5, HIGH);
    digitalWriteFast(Led6, HIGH);
    digitalWriteFast(Led7, HIGH);
    digitalWriteFast(Led8, HIGH);
    digitalWriteFast(LedCentrale, LOW);
    delay(taf);
    
    digitalWriteFast(Led1, LOW);
    digitalWriteFast(Led2, LOW);
    digitalWriteFast(Led3, LOW);
    digitalWriteFast(Led4, LOW);
    digitalWriteFast(Led5, LOW);
    digitalWriteFast(Led6, LOW);
    digitalWriteFast(Led7, LOW);
    digitalWriteFast(Led8, LOW);
    digitalWriteFast(LedCentrale, HIGH);
    delay(tef);
}

void extcen_2(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWriteFast(Led1, LOW);
    digitalWriteFast(Led2, HIGH);
    digitalWriteFast(Led3, LOW);
    digitalWriteFast(Led4, HIGH);
    digitalWriteFast(Led5, HIGH);
    digitalWriteFast(Led6, LOW);
    digitalWriteFast(Led7, LOW);
    digitalWriteFast(Led8, HIGH);
    digitalWriteFast(LedCentrale, LOW);
    delay(taf);
    
    digitalWriteFast(Led1, HIGH);
    digitalWriteFast(Led2, LOW);
    digitalWriteFast(Led3, HIGH);
    digitalWriteFast(Led4, LOW);
    digitalWriteFast(Led5, LOW);
    digitalWriteFast(Led6, HIGH);
    digitalWriteFast(Led7, HIGH);
    digitalWriteFast(Led8, LOW);
    digitalWriteFast(LedCentrale, HIGH);
    delay(tef);
}

void extcen_3(float fqa, float fqe)

{
  taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWriteFast(Led1, HIGH);
    digitalWriteFast(Led2, LOW);
    digitalWriteFast(Led3, HIGH);
    digitalWriteFast(Led4, LOW);
    digitalWriteFast(Led5, LOW);
    digitalWriteFast(Led6, HIGH);
    digitalWriteFast(Led7, HIGH);
    digitalWriteFast(Led8, LOW);
    digitalWriteFast(LedCentrale, LOW);
    delay(taf);
    
    digitalWriteFast(Led1, LOW);
    digitalWriteFast(Led2, HIGH);
    digitalWriteFast(Led3, LOW);
    digitalWriteFast(Led4, HIGH);
    digitalWriteFast(Led5, HIGH);
    digitalWriteFast(Led6, LOW);
    digitalWriteFast(Led7, LOW);
    digitalWriteFast(Led8, HIGH);
    digitalWriteFast(LedCentrale, HIGH);
    delay(tef);
}

void fin()

{
  digitalWriteFast(Led1, LOW);
  digitalWriteFast(Led2, LOW);
  digitalWriteFast(Led3, LOW);
  digitalWriteFast(Led4, LOW);
  digitalWriteFast(Led5, LOW);
  digitalWriteFast(Led6, LOW);
  digitalWriteFast(Led7, LOW);
  digitalWriteFast(Led8, LOW);
  digitalWriteFast(LedCentrale, LOW);
}

void programme_1()

{
  while (i<10)
    
      {
            extcen(fqac, fqec);
            i=i+1;
            fqac=fqac+0.2;
            fqec=fqec+0.3;
            lumen=lumen+1;
      }

        while (i<14)
      {
            extcen_3(fqac, fqec);
            i=i+1;
            fqac=fqac+0.2;
            fqec=fqec+0.1;
      }

        while (i<200)
      {
            extcen_2(fqac, fqec);
            i=i+1;
            fqac=fqac+0.2;
            fqec=fqec+0.2;
      }

        while (i<400)
      {
            swg(12.1);
            i=i+1;
      }

        while (i<600)
      {
            desync_full(13.975,14.021);
            i=i+1;
      }

        while (i<800)
      {
            swg(9.915);
            i=i+1;
      }

        while (i<1200)
      {
            desync_full(10.321,8.512);
            i=i+1;
      }

        while (i<1400)
      {
            swg(11.118);
            i=i+1;
      }

        while (i<1550)
      {
            extcen_2(13.6,12.6);
            i=i+1;
      }

        while (i<1700)
      {
            extcen_2(13.2456,13.1237);
            i=i+1;
      }

        while (i<1800)
      {
            desync_full(11.3,8.2);
            i=i+1;
      }

        while (i<2000)
      {
            swg(11.7);
            i=i+1;
      }

        while (i<2200)
      {
            swg(11.75);
            i=i+1;
      }

        while (i<2400)
      {
            desync_full(11.77,22.77);
            i=i+1;
      }

        while (i<2600)
      {
            swg(11.9121457);
            i=i+1;
      }

        while (i<2610)
      {
            swg(3.14159);
            i=i+1;
      }

        while (i<2700)
      {
            extcen(6.454,13.14159);
            i=i+1;
      }

        while (i<2725)
      {
            swg(7.14159);
            i=i+1;
      }

        while (i<2755)
      {
            swg(9.14159);
            i=i+1;
      }

        while (i<3200)
      {
            swg(14.14159);
            i=i+1;
      }

        while (i<3500)
      {
            desync_full(14.14159,26);
            i=i+1;
      }

        while (i<3700)
      {
            desync_full(18.14159,46);
            i=i+1;
      }

        while (i<3900)
      {
            extcen_3(15.14159,12.871);
            i=i+1;
      }

        while (i<4100)
      {
            extcen_2(13.14159,25.871);
            i=i+1;
      }

        while (i<4300)
      {
            desync_full(37.14159,35.871);
            i=i+1;

      }

        while (i<4400)
      {
            desync_full(69.14159,54.871);
            i=i+1;

      }

        while (i<4600)
      {
            desync_full(85.14159,83.871);
            i=i+1;

      }

        while (i<5000)
      {
            desync_full(131.14159,132.4568);
            i=i+1;

      }
}

void programme_2()

{
      while (i<200)
    
      {
            fqa=100;
            fqe=100;
            desync_full(fqa, fqe);
            i=i+1;
            fqa=fqa-0.2;
            fqe=fqe-0.3;
      }

        while (i<400)
      {
            swg(12.1);
            i=i+1;
      }

        while (i<600)
      {
            extcen_2(11.975,14.021);
            i=i+1;
      }

        while (i<800)
      {
            swg(9.915);
            i=i+1;
      }

        while (i<1200)
      {
            desync_full(10.321,8.512);
            i=i+1;
      }

        while (i<1400)
      {
            swg(11.118);
            i=i+1;
      }

        while (i<1550)
      {
            extcen_2(10.6,9.6);
            i=i+1;
      }

        while (i<1700)
      {
            extcen_2(13.2456,13.1237);
            i=i+1;
      }

        while (i<1800)
      {
            desync_full(7.3,8.2);
            i=i+1;
      }

        while (i<2000)
      {
            swg(15.7);
            i=i+1;
      }

        while (i<2200)
      {
            swg(10.23);
            i=i+1;
      }

        while (i<2400)
      {
            desync_full(19.77,22.77);
            i=i+1;
      }

        while (i<2600)
      {
            swg(15);
            i=i+1;
      }

        while (i<2610)
      {
            swg(17.14159);
            i=i+1;
      }

        while (i<2700)
      {
            extcen(16.454,13.14159);
            i=i+1;
      }

        while (i<2725)
      {
            swg(8.14159);
            i=i+1;
      }

        while (i<2755)
      {
            swg(15.14159);
            i=i+1;
      }

        while (i<3200)
      {
            swg(9.14159);
            i=i+1;
      }

        while (i<3500)
      {
            desync_full(17.14159,26);
            i=i+1;
      }

        while (i<3700)
      {
            desync_full(18.14159,46);
            i=i+1;
      }

        while (i<3900)
      {
            extcen_3(11.14159,12.871);
            i=i+1;
      }

        while (i<4100)
      {
            extcen_2(13.14159,25.871);
            i=i+1;
      }

        while (i<4300)
      {
            desync_full(37.14159,35.871);
            i=i+1;

      }

        while (i<4400)
      {
            desync_full(69.14159,54.871);
            i=i+1;

      }

        while (i<4600)
      {
            desync_full(85.14159,83.871);
            i=i+1;

      }

        while (i<5000)
      {
            desync_full(131.14159,132.4568);
            i=i+1;

      }
}

void loop() 

{

boolean etatBouton1 = digitalRead(Bouton1);
boolean etatBouton2 = digitalRead(Bouton2);

  if (etatBouton1==LOW)

      {
         programme_1();
      }

  if (etatBouton2==LOW)

      {
         programme_2();
      }


}


