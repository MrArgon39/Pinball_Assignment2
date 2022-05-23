int leftFlipper = 30;
int rightFlipper = 31;
int leftFlipperButton = A0;
int rightFlipperButton = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftFlipper,OUTPUT);
  pinMode(rightFlipper,OUTPUT);
  pinMode(leftFlipperButton,INPUT);
  pinMode(rightFlipperButton,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(leftFlipperButton)==1){
  digitalWrite(leftFlipper,HIGH);
}
else{
  digitalWrite(leftFlipper,LOW);
}
if (digitalRead(rightFlipperButton)==1){
  digitalWrite(rightFlipper,HIGH);
}
else{
  digitalWrite(rightFlipper,LOW);
}

}
