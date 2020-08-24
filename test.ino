#include <ENC.h>

int data_old;

ENC enc(8,9);

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(enc.data(1) != data_old){
    data_old = enc.data(1);
    Serial.println(enc.data(1));
  }
}

ISR (TIMER2_COMPA_vect){enc.data(1);}
