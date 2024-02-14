void writeData(){
  if (logfile.size() == 0){
    displayLogfileSize();
    logfile.println("time,animal,pellets,motorTurns,battery,delay,protocol");
    delay(1000);
  }
  sprintf(data, "%02d,%02d,%02d,%02d,%02d,%02d,%s", rtc.getEpoch(),
  config.animal, pelletCount, blockCode, batt, fedDelay, config.protocol);
  Serial.println(data);
  logfile.println(data);
  logfile.flush();
  dataLog = true;
}
