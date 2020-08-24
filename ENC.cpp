#include <ENC.h>

ENC::ENC(uint8_t clk, uint8_t dt){
            CLK = clk;
            DT = dt;
           
  TCCR1B |= (1 << WGM22)|(1 << CS20)|(1 << CS21); 
  TIMSK2 |= (1 << OCIE2A); 
  OCR2A = 250; // 1 ms
}

int ENC::data(bool eneble){
  switch(CLK){
    case 2: enc_a = ((PIND >> 2) & 1);break;
    case 3: enc_a = ((PIND >> 3) & 1);break;
    case 4: enc_a = ((PIND >> 4) & 1);break;
    case 5: enc_a = ((PIND >> 5) & 1);break;
    case 6: enc_a = ((PIND >> 6) & 1);break;
    case 7: enc_a = ((PIND >> 7) & 1);break;
    case 8: enc_a = ((PINB >> 0) & 1);break;
    case 9: enc_a = ((PINB >> 1) & 1);break;
   case 10: enc_a = ((PINB >> 2) & 1);break;
   case 11: enc_a = ((PINB >> 3) & 1);break;
   case 12: enc_a = ((PINB >> 4) & 1);break;
   case 13: enc_a = ((PINB >> 5) & 1);break;}_delay_us(500);  
  switch(DT){
    case 2: enc_b = ((PIND >> 2) & 1);break;
    case 3: enc_b = ((PIND >> 3) & 1);break;
    case 4: enc_b = ((PIND >> 4) & 1);break;
    case 5: enc_b = ((PIND >> 5) & 1);break;
    case 6: enc_b = ((PIND >> 6) & 1);break;
    case 7: enc_b = ((PIND >> 7) & 1);break;
    case 8: enc_b = ((PINB >> 0) & 1);break;
    case 9: enc_b = ((PINB >> 1) & 1);break;
   case 10: enc_b = ((PINB >> 2) & 1);break;
   case 11: enc_b = ((PINB >> 3) & 1);break;
   case 12: enc_b = ((PINB >> 4) & 1);break;
   case 13: enc_b = ((PINB >> 5) & 1);break;}
   if((!enc_a) && (enc_old_a)){
    if(enc_b) {enc_data++;}   
     else {enc_data--;}}   
    enc_old_a = enc_a;
   if(eneble == 0){enc_data = 0;}
    return enc_data;
}


     
