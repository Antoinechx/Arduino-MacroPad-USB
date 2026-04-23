#include "Keyboard.h"
#include <Mouse.h>

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6 = 7;
const int buttonPin7 = 8;

boolean buttonState1Pressed = false;
boolean buttonState2Pressed = false;
boolean buttonState3Pressed = false;
boolean buttonState4Pressed = false;
boolean buttonState5Pressed = false;
boolean buttonState6Pressed = false;
boolean buttonState7Pressed = false;

#define JOYSTICK_X_PIN 20
#define JOYSTICK_Y_PIN 19

boolean joystickActive1 = false;  // Flag to track joystick state
boolean joystickActive2 = false;

const int ledPin = 10;
// Setup-----------------------------------------------------------------------------
void setup() {
  // Initialiser la communication série
  Serial.begin(115200);

  // Initialiser la bibliothèque Keyboard
  Keyboard.begin();

  // Définir les broches des boutons comme entrées
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);

  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);

  pinMode(ledPin, OUTPUT);
}
// Loop-----------------------------------------------------------------------------
void loop() {
  // Lire l'état des boutons
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int buttonState5 = digitalRead(buttonPin5);
  int buttonState6 = digitalRead(buttonPin6);
  int buttonState7 = digitalRead(buttonPin7);

  boolean buttonState1Current = digitalRead(buttonPin1);
  boolean buttonState2Current = digitalRead(buttonPin2);
  boolean buttonState3Current = digitalRead(buttonPin3);
  boolean buttonState4Current = digitalRead(buttonPin4);
  boolean buttonState5Current = digitalRead(buttonPin5);
  boolean buttonState6Current = digitalRead(buttonPin6);
  boolean buttonState7Current = digitalRead(buttonPin7);

  int16_t xValue = analogRead(JOYSTICK_X_PIN);
  int16_t yValue = analogRead(JOYSTICK_Y_PIN);

  digitalWrite(ledPin, LOW);

 

  //Button handling----------------------------------------------------------------
  if (buttonState1Current == LOW && !buttonState1Pressed) {
    Keyboard.press('S');
    delay(10);
    Keyboard.releaseAll();
    Keyboard.press('q');
    delay(10);  
    Keyboard.press('p');
    delay(10);  
    Keyboard.press('h');
    Keyboard.releaseAll();
    delay(10);  
    Keyboard.press('i');
    delay(10);
    Keyboard.press('r');
    delay(10);
    Keyboard.releaseAll();
    Keyboard.press('q');
    delay(10);
    Keyboard.releaseAll();
    Keyboard.press(KEY_KP_4);
    delay(10);
    Keyboard.press(KEY_RETURN);
    delay(10);
    Keyboard.releaseAll();
    buttonState1Pressed = true;
  } else if (buttonState1Current == HIGH) {
    buttonState1Pressed = false;
  }


  if (buttonState2Current == LOW && !buttonState2Pressed) {
    Keyboard.press(KEY_LEFT_GUI);
    delay(10);
    Keyboard.press('w');
    delay(10);
    Keyboard.releaseAll();
    buttonState2Pressed = true;
  } else if (buttonState2Current == HIGH) {
    buttonState2Pressed = false;
  }
  
  if (buttonState3Current == LOW && !buttonState3Pressed) {
    //Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press('c');
    delay(10);
    Keyboard.releaseAll();
    buttonState3Pressed = true;
  } else if (buttonState3Current == HIGH) {
    buttonState3Pressed = false;
  }

  if (buttonState4Current == LOW && !buttonState4Pressed) {
    delay(10);
    Keyboard.press('v');
    delay(10);
    Keyboard.releaseAll();
    buttonState4Pressed = true;
  } else if (buttonState4Current == HIGH) {
    buttonState4Pressed = false;
  }

  if (buttonState5Current == LOW && !buttonState5Pressed) {
    delay(10);
    Keyboard.press('w');
    delay(10);
    Keyboard.releaseAll();
    buttonState5Pressed = true;
  } else if (buttonState5Current == HIGH) {
    buttonState5Pressed = false;
  }

  if (buttonState6Current == LOW && !buttonState6Pressed) {
    Keyboard.press(KEY_LEFT_GUI);
    delay(10);
    Keyboard.press('c');
    delay(10);
    Keyboard.releaseAll();
    buttonState6Pressed = true;
  } else if (buttonState6Current == HIGH) {
    buttonState6Pressed = false;
  }
  
  if (buttonState7Current == LOW && !buttonState7Pressed) {
    Keyboard.press(KEY_LEFT_GUI);
    delay(10);
    Keyboard.press('v');
    delay(10);
    Keyboard.releaseAll();
    buttonState7Pressed = true;
  } else if (buttonState7Current == HIGH) {
    buttonState7Pressed = false;
  }

  //Joystick handling ---------------------------------------------------------
  joystickActive1 = (xValue > 1000 || xValue < 20);
  joystickActive2 = (yValue > 1000 || yValue < 20);

  if (joystickActive1) {
    if (xValue > 1000) {
      //Keyboard.press(KEY_DOWN_ARROW);
      Mouse.move(0, 0, -1);
      Serial.println(xValue);
      delay(200);
    } else if (xValue < 20) {
      //Keyboard.press(KEY_UP_ARROW);
      Mouse.move(0, 0, 1);
      Serial.println(xValue);
      delay(200);
    }
  } else {
    Keyboard.releaseAll();
  }
  if (joystickActive2) {
    if (yValue > 1000) {
      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.move(0, 0, 1);
      Serial.println(yValue);
      delay(100);
    } else if (yValue < 20) {
      Keyboard.press(KEY_LEFT_SHIFT);
      Mouse.move(0, 0, -1);
      Serial.println(yValue);
      delay(100);
    }
  } else {
    // Release all keys if joystick is not active
    Keyboard.releaseAll();
  }
}
