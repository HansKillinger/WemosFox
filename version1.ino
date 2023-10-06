
char stringCallSign[] = "XXXXX fox ";//replace 'XXXXX' with your call sign
char stringGPSinvalid[] = "GPS invalid ";

// Pin variables
int audioPin = 2;    // output audio on pin 2
int note = 800;      // audio tone frequency (Hz)
int keyline = 0;     // control keyline on pin 0

//********************************
// dotLen = 1200/(words per minute)
// 100 = 12 words per minute
// 60 = 20 words per minute
// 48 = 25 words per minute
// 40 = 30 words per minute
// 20 = 60 words per minute
//********************************

//Morse variables
int dotLen = 60;             // length of the morse code 'dot'
int dashLen = dotLen * 3;    // length of the morse code 'dash'
int elemPause = dotLen;      // length of the pause between elements of a character
int Spaces = dotLen * 3;     // length of the spaces between characters
int wordPause = dotLen * 7;  // length of the pause between words
int DeadTime = 30000;        // Morse code loop will wait this many milliseconds between transmissions


unsigned long WaitUntil = 0 ;


void setup() {                

  pinMode(keyline, OUTPUT);   
  digitalWrite(keyline, HIGH);
  
  WaitUntil = millis() + DeadTime;
}


void loop()
{ 
  //***************
  //morse code loop.  Pause between transmissions by the value in 'DeadTime'
  if (millis() >= WaitUntil){
    //key the radio
    digitalWrite(keyline, LOW);
    //wait for the radio to be keyed
    delay(250);
    
    // Loop through the string and get each character one at a time until the end is reached
    // call sign
    for (int i = 0; i < sizeof(stringCallSign) - 1; i++)
    {
  	char tmpChar = stringCallSign[i];
  	tmpChar = toLowerCase(tmpChar);
  	TX_Morse(tmpChar);
        MorseSpace(Spaces);//between letter pause
    }
    //unkey the radio
    digitalWrite(keyline, HIGH);    
    MorseSpace(1);			
    //set the next time to TX the morse code
    WaitUntil = millis() + DeadTime;
    //turn back on the GPS serial port
  }
}


// DOT
void MorseDot()
{
  digitalWrite(ledPin, HIGH);  	// turn the LED on 
  tone(audioPin, note, dotLen);	// start playing a tone
  delay(dotLen);             	// hold in this position
}

// DASH
void MorseDash()
{
  digitalWrite(ledPin, HIGH);  	// turn the LED on 
  tone(audioPin, note, dashLen);	// start playing a tone
  delay(dashLen);               // hold in this position
}

// Turn Off
void MorseSpace(int delayTime)
{
  digitalWrite(ledPin, LOW);    	// turn the LED off  	
  noTone(audioPin);	       	   	// stop playing a tone
  delay(delayTime);            	// hold in this position
}

// *** Characters to Morse Code Conversion *** //
void TX_Morse(char tmpChar)
{
	// Take the passed character and use a switch case to find the morse code for that character
	switch (tmpChar) {
	  case 'a':	
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'b':
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'c':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'd':
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'e':
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'f':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'g':
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'h':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'i':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'j':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
          case 'k':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'l':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
          case 'm':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'n':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'o':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'p':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 'q':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'r':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 's':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case 't':
	        MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'u':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'v':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'w':
	        MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'x':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'y':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case 'z':
	        MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case ' ':
		MorseSpace(dotLen);
		break;
	  case '1':
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case '2':
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case '3':
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case '4':
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;
	  case '5':
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case '6':
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case '7':
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case '8':
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case '9':
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDot();
		MorseSpace(elemPause);
		break;
	  case '0':
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		MorseDash();
		MorseSpace(elemPause);
		break;

	  default: 
		MorseSpace(Spaces);			
	}
}

int Char2Int(char in){
  switch (in){
    case '0':
      return 0;
      break;
    case '1':
      return 1;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 4;
      break;
    case '5':
      return 5;
      break;
    case '6':
      return 6;
      break;
    case '7':
      return 7;
      break;
    case '8':
      return 8;
      break;
    case '9':
      return 9;
      break;
    case 'a':
      return 10;
      break;
    case 'b':
      return 11;
      break;
    case 'c':
      return 12;
      break;
    case 'd':
      return 13;
      break;
    case 'e':
      return 14;
      break;
    case 'f':
      return 15;
      break;

    case 'A':
      return 10;
      break;
    case 'B':
      return 11;
      break;
    case 'C':
      return 12;
      break;
    case 'D':
      return 13;
      break;
    case 'E':
      return 14;
      break;
    case 'F':
      return 15;
      break;
  }
}

