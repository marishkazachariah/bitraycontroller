/*
 * Calling out all the sensors and their locations on the Arduino Pro Mini.
 * SW, X and Y pin are are part of the joystick using a mixture and digital and analog power
 * All the buttons are digital sensors and are using digital power
 */ 
const int SW_pin = 3;
const int X_pin = A1;
const int Y_pin = A0; 
const int button1 = 5;
const int button2 = 6;
const int button3 = 7;
const int button4 = 8;
const int button5 = 9;
//declaring the variable names to distinguish all the buttons in code
int buttonOne;
int buttonTwo;
int buttonThree;
int buttonFour;
int buttonFive;

void setup() {
  //declaring all variables as inactive/inputs 
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);

    Serial.begin(9600);
  
}

void loop() {
  buttonOne = digitalRead(button1);
  buttonTwo = digitalRead(button2);
  buttonThree = digitalRead(button3);
  buttonFour = digitalRead(button4);
  buttonFive = digitalRead(button5);
  
  //Using booleans to call any push or button-presses as a number for Unity to read within C-Sharp
  if(analogRead(X_pin) >= 1010)
  {
  Serial.write(1);  
  Serial.flush();
  delay(20);
  }

  if(analogRead(X_pin) == 0)
  {
  Serial.write(2);    
  Serial.flush();
  delay(20);
  }

  if(analogRead(Y_pin) >= 1010)
  {
  Serial.write(3);    
  Serial.flush();
 // delay(20);
  }

   if(analogRead(Y_pin) == 0)
  {
  Serial.write(4);    
  Serial.flush();
  delay(20);
  }

//void serialToUnity() {
  if(buttonOne == LOW) {
    Serial.write(5);
    Serial.println("button1pressed");      
  }
   if(buttonTwo == LOW) {
    Serial.write(6);
    Serial.println("button22");      
  }
   if(buttonThree == LOW) {
    Serial.write(7);
    Serial.println("button33");      
  }
   if(buttonFour == LOW) {
    Serial.write(8);
    Serial.println("button44");      
  }
   if(buttonFive == LOW) {
    Serial.write(9);
    Serial.println("button555");      
  }
  Serial.flush();
  delay(20);
//}
}

