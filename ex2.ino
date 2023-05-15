/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"




// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4,NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4,NOTE_G4
};

int melody2[] = {
  NOTE_C4, NOTE_C4, NOTE_E4 ,NOTE_E4,NOTE_G4,NOTE_G4,NOTE_E4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4
};

int noteDurations2[] = {
  4, 4, 4, 4, 4, 4, 4  
};

void setup() {
  // iterate over the notes of the melody:
  pinMode(10,INPUT_PULLUP);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);  
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

bool check = true;
int buttonState = 0;

void loop() {
  // no need to repeat the melody.
  
  buttonState = digitalRead(10);
  Serial.println(check);
  if(buttonState == LOW){ check = !check;}
  if(check == true){  
    for (int thisNote = 0; thisNote < 7; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(13, melody[thisNote], noteDuration);
if(melody[thisNote]==NOTE_C4){
  digitalWrite(2,HIGH);
  delay(noteDuration);
  digitalWrite(2,LOW);
}else if(melody[thisNote]==NOTE_D4){
  digitalWrite(3,HIGH);
  delay(noteDuration);
  digitalWrite(3,LOW);
} else if(melody[thisNote]==NOTE_E4){
  digitalWrite(4,HIGH);
  delay(noteDuration);
  digitalWrite(4,LOW);
} else if(melody[thisNote]==NOTE_F4){
  digitalWrite(5,HIGH);
  delay(noteDuration);
  digitalWrite(5,LOW);
} else if(melody[thisNote]==NOTE_G4){
  digitalWrite(6,HIGH);
  delay(noteDuration);
  digitalWrite(6,LOW);
} else if(melody[thisNote]==NOTE_A4){
  digitalWrite(7,HIGH);
  delay(noteDuration);
  digitalWrite(7,LOW);
} else if(melody[thisNote]==NOTE_B4){
  digitalWrite(8,HIGH);
  delay(noteDuration);
  digitalWrite(8,LOW);
} 

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(13);
    }
  }
  else {
    for (int thisNote = 0; thisNote < 7; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations2[thisNote];
      tone(13, melody2[thisNote], noteDuration);
      if(melody2[thisNote]==NOTE_C4){
  digitalWrite(2,HIGH);
  delay(noteDuration);
  digitalWrite(2,LOW);
}else if(melody2[thisNote]==NOTE_D4){
  digitalWrite(3,HIGH);
  delay(noteDuration);
  digitalWrite(3,LOW);
} else if(melody2[thisNote]==NOTE_E4){
  digitalWrite(4,HIGH);
  delay(noteDuration);
  digitalWrite(4,LOW);
} else if(melody2[thisNote]==NOTE_F4){
  digitalWrite(5,HIGH);
  delay(noteDuration);
  digitalWrite(5,LOW);
} else if(melody2[thisNote]==NOTE_G4){
  digitalWrite(6,HIGH);
  delay(noteDuration);
  digitalWrite(6,LOW);
} else if(melody2[thisNote]==NOTE_A4){
  digitalWrite(7,HIGH);
  delay(noteDuration);
  digitalWrite(7,LOW);
} else if(melody2[thisNote]==NOTE_B4){
  digitalWrite(8,HIGH);
  delay(noteDuration);
  digitalWrite(8,LOW);
} 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(13);    
    }
  }
 
delay(200);  
}
