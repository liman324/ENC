//  Alexander Liman
//  liman324@yandex.ru
//  rcl-radio.ru

#ifndef  ENC_H
#define  ENC_H

#include <Arduino.h>


class  ENC
  {
    public:

  ENC(uint8_t, uint8_t);
  int data(bool eneble);
  

    private:
  bool enc_a;
  bool enc_b;
  bool enc_old_a;
  int enc_data;


  uint8_t CLK;
  uint8_t DT;

  };
#endif
