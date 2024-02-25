//Homemade Steering Wheel, Pedals and H-Shifter
//4 Potentiometer + 8 Micro Limit Switch + 1 Toggle Switch (3 Position)
//Use Arduino Pro Micro
//Tested in ETS 2 and ATS
//Non-Commercial for Personal use only.

#include <Joystick.h>

#define joyRY A2
#define joyRZ A1
#define joyThrottle A3
#define joySteering A0
#define joyButton1 2
#define joyButton2 3
#define joyButton3 4
#define joyButton4 5
#define joyButton5 6
#define joyButton6 7
#define joyButton7 8
#define joyButton8 9
#define joyButton9 16
#define joyButton10 10

int ryAxis_ = 0;
int rzAxis_ = 0;
int throttle_ = 0;
int steering_ = 0;
int lastButton1State = 0;
int lastButton2State = 0;
int lastButton3State = 0;
int lastButton4State = 0;
int lastButton5State = 0;
int lastButton6State = 0;
int lastButton7State = 0;
int lastButton8State = 0;
int lastButton9State = 0;
int lastButton10State = 0;
const int numReadings = 10;
int readings[numReadings];

Joystick_ Joystick(0x12, JOYSTICK_TYPE_JOYSTICK, 10, 0,false,false,false,false,true,true,false,true,false,false,true);

const bool initAutoSendState = true;

void setup()
{
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) 
  {
    readings[thisReading] = 0;
  }
  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);
  pinMode(joyButton5, INPUT_PULLUP);
  pinMode(joyButton6, INPUT_PULLUP);
  pinMode(joyButton7, INPUT_PULLUP);
  pinMode(joyButton8, INPUT_PULLUP);
  pinMode(joyButton9, INPUT_PULLUP);
  pinMode(joyButton10, INPUT_PULLUP);

  Joystick.begin();
}

void loop() 
{
  ryAxis_ = analogRead(joyRY);
  ryAxis_ = map(ryAxis_,0,1023,0,255);
  Joystick.setRyAxis(ryAxis_);

  rzAxis_ = analogRead(joyRZ);
  rzAxis_ = map(rzAxis_,0,1023,0,255);
  Joystick.setRzAxis(rzAxis_);

  throttle_ = analogRead(joyThrottle);
  throttle_ = map(throttle_,0,1023,0,255);
  Joystick.setThrottle(throttle_);

  steering_ = analogRead(joySteering);
  steering_ = map(steering_,0,1023,0,1278);
  Serial.println(steering_);
delay(0.5);
  Joystick.setSteering(steering_);


  int currentButton1State = !digitalRead(joyButton1);
  if (currentButton1State != lastButton1State)
  {
    Joystick.setButton(0, currentButton1State);
    lastButton1State = currentButton1State;
  }

  int currentButton2State = !digitalRead(joyButton2);
  if (currentButton2State != lastButton2State)
  {
    Joystick.setButton(1, currentButton2State);
    lastButton2State = currentButton2State;
  }
  int currentButton3State = !digitalRead(joyButton3);
  if (currentButton3State != lastButton3State)
  {
    Joystick.setButton(2, currentButton3State);
    lastButton3State = currentButton3State;
  }
  int currentButton4State = !digitalRead(joyButton4);
  if (currentButton4State != lastButton4State)
  {
    Joystick.setButton(3, currentButton4State);
    lastButton4State = currentButton4State;
  }
  int currentButton5State = !digitalRead(joyButton5);
  if (currentButton5State != lastButton5State)
  {
    Joystick.setButton(4, currentButton5State);
    lastButton5State = currentButton5State;
  }
  int currentButton6State = !digitalRead(joyButton6);
  if (currentButton6State != lastButton6State)
  {
    Joystick.setButton(5, currentButton6State);
    lastButton6State = currentButton6State;
  }
  int currentButton7State = !digitalRead(joyButton7);
  if (currentButton7State != lastButton7State)
  {
    Joystick.setButton(6, currentButton7State);
    lastButton7State = currentButton7State;
  }
  int currentButton8State = !digitalRead(joyButton8);
  if (currentButton8State != lastButton8State)
  {
    Joystick.setButton(7, currentButton8State);
    lastButton8State = currentButton8State;
  }
  int currentButton9State = !digitalRead(joyButton9);
  if (currentButton9State != lastButton9State)
  {
    Joystick.setButton(8, currentButton9State);
    lastButton9State = currentButton9State;
  }
  int currentButton10State = !digitalRead(joyButton10);
  if (currentButton10State != lastButton10State)
  {
    Joystick.setButton(9, currentButton10State);
    lastButton10State = currentButton10State;
  }

}
