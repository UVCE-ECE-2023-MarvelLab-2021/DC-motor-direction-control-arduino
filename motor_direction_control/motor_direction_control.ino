void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT); // Motor pin 1
  pinMode(5,OUTPUT); // Motor pin 1
  pinMode(3,OUTPUT); // Motor pin 1
  pinMode(5,OUTPUT); // Motor pin 1
  pinMode(A0,INPUT);  // 10k Potentiometer
}

void loop() {
  int s=analogRead(A0); // 10k Potentiometer
  int z = 0;
  if (s < 512) {
    int z=map(512-s,0,512,0,255);
    analogWrite(5,0);
    if (z>50){
    analogWrite(3,z);
    }
    Serial.println(z);
  }
  else {
    int z=map(s-512,0,512,0,255);
    analogWrite(3,0);
    if (z>50){
    analogWrite(5,z);
    }
    Serial.println(z);
  }
}
