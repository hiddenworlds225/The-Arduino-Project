
int Round = 0;
int Avgchk = 5;
float Time = 0;
float Timetotal = 0;
float Averagetotal = 0;
int Timer = 0;
const int LED = 3;
const int Check = 2;
const int Button = 4;
const int RESET = 5;


void setup(){


  Serial.begin(9600);
  //Sets up pins
  pinMode(Button, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Check, INPUT);
  pinMode(RESET, INPUT);
  //Check LED
  Serial.println("Checking LED");
  digitalWrite(LED, HIGH);
  delay(1000);

  if (digitalRead(Check) == 1){
    Serial.println("Working");
  }
  else{
    Serial.println("Logic Error");

  }
  digitalWrite(LED, LOW); 
  //Check Button
  Serial.println("Waiting for button press");
  do{
  }
  while(digitalRead(Button) != 1);

  Serial.println("Setup Complete");

}


void loop(){
  //set round #
  Round = Round + 1;
  //Set for 1 - 10 secs
  Timer = (random(1, 11)*1000);
  Serial.println("Starting");
  delay(Timer);
  digitalWrite(LED, HIGH);
  do{ 
    Time=Time+1;
  }
  while(digitalRead(Button) != 1);
  //Some Minor Math
  Time = (Time / 1000);
  Timetotal = (Timetotal + Time);
  //Displays Stats
  Roundsum();
  Average();
  delay(3500);
  //Restarts loop noti
  Serial.println("Restarting");
  Time = 0;
  digitalWrite(LED, LOW);
  FLUSH();

  delay(2000);



}

//Summary of Round
void Roundsum() {
  Serial.print("Your reaction time was ");
  Serial.print(Time);
  Serial.print(" milliseconds in Round ");
  Serial.print(Round);
  Serial.println(".");

}
//Time Average
void Average(){
  if(Round == Avgchk){
    Serial.print("Your Average is ");
    Serial.print((Timetotal / Round));
    Serial.print(" in the last ");
    Serial.print(Round);
    Serial.println(" Round(s).");
    Avgchk = (Avgchk + 5);
  }
  else{
  }
}
//Resets all data 
void FLUSH(){
  if (digitalRead(RESET) == 1){
    Serial.println("DEVICE RESET DETECTED.");
    Round = 0;
    Avgchk = 5;
    Time = 0;
    Timetotal = 0;
    Averagetotal = 0;
    Timer = 0;

    setup();
  }
  else{

  }

}








