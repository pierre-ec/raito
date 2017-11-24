//#include <digitalWriteFast.h>

int i = 0; 

const int Led1 = 2, Led2 = 3, Led3 = 4, Led4 = 5, 
Led5 = 6, Led6 = 7, Led7 = 8, Led8 = 9, LedCentrale = 11;

float fq = 1, fqa, fqe, fqac, fqec, taf, tef, frequence, lumen = 0;

int dc_prog = 0.1;

void setup() 

{               

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

void swg(float frequence) 

{

  float temps;

  temps = (1/frequence)*500;

  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
  digitalWrite(Led5, HIGH);
  digitalWrite(Led6, HIGH);
  digitalWrite(Led7, HIGH);
  digitalWrite(Led8, HIGH);
  digitalWrite(LedCentrale, HIGH);
  delay(temps);
  
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
  digitalWrite(Led5, LOW);
  digitalWrite(Led6, LOW);
  digitalWrite(Led7, LOW);
  digitalWrite(Led8, LOW);
  digitalWrite(LedCentrale, LOW);
  delay(temps);

}

void desync_full(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
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

void dc_dim_desync_full(float fqa, float dc, int lumen)

{
    taf=(1/fqa)*dc*1000;
    tef=(1/fqa)*(1-dc)*1000;
    
    analogWrite(Led1, lumen);
    analogWrite(Led2, lumen);
    analogWrite(Led3, lumen);
    analogWrite(Led4, lumen);
    analogWrite(Led5, lumen);
    analogWrite(Led6, lumen);
    analogWrite(Led7, lumen);
    analogWrite(Led8, lumen);
    analogWrite(LedCentrale, lumen);
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

void dim_desync_full(float fqa, float fqe, int lumen)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    analogWrite(Led1, lumen);
    analogWrite(Led2, lumen);
    analogWrite(Led3, lumen);
    analogWrite(Led4, lumen);
    analogWrite(Led5, lumen);
    analogWrite(Led6, lumen);
    analogWrite(Led7, lumen);
    analogWrite(Led8, lumen);
    analogWrite(LedCentrale, HIGH);
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

void desync_cen(float fqa, float fqe, int lumen)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    analogWrite(LedCentrale, lumen);
    delay(taf);
    
    digitalWrite(LedCentrale, LOW);
    delay(tef);

}


void extcen(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, HIGH);
    digitalWrite(Led5, HIGH);
    digitalWrite(Led6, HIGH);
    digitalWrite(Led7, HIGH);
    digitalWrite(Led8, HIGH);
    digitalWrite(LedCentrale, LOW);
    delay(taf);
    
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    digitalWrite(Led6, LOW);
    digitalWrite(Led7, LOW);
    digitalWrite(Led8, LOW);
    digitalWrite(LedCentrale, HIGH);
    delay(tef);
}

void extcen_2(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, HIGH);
    digitalWrite(Led5, HIGH);
    digitalWrite(Led6, LOW);
    digitalWrite(Led7, LOW);
    digitalWrite(Led8, HIGH);
    digitalWrite(LedCentrale, LOW);
    delay(taf);
    
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    digitalWrite(Led6, HIGH);
    digitalWrite(Led7, HIGH);
    digitalWrite(Led8, LOW);
    digitalWrite(LedCentrale, HIGH);
    delay(tef);
}

void extcen_3(float fqa, float fqe)

{
    taf=(1/fqa)*500;
    tef=(1/fqe)*500;
    
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);
    digitalWrite(Led4, LOW);
    digitalWrite(Led5, LOW);
    digitalWrite(Led6, HIGH);
    digitalWrite(Led7, HIGH);
    digitalWrite(Led8, LOW);
    digitalWrite(LedCentrale, LOW);
    delay(taf);
    
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    digitalWrite(Led3, LOW);
    digitalWrite(Led4, HIGH);
    digitalWrite(Led5, HIGH);
    digitalWrite(Led6, LOW);
    digitalWrite(Led7, LOW);
    digitalWrite(Led8, HIGH);
    digitalWrite(LedCentrale, HIGH);
    delay(tef);
}

void fin()

{
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
            dc_dim_desync_full(fq, 0.5, lumen);
            i++;
            lumen++;
            fq=fq+0.2;
      }

        while (i<400)
      {
            dc_dim_desync_full(12.1, 0.5, 255);
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

programme_2();

}


