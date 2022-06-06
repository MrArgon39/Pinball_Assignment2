// Solenoids
int leftFlipperSolenoid = 30;
int rightFlipperSolenoid = 31;

// User Buttons
int leftFlipperButton = A0;
int rightFlipperButton = A1;

// Testing Buttons

// Playfield Switches
int shooterLaneSwitch = A2;

// Playfield Lights
int shootAgain = 12;


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftFlipperSolenoid, OUTPUT);
  pinMode(rightFlipperSolenoid, OUTPUT);
  pinMode(leftFlipperButton, INPUT);
  pinMode(rightFlipperButton, INPUT);
  pinMode(shooterLaneSwitch,INPUT);
  pinMode(shootAgain,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (digitalRead(leftFlipperButton) == 1)
  {
    fireLeftFlipper(1);
  }
  else
  {
    fireLeftFlipper(0);
  }
  if (digitalRead(rightFlipperButton) == 1)
  {
    fireRightFlipper(1);
  }
  else
  {
    fireRightFlipper(0);
  }
  if(digitalRead(shooterLaneSwitch)==1){
    digitalWrite(shootAgain,HIGH);
  }
  else{
    digitalWrite(shootAgain,LOW);
  }

}

void fireLeftFlipper(int fireState)
{
  if (fireState == 1)
  {
    digitalWrite(leftFlipperSolenoid, HIGH);
    //Serial.println("test");
  }
  else
  {
    digitalWrite(leftFlipperSolenoid, LOW);
  }
}

void fireRightFlipper(int fireState)
{
  if (fireState == 1)
  {
    digitalWrite(rightFlipperSolenoid, HIGH);
  }
  else
  {
    digitalWrite(rightFlipperSolenoid, LOW);
  }
}