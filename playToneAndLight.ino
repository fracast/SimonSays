

  void playToneAndLight(int color)
  

  
    {
      
      Serial.print("inside PlayToneAndLight ");
      Serial.print("   color = ");
      Serial.println( color );
      
      
      
      if(color == 1)   // 1 = Red
        {
          digitalWrite( redLED,HIGH);
          tone(speakerPin,CThree);
          delay(simonSpeed);    
          digitalWrite( redLED,LOW);
          noTone(speakerPin);        
        }
        
      if(color == 2)
        {
          digitalWrite( yellLED,HIGH);
          tone(speakerPin,CFour);
          delay(simonSpeed);    
          digitalWrite( yellLED,LOW);
          noTone(speakerPin);        
        }
      
      if(color == 3)
        {
          digitalWrite( blueLED,HIGH);
          tone(speakerPin,CFive);
          delay(simonSpeed);    
          digitalWrite( blueLED,LOW);
          noTone(speakerPin);        
        }
      
      if(color == 4)
        {
          digitalWrite( greenLED,HIGH);
          tone(speakerPin,CSix);
          delay(simonSpeed);    
          digitalWrite( greenLED,LOW);
          noTone(speakerPin);        
        }  
    }
