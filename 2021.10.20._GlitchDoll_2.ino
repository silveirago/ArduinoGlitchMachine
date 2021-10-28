/* Noise machine using three potentiometers connected to analog inputs
  and a piezo or small speaker. A pushbutton turns on the noise, the potentiometers
  control the pitch using the Arduino tone() function, and two delay
  values which control the length of each tone and length between
  each tone. The potentiometers give analog values which are changed
  using the map() function into larger or smaller ranges to suit your
  musical tastes.
  This code is in the public domain.
  Matt Thomas 05/04/2019
*/
const int buttonPin = 2;  // Pushbutton pin 2
const int speaker = 6;    // Speaker or piezo in pin 9
int buttonState = 0;      // Variables for the button
int potZero;              // and potentiometers
int potOne;
int potTwo;

long randNumber;

int led1 = 9;

void setup() {
  pinMode(9, OUTPUT);     // Speaker/piezo output pin
  pinMode(led1, OUTPUT);     // Speaker/piezo output pin
  pinMode(2, INPUT_PULLUP);     // Speaker/piezo output pin

Serial.begin(9600);

  randomSeed(analogRead(A5));
}

void loop() {

  buttonState = digitalRead(buttonPin);  // Read the pushbutton state
  potZero = analogRead(A0);    //Variables for reading the analog values
  potOne  = analogRead(A1);
  potTwo  = analogRead(A2);

  int htz = map(potZero, 0, 1023, 20, 5000); // Map the analog readings into
  int high = map(potOne, 0, 1023, 100, 0); // new number ranges and create
  int low = map(potTwo, 0, 1023, 100, 0);  // new variables

  // print a random number from 0 to 299
  if (buttonState == LOW) {
    randomSeed(analogRead(A5));
    randNumber = random(15);
  }
  else {
    randNumber = 0;
  }


  // If the pushbutton is pressed...
  tone(speaker, htz);        // Sound on
  digitalWrite(led1, HIGH);

  delay(high + randNumber);               // Length of tone
  noTone(speaker);           // Sound off
  digitalWrite(led1, LOW);
  
  delay(low + randNumber);                // Time until next tone




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Serial.print("potZero: ");
Serial.print(potZero);
Serial.print("  | potOne: ");
Serial.print(potOne);
Serial.print("  | potTwo: ");
Serial.print(potTwo);

Serial.print("    ");

Serial.print("Hzt: ");
Serial.print(htz);
Serial.print("  | High: ");
Serial.print(high);
Serial.print("  | Low: ");
Serial.println(low);

}
