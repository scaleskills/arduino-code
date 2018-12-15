//This program will take care of D scale
//E Scale={"E1","F1_S","G1_S","A1","B1","C2_S","D2_S","E2"};
//Fingering={1,2,3,1,2,3,4,5};
//Black Keys: 1=F1_S, 2=C2_S, 3=G1_S, 4=D2_S
//White Keys: 1=C1, 2=D1, 3=E1, 4=F1, 5=G1, 6=A1, 7=B1, 8=C2, 9=D2, 10=E2
//E Scale Black={"F1_S","G1_S","C2_S","D2_S"};
//E Scale White={"E1","A1","B1","E2"};

//Servo Code
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 180;    // variable to store the servo position

//LED pins
//int LED3 = 3; //E1
//int LED6 = 6; //A1
//int LED7 = 7; //B1
//int LED10 = 10; //E2

//C1 {1,2,3}(Example)
  //int C1redPin = 1;
  //int C1greenPin = 2;
  //int C1bluePin = 3;
//D1 {4,5,6}
//E1 {7,8,9}
  int E1redPin = 7;
  int E1greenPin = 8;
  int E1bluePin = 9;
//F1 {10,11,12}
//G1 {13,14,15}
//A1 {16,17,18}
  int A1redPin = 16;
  int A1greenPin = 17;
  int A1bluePin = 18;
//B1 {19,20,21}
  int B1redPin = 19;
  int B1greenPin = 20;
  int B1bluePin = 21;
//C2 {22,23,24}
//D2 {25,26,27}
//E2 {28,29,30}
  int E2redPin = 28;
  int E2greenPin = 29;
  int E2bluePin = 30;

//Arduino Analog Pins Octave 1
int analogPinF1_S= 1;
int analogPinG1_S= 2;
int analogPinC2_S= 3;
int analogPinD2_S= 4;

//Row Input Values
int rawF1_S= 0;
int rawC2_S= 0;
int rawG1_S= 0;
int rawD2_S= 0;

bool greeting= true;

void setup()
{

  //Set up Servos
  myservo.attach(31);  // attaches the servo on pin 31 to the servo object
  myservo.attach(33);  // attaches the servo on pin 31 to the servo object
  myservo.attach(35);  // attaches the servo on pin 31 to the servo object
  myservo.attach(37);  // attaches the servo on pin 31 to the servo object
  
  //Set up dummy LEDs
//  pinMode(LED3, OUTPUT);
//  pinMode(LED6, OUTPUT);
//  pinMode(LED7, OUTPUT);
//  pinMode(LED10, OUTPUT);

  //Turn dummy LEDs on
//  digitalWrite(LED3, HIGH);
//  digitalWrite(LED6, HIGH);
//  digitalWrite(LED7, HIGH);
//  digitalWrite(LED10, HIGH);
  
  // initialize serial communicatibon at 9600 bits per second:
  Serial.begin(9600);
}

void loop()
{
  while (greeting){
        //SERVO DOWN ON START
        delay(1000);                       // waits 1000ms
        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(5);                       // waits 15ms for the servo to reach the position
        }

        //int LED3 = 3; //E1 <Fingering: 1>
        //int LED6 = 6; //A1 <Fingering: 1>
        //int LED7 = 7; //B1 <Fingering: 2>
        //int LED10 = 10; //E2 <Fingering: 5>

        //Coloring
        //Red=1 {255,0,0}
        //Yellow=2 {255,255,0}
        //Green=3 {0,255,0}
        //Blue=4 {0,0,255}
        //Purple=5 {170,0,255}
        //Aqua= MISC {0,255,255}
        //White= MISC {255,255,255}

        //LEDS TURN ON
        setColorE1(255,0,0); //1 Red Color
        setColorA1(255,0,0); //1 Red Color
        setColorB1(0,255,255); //2 Yellow Color
        setColorE2(170,0,255); //5 Purple Color
        
      //STARTING E SCALE PROGRAM
      Serial.println(" YOU ARE NOW LEARNING HOW TO PLAY THE E SCALE! ");
      Serial.print(" PLEASE FOLLOW THE DIRECTTIONS OF THE USER STUDY FACILITATOR.");
      greeting=false;
    }
    
  //Initialize press listeners
  bool F1_S_PRESSED= false;
  bool C2_S_PRESSED= false;
  bool G1_S_PRESSED= false;
  bool D2_S_PRESSED= false;
  
  //Read in resistor values for pressure sensor foams
  int rawF1_S= 0;
  int rawC2_S= 0;
  int rawG1_S= 0;
  int rawD2_S= 0;

  rawF1_S= analogRead(analogPinF1_S);
  rawC2_S= analogRead(analogPinC2_S);
  rawG1_S= analogRead(analogPinG1_S);
  rawD2_S= analogRead(analogPinD2_S);

  //Calibration!!!!!!!!
//  Serial.print("raw F1_S is");
//  Serial.println(rawF1_S);
//  Serial.print("raw G1_S is");
//  Serial.println(rawG1_S);
//  Serial.print("raw C2_S is");
//  Serial.println(rawC2_S);
//  Serial.print("raw D2_S is");
//  Serial.println(rawD2_S);
//    
  //Key Press Listeners
  if(rawF1_S>800)
    {
      Serial.println("F1_S BLACK KEY IS PRESSED");
      F1_S_PRESSED= true;
    }
  if(rawG1_S>800)
    {
      Serial.println("C2_S BLACK KEY IS PRESSED");
      G1_S_PRESSED= true;
    }
  if(rawC2_S>1000)
    {
      Serial.println("C2_S BLACK KEY IS PRESSED");
      C2_S_PRESSED= true;
    }
  if(rawD2_S>1000)
    {
      Serial.println("C2_S BLACK KEY IS PRESSED");
      D2_S_PRESSED= true;
    }
    
   //Hacky Check
  if (F1_S_PRESSED and C2_S_PRESSED and G1_S_PRESSED and D2_S_PRESSED){
    Serial.println("CONGRATS! YOU MASTERED THE E SCALE!");
    F1_S_PRESSED= false;
    C2_S_PRESSED= false;
    G1_S_PRESSED= false;
    D2_S_PRESSED= false;
    
  }
    delay(1000);
}

//Set color helper function
void setColorE1(int redValue, int greenValue, int blueValue){
  analogWrite(E1redPin, redValue);
  analogWrite(E1greenPin, greenValue);
  analogWrite(E1bluePin, blueValue);
  }
void setColorA1(int redValue, int greenValue, int blueValue){
  analogWrite(A1redPin, redValue);
  analogWrite(A1greenPin, greenValue);
  analogWrite(A1bluePin, blueValue);
  }
void setColorB1(int redValue, int greenValue, int blueValue){
  analogWrite(B1redPin, redValue);
  analogWrite(B1greenPin, greenValue);
  analogWrite(B1bluePin, blueValue);
  }
void setColorE2(int redValue, int greenValue, int blueValue){
  analogWrite(E2redPin, redValue);
  analogWrite(E2greenPin, greenValue);
  analogWrite(E2bluePin, blueValue);
  }
  
