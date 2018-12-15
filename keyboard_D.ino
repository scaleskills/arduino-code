//This program will take care of D scale
//D Scale={"D1","E1","F1_S","G1","A1","B1","C2_S","D2"};
//Fingering={1,2,3,1,2,3,4,5};
//Black Keys: 1=F1_S, 2=C2_S, 3=G1_S, 4=D2_S
//White Keys: 1=C1, 2=D1, 3=E1, 4=F1, 5=G1, 6=A1, 7=B1, 8=C2, 9=D2, 10=E2
//D Scale Black={"F1_S","C2_S"};
//D Scale White={"D1","E1","G1","A1","B1","D2"};

//Servo Code
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 180;    // variable to store the servo position

//LED pins
//int LED2 = 2; //D1
//int LED3 = 3; //E1
//int LED5 = 5; //G1
//int LED6 = 6; //A1
//int LED7 = 7; //B1
//int LED9 = 9; //D2

//C1 {1,2,3}(Example)
  //int C1redPin = 1;
  //int C1greenPin = 2;
  //int C1bluePin = 3;
//D1 {4,5,6}
  int D1redPin = 4;
  int D1greenPin = 5;
  int D1bluePin = 6;
//E1 {7,8,9}
  int E1redPin = 7;
  int E1greenPin = 8;
  int E1bluePin = 9;
//F1 {10,11,12}
//G1 {13,14,15}
  int G1redPin = 13;
  int G1greenPin = 14;
  int G1bluePin = 15;
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
  int D2redPin = 25;
  int D2greenPin = 26;
  int D2bluePin = 27;
//E2 {28,29,30}

//Arduino Analog Pins Octave 1
int analogPinF1_S= 1;
int analogPinC2_S= 2;

//Row Input Values
int rawF1_S= 0;
int rawC2_S= 0;

bool greeting= true;

void setup()
{

  //Set up Servos
  myservo.attach(31);  // attaches the servo on pin 31 to the servo object F#
  myservo.attach(33);  // attaches the servo on pin 31 to the servo object C#
  
//  //Set up dummy LEDs
//  pinMode(LED2, OUTPUT);
//  pinMode(LED3, OUTPUT);
//  pinMode(LED5, OUTPUT);
//  pinMode(LED6, OUTPUT);
//  pinMode(LED7, OUTPUT);
//  pinMode(LED9, OUTPUT);
//  
//  //Turn dummy LEDs on
//  digitalWrite(LED2, HIGH);
//  digitalWrite(LED3, HIGH);
//  digitalWrite(LED5, HIGH);
//  digitalWrite(LED6, HIGH);
//  digitalWrite(LED7, HIGH);
//  digitalWrite(LED9, HIGH);
  
  // initialize serial communication at 9600 bits per second:
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

        //int LED2 = 2; //D1 <Fingering 1>
        //int LED3 = 3; //E1 <2>
        //int LED5 = 5; //G1 <1>
        //int LED6 = 6; //A1 <2>
        //int LED7 = 7; //B1 <3>
        //int LED9 = 9; //D2 <5>

        //Coloring
        //Red=1 {255,0,0}
        //Yellow=2 {255,255,0}
        //Green=3 {0,255,0}
        //Blue=4 {0,0,255}
        //Purple=5 {170,0,255}
        //Aqua= MISC {0,255,255}
        //White= MISC {255,255,255}

        //LEDS TURN ON
        setColorD1(255,0,0); //1 Red
        setColorE1(255,255,0); //2 Yellow
        setColorG1(255,0,0); //1 Red Color
        setColorA1(0,255,255); //2 Yellow Color
        setColorB1(0,255,0); //3 Green
        setColorD2(170,0,255); //5 Purple

      //START D SCALE PROGRAM
      Serial.println(" YOU ARE NOW LEARNING HOW TO PLAY THE D SCALE ");
      Serial.print(" PLEASE FOLLOW THE DIRECTTIONS OF THE USER STUDY FACILITATOR ");
      greeting=false;
    }
    
  bool F1_S_PRESSED= false;
  bool C2_S_PRESSED= false;

  //Read in resistor values for pressure sensor foams
  int rawF1_S= 0;
  int rawC2_S= 0;

  rawF1_S= analogRead(analogPinF1_S);
  rawC2_S= analogRead(analogPinC2_S);

  //Calibration
  //  Serial.print("raw F1_S is");
  //  Serial.println(rawF1_S);
  //  Serial.print("raw C2_S is");
  //  Serial.println(rawC2_S);
    
  //Key Press Listeners
  if(rawF1_S>800)
    {
      Serial.println("F1_S BLACK KEY IS PRESSED");
      F1_S_PRESSED= true;
    }
  if(rawC2_S>800)
    {
      Serial.println("C2_S BLACK KEY IS PRESSED");
      C2_S_PRESSED= true;
    }

   //Hacky Check
  if (F1_S_PRESSED and C2_S_PRESSED){
    Serial.println("CONGRATS! YOU MASTERED THE D SCALE!");
    F1_S_PRESSED= false;
    C2_S_PRESSED= false;
  }
    delay(500);
}

//Set color helper function
void setColorD1(int redValue, int greenValue, int blueValue){
  analogWrite(D1redPin, redValue);
  analogWrite(D1greenPin, greenValue);
  analogWrite(D1bluePin, blueValue);
  }
void setColorE1(int redValue, int greenValue, int blueValue){
  analogWrite(E1redPin, redValue);
  analogWrite(E1greenPin, greenValue);
  analogWrite(E1bluePin, blueValue);
  }
void setColorG1(int redValue, int greenValue, int blueValue){
  analogWrite(G1redPin, redValue);
  analogWrite(G1greenPin, greenValue);
  analogWrite(G1bluePin, blueValue);
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
void setColorD2(int redValue, int greenValue, int blueValue){
  analogWrite(D2redPin, redValue);
  analogWrite(D2greenPin, greenValue);
  analogWrite(D2bluePin, blueValue);
  }
