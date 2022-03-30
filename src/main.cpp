#include <Arduino.h>
#include "Keyboard.h"

// ------------- Initial Variables -----------------
const int ROWS = 6;
const int COLS = 4;
int val = 0;


// Keyboard Layers

// Base Layer
int layerBase[ROWS][COLS] = {
  {177, 128, 130, 179}, //  Esc
  {7, 129, 47,  42},  //  Num Lock
  {55,  56,  57,  45},  //
  {52,  53,  54,  43},  //
  {49,  50,  51,  176}, //
  {48,  0,   46,  0}    //
};

// Num Lock Layer
int layerNum[ROWS][COLS] = {
  {177, 128, 130, 179},
  {7, 129, 47,  42},
  {55,  56,  57,  45},
  {52,  53,  54,  43},
  {49,  50,  51,  176},
  {48,  0,   46,  0} 
};

// Shift Layer
int layerShift[ROWS][COLS] = {
  {177, 128, 130, 179},
  {7, 129, 47,  42},
  {55,  56,  57,  45},
  {52,  53,  54,  43},
  {49,  50,  51,  176},
  {48,  0,   46,  0} 
};


// States
bool numToggle = false;
bool numWasDown = false;
bool shiftPressed = false;

// Row Pins
int rowPins[ROWS] = {2,3,4,5,6,8};

// Column Pins
int colPins[COLS] = {12,11,10,9};

// LED Pins
int LED_Pint = 9;

// -------------- Setup ----------------------
void setup() {
  // Setup Rows
  for (int row = 0; row<ROWS; row++) {
    pinMode(rowPins[row],INPUT_PULLUP);
  };
  // Setup Columns
  for (int col = 0; col<COLS; col++) {
    pinMode(colPins[col],OUTPUT);
    digitalWrite(colPins[col], HIGH);
  };
  // Select initial layer
  Keyboard.begin();
}

// --------------- Functions ------------------

// KeyPressed Function
void keyPress(int row, int col) {
  Keyboard.press(layerBase[row][col]);
}

// KeyRelease Fuction
void keyRelease(int row, int col) {
  Keyboard.release(layerBase[row][col]);
}

// ----------------- Loop ----------------------
void loop() {
    // For each Column
  for (int col = 0; col<COLS; col++) {
    digitalWrite(colPins[col], LOW);        // Set the current column pin to low
    delayMicroseconds(5);                   // Delay the code slightly, apparently this can help prefent errors
    // For each Row
    for (int row = 0; row<ROWS; row++) {

      // If the key is being pressed
      if (digitalRead(rowPins[row]) == LOW) {
        keyPress(row,col);     // print a character
      } 

      // If the key is currently not pressed
      else if (digitalRead(rowPins[row]) == HIGH) {
        keyRelease(row,col);   // Release the selected key
      };  //  End of IF-Else Statement


      delayMicroseconds(500);
    };  //  End of Row For loop
    digitalWrite(colPins[col], HIGH);     // Reset Column Pin
    delayMicroseconds(500);
  };  //  End of Col For loop
} // End of Loop
// ----------------- Functions --------------------

int readKey(int keyPress, bool shiftPressed, bool numToggle) {
  int result;
  // If the key is num lock
  if (keyPress == 7) {

  };
  // If the key press is shift
  // If shift is being pressed
  // If numlock was pressed
}
