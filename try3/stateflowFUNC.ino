void checkWindup()
{
  if(vErrorTotal > (MAX_ERROR / loopTime))
  {
    vErrorTotal = 0.0;
    delay(5000);
  }  
}

state stateCheck()
{
  //Serial.println("checking state");

  // If pause switch is on  
  /*if (digitalRead(SW4) == LOW) 
    {
      myState = PAUSE;
      Serial.println("pause switch");
      return myState;
    }
  else
  {
    myState = PLAY;
  }*/
  //If Tx says to pause
  
  if (millis() - prevRecStateTime > recStatePeriod)
  {
  stateValue = pulseIn(REC_STATE, HIGH, 25000);
  //Serial.print(" State Value: ");
  //Serial.print(stateValue);
  if (stateValue > 1790 && stateValue < 2000 ) // channel is all the way high
    {myState = PAUSE;
    Serial.print(" stateValueTx: ");
    Serial.println(stateValue);
    return myState;}
    prevRecStateTime = millis();
  }
        
  // low Batt Warning
  
  if ( getBattVoltVal() < lowBattWarning && getBattVoltVal() > 1 )
  {
    if (millis() > 1000)
    {
      digitalWrite(16, HIGH);
      Serial.println("batt volts error");
      myState = PAUSE;
      return myState;
    }
  }
  else 
    { //digitalWrite(16, LOW);
      myState = PLAY;
     }
   
  //exceeding top speed 

  /*
  noInterrupts();
  wheelSpeed_1_Copy = wheelSpeed_1;
  interrupts();
    
  if (wheelSpeed_1_Copy > speedLimit )
    {myState = PAUSE;
    return myState;}

  */
/*
  myState = motorSaturationTimeout(vError);
  if (myState == PAUSE)
  {
    return myState;
  }
*/
  
  //Serial.println("reached bottom");
  //myState = PLAY;

    //Check for bluetooth message that might change state
    
  if(packetAvailable())
  {
    packetParse(); 
      if(BTStateValue == 1)
        myState = PLAY;
      else
      {
        myState = PAUSE;
        Serial.print(" BT Start Pause ");
      }
  }
  else
  {
      if(BTStateValue == 1)
        myState = PLAY;
      else
      {
        myState = PAUSE;
        Serial.print(" BT Continue Pause ");
      }
  }
  
  return myState;
}
