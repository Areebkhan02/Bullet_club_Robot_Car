// Motor A, TivaC and L298N connections
int enA = 26;   //ENABLE pin (PD3) for Motor A to provide PWM 
int in1 = 11;   //IN1 pin (PA2) for Motor A for direction
int in2 = 12;   //IN2 pin (PA3) for Motor A for direction23333223232332222222222222222222222333333333333333333333333333333333333


int enB = 25;   //ENABLE pin (PD2) for Motor A to provide PWM 
int in3 = 8;   //IN1 pin (PA5) for Motor A for direction
int in4 = 9;   //IN2 pin (PA6) for Motor A for direction

int enC = 23;   //ENABLE pin (PD0) for Motor A to provide PWM 
int in5 = 28;   //IN1 pin (PE2) for Motor A for direction
int in6 = 29;   //IN2 pin (PE3) for Motor A for direction

int enD = 24;   //ENABLE pin (PD1) for Motor A to provide PWM 
int in7 = 5;   //IN1 pin (PE4) for Motor A for direction
int in8 = 6;   //IN2 pin (PE5) for Motor A for direction

void setup() {
  Serial.begin(115200); //Serial initializing for Debugging
  
  //Specify pinModes for enA, in1 and in2 below
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);

   pinMode(enB,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(enC,OUTPUT);
  pinMode(in5,OUTPUT);
  pinMode(in6,OUTPUT);

  pinMode(enD,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(in8,OUTPUT);
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

   digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);

   digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);

  //Initialize SW2 Switch as Input
  //pinMode(SW2, INPUT_PULLUP);  //State for SW2 with pullUp resistor
}

void loop() {
    // Make the motor run clockwise direction using in1 and in2 states below
    analogWrite(enA, 255); //Run motor with 100% duty cycle
    analogWrite(enB, 255); //Run motor with 100% duty cycle
    analogWrite(enC, 255); //Run motor with 100% duty cycle
    analogWrite(enD, 255); //Run motor with 100% duty cycle

    digitalWrite(in1, LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8,LOW);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2,HIGH);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4,HIGH);

      digitalWrite(in5, LOW);
    digitalWrite(in6,HIGH);

      digitalWrite(in7, LOW);
    digitalWrite(in8,HIGH);
    delay(2000);

    digitalWrite(in1, LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8,LOW);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2,HIGH);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4,HIGH);

      digitalWrite(in5, LOW);
    digitalWrite(in6,HIGH);

      digitalWrite(in7, HIGH);
    digitalWrite(in8,HIGH);
    delay(2000);
    digitalWrite(in1, LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8,LOW);
    delay(2000);
    analogWrite(enA, 64); //Run motor with 100% duty cycle
    digitalWrite(in1, LOW);
    digitalWrite(in2,HIGH);
    
    digitalWrite(in3, LOW);
    digitalWrite(in4,HIGH);

      digitalWrite(in5, HIGH);
    digitalWrite(in6,HIGH);

      digitalWrite(in7, LOW);
    digitalWrite(in8,HIGH);
    delay(2000); 
    digitalWrite(in1, LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4,LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6,LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8,LOW);
    delay(2000);

    digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);

     digitalWrite(in3, HIGH);
    digitalWrite(in4,LOW);

     digitalWrite(in5, HIGH);
    digitalWrite(in6,LOW);

     digitalWrite(in7, HIGH);
    digitalWrite(in8,LOW);
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4,LOW);
    delay(2000);
    

    
    
}
