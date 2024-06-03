  ////////////////////////////////////////////////////
//Ultrasonic Pins Definition, here we specify pin usage for our tivaC Board
#include <Servo.h>   //Using built-in servo library with precise PWMs, for Task02/03
Servo myservo_attac_1;       //Creates an object of Servo, for Task02/03
Servo myservo_attac_2;       //Creates an object of Servo, for Task02/03


//Variables for pins and servo position "pos"
int pos = 0;                        // variable to store the servo position in
const int Servo_control_pin1 = 30;   //Pin connection for Servo PWM, equivalent to PF1
const int Servo_control_pin2 = 40;

const int echo = 9, Trig = 10;  //Pin connections for HC-SR04

////////////////////////////////////////////////////
//Time Update Variables

long duration, cm;                          //To measure pulse width and distance in cm
long distance = 0;                          //To return distance of object
unsigned long LastUpdateMicrosecs = 0;    
unsigned long LastUpdateMillisecs = 0;
unsigned long CurrentMicrosecs = 0;
unsigned long MicrosecsSinceLastUpdate = 0;
float SecondsSinceLastUpdate = 0;
long cm1;
int State = 0;

////////////////////////////////////////////////////
//Initializing Pins Function

void setup()
{
  Serial.begin(115200);     //Initialize Serial COM Port with 115200 buad rate
  pinMode(Trig, OUTPUT);    //Trigger is output since it will send 8 pulses at 40KHz from HC-SR04
  pinMode(echo, INPUT);     //Echo is input since it will detect the reflected wave from HC-SR04
  myservo_attac_1.attach(Servo_control_pin1);
  myservo_attac_2.attach(Servo_control_pin2); 

}


////////////////////////////////////////////////////
//Main Loop that will keep on running, it is similar to int main()
void loop()
{
   
    cm1 = Update_Ultra_Sonic(); //This function operates HC-SR04   
       // auxillary variable cm1 and new function made Led_glow
             //Delay between prints on Serial Monitor
    Object_Detection(cm1);  // Led_glow function for different types of glows that appears 
     delay(200); 
}

////////////////////////////////////////////////////
//Will update ultrasonic sensors through Serial port

long Update_Ultra_Sonic()
{
  //Setting Trig Signal HIGH for 10us to produce burst of 8 pulses at 40KHz
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  //digitalRead(anypin/switch) //Use this function to read the state of any Pin/Switch i.e. SW1 and SW2

  duration = pulseIn(echo, HIGH);   // Reads duration (microseconds) for which Echo pin reads HIGH till wave is reflected
  cm = microsecondsToCentimeters(duration); // convert the time into a distance, refer to function below
  
  //Sending through serial port to print on Monitor
  Serial.print("Distance=");
  Serial.print("\t");
  Serial.print(cm);
  Serial.print("\n");
  return cm;
}

void Object_Detection(long distance)
{ if (distance > 100){
    // robot stops working condition applying here 
    while(1){
              myservo_attac_1.write(90);
              myservo_attac_1.write(0);
              myservo_attac_2.write(90);
              myservo_attac_2.write(0);
      }  
  }
}


////////////////////////////////////////////////////
//Conversion of microsecond to centimeter
long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.

// convert speed of sound from m/s to cm/us

// Use the formula:     distance(cm) = speed(cm/us) * time(us)
// Write distance formula here
long double distance = 0.034 * microseconds;    // here we did (340 x 100)/10^6 to get 0.034 that is the speed of sound in cm/us to be multiplied by microseconds 
// so that we can get distance in cm.
// We take half of the distance travelled since its a reflected wave

return distance / 2;
}
