
 /*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int firstSensorPin = A0; //analog pin 0
int secondSensorPin = A1; //analog pin 0
int thirdSensorPin = A2;
int fourthSensorPin = A3;
int fifthSensorPin = A4;

int low1;
int low2;
int low3;
int low4;
int low5;

int hi1,hi2,hi3,hi4,hi5;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
    Serial.begin(9600);
    hi1 = analogRead(firstSensorPin);
    hi2 = analogRead(secondSensorPin);
    hi3 = analogRead(thirdSensorPin);
    hi4 = analogRead(fourthSensorPin);
    hi5 = analogRead(fifthSensorPin);
    low1 = hi1 - 120;
    low2 = hi2 - 120;
    low3 = hi3 - 120;
    low4 = hi4 - 120;
    low5 = hi5 - 120;
    
                    
}

void loop() {
  
  int firstSensorReading = analogRead(firstSensorPin); 
  int secondSensorReading = analogRead(secondSensorPin); 
  int thirdSensorReading = analogRead(thirdSensorPin);
  int fourthSensorReading = analogRead(fourthSensorPin);
  int fifthSensorReading = analogRead(fifthSensorPin);


  //In my tests I was getting a reading on the arduino between 512, and 614. 
  //Using map(), you can convert that to a larger range like 0-100.
  int first = map(firstSensorReading, hi1, low1, 0, 100);
  int second = map(secondSensorReading, hi2, low2, 0, 100);
  int third = map(thirdSensorReading, hi3, low3, 0, 100);
  int fourth = map(fourthSensorReading, hi4, low4, 0, 100);
  int fifth = map(fifthSensorReading, hi5, low5, 0, 100);

  int average = 0;  //average of the all flexed fingers is calculated, and that is played.
  int count = 0;
  
  /* ALL YOU HAVE TO DO IN THIS CODE IS ADD THE THIRD FORTH AND POSSIBLY FIFTH FLEX SENSORS */ 
  if (first > 50){
    count++;
    average = (melody[0] + average)/count;
  }
  if (second > 50){
    count++;
    average = (melody[1] + average)/count;

  }
  if (third > 50){
    count++;
    average = (melody[2] + average)/count;

  }
  if (fourth > 50){
    count++;
    average = (melody[3] + average)/count;

  }
  if (fifth > 50){
    count++;
    average = (melody[4] + average)/count;

  }  
  if (average != 0){
    tone(8, average);
  }
  else
    noTone(8);

  delay(80); //just here to slow down the output for easier reading
  // no need to repeat the melody.
}
