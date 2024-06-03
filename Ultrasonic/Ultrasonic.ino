  ////////////////////////////////////////////////////
//Ultrasonic Pins Definition, here we specify pin usage for our tivaC Board

const int echo = 9, Trig = 10;  //Pin connections for HC-SR04
const int LED1 = 11;          //Specify Pin for LED1
const int LED2 = 12;
const int LED3 = 13;
const int SW1 = 31;
const int SW2 = 17;

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
  pinMode(LED1, OUTPUT);    //Pin for LED1 should output HIGH(on) or LOW(off)
  pinMode(LED2,OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}


////////////////////////////////////////////////////
//Main Loop that will keep on running, it is similar to int main()
void loop()
{
    if (State == 0 and digitalRead(SW2) == 0){   // I have added this part to see that when I press switch 2  the working should stop.
      State = 1;
      Serial.print("Run State = 1");
      }
    else if (State == 1 and digitalRead(SW2) == 0){   // The pin configuration of switch 1 appears to be not correct so I used SW2 instead to do the same thing ON/OFF
      State = 0;
      Serial.print("Run State = 0");
      }
      // Imp note : I was testing with the switches to see which was optimum since SW1 was not working so I arrived with different results but in all the cases my
      //LED appears to be working correctly till task 3 part 4. The part 5 was allover the place.
    if (State == 0){ // This part makes sure that program will only run when State is zero 
    cm1 = Update_Ultra_Sonic(); //This function operates HC-SR04   
       // auxillary variable cm1 and new function made Led_glow
             //Delay between prints on Serial Monitor
    Led_glow(cm1);  // Led_glow function for different types of glows that appears 
     delay(200); }
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

void Led_glow(long distance)
{ if (distance >= 15 and distance <= 30){
    digitalWrite(LED1,HIGH);   // distance high
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);    // Task 3 part 1 
    
  }
  else if ( distance >= 5 and distance <= 15){
    digitalWrite(LED1,HIGH);   // Task 3 part 2
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
    }
  else if (distance >= 0 and distance <=5){
    digitalWrite(LED1,HIGH);   // Task 3 part 3 
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    }
  else if ( distance > 100){
    digitalWrite(LED1,HIGH);   // Task 3 part 4 blinking
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    delay(200);
    digitalWrite(LED1,LOW);   // distance high
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
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
