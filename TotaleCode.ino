int IRSensor = 2;
int IRSensor2 = 4;

// Motor A connections
int enA = 9;
int in1 = 12;
int in2 = 6;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 8;
const int trigPin = 10; //10
const int echoPin = 11; //11
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Init Serial at 115200 Baud Rate.

  Serial.println("Serial Working"); // Test to check if serial is working or not

  pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
  pinMode(IRSensor2, INPUT); // IR Sensor pin INPUT

  	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void loop() {
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  int sensorStatus2 = digitalRead(IRSensor2); // Set the GPIO as Input
  if ((sensorStatus == 0) && (sensorStatus2 == 0)) // Check if the pin high or not
  {
    Serial.println("Both white / go straight"); // print Motion Detected! on the serial monitor window
    straight();
  }
  else if ((sensorStatus == 1) && (sensorStatus2 == 0))  {
    Serial.println("Left: black / Right: white / Turn"); // print Motion Ended! on the serial monitor window
    turnRight();
  }
  else if ((sensorStatus == 0) && (sensorStatus2 == 1)){
    Serial.println("Left: white / Right: black / Turn"); // print Motion Ended! on the serial monitor window
    turnLeft();
  }
  else {
    Serial.println("Stop"); // print Motion Ended! on the serial monitor window
    stop();
  }
}

void straight(){
  	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 65);
	analogWrite(enB, 65);
  	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void turnLeft(){
  	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 65);
	analogWrite(enB, 65);
  	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void stop(){
  	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 65);
	analogWrite(enB, 65);
  	// Turn on motor A & B
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void turnRight(){
  	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 65);
	analogWrite(enB, 65);
  	// Turn on motor A & B
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

// This function lets you control spinning direction of motors
void directionControl() {
	// Set motors to maximum speed
	// For PWM maximum possible values are 0 to 255
	analogWrite(enA, 65);
	analogWrite(enB, 65);

	// Turn on motor A & B
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
	delay(2000);
	
	// Now change motor directions
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	delay(2000);
	
	// Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
		analogWrite(enB, i);
		delay(20);
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
