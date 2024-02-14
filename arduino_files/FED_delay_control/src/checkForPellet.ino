void checkForPellet() {
  getFeedingDelay();
//  displayInt(blockCode);
//  delay(500);
  queryPI();
  if (pellet) {
    delay(500);
    delayLogic = true;
    boopCount = 0;
  }
  else {
    if (delayLogic == true) {
      for (int i = 0; i < fedDelay; i++) {
	      for (int k = 0; k < 100; k++){
			if(digitalRead(PELLET_WELL) == LOW){
				boopCount++;
				displayBoop(boopCount);
				delayLogic = false;
			}
			delay(10);
	      }
          	displayDelay( (fedDelay) - (i));
          	delayLogic = false;
      }
    }
  }
}
