void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT); // Motor pin 1
  pinMode(4,OUTPUT); // Motor pin 2
  digitalWrite(4,LOW); // Normally LOW inthis pin
  pinMode(A0,INPUT);  // 10k Potentiometer
}

void loop() {
  int s=analogRead(A0); // 10k Potentiometer
  if (s < 512) {
    int z=map(s,0,512,0,255);
    analogWrite(3,z);
  }
  else {
    int z=map(s-512,0,512,0,255);
    analogWrite(3,z);
  }
  Serial.println(z);
}
