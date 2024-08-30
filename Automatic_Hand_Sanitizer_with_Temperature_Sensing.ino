#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define PIR_PIN 2
#define SERVO_PIN 9
#define TEMP_THRESHOLD 37.5  // High temperature threshold (in Celsius)

// Create instances for sensors and modules
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Servo sanitizerServo;
SoftwareSerial gsm(7, 8); // RX, TX for GSM module

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  gsm.begin(9600);
  
  // Initialize the temperature sensor
  mlx.begin();
  
  // Initialize the PIR sensor pin
  pinMode(PIR_PIN, INPUT);
  
  // Attach the servo motor to the pin
  sanitizerServo.attach(SERVO_PIN);
  
  // Move the servo to the initial position
  sanitizerServo.write(0);
  
  Serial.println("Automatic Hand Sanitizer System Ready.");
}

void loop() {
  // Check if the PIR sensor detects a hand
  if (digitalRead(PIR_PIN) == HIGH) {
    Serial.println("Hand detected!");

    // Measure the temperature of the hand
    double temp = mlx.readObjectTempC();
    Serial.print("Measured Temperature: ");
    Serial.print(temp);
    Serial.println(" °C");
    
    if (temp > TEMP_THRESHOLD) {
      // If temperature is high, send an alert message
      sendAlertMessage(temp);
    }

    // Activate the sanitizer
    dispenseSanitizer();
    
    // Wait for a while before resetting
    delay(2000);
  }
}

void dispenseSanitizer() {
  // Rotate the servo to dispense sanitizer
  sanitizerServo.write(90);
  delay(1000);  // Keep the dispenser on for 1 second
  sanitizerServo.write(0);  // Return to the initial position
  Serial.println("Sanitizer dispensed.");
}

void sendAlertMessage(double temp) {
  gsm.print("AT+CMGF=1\r");  // Set SMS mode to text
  delay(1000);
  gsm.print("AT+CMGS=\"+1234567890\"\r");  // Replace with admin's phone number
  delay(1000);
  gsm.print("ALERT! High Temperature Detected: ");
  gsm.print(temp);
  gsm.print(" °C. Please check immediately.\r");
  delay(1000);
  gsm.write(26);  // ASCII code for CTRL+Z to send the message
  Serial.println("Alert message sent to admin.");
  delay(1000);
}
