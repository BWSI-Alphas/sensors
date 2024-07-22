const int trigPin = 12;
const int echoPin = 13;

// threshold distance in centimeters
const int thresholdDistance = 60;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Triggering the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delay(1000);
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);

  // Reading the echo pulse
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculating distance in centimeters
  int distance = duration * 0.034 / 2;

  // Print distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if distance is less than threshold
  if (distance < thresholdDistance) {
    Serial.println("Object detected");
    
  }

  delay(1000); 
}