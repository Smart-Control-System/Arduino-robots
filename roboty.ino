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


char val;
bool control;


int trigPin = A3;
int echoPin = A4;


void setup() {
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
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin, INPUT);
}

void loop() {
  
  //int duration, cm;
   if (Serial.available()){
    val = Serial.read();

    if(val == "w"){
      Forward();
    }
    if (val == "s"){
      Backward(); 
    }
    if (val == "a"){
      TurnLeft();
    }
    if (val == "d"){
      TurnRight();
    }
    
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);
  cm = duration /58;
  Serial.print (cm);
  Serial.println(" cm");

  delay(1000);
  
}
