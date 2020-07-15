
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6b700384b4d94c158a2fa0c5ebd6a82d";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi";
char pass[] = "becca123";

int R1 = D1; 
int R2 = D2; 
int L1 = D3; 
int L2 = D4; 
//int mop = D5;
//int pump = D6;

void setup() {
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
}

void loop() {
  Blynk.run();

}
// Handling Joystick data
BLYNK_WRITE(V1) {
  int x = param[0].asInt();
  int y = param[1].asInt();
  if (x == 0 && y == 1) {       //FORWARD
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);

    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  } else if (x == 0 && y == -1) {  //BACKWARD
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);

    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  } else if (x == 1 && y == 0) {  //RIGHT
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);

    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  } else if (x == -1 && y == 0) {  //LEFT
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);

    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  } else if (x == 0 && y == 0) {  //Stay
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);

    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  }
}

//BLYNK_WRITE(V2) {
//  if(param.asInt() == 1){
//    digitalWrite(m11, HIGH);
//    digitalWrite(m12, LOW);
//
//    digitalWrite(m21, LOW);
//    digitalWrite(m22, HIGH);
//  } 
//  else{
//    digitalWrite(m11, LOW);
//    digitalWrite(m12, LOW);
//
//    digitalWrite(m21, LOW);
//    digitalWrite(m22  , LOW);
//  }
//}
