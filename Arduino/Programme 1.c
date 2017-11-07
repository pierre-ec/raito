// PWM sur led centrale avec analogWrite()

int i = 0; 

const int Led1 = 2, Led2 = 3, Led3 = 4, Led4 = 5, 
Led5 = 6, Led6 = 7, Led7 = 8, Led8 = 9, LedCentrale = 11;

float fq = 1, fqa, fqe, fqac, fqec, taf, tef, frequence, lumen = 0;

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

void loop() 

{

  while (i<10)
{
      desync_cen(fqac, fqec);
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
      desync_full(17.14159,5.871);
      i=i+1;

}

  while (i<4400)
{
      desync_full(19.14159,5.871);
      i=i+1;

}

  while (i<4600)
{
      desync_full(25.14159,5.871);
      i=i+1;

}

  while (i<5000)
{
      fqe=4;
      desync_full(31.14159,fqe);
      i=i+1;
      fqe=fqe+0.5;

}
fin();

}
