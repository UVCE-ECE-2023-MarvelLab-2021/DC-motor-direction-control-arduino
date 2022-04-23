void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT); // direction control pin given to IN1 of L298N driver
  pinMode(5,OUTPUT); // direction control pin given to IN2 of L298N driver
  pinMode(A0,INPUT);  // analog pin to read 10k potentiometer ouput
}

void loop() {
  int s=analogRead(A0); // read 10k potentiometer output
  int z = 0;
  if (s < 512) {
    int z=map(512-s,0,512,0,255);
    analogWrite(5,0); // disable anticlockwise rotation of dc motor shaft
    if (z>50){
    analogWrite(3,z); // drive the motor in clockwise direction
    }
    Serial.println(z);
  }
  else {
    int z=map(s-512,0,512,0,255);
    analogWrite(3,0); // disable clockwise rotation of dc motor shaft
    if (z>50){
    analogWrite(5,z); // drive the motor in anticlockwise direction
    }
    Serial.println(z);
  }
}