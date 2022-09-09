int motor_lA = 9;
int motor_lB = 10;
int motor_enableA = 11;

int motor_rA = 3;
int motor_rB = 4;
int motor_enableB = 5;

int trigger_front = A0;
int echo_front = A1;

int trigger_left = A2;
int echo_left = A3;

int trigger_right = A4;
int echo_right = A5;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor_lA,OUTPUT);   //left motors forward
  pinMode(motor_lB,OUTPUT);   //left motors reverse
  pinMode(motor_enableA, OUTPUT);

  pinMode(motor_rA,OUTPUT);   //right motors forward
  pinMode(motor_rB,OUTPUT);   //rignt motors reverse
  pinMode(motor_enableB, OUTPUT);

  pinMode(trigger_front,OUTPUT);
  pinMode(echo_front,INPUT);

  pinMode(trigger_left,OUTPUT);
  pinMode(echo_left,INPUT);

  pinMode(trigger_right,OUTPUT);
  pinMode(echo_right,INPUT);
  
  analogWrite(motor_enableA, 80);
  analogWrite(motor_enableB, 88);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;
    
  //Calculating distance
  
  digitalWrite(trigger_front, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_front, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_front, LOW);
  duration_front = pulseIn(echo_front, HIGH);
  distance_front= duration_front*0.034/2;

  digitalWrite(trigger_left, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_left, LOW);
  duration_left = pulseIn(echo_left, HIGH);
  distance_left= duration_left*0.034/2;

  digitalWrite(trigger_right, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_right, LOW);
  duration_right = pulseIn(echo_right, HIGH);
  distance_right= duration_right*0.034/2;

  Serial.print("front = ");
  Serial.println(distance_front);
  Serial.print("Left = ");
  Serial.println(distance_left);
  Serial.print("Right = ");
  Serial.println(distance_right);  
  delay(50);


  if (distance_front >20){

    forward();
    
    if(distance_left > 10&& distance_left<20){
      forward();
    }
    if(distance_left >=20){
       left();
       delay(30);
       forward();
    }
    if(distance_left<10 && distance_left>0){
      right();
      delay(30);
      forward();
    }
 } 
  
  if(distance_front<=20&& distance_right > 20){
    Stop();
    delay(1000);
    right();
    delay(400);
    
  }

  if(distance_front<=20 && distance_right<20){
    Stop();
    delay(1000);
    right();
    delay(800);
   
  }
  
  
}

void forward()
{
  digitalWrite(motor_lA,1);
  digitalWrite(motor_lB,0);
  digitalWrite(motor_rA,1);
  digitalWrite(motor_rB,0);
  delay(1000);
}


void right(){
  digitalWrite(motor_lA,1);
  digitalWrite(motor_lB,0);
  digitalWrite(motor_rA,0);
  digitalWrite(motor_rB,1);
 delay(10);
}


void left(){
  digitalWrite(motor_lA,0);
  digitalWrite(motor_lB,1);
  digitalWrite(motor_rA,1);
  digitalWrite(motor_rB,0);
  delay(10);
}



void Stop(){
  digitalWrite(motor_lA,0);
  digitalWrite(motor_lB,0);
  digitalWrite(motor_rA,0);
  digitalWrite(motor_rB,0);
  delay(300);
}
