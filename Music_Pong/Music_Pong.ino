#include "notes.h"
#include "constants.h"
#include "variables.h"

int SONG_NOTES[] = {NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1, NOTE_A1, NOTE_B1, NOTE_C2};

void setup() {
  Serial.begin(9600);
//  pinMode(13, OUTPUT);
  pinMode(LDR_1_PIN, INPUT);   //initialize the LDR pin as an input
  pinMode(LDR_2_PIN, INPUT);   //initialize the LDR pin as an input
  pinMode(LDR_3_PIN, INPUT);   //initialize the LDR pin as an input
  pinMode(LDR_4_PIN, INPUT);   //initialize the LDR pin as an input
  pinMode(LDR_5_PIN, INPUT);   //initialize the LDR pin as an input
  pinMode(LDR_6_PIN, INPUT);   //initialize the LDR pin as an input
}

void loop() {
  sumOfArray();
  processLDRs();

  if(octave != -1 && octave != MAX_INDEX){
    processJoystick();
  }else if(octave == MAX_INDEX){
    playSong();
//    digitalWrite(13, LOW);
  }
}

void playSong(){
//  digitalWrite(13, HIGH);
  for(int songOctave = 0; songOctave < 8; songOctave++){
    for(int note = 0; note < 8; note++){
       MIDImessage(noteON, SONG_NOTES[note], VOLUME, songOctave);
       delay(250);
    }
  }
}

void sumOfArray(){
  int count = 0;
  for (int i = 0; i <= MAX_INDEX; i++){
    if(ldrStates[i] == 1)
      count += 1;
  }
  octave = count-1;
}

void processLDRs(){
  isDark(LDR_1_PIN);  
  isDark(LDR_2_PIN);
  isDark(LDR_3_PIN);  
  isDark(LDR_4_PIN);
  isDark(LDR_5_PIN);  
  isDark(LDR_6_PIN);
}

void isDark(int pinToCheck) {
  int ldrStatus = analogRead(pinToCheck);   //read the status of the LDR value
  if (ldrStatus <= 200) { // Need to adjust this value once built
    ldrStates[pinToCheck - 10] = 1;
  }
  else {
    ldrStates[pinToCheck - 10] = 0;
  }
}

// Adapted from: https://www.instructables.com/id/Arduino-Sensors-and-MIDI/
void processJoystick(){
  int xRead = analogRead(X_PIN);
  int yRead = analogRead(Y_PIN);

  if (xRead < 768 && xRead > 256 && yRead == 0 && jsStates[0] == 0) { callMidiFor(0, NOTE_C1); }
  if (xRead >= 768 && xRead <= 1023 && yRead >= 0 && yRead <= 256 && jsStates[1] == 0) { callMidiFor(1, NOTE_D1); }
  if (yRead < 768 && yRead > 256 && xRead == 1023 && jsStates[2] == 0) { callMidiFor(2, NOTE_E1); }
  if (yRead >= 768 && yRead <= 1023 && xRead >= 768 && xRead <= 1023 && jsStates[3] == 0) { callMidiFor(3, NOTE_F1); }
  if (xRead < 768 && xRead > 256 && yRead == 1023 && jsStates[4] == 0) { callMidiFor(4, NOTE_G1); }
  if (yRead >= 768 && yRead <= 1023 && xRead >= 0 && xRead <= 256 && jsStates[5] == 0) { callMidiFor(5, NOTE_A1); }
  if (yRead < 768 && yRead > 256 && xRead == 0 && jsStates[6] == 0) { callMidiFor(6, NOTE_B1); }
  if (xRead >= 0 && xRead <= 256 && yRead >= 0 && yRead <= 256 && jsStates[7] == 0) { callMidiFor(7, NOTE_C2); }   
   
  if (xRead >= 518 && xRead <= 522 && yRead >= 487 && yRead <= 489){
    for(int state = 0; state < 8; state++){
      if(jsStates[state] == 1){
        jsStates[state] = 0;
      }
    }
  }
}

void callMidiFor(int stateIndex, int note){
  jsStates[stateIndex] = 1;
  MIDImessage(noteON, note, VOLUME, octave);
}

void MIDImessage(byte control, byte note, byte volume, int octave) {
  Serial.write(control);
  Serial.write(note+(12*(octave)));
  Serial.write(volume);
}
