#define relayPin 8
String command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("on")) {
      digitalWrite(relayPin, HIGH);
    }
    else if (command.equals("off")) {
      digitalWrite(relayPin, LOW);
    }
  }
}
