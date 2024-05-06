void createHeaders(){
  // if logfile is empty write headers
  if (logfile.size() == 0){
    displayLogfileSize();
    logfile.println("time,animal,pellets,boops,motorTurns,battery,delay,protocol");
    delay(1000);
  }
  logfile.flush();
}
