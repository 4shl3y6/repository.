//#include <ESP_Google_Sheet_Client_FS_Config.h>
//#include <ESP_Google_Sheet_Client.h>

#include <Adafruit_AS7341.h>

Adafruit_AS7341 as7341;

//Light -> pins

const int white = 8;
const int red =7;
const int orange = 6;
const int yellow = 5;
const int green = 4;
const int blue = 3;
const int uv = 2;

int whiteVal;
int redVal;
int orangeVal;
int yellowVal;
int greenVal;
int blueVal3;
int uvVal2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {//While there is nothing on the serial
    delay(1);
  }
  
  if (!as7341.begin()){//While the sensor doesn't begin
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }

  as7341.setATIME(100);
  as7341.setASTEP(999);
  as7341.setGain(AS7341_GAIN_256X);
//LED SETUP
  pinMode(white, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(uv, OUTPUT);
  //They're gonna start off with no voltage
  digitalWrite(white,LOW);
  digitalWrite(red,LOW);
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(uv, LOW);


}

//Code for the light sensor
void adaLightShow() {
  // Read all channels at the same time and store in as7341 object
  if (!as7341.readAllChannels()){
    Serial.println("Error reading all channels!");
    return;
  }

  // Print out the stored values for each channel
  Serial.print("F1 415nm/Blue Violet: ");//Blue violet
  Serial.println(as7341.getChannel(AS7341_CHANNEL_415nm_F1));
  Serial.print("F2 445nm/Blue1: ");//Blue
  Serial.println(as7341.getChannel(AS7341_CHANNEL_445nm_F2));
  Serial.print("F3 480nm/Blue2: ");//Blue
  Serial.println(as7341.getChannel(AS7341_CHANNEL_480nm_F3));
  Serial.print("F4 515nm/Green1: ");//Green
  Serial.println(as7341.getChannel(AS7341_CHANNEL_515nm_F4));
  Serial.print("F5 555nm/Green-Orange: ");//Green
  Serial.println(as7341.getChannel(AS7341_CHANNEL_555nm_F5));
  Serial.print("F6 590nm/Orange-Yellow: ");//Orange
  Serial.println(as7341.getChannel(AS7341_CHANNEL_590nm_F6));
  Serial.print("F7 630nm/Red1: ");//Red
  Serial.println(as7341.getChannel(AS7341_CHANNEL_630nm_F7));
  Serial.print("F8 680nm/Red2: ");//Red
  Serial.println(as7341.getChannel(AS7341_CHANNEL_680nm_F8));

  Serial.print("Clear    : ");
  Serial.println(as7341.getChannel(AS7341_CHANNEL_CLEAR));

  Serial.print("Near IR  : "); //Near IR
  Serial.println(as7341.getChannel(AS7341_CHANNEL_NIR));

  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Hello, welcome to the spectrometre");
  Serial.print('\n');
  Serial.print("What would you like to do?");
  Serial.print('\n');
while (Serial.available()==0){//While there is nothing in the serial monitor asker, do this... It does nothing! ITs
    
  }
  String instr = Serial.readString();
  if (instr == "Start"){
    //Light
    
    //Red
    digitalWrite(red,HIGH);
    adaLightShow();
    digitalWrite(red,LOW);
    Serial.print("Red complete");
    Serial.print('\n');

    //Orange
    digitalWrite(orange,HIGH);
    adaLightShow();
    digitalWrite(orange,LOW);
    Serial.print("Orange complete");
    Serial.print('\n');
    
    //Yellow
    digitalWrite(yellow,HIGH);
    adaLightShow();
    digitalWrite(yellow,LOW);
    Serial.print("Yellow complete");
    Serial.print('\n');
    
    //Green
    digitalWrite(green,HIGH);
    adaLightShow();
    digitalWrite(green,LOW);
    Serial.print("Green complete");
    Serial.print('\n');
    
    //Blue
    digitalWrite(blue,HIGH);
    adaLightShow();
    digitalWrite(blue,LOW);
    Serial.print("Blue complete");
    Serial.print('\n');
    
    //UV
    
    digitalWrite(uv,HIGH);
    adaLightShow();
    digitalWrite(uv,LOW);
    Serial.print("UV complete");
    Serial.print("\t");
    Serial.print('\n');
    
    //White
    digitalWrite(white,HIGH);
    adaLightShow();
    digitalWrite(white,LOW);
    Serial.print("White complete");
    Serial.print('\n');

    Serial.print("Analysis finished");
    Serial.print('\n');
  }
  if (instr =="Stop"){
    Serial.print("Stop");
  }
  if (instr == "Calibrate"){
    Serial.print("Calibrated");
  }
}
