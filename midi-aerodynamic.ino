#include "midi_notes.h"

/*  MIDI Aerodynamic
 *   
 *  MIDI demo to check if MIDI out works.
 *   
 *  5 pin MIDI jack:
 *  pin 2 -> 5V (with 220 Ohm resistor)
 *  pin 3 -> GND
 *  pin 4 - > D1 (TX/Serial out)
 *  
 *  Special thanks to Daft Punk.
 *  
 */


int mod = 12 * 1; // multiply by n for octave shift
int d = 125; // delay for each note

int noteON = 144;   // 0b10010000, MIDI note on command
int noteOFF = 128;  // 0b10000000, MIDI note off command

void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);
  Serial.write(MIDInote);
  Serial.write(MIDIvelocity);
}

void play(int n, int v=127) {
  n = n + mod;
  
  MIDImessage(noteON, n, v);
  delay(d);
  MIDImessage(noteOFF, n, v);
}

void setup() {
  Serial.begin(31250); // MIDI baud rate
}

void loop() {
  for (int i=0; i<4; i++) {
    play(NOTE_D4);
    play(NOTE_FS3);
    play(NOTE_B3);
    play(NOTE_FS3);
  }

  for (int i=0; i<4; i++) {
    play(NOTE_D4);
    play(NOTE_GS3);
    play(NOTE_B3);
    play(NOTE_GS3);
  }

  for (int i=0; i<4; i++) {
    play(NOTE_G4);
    play(NOTE_B3);
    play(NOTE_E4);
    play(NOTE_B3);
  }

  for (int i=0; i<4; i++) {
    play(NOTE_E4);
    play(NOTE_A3);
    play(NOTE_CS4);
    play(NOTE_A3);
  }

  mod++; // 1 semitone transpose 
}


