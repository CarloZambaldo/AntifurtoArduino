int  Led = 13 ;
int Led2 = 12;
int Led3 = 11;
int Led_off = 10;
int Allarm = 2;
int Pulsante1 = 7;
int Pulsante2 = 6;
int Pulsante3 = 5;
int AllarmSensor = A0;
int Valore1 = 0;
int Valore2 = 0;
int Valore3 = 0;
int ValoreAllarme;
int VariabileControllo;

void setup() 
{
  pinMode(Led, OUTPUT); 
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);  
  pinMode(Led_off, OUTPUT);
  pinMode(Pulsante1, INPUT);
  pinMode(Pulsante2, INPUT);
  pinMode(Pulsante3, INPUT);
  pinMode(AllarmSensor, INPUT);
}

void loop(){
  Valore1 = digitalRead(Pulsante1);
  Valore2 = digitalRead(Pulsante2); 
  Valore3 = digitalRead(Pulsante3);
  
//pulsante1  
  if (Valore1 == HIGH) 
{ 
    VariabileControllo = LOW;
    tone(Allarm, 1500, 1);
    digitalWrite(Led_off, LOW);
    digitalWrite(Led, LOW);
    digitalWrite(Led2, HIGH); 
    delay(1000);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);
    digitalWrite(Allarm, LOW); 
  }
 else 
{
    digitalWrite(Led2, HIGH);
    delay(10);
    digitalWrite(Led2, LOW);
    delay(400);
    
  }
  
//pulsante2  
if (Valore2 == HIGH) 
{ 
    VariabileControllo = HIGH;
    digitalWrite(Led, HIGH);
    digitalWrite(Led3, LOW);
    digitalWrite(Led_off, LOW);
  }
  
//pulsante3  
  if (Valore3 == HIGH) 
{ 
    digitalWrite(Led, LOW);
    digitalWrite(Led2, LOW);
    digitalWrite(Led3, LOW);
    digitalWrite(Allarm, LOW);
    digitalWrite(Led_off, HIGH);
    tone(Allarm, 1300, 40);
    delay(1800);
    digitalWrite(Led_off, LOW);
  }
  
 // allarme
    ValoreAllarme = digitalRead(AllarmSensor); 
   if (VariabileControllo == HIGH) {
      if  (ValoreAllarme == LOW){
        delay(2000);
        tone(Allarm, 1500, 20000);
    }
  }
}
