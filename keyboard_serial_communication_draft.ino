#include <SoftwareSerial.h>

//Adaptive Concept:
//Users should be able to play scales FASTER and MORE ACCURATELY after our tool

//the typedef is data structure that allows you to define variables. We are defining a keyboard typedef
typedef struct keyboard{
  //Level is the level the user is playing at
  //Level 1 : Full assistance (black keys + LEDs)
  //Level 2 : Partial assistance (black keys)
  //Level 3 : No assistance
  int level= 1;
  
  //Scale is the scale key the user is playing
  String scale=SCALES[0];
  String k1;
  String k2;
  String k3;
  String k4;
  String k5;
  String k6;
  
} keyboard;
keyboard Master;

//SoftwareSerial allows for you to define other arduinos. 
//TODO: We are only needing 2 for the first round of user testing, but will scale POSSIBLY later if we include white keys
SoftwareSerial Ad2(2,3);
SoftwareSerial Ad3(4,5);
SoftwareSerial Ad4(6,7);

//These are the list of scales we want the user to try to play
String SCALES[1]={"C","D","E"}; // TODO: In the future, we will want {"C","D","E","F","E_F","G_F"} possibly

//These are the individual keys of each scale
String C_SCALE[8]= {"C1","D1","E1","F1","G1","A1","B1","C2"};
String D_SCALE[8]= {"D1","E1","F1_S","G1","A1","B1","C1_S","D"};
String E_SCALE[8]= {"E1","F1_S","G1_S","A1","B1","C2_S","D2_S","E2"};

//These are the black keys to be pressed of each scale
String C_SCALE_BLACK[0]= {};
String D_SCALE_BLACK[2]={"F1_S","C2_S"};
String E_SCALE_BLACK[4]={"F1_S","G1_S","C2_S","D2_S"};

//These are the LEDS that should light up 
//TODO: Maybe in the future we can expand this to black keys, but for now we are only lighting up white keys
String C_SCALE_LIGHT[8]={"C1","D1","E1","F1","G1","A1","B1","C1"};
String D_SCALE_LIGHT[6]={"D1","E1","G1","A1","B1","D"};
String E_SCALE_LIGHT[4]={"E1","A1","B1","E2"};

//This is the next "target" key to be played.
//TODO: In the future we will expland this to all keys, but for now we are only checking black keys
String targetKey;

//Mistake counter
int mistake_counter=0;

//This method senses when a mistake is made
bool senseMistake(String target, String pressed){

  if (target){
    
  }
}

//Key listener method
//supports reading across all arduinos; is called during every loop
//TODO: Currently only implemented for 10 black keys, but we might scale this later for white keys.
//Input: Level, Scale, Keys to press in scale, targetKey
//Output:
String keyListener(level, scale, targetKey){
  
  //Defines pin numbers corresponding to keys
  //Arduino Analog Pins Black Octave 1U
  int analogPinC1_S= 1;
  int analogPinD1_S= 3;
  int analogPinF1_S= 6;
  int analogPinG1_S= 8;
  int analogPinA1_S= 10;
  //Arduino Analog Pins Black Octave 2
  int analogPinC2_S= 13;
  int analogPinD2_S= 15;
  int analogPinF2_S= 18;
  int analogPinG2_S= 20;
  int analogPinA2_S= 22;

  //TODO: We can scale for WHITE keys possibly later
  //Arduino Analog Pins White & Black Octave 1
//  int analogPinC1= 0;
//  int analogPinD1= 2;
//  int analogPinE1= 4;
//  
//  int analogPinF1= 5;
//  int analogPinG1= 7;
//  int analogPinA1= 9;
//  int analogPinB1= 11;

//  int analogPinC2_S= 13;
//  int analogPinD2_S= 15;
//  int analogPinF2_S= 18;
//  int analogPinG2_S= 20;
//  int analogPinA2_S= 22;

  //Arduino Analog Pins White & Black Octave 2
//  int analogPinC2= 12;
//  int analogPinD2= 14;
//  int analogPinE2= 16;
//  
//  int analogPinF2= 17;
//  int analogPinG2= 19;
//  int analogPinA2= 21;
//  int analogPinB2= 23;

//  int analogPinC2_S= 13;
//  int analogPinD2_S= 15;
//  int analogPinF2_S= 18;
//  int analogPinG2_S= 20;
//  int analogPinA2_S= 22;


  //Reads in resistance number from pins
  
  //Octave 1
  rawC1_S= analogRead(analogPinC1_S);
  rawD1_S= analogRead(analogPinD1_S);
  rawF1_S= analogRead(analogPinF1_S);
  rawG1_S= analogRead(analogPinG1_S);
  rawA1_S= analogRead(analogPinA1_S);
  
  //Octave 2
  rawC1_S= analogRead(analogPinC1_S);
  rawD1_S= analogRead(analogPinD1_S);
  rawF1_S= analogRead(analogPinF1_S);
  rawG1_S= analogRead(analogPinG1_S);
  rawA1_S= analogRead(analogPinA1_S);

  //TODO: We can scale this for white keys later.
 //Ad2 will be available if sending data. We just have to make sure this is on.
 while (Ad2.available()){
    //C1_S
    if(rawC1_S>10) //10 is just a filler for foam resistance
    {
      Serial.println("C1_S KEY IS PRESSED");
      //if this is true, there is a mistake, and we will mark it in terminal as well as increment # of mistakes
      if (senseMistake(targetKey,"C1_S")){
        Serial.println("MISTAKE: C1_S");
        mistake_counter+=1;
      }
    }

    //D1_S
    if(rawD1_S>10) //10 is just a filler for foam resistance
    {
      Serial.println("D1_S KEY IS PRESSED");
      //if this is true, there is a mistake, and we will mark it in terminal as well as increment # of mistakes
      if (senseMistake(targetKey,"D1_S")){
        Serial.println("MISTAKE: D1_S");
        mistake_counter+=1;
      }
    }

    //F1_S
    if(rawF1_S>10) //10 is just a filler for foam resistance
    {
      Serial.println("F1_S KEY IS PRESSED");
      //if this is true, there is a mistake, and we will mark it in terminal as well as increment # of mistakes
      if (senseMistake(targetKey,"F1_S")){
        Serial.println("MISTAKE: F1_S");
        mistake_counter+=1;
      }
    }

    //G1_S
    if(rawG1_S>10) //10 is just a filler for foam resistance
    {
      Serial.println("G1_S KEY IS PRESSED");
      //if this is true, there is a mistake, and we will mark it in terminal as well as increment # of mistakes
      if (senseMistake(targetKey,"G1_S")){
        Serial.println("MISTAKE: G1_S");
        mistake_counter+=1;
      }
    }

    //A1_S
    if(rawA1_S>10) //10 is just a filler for foam resistance
    {
      Serial.println("A1_S KEY IS PRESSED");
      //if this is true, there is a mistake, and we will mark it in terminal as well as increment # of mistakes
      if (senseMistake(targetKey,"A1_S")){
        Serial.println("MISTAKE: A1_S");
        mistake_counter+=1;
      }
    }   
  }
}

void setup() {
  // put your setup code here, to run once:
  Ad2.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //  Serial.print(Master.scale);
  senseKey();
  Ad2.print("Echo\n");
  delay(1);
  while(Ad2.available()){
    Serial.write(Ad2.read());
    }

  //listen for pressed keys
  keyListener();
}
