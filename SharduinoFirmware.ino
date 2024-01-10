/**
 * Constants
 */
const int DEFAULT_BLINK_DELAY = 1000; // Default blink duration in milliseconds
const char* UNIQUE_ID = "Arduino01"; // Unique identification for this Arduino

void setup() {
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    // Check if there is data available on the serial port
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n');
        int delimiterIndex = input.indexOf(':');
        String command = input.substring(0, delimiterIndex);
        String parameters = input.substring(delimiterIndex + 1);

        // Execute actions based on the received command
        if (command == "identify") {
            identify();
        } else {
            int pin, time;
            parseParameters(parameters, pin, time);

            if (command == "blink") {
                blink(pin, time);
            } else if (command == "on") {
                digitalWrite(pin, HIGH);
                delay(time);
                digitalWrite(pin, LOW); // Change to opposite state after specified time
            } else if (command == "off") {
                digitalWrite(pin, LOW);
                delay(time);
                digitalWrite(pin, HIGH); // Change to opposite state after specified time
            }
        }
    }
}

// Function to identify the Arduino
void identify() {
    Serial.println(UNIQUE_ID);
}

// Function to blink a pin
void blink(int pin, int time) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(time > 0 ? time : DEFAULT_BLINK_DELAY);
    digitalWrite(pin, LOW);
}

// Function to parse command parameters
void parseParameters(String params, int &pin, int &time) {
    int commaIndex = params.indexOf(',');
    pin = params.substring(0, commaIndex).toInt();
    time = params.substring(commaIndex + 1).toInt();
}
