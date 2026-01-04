int pin = 11;

void setup(){
  pinMode(pin, OUTPUT);
}

void loop(){
  for(int i=0; i<256; i++){
    analogWrite(pin, i);
    delay(2);
  }
  for(int i=255; i>=0; i--){
    analogWrite(pin, i);
    delay(2);
  }
}