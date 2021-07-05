#define ON HIGH
#define OFF LOW
#define RN 63  

//#define LF 9
//#define LB 10
//#define RF 11
//#define RB 6  
//reversed:
#define RB 9
#define RF 6
#define LB 11
#define LF 10   


int val;
bool control;

void setup()
{
  Serial.begin(9600); 
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  control = true;
}

void Forward(){
    digitalWrite(RF, ON);
    digitalWrite(RB, OFF);
    digitalWrite(LF, ON);
    digitalWrite(LB, OFF);  
  }

void Backward(){
    digitalWrite(RF, OFF);
    digitalWrite(RB, ON);
    digitalWrite(LF, OFF);
    digitalWrite(LB, ON);
  }

void TurnRight(){
    digitalWrite(RF, OFF);
    digitalWrite(RB, ON); 
    digitalWrite(LF, ON);
    digitalWrite(LB, OFF);
  }

void TurnLeft(){
    digitalWrite(RF, ON);
    digitalWrite(RB, OFF);
    digitalWrite(LF, OFF);
    digitalWrite(LB, ON);
  }

void RightForward(){
    analogWrite(RF, ON);
    digitalWrite(RB, OFF);
    digitalWrite(LF, ON);
    digitalWrite(LB, OFF);
  }

void RightBackward(){
    digitalWrite(RF, OFF);
    analogWrite(RB, RN);
    digitalWrite(LF, OFF);
    digitalWrite(LB, ON);
  }
 
void LeftForward(){
    digitalWrite(RF, ON);
    digitalWrite(RB, OFF);
    analogWrite(LF, ON);
    digitalWrite(LB, OFF);
  }

void LeftBackward(){
    digitalWrite(RF, OFF);
    digitalWrite(RB, ON);
    digitalWrite(LF, OFF);
    analogWrite(LB, RN);
  }

void Stop(){
    digitalWrite(RF, ON);
    digitalWrite(RB, ON);
    digitalWrite(LF, ON);
    digitalWrite(LB, ON);
  }
void test_rf(){
  digitalWrite(RF, ON);
  digitalWrite(RB, OFF);
  digitalWrite(LF, OFF);
  digitalWrite(LB, OFF);
}

void test_rb(){
  digitalWrite(RF, OFF);
  digitalWrite(RB, ON);
  digitalWrite(LF, OFF);
  digitalWrite(LB, OFF);
}

void test_lf(){
  digitalWrite(RF, OFF);
  digitalWrite(RB, OFF);
  digitalWrite(LF, ON);
  digitalWrite(LB, OFF);
}

void test_lb(){
  digitalWrite(RF, OFF);
  digitalWrite(RB, OFF);
  digitalWrite(LF, OFF);
  digitalWrite(LB, ON);
}

void fuck_stop_all(){
  digitalWrite(RF, OFF);
  digitalWrite(RB, OFF);
  digitalWrite(LF, OFF);
  digitalWrite(LB, OFF);
}
void loop()
{

  if (Serial.available())
  {
    val = Serial.read();
    Serial.println(val);
  }
if (val==88)
control = false;

if (val==120)
control = true;

if (control==true)
{
//  if (val == 1){
//    test_rf();
//  }
//  else if (val == 2){
//    test_rb();
//  }
//  else if (val == 3){
//    test_lf();
//  }
//  else if (val == 4){
//    test_lb();
//  }
//  else if (val == 5){
//    fuck_stop_all();
//  }
//  
    if (val == 70)
    {
      Forward();
    }
    
    else if (val == 66)
    {
      Backward();
    }

    else if (val == 76)
    {
      TurnLeft();
    }

    else if (val == 82)
    {
      TurnRight();
    }

    else if (val == 73)
    {
      RightForward();
    }

    else if (val == 74)
    {
      RightBackward();
    }

    else if (val == 71)
    {
      LeftForward();
    }

    else if (val == 72)
    {
      LeftBackward();
    }

    else if (val == 83)
    {
      fuck_stop_all();
    }
}
  
  }
