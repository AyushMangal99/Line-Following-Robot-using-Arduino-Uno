int f1,f2,z1 = 0;                                 //Declaring Variables.

void setup() {
 
  pinMode(A0, INPUT);                             //Input pin number A0 as IR Sensor1
  pinMode(A1, INPUT);                             //Input pin number A1 as IR Sensor2
  pinMode(A2, INPUT);                             //Input pin number A2 as IR Sensor3
  pinMode(8, OUTPUT);                             //Output pin number 8 
  pinMode(9, OUTPUT);                             //Output pin number 9
  pinMode(10, OUTPUT);                            //Output pin number 10
  pinMode(11, OUTPUT);                            //Output pin number 11 
}

void loop() {
  
  f1 = analogRead(A0);                           //Reading value from lEFT Sensor and storing in f1 variable.
  f2 = analogRead(A1);                           //Reading value from Right Sensor and storing in f2 variable.
  z1 = analogRead(A2);                           //Reading value from Station Sensor and storing in z1 variable.


 if(z1<511)                                      //Checking condition for Station.
        {
             digitalWrite(8, HIGH);          
             digitalWrite(9, HIGH);
             digitalWrite(10, HIGH);
             digitalWrite(11, HIGH);
             delay(5000);                         //Wait at Station for 5 second.
        }
  
 else

  {
    if(f1 > 511 && f2 > 511)                      // Move Forward
      {
        digitalWrite(8, HIGH);                    //Assigning Digital Value as HIGH.
        digitalWrite(9, LOW);                     //Assigning Digital Value as LOW.
        digitalWrite(10, HIGH);                   //Assigning Digital Value as HIGH.
        digitalWrite(11, LOW);                    //Assigning Digital Value as LOW.
      }
  
    if(f1 > 511 && f2 < 511)                      //Turn Right
      {
        digitalWrite(8, HIGH);                    //Assigning Digital Value as HIGH.
        digitalWrite(9, LOW);                     //Assigning Digital Value as LOW.
        digitalWrite(10, LOW);                    //Assigning Digital Value as LOW.
        digitalWrite(11, LOW);                    //Assigning Digital Value as LOW.
      }
  
    if(f1 < 511 && f2 > 511)                      //Turn Left
      {
        digitalWrite(8, LOW);                     //Assigning Digital Value as LOW.
        digitalWrite(9, LOW);                     //Assigning Digital Value as LOW.
        digitalWrite(10, HIGH);                   //Assigning Digital Value as HIGH.
        digitalWrite(11, LOW);                    //Assigning Digital Value as LOW.
      }
  
    if(f1 < 511 && f2 < 511)                      //Stop
      {
        digitalWrite(8, HIGH);                     //Assigning Digital Value as HIGH.
        digitalWrite(9, HIGH);                     //Assigning Digital Value as HIGH.
        digitalWrite(10, HIGH);                    //Assigning Digital Value as HIGH.
        digitalWrite(11, HIGH);                    //Assigning Digital Value as HIGH.
      }
  }                                              

}
