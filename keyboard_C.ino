//This program will take care of C scale
//C Scale={"C1","D1","E1","F1","G1","A1","B1","C2"};
//Fingering={1,2,3,1,2,3,4,5};
//Black Keys: 1=F1_S, 2=C2_S, 3=G1_S, 4=D2_S
//White Keys: 1=C1, 2=D1, 3=E1, 4=F1, 5=G1, 6=A1, 7=B1, 8=C2, 9=D2, 10=E2
//C Scale Black={};
//C Scale White={"C1","D1","E1","F1","G1","A1","B1","C2"};

//LED pins
//int LED1 = 1; //C1
//int LED2 = 2; //D1
//int LED3 = 3; //E1
//int LED4 = 4; //F1
//int LED5 = 5; //G1
//int LED6 = 6; //A1
//int LED7 = 7; //B1
//int LED8 = 8; //C2

//C1 {1,2,3}(Example)
  int C1redPin = 1;
  int C1greenPin = 2;
  int C1bluePin = 3;
//D1 {4,5,6}
  int D1redPin = 4;
  int D1greenPin = 5;
  int D1bluePin = 6;
//E1 {7,8,9}
  int E1redPin = 7;
  int E1greenPin = 8;
  int E1bluePin = 9;
//F1 {10,11,12}
  int F1redPin = 10;
  int F1greenPin = 11;
  int F1bluePin = 12;
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
  int C2redPin = 22;
  int C2greenPin = 23;
  int C2bluePin = 24;

bool greeting= true;

void setup()
{

  //Coloring
    //Red=1 {255,0,0}
    //Yellow=2 {255,255,0}
    //Green=3 {0,255,0}
    //Blue=4 {0,0,255}
    //Purple=5 {170,0,255}
    //Aqua= MISC {0,255,255}
    //White= MISC {255,255,255}

        //LED pins
//int LED1 = 1; //C1 <1>
//int LED2 = 2; //D1 <2>
//int LED3 = 3; //E1 <3>
//int LED4 = 4; //F1 <4>
//int LED5 = 5; //G1 <5>
//int LED6 = 6; //A1 <6>
//int LED7 = 7; //B1 <7>
//int LED8 = 8; //C2 <8>

    //LEDS TURN ON
    setColorC1(255,0,0); //1 Red
    setColorD1(255,255,0); //2 Yellow
    setColorE1(0,255,255); //3 Green
    setColorF1(255,0,0); //1 Red
    setColorG1(255,95,0); //2 Yellow
    setColorA1(0,255,0); //3 Green
    setColorB1(0,0,255); //4 Blue
    setColorC2(170,0,255); //5 Purple
        
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop()
{
    while (greeting){
      Serial.println(" YOU ARE NOW LEARNING HOW TO PLAY THE C SCALE ");
      Serial.print(" PLEASE FOLLOW THE DIRECTTIONS OF THE USER STUDY FACILITATOR ");
      greeting=false;
    }
}

//Set color helper function

void setColorC1(int redValue, int greenValue, int blueValue){
  analogWrite(C1redPin, redValue);
  analogWrite(C1greenPin, greenValue);
  analogWrite(C1bluePin, blueValue);
  }
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
  void setColorF1(int redValue, int greenValue, int blueValue){
  analogWrite(F1redPin, redValue);
  analogWrite(F1greenPin, greenValue);
  analogWrite(F1bluePin, blueValue);
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
void setColorC2(int redValue, int greenValue, int blueValue){
  analogWrite(C2redPin, redValue);
  analogWrite(C2greenPin, greenValue);
  analogWrite(C2bluePin, blueValue);
  }
  
