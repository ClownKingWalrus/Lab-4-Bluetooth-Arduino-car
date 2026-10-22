#include <SoftwareSerial.h>

//oled includes
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//oled const
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C //the address we are writing to

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// RX, TX pin definitions for Bluetooth
SoftwareSerial BTSerial(12, 11); 

def LeftTriangle() {
  display.ClearDisplay();
  display.fillTriangle(110, 15, 110, 49, 75, 32, WHITE);
  display.display();
}

def RightTriangle() {
  display.ClearDisplay();
  display.fillTriangle(75, 15, 75, 49, 110, 32, WHITE);
  display.display();
}

def carHazards() {
  for (int i = 0; i < 4; i++){
    RightTriangle();
    LeftTriangle();
    sleep(0.5);
  }
}

void setup() {
  // Start the standard serial monitor
  Serial.begin(9600);
  
  // Start the bluetooth serial port
  BTSerial.begin(9600);
  Serial.println("Ready to receive data from phone...");

  //oled setup
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
     Serial.println(F("SSD1306 allocation failed"));
     sleep(5);
     return;
  }
  // Clear the buffer.
  display.clearDisplay();

 // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 28);
  display.println("Hello world!");
  sleep(5);
  display.clearDisplay();
}

void loop() {
  // Check if data is available from the phone via Bluetooth
  // if (BTSerial.available() > 0) {
  //   char incomingChar = BTSerial.read();
  //   // Print the data out to the Arduino Serial Monitor
  //   Serial.print(incomingChar);
  // }

  RightTriangle();
  sleep(3);

}