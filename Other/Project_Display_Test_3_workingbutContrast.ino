//   Roman Bond   Arduino Project I   CMPT422

//Screen size test
//"1------x2-----16"
//" Welcome to the "
//"Bond Binary Calc"
//"   Booting...   "

//  -----   Boot screen things   -----   //

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int testTime = (millis() / 1000);

// Boot screen
String boot0 = "   Booting      ";
String boot1 = "   Booting.     ";
String boot2 = "   Booting..    ";
String boot3 = "   Booting...   ";

// Splash screen / welcome screen
String splash1 = " Welcome to the ";
String splash2 = "Bond Binary Calc";

//  -----   Important variables   -----   //

int switchState1 = 0;       // button 1
int switchState2 = 0;       // button 2
int switchStateTest = 0;    // button 3
int buttonHold_1 = 1;       // button 1 hold counter
int buttonHold_2 = 1;       // button 2 hold counter
int stat = 1;             // stat
int currentBit = 0;         // tracks binary bit being modified
int binaryOne[8] = {2,2,2,2,2,2,2,2};   // first binary value 
int binaryTwo[8] = {2,2,2,2,2,2,2,2};   // second binary value
int binary1[8] = {0,0,0,0,0,0,0,0};   // first binary value 
int binary2[8] = {0,0,0,0,0,0,0,0};   // second binary value
int answer[9] = {0,0,0,0,0,0,0,0,0};
int a1[1] = {0};
int a2[2] = {0,0};
int a3[3] = {0,0,0};
int a4[4] = {0,0,0,0};
int a5[5] = {0,0,0,0,0};
int a6[6] = {0,0,0,0,0,0};
int a7[7] = {0,0,0,0,0,0,0};
int a8[8] = {0,0,0,0,0,0,0,0};
int a9[9] = {0,0,0,0,0,0,0,0,0};
int aVal = 0;
bool carry = false;
bool test = false;
int binary1N = 0;
int binary2N = 0;
int tempAdd = 0;
int contrast = 1;
//int binaryANS[9] = {0,0,0,0,0,0,0,0,0};

//  -----   Functions   -----   //

void setup() {                                      //   Setup Function
  Serial.begin(9600);
  //contrast being set
  pinMode(6, OUTPUT);  
  analogWrite(6, contrast);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  lcd.begin(16, 2);
  lcd.println(boot0);
  delay(250);
  lcd.clear();
  lcd.println(boot1);
  delay(250);
  lcd.clear();
  lcd.println(boot2);
  delay(250);
  lcd.clear();
  lcd.println(boot3);
  delay(250);
  lcd.clear();
  delay(250);
}                   // Good

void loop() {                                       //   Loop Function
  controller();
}                    // Good

void counter(){
  //Button 1
      switchState1 = digitalRead(2);
      //Button 2
      switchState2 = digitalRead(3);
      //Button 3
      switchStateTest = digitalRead(4);
    
      //counts button 1 "presses"
      if(switchState1 == HIGH){
        buttonHold_1++;
      }
      //counts button 2 "presses"
      if(switchState2 == HIGH){
        buttonHold_2++;
      }

      buttons();
}                  // Good

