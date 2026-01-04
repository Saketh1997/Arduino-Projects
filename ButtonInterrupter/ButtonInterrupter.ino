int Input_pin = 2;
const unsigned long time_delay = 50; 
volatile unsigned long cur_time = 0;
volatile bool button_press = false;
int press_count = 0; 

void buttonInterrupt(){
  unsigned long now = millis();
  if(now - cur_time > time_delay){
    button_press = true;
    cur_time = now;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(Input_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Input_pin), buttonInterrupt, FALLING);

  Serial.println("Interrupt Button Logger ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(button_press){
    button_press = false;
    press_count++;

    Serial.print("Press #");
    Serial.print(press_count);
    Serial.print(" at ");
    Serial.print(millis());
    Serial.print(" ms\n");
  }
}
