void spin(){
  if (!pellet){
    for (int i = 0; i < 41 + random(0, 50); i++){
      myMotor->step(i, FORWARD, DOUBLE);
      queryPI();
      if (pellet){
        break; // if pellet was delivered after clearJam exit loop
      }
    }
  }
  myMotor->release();
  numClears++;
  delay(500);
}

void setPellets() {
  if (!pellet && !pelletJam) {
    displaySetPellets();
    for (int i = 0; i < 40 + random(0, 10); i++) {
        queryPI();
	delay(250);
      if (!pellet) {
        myMotor->step(100, BACKWARD, DOUBLE);
        myMotor->step(100, FORWARD, DOUBLE);
      }
    }
    myMotor->release();
  }
}


void feed() {
  if (!pellet && !pelletJam) {
    displayFeed();
    for (int i = 0; i < 20 + random(0, 10); i++) {
        queryPI();
	delay(10);
      if (!pellet) {
        myMotor->step(7, BACKWARD, DOUBLE);
        myMotor->step(14, FORWARD, DOUBLE);
	delay(50);
      }
    }
    myMotor->release();
  }
  motorTurns++;

  if (motorTurns > turnsBeforeClear){
    pelletJam = true;
    motorTurns = 0;
  }
  else{
  	pelletJam = false;
	}

  if (motorTurns > 10){
    doSpin = true;
  }
  else{
    doSpin = false;
  }
}

void clearJam(){
// clear jam is now spinning in the reverse direction
// to avoid jams
// if fails 5 attempts to deliver pellet it makes a spin
  if (!pellet){
    displayFeedCounter();
    for (int i = 0; i < 20 + random(0, 10); i++) {
        queryPI();
	delay(10);
      if (!pellet) {
        myMotor->step(7, FORWARD, DOUBLE);
        myMotor->step(14, BACKWARD, DOUBLE);
	delay(50);
      }
    }
  }
  myMotor->release();
  numClears++;
  pelletJam = false;
  delay(500);
}