void controller(){                                  //   Controller Function
  bool cont = true;
  while(cont == true){
    
      if(stat == 1){                              //   stat 1 is the Splash screen
        lcd.setCursor(0, 0);
        lcd.print(splash1);
        lcd.setCursor(0, 1);
        lcd.print(splash2);
        delay(5);
        counter();
      }
      
      else if(stat == 2){                        //   stat 2 is the binaryOne screeen
        //binaryOne screen
        lcd.setCursor(0, 0);
        lcd.print("1st byte: ");
        lcd.setCursor(0, 1);
        for (int i=0; i<8; i++){                    //   For loop that controls 1 to 0 to 1 action
          if(binaryOne[i]%2 == 0){
            //print 0
            lcd.print("0");
          }else{
            //print 1
            lcd.print("1");
          }
        }
        lcd.setCursor(currentBit, 1);
        lcd.blink();
        delay(150);
        counter();
        //buttons();
      }
      
      else if(stat == 3){                        //   stat 3 is the binaryTwo screen
        //binaryTwo screen
        lcd.setCursor(0, 0);
        lcd.print("2nd byte: ");
        lcd.setCursor(0, 1);
        for (int i=0; i<8; i++){                    //   For loop that controls 1 to 0 to 1 action
          if(binaryTwo[i]%2 == 0){
            //print 0
            lcd.print("0");
          }else{
            //print 1
            lcd.print("1");
          }
        }
        lcd.setCursor(currentBit, 1);
        lcd.blink();
        delay(150);
        counter();
        //buttons();
      }
      
      else if(stat == 4){                        //   stat 4 is the binaryResults page
        calc();
        lcd.clear();
        delay(1000);
        lcd.setCursor(0, 0);
        lcd.print("A: ");
        lcd.print(binary1N);
        lcd.print("+");
        lcd.print(binary2N);
        lcd.print("=");
        lcd.print(tempAdd);
          
        lcd.setCursor(0, 1);
        if(aVal==1){
            for(int i=0;i<1;i++){
                lcd.print(a1[i]);
                Serial.println(a1[i]);
            }
        }
          if(aVal==2){
            for(int i=0;i<2;i++){
                lcd.print(a2[i]);
                Serial.println(a2[i]);
            }
        }
          if(aVal==3){
            for(int i=0;i<3;i++){
                lcd.print(a3[i]);
                Serial.println(a3[i]);
            }
        }
          if(aVal==4){
            for(int i=0;i<4;i++){
                lcd.print(a4[i]);
                Serial.println(a4[i]);
            }
        }
          if(aVal==5){
            for(int i=0;i<5;i++){
                lcd.print(a5[i]);
                Serial.println(a5[i]);
            }
        }
          if(aVal==6){
            for(int i=0;i<6;i++){
                lcd.print(a6[i]);
                Serial.println(a6[i]);
            }
        }
          if(aVal==7){
            for(int i=0;i<7;i++){
                lcd.print(a7[i]);
                Serial.println(a7[i]);
            }
        }
          if(aVal==8){
            for(int i=0;i<8;i++){
                lcd.print(a8[i]);
                Serial.println(a8[i]);
            }
        }if(aVal==9){
            for(int i=0;i<9;i++){
                lcd.print(a9[i]);
                Serial.println(a9[i]);
            }
        }
        counter();
      }
      
      else if(stat == 5){                        //   stat 5 is the contrast settings page
          lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set Contrast: ");
        lcd.setCursor(0, 1);
        lcd.print(contrast);
          Serial.print("Controller contrast: ");
              Serial.println(contrast);
          delay(150);
        counter();
      }

      else{
        //
      }
  }
}               // Somethings commented

void buttons() {                                    //   Buttons Function
  //
  //
  if(buttonHold_1 > 10 && buttonHold_2 > 10){       //   Button 1 & 2 Pressed   
      buttonHold_1 = 1;
      buttonHold_2 = 1;
    if(stat == 4){
      lcd.clear();
      lcd.setCursor(0, 0);
//      lcd.print("1 P! - ");
//      lcd.print(buttonHold_1);
      lcd.setCursor(0, 1);
//      lcd.print("2 P! - ");
//      lcd.print(buttonHold_2);
      delay(250);
      lcd.clear();
      stat = 5;
        contrastSettings();
//      controller();
    }
    
    if(stat == 1){
      lcd.clear();
      lcd.setCursor(0, 0);
//      lcd.print("B1 - ");
//      lcd.print(buttonHold_1);
      lcd.setCursor(0, 1);
//      lcd.print("B2 - ");
//      lcd.print(buttonHold_2);
      delay(250);
      lcd.clear();
      buttonHold_1 = 1;
      buttonHold_2 = 1;
      start();
    }
  }
  
  else if(buttonHold_1 > 30){                      //   Button 1 Pressed   ( 1 or 0 )
//    lcd.clear();
//    lcd.setCursor(0, 1);
//    lcd.print("  Button 1: ");
//    lcd.print(buttonHold_1);
    delay(250);
//    lcd.clear();
    buttonHold_1 = 1;
    if(stat == 2){
      binaryOne[currentBit]++;                      // Adds 1 to the current binary!!!ONE!!! bit
//      lcd.print("binaryOne[");
//      lcd.print(currentBit);
//      lcd.print("]=");
//      lcd.print(binaryOne[currentBit]);
    }
    if(stat == 3){
      binaryTwo[currentBit]++;                      // Adds 1 to the current binary!!!TWO!!! bit
//      lcd.print("binaryTwo[");
//      lcd.print(currentBit);
//      lcd.print("]=");
//      lcd.print(binaryTwo[currentBit]);
    }
    if(stat == 4){
        //
    }
    if(stat == 5){
        contrast=contrast+24;
        Serial.println(contrast);
        analogWrite(6, contrast);
//      if(contrast < 1023){
//       contrast=+1;
//      }else{
//        lcd.clear();
//        lcd.print("Max contrast!");
//        delay(1000);                      // Adds 1 to the contrast
//      }
    }
    delay(250);
  }
  
  else if(buttonHold_2 > 30){                      //   Button 2 Pressed   ( next bit )
    lcd.clear();
    buttonHold_2 = 1;
    if(stat == 2){
        if(currentBit == 7){
          currentBit = 0;
          stat = 3;
        }else{
          currentBit++;                                   // Adds 1 to the currentBit to move
        }
    }else if(stat == 3){
        if(currentBit == 7){
          currentBit = 0;
          stat = 4;
        }else{
          currentBit++;                                   // Adds 1 to the currentBit to move
        }
    }else if(stat == 4){
        //
    }else if(stat == 5){
        contrast=contrast-24;
        Serial.println(contrast);
        analogWrite(6, contrast);
//      if(contrast == 1){
//        lcd.clear();
//        lcd.print("Min contrast!");
//        delay(1000);
//      }else{
//        contrast=contrast-1;                      // Subs 1 from the contrast
//      }
    }
  }else{
    counter();
  }
}                 // Alerts commented

