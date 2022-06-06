// Solenoids
int leftFlipperSolenoid = 30;
int rightFlipperSolenoid = 31;

// User Buttons
int leftFlipperButton = A0;
int rightFlipperButton = A1;
int gameStart = A2;

// Testing Buttons

// Playfield Switches
int troughSwitch = A3;
int fSwitch = A4;
int oneOneSwitch = A5;
int oneTwoSwitch = A6;
int oneThreeSwitch = A7;

// Playfield Lights
int shootAgain = 39;
int Bonus1k = 40;
int Bonus2k = 41;
int Bonus4k = 42;
int Bonus8k = 43;
int Bonus16k = 44;
int fLight = 45;
int oneOne = 46;
int oneTwo = 47;
int oneThree = 48;
int gameOver = 49;

// Score
int score = 0; // The score, will be printed to the serial monitor as I have no
               // time to implement a scoreboard.

// Assorted other variables
int fState = 0;
int oneOneState = 0;
int oneTwoState = 0;
int oneThreeState = 0;
int shootAgainState = 0;
int gameOverState = 1;

int bonus = 0; // Value of the bonus divided by 1000

void setup()//No plan survives first contact with the enemy.
{
  // Setup all the things.
  Serial.begin(9600);
  pinMode(leftFlipperSolenoid, OUTPUT);
  pinMode(rightFlipperSolenoid, OUTPUT);
  pinMode(leftFlipperButton, INPUT);
  pinMode(rightFlipperButton, INPUT);
  pinMode(troughSwitch, INPUT);
  pinMode(fSwitch, INPUT);
  pinMode(oneOneSwitch, INPUT);
  pinMode(oneTwoSwitch, INPUT);
  pinMode(oneThreeSwitch, INPUT);
  pinMode(shootAgain, OUTPUT);
  pinMode(gameOver, OUTPUT);
  pinMode(Bonus1k, OUTPUT);
  pinMode(Bonus2k, OUTPUT);
  pinMode(Bonus4k, OUTPUT);
  pinMode(Bonus8k, OUTPUT);
  pinMode(Bonus16k, OUTPUT);
  pinMode(oneOne, OUTPUT);
  pinMode(oneTwo, OUTPUT);
  pinMode(oneThree, OUTPUT);
}

void loop()
{
  while (gameOverState != 1)
  {
    digitalWrite(gameOver,LOW);
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
  bonusHandler();
  f111LightsHandler();
  shootAgainHandler();
  }

  digitalWrite(gameOver,HIGH);
  if (digitalRead(gameStart)==HIGH){
    gameOverState = 0;
  }

  
}

void fireLeftFlipper(int fireState)
{
  if (fireState == 1)
  {
    digitalWrite(leftFlipperSolenoid, HIGH);
    // Serial.println("test");
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

void bonusHandler()
{ // Handles the value of the bonus, stored in a single
  // byte as the number of values isn't that large.
  if (bitRead(bonus, 0) == 1)
  {
    digitalWrite(Bonus1k, HIGH);
  }
  else
  {
    digitalWrite(Bonus1k, LOW);
  }
  if (bitRead(bonus, 1) == 1)
  {
    digitalWrite(Bonus2k, HIGH);
  }
  else
  {
    digitalWrite(Bonus2k, LOW);
  }
  if (bitRead(bonus, 2) == 1)
  {
    digitalWrite(Bonus4k, HIGH);
  }
  else
  {
    digitalWrite(Bonus4k, LOW);
  }
  if (bitRead(bonus, 3) == 1)
  {
    digitalWrite(Bonus8k, HIGH);
  }
  else
  {
    digitalWrite(Bonus8k, LOW);
  }
  if (bitRead(bonus, 4) == 1)
  {
    digitalWrite(Bonus16k, HIGH);
  }
  else
  {
    digitalWrite(Bonus16k, LOW);
  }
}

void f111LightsHandler()
{
  if (digitalRead(fSwitch) == HIGH && fState != 1)
  {
    fState = 1;
    digitalWrite(fLight, HIGH);
    score = score + 100;
  }
  if (digitalRead(oneOneSwitch) == HIGH && oneOneState != 1)
  {
    oneOneState = 1;
    digitalWrite(oneOne, HIGH);
    score = score + 100;
  }
  if (digitalRead(oneTwoSwitch) == HIGH && oneTwoState != 1)
  {
    oneTwoState = 1;
    digitalWrite(oneTwo, HIGH);
    score = score + 100;
  }
  if (digitalRead(oneThreeSwitch) == HIGH && oneThreeState != 1)
  {
    oneThreeState = 1;
    digitalWrite(oneThree, HIGH);
    score = score + 100;
  }
  if (fState == 1 && oneOneState == 1 && oneTwoState == 1 && oneThreeState == 1)
  {
    shootAgainState = 1;
    digitalWrite(fLight, LOW);
    digitalWrite(oneOne, LOW);
    digitalWrite(oneTwo, LOW);
    digitalWrite(oneThree, LOW);
    fState = 0;
    oneOneState = 0;
    oneTwoState = 0;
    oneThreeState = 0;
  }
}

void shootAgainHandler(){
  if(shootAgainState==1){
    digitalWrite(shootAgain,HIGH);
  }
  else{
    digitalWrite(shootAgain,LOW);
  }
}

void gameOverHandler(){
  if(digitalRead(troughSwitch)== HIGH && shootAgainState == 1){
    shootAgainState = 0;
  }
  else if (digitalRead(troughSwitch)==HIGH && shootAgainState == 0){//We broke it Jim
    Serial.print("Final score is ");
    Serial.print(score);
    Serial.println(" points, Well done!");
    gameOverState=1;
    oneOneState = 0;
    oneTwoState = 0;
    oneThreeState = 0;
    fState = 0;
    bonus = 0;
    score = 0;
  }
}