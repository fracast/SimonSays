//SIMON-SAY-STYLE GAME Step 2, YURY G. OCT 2012
//This code adds the feature of Simon Saying Something, With Time/Speed Game Mechanic, LEDs, and Sound.
//PINS ARE NOW DECLARED 

//Button Pins

#include "pitches.h"
  
 int CThree = NOTE_C6;
 int CFour = NOTE_D6;
 int CFive = NOTE_E6;
 int CSix = NOTE_F6;

int greenButt = 4; //  declare pins for buttons
int yellButt = 5;
int redButt = 6;
int blueButt = 7;


//LED Pins

int greenLED = 9; //  declare pins for LED's
int yellLED = 10;
int redLED = 11;
int blueLED = 12;



// Color Code we Use for R,Y,B,G and 1,2,3,4 repectfully
int redValue = 1;  //  declare values for colors for buttons
int yellValue = 2;
int blueValue = 3;
int greenValue = 4;

int speakerPin = 8 ;  //declare your speaker pin

int userSays = 0;  //value to hold User Input
int userStep = 0;   //  user step counter


boolean simonDone;
int simonSays[99] ={};       
int nextStep = 0 ;   

int simonSpeed = 200;


void setup()
{
   Serial.begin(9600);
  pinMode(redLED, OUTPUT);   //Set Pin Mode
  pinMode(yellLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(speakerPin, OUTPUT);    // set speaker to output
  
  
  pinMode(redButt, INPUT_PULLUP);  //set pull-up resistors on Buttons, So closing the switch will bring Pin to Ground. 
  pinMode (yellButt,INPUT_PULLUP);
  pinMode (blueButt,INPUT_PULLUP);
  pinMode (greenButt,INPUT_PULLUP);
  
 
  randomSeed(analogRead(0));  
  restartSeq();
  
}

void loop ()
{


  if (simonDone == false)    
  {
    simonSays[nextStep] = random(1,5) ;

    Serial.print("nextStep: " );    
    Serial.println(nextStep);
    Serial.print("simonSays: ");

    for (int i =0; i <= nextStep ; i++)  
    {
      Serial.print(simonSays[i]);      
      Serial.print(" , ");
      delay(simonSpeed);      // controls speed that simonSays something  
      
      playToneAndLight(simonSays[i]);   
 
  }
    
    simonSpeed= (simonSpeed - (nextStep*5));  //  This seeds up Simon on each turn by forumla (500-(nextStep*5). 
                                            //  Change the multiplier (5 in this case) to make game faster or slower 
                                            //  The multiplier is MAJOR factor in how hard the game is. 
                                           //   This sets Simon's TOP SPEED. Also important in making game interesting yet winable.                                         
    simonSpeed = max(simonSpeed, 200);   //this maxes out simon speed at 200 ms
    simonDone = true; 
    
    Serial.print("simonSpeed: " );    // Show how the new time feature works
    Serial.println(simonSpeed);         // Show how the new time feature works  
    Serial.println(" "); 
    
    nextStep++;    //  add one more step to simon's sequence 
    userStep = 0;  // make the user step from the first step
    
  }


  if (simonDone == true)  
  {
     // listen for user input
  
    
    if (userStep < nextStep) 
      {
   
            if(digitalRead(redButt) == LOW)  //redButt was pressed
               {   
                       userSays = redValue;
                               if(userSays == simonSays[userStep])
                                     {
                                         playToneAndLight(redValue);
                                         userStep++;                

                                     }
                               else
                                 {
                                 playToneAndLight(redValue);
                                 youLose();
                                 }
                               
                                     
               }
           
           if(digitalRead(yellButt) == LOW)
               {  
                            
                       userSays = yellValue;
                               if(userSays == simonSays[userStep])
                                     {
                                         playToneAndLight(yellValue);
                                         userStep++;
                                     }
                                     
                                else
                                 {
                                 playToneAndLight(yellValue);
                                 youLose();
                                 }
               }
        
     
           if(digitalRead(blueButt) == LOW)
               {  
                            
                       userSays = blueValue;
                               if(userSays == simonSays[userStep])
                                     {
                                         playToneAndLight(blueValue);
                                         userStep++;
                                     }
                                else
                                 {
                                 playToneAndLight(blueValue);
                                 youLose();
                                 }
               }
     
     
           if(digitalRead(greenButt) == LOW)
               {  
                            
                       userSays = greenValue;
                               if(userSays == simonSays[userStep])
                                     {
                                         playToneAndLight(greenValue);
                                         userStep++;
                                     }
                               else
                                 {
                                 playToneAndLight(greenValue);
                                 youLose();
                                 }
               }
     
      
          
      }
       
       
     if (userStep >= nextStep)
          {
            simonDone = false;  // user completed successfully, give simon the next turn
            correctSound() ;  
          }
   
  }
}





