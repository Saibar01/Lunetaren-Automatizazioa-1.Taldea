
/* Luneta joystick bitartez mugitzea lortuko dugu.
  by Carlos Incera, Ekaitz Alcantara & Erik Aldabaldetreku
  This example code is in the public domain.
*/
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

boolean Direction = true;
int Steps = 0;
int ledPin = 13;

// Pauso erdiko Matrizea. Beste kontroletarako matrizea aldatu.

int Paso [ 8 ][ 4 ] =
{ {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

void setup()
{
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  
}

void loop()
{ int x = analogRead(0);
  Serial.print("X:  ");
  Serial.println(x);

  if (x < 400) {
    Direction = 1;
    digitalWrite(ledPin,HIGH);
    stepper() ;     // Pauso bat aurrera
    delay (1) ;
  }
  else if (x > 600) {
    Direction = 0;
    digitalWrite(ledPin,HIGH);
    stepper() ;     // Pauso bat aurrera
    delay (1) ;
  }
  else {digitalWrite(ledPin,LOW);}

}

void stepper()              //Pauso bat aurrera egiten duen Funtzioa
{
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  SetDirection();

  Serial.print("Pausoa:  ");
  Serial.println(Steps);
  Serial.print("Norantza:  ");
  Serial.println(Direction);
  Serial.println("");

}

// Norantzaren arabera bobinen eszitazio norantza definitzen duen Funtzioa
void SetDirection()
{
  if (Direction)
    Steps++;
  else
    Steps--;

  Steps = ( Steps + 8 ) % 8 ;
}
