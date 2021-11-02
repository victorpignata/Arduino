
# define POT A0
#define BUTTON 8
#define Entrada2 7
#define LED_HORARIO 12
#define Entrada1 2
#define LED_ANTI_HORARIO 13
#define Potencia 3

int valorPot = 0;
int velocidade = 0;
int estadoButton = 0;
   
void setup()  
{  
  
  Serial.begin(9600);
  pinMode(POT, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_HORARIO, OUTPUT); 
  pinMode(LED_ANTI_HORARIO, OUTPUT); 
  pinMode(Potencia, OUTPUT); 
  pinMode(Entrada1, OUTPUT);  
  pinMode(Entrada2, OUTPUT);  
}  
   
void loop()  
{  
  
  valorPot = analogRead (POT);
  
  velocidade = map(valorPot ,0 ,1023, 0, 255);

   estadoButton = digitalRead (BUTTON);
  
  analogWrite(Potencia, velocidade);   
   
  if (estadoButton == HIGH){
       analogWrite(LED_HORARIO, 250);
      analogWrite(LED_ANTI_HORARIO, 0);
      digitalWrite(Entrada1, LOW);  
    digitalWrite(Entrada2, HIGH);  
  
  }
    
  else{
      analogWrite(LED_ANTI_HORARIO, 250);
      analogWrite(LED_HORARIO, 0);
    digitalWrite(Entrada1, HIGH);  
      digitalWrite(Entrada2, LOW); 
  
  }
}  
