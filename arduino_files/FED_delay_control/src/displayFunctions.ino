void displayExperimentInfo() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(2);
  char experimentalInfo[80];
  unsigned long epoch = rtc.getEpoch();
  sprintf(experimentalInfo,
  "Animal: %02d\n\Cond: %s\nTime: %02d:%02d:%02d\nPellets: %02d\nBoops: %02d\nBattery: %d\nRandomFeed: %d",
  config.animal,
  config.protocol,
  hour(epoch),
  minute(epoch),
  second(epoch),
  pelletCount,
  boopCount,
  batt,
  config.randomFeed
  );
  display.println(experimentalInfo);

  display.refresh();
  blockDisplay = true;
}

void displaySDSuccess() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("SD successful");

  display.refresh();
}

void displaySDError() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("SD error");

  display.refresh();
}

void displayLogfileSize() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("Logfile size: ");
  display.println(logfile.size());

  display.refresh();
}

void displayFeed() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("Feeding...");

  display.refresh();
}

void displaySetPellets() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("Fixing up pellet position...");

  display.refresh();
}

void displayFeedCounter() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("counter-feed...");

  display.refresh();
}

void displayDelay(int count) {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(40, 50);
  display.setTextSize(4);
  char msg[30];
  sprintf(msg,"Delay: %02d", count);
  display.println(msg);

  display.refresh();
}

void displayInt(int result) {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(40, 50);
  display.setTextSize(4);
  char msg[50];
  sprintf(msg,"%02d", result);
  display.println(msg);

  display.refresh();
}

void displayDeliveryBlock() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(40, 50);
  display.setTextSize(4);
  display.println("Delivery Block");

  display.refresh();
}

void displayJam() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(40, 50);
  display.setTextSize(4);
  display.println("Clearing Jam");

  display.refresh();
}

void displayMotorTurns() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);
  display.setCursor(0, 10);
  display.setTextSize(3);
  display.println("Motor turns: ");
  display.println(motorTurns);
  display.refresh();
}

void displayBoop(int count) {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);

  display.setCursor(40, 50);
  display.setTextSize(4);
  char msg[30];
  sprintf(msg,"Boop: %02d", count);
  display.println(msg);

  display.refresh();
}
