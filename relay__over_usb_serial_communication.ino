#define relayPin 8
String command;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
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
