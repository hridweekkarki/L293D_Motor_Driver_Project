const int button1 = 13, button2 = 6, motor_pin1 = 9, motor_pin2=10;
int button1State = 0, button2State = 0;

void Stop(){
  analogWrite(motor_pin2, 0);
  analogWrite(motor_pin1, 0);  
}

void counterclockwise(int Speed){
  analogWrite(motor_pin2, Speed);
  analogWrite(motor_pin1, 0);
  }

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(motor_pin1,OUTPUT);
pinMode(motor_pin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
button1State = digitalRead(button1);
button2State = digitalRead(button2);
Serial.println(button1State);
Serial.println(button2State);

if (button1State == HIGH && button2State == HIGH){
  Serial.println("COMMAND OVERLAP");
  delay(100);
}
else if (button1State == HIGH){
  Stop();
  delay(1000);
}
else if (button2State == HIGH){
  counterclockwise(100);
  delay(1000);
}
}
