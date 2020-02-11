//set pin numbers
//const won't change
const int ledPin = 13;   //the number of the LED pin
const int ldrPin = A0;  //the number of the LDR pin
int count = 0;


void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  //initialize the LED pin as an output
  pinMode(ldrPin, INPUT);   //initialize the LDR pin as an input
}

void loop() {

  int ldrStatus = analogRead(ldrPin);   //read the status of the LDR value

  //check if the LDR status is <= 300
  //if it is, the LED is HIGH

   if (ldrStatus <=300) {

    digitalWrite(ledPin, HIGH);               //turn LED on
    Serial.println("LDR is DARK, LED is ON");

     delay(500);

  // serial write section

    Serial.println("Start1");
    Serial.print("\n");
    Serial.flush();

    if(count < 10){
      count = count + 1;
      Serial.println(count);
      Serial.flush();
      
    }else{
      Serial.println("Start2");
      Serial.print("\n");
      Serial.flush();
      count = 0;
    }
    
   }
  else {

    digitalWrite(ledPin, LOW);          //turn LED off
    Serial.println("---------------");
    Serial.println("Stop2");
    Serial.print("\n");
    Serial.flush();
    
  }
}


////set pin numbers
////const won't change
//const int ledPin = 13;   //the number of the LED pin
//const int ldr1Pin = A15;  //the number of the LDR pin
//const int ldr2Pin = A14;
//const int ldr3Pin = A13;
//const int ldr4Pin = A12;
//const int ldr5Pin = A11;
//const int ldr6Pin = A10;
//bool sent = 0;
//
//void setup() {
// 
//  Serial.begin(9600);
////  pinMode(ledPin, OUTPUT);  //initialize the LED pin as an output
//  pinMode(ldr1Pin, INPUT);   //initialize the LDR pin as an input
//  pinMode(ldr2Pin, INPUT);   //initialize the LDR pin as an input
//  pinMode(ldr3Pin, INPUT);   //initialize the LDR pin as an input
//  pinMode(ldr4Pin, INPUT);   //initialize the LDR pin as an input
//  pinMode(ldr5Pin, INPUT);   //initialize the LDR pin as an input
//  pinMode(ldr6Pin, INPUT);   //initialize the LDR pin as an input
//}
//
//void loop() {
////  isDark(ldr1Pin);  
////  isDark(ldr2Pin);
////  isDark(ldr3Pin);  
////  isDark(ldr4Pin);
//  isDark(ldr5Pin); 
//  isDark(ldr6Pin);
//}
//
//void isDark(int pinToCheck) {
//  int ldrStatus = analogRead(pinToCheck);   //read the status of the LDR value
////  delay(100);/
//   if (ldrStatus <= 500) { // Need to adjust this value once built
////    digitalWrite(ledPin, HIGH);               //turn LED on
////    Serial.println("Pin " + String(pinToCheck-63) + " LDR is DARK, CUP is ENABLED");
//// 
//  if(sent==0){
//    sent = 1;
//    Serial.println("Start"+String(pinToCheck-63));
////    Serial.print("Satrt/1");
//    Serial.flush();
////    Serial.println("Pin " + String(pinToCheck-58) + " is reading " + String(ldrStatus));
//  }
//    
//   }
//  else {
//    sent = 0;
//    Serial.println("Stop"+String(pinToCheck-63));
//    Serial.flush();
////    Serial.println("Pin " + String(pinToCheck-58) + " is reading " + String(ldrStatus));
//  }
//}
