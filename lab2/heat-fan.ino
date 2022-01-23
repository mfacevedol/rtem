// control fan and heater
// to measure temperature changes next to a resistor
int heaterPin = 10;
int fanPin =9;
// edit the following values in minutes as needed 
int fanTime=5;
int heatTime=5;
int repeatTime=5;

void setup(){
	pinMode(heaterPin, OUTPUT);
	pinMode(fanPin, OUTPUT);
	Serial.begin(9600);	
}

void wait_min(int duration_min){
  // messages and allow time to measure
  Serial.println("You can read several values of temperature"); 
  Serial.println("Try to take readings every 0.1C or at least every 0.5C"); 
  for(int i=1; i<=duration_min;i++){
   delay(60000);
   Serial.print(i);
   Serial.print(" min ");
  }
  Serial.println("");
}

void loop(){
  Serial.println("Started with heater off");
  digitalWrite(heaterPin,LOW);

	Serial.print("Now turning fan on for "); Serial.print(fanTime);
	Serial.println(" minutes");
  digitalWrite(fanPin,HIGH);
  wait_min(fanTime);
  
	Serial.println("Turned fan off");
	digitalWrite(fanPin,LOW);
		
  Serial.print("Now turning heat on for "); Serial.print(heatTime);
  Serial.println(" minutes");
  digitalWrite(heaterPin,HIGH);
  wait_min(heatTime);
		
	Serial.println("Turned the heater off");
  digitalWrite(heaterPin,LOW);
  
  Serial.print("The loop will repeat in "); Serial.print(repeatTime);
  Serial.println(" minutes");
	wait_min(repeatTime);
}
