#define IR_sensor A4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_sensor,INPUT);
}

void loop() {

  Serial.println(analogRead(IR_sensor));
 
  analogRead(IR_sensor); 
  //threshold 500 (71~72 and 1019)
  //if under 500 --> too close
  
   delay(500);
}


