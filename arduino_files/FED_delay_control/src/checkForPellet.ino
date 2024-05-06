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
      bool boop_off = true;
      for (int i = 0; i < fedDelay; i++) {
	      for (int k = 0; k < 100; k++){
			if(digitalRead(PELLET_WELL) == LOW && boop_off){
				boopCount++;
				displayBoop(boopCount);
				delayLogic = false;
				boop_off = false;
			}
			if(digitalRead(PELLET_WELL) == HIGH){
				boop_off = true;
			}
			delay(10);
	      }
          	displayDelay( (fedDelay) - (i));
          	delayLogic = false;
      }
    }
  }
}