void start(){
  stat = 2;
  Serial.print(stat);
  bool binOne = true;
  while(binOne == true){
     switchState1 = digitalRead(2);
      //Button 2
      switchState2 = digitalRead(3);
      //Button 3
      switchStateTest = digitalRead(4);
    controller();
  }
  lcd.clear();
  //controller();
  stat = 3;
  Serial.print(stat);
  bool binTwo = true;
  while(binTwo == true){
    switchState1 = digitalRead(2);
      //Button 2
      switchState2 = digitalRead(3);
      //Button 3
      switchStateTest = digitalRead(4);
    controller();
  }
  lcd.clear();
  //binaryResults();
}                    // Good

void binaryResults(){
  stat = 4;
  Serial.print(stat);
  bool bin = true;
  while(bin == true){
    switchState1 = digitalRead(2);
      //Button 2
      switchState2 = digitalRead(3);
      //Button 3
      switchStateTest = digitalRead(4);
    controller();
    if(switchStateTest == HIGH){
      bin = false;
    }
  }
  lcd.clear();
}            // Good

void contrastSettings(){
    Serial.println("ContrastSetting() reached");
  stat = 5;
  Serial.print(stat);
  bool bin = true;
  while(bin == true){
    switchState1 = digitalRead(2);
      //Button 2
      switchState2 = digitalRead(3);
      //Button 3
      switchStateTest = digitalRead(4);
    controller();
  }
    lcd.clear();
}         // Good

void calc(){
    //1st byte conversion
    int binary1Temp=0;
    int binary2Temp=0;
    for (int i=0; i<8; i++){
          if(binaryOne[i]%2 == 0){
            binary1[i]=0;
          }else{
            binary1[i]=1;
          }
    }
    //2nd byte conversion
    for (int i=0; i<8; i++){
          if(binaryTwo[i]%2 == 0){
            binary2[i]=0;
          }else{
            binary2[i]=1;
          }
    }

    for (int i=0; i<8; i++){
      int binNum[8]={128,64,32,16,8,4,2,1};
      bool carry1 = false;
      if(binary1[i]==1){
        binary1N = binary1N+binNum[i];
      }
      if(binary2[i]==1){
        binary2N = binary2N+binNum[i];
      }
    }

    tempAdd = binary1N+binary2N;

      Serial.print("Binary Result = ");
      int n = tempAdd;
      num2Binary(n);

//      Serial.print(" ");
//      Serial.print(" ");
//      Serial.print(" ");
}                     // Lots commented

int num2Binary(int n){
    int binaryArr[9]={0,0,0,0,0,0,0,0,0};
    int i = 0;
    while (n > 0) {
        binaryArr[i] = n % 2;
        n = n / 2;
        i++;
    }
    //Serial.print(i);
    int count = 0;
    // printing binary array in reverse order
    if(i==1){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a1[count] = binaryArr[j];
            count++;
        }
        aVal = 1;
    }
    if(i==2){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a2[count] = binaryArr[j];
            count++;
        }
        aVal = 2;
    }
    if(i==3){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a3[count] = binaryArr[j];
            count++;
        }
        aVal = 3;
    }
    if(i==4){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a4[count] = binaryArr[j];
            count++;
        }
        aVal = 4;
    }
    if(i==5){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a5[count] = binaryArr[j];
            count++;
        }
        aVal = 5;
    }
    if(i==6){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a6[count] = binaryArr[j];
            count++;
        }
        aVal = 6;
    }
    if(i==7){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a7[count] = binaryArr[j];
            count++;
        }
        aVal = 7;
    }
    if(i==8){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a8[count] = binaryArr[j];
            count++;
        }
        aVal = 8;
    }
    if(i==9){
        for (int j = i - 1; j >= 0; j--){
            Serial.print(binaryArr[j]);
            a9[count] = binaryArr[j];
            count++;
        }
        aVal = 9;
    }
    
}           // Good











































































//Roman Bond