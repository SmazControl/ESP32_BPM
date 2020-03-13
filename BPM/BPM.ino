//  Variables

int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0

int LED21 = 21;   //  The on-board Arduion LED

int Signal;                // holds the incoming raw data. Signal value can range from 0-1024

int Threshold = 3450;            // Determine which Signal to “count as a beat”, and which to ingore.

unsigned long Time_Count;

int Beat_Count;

// The SetUp Function:

void setup() {

  pinMode(21,OUTPUT);         // pin that will blink to your heartbeat!

  Serial.begin(9600);         // Set’s up Serial Communication at certain speed.

  Time_Count = millis();

  Beat_Count = 0;
}

// The Main Loop Function

void loop() {

  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor’s value.

  // Assign this value to the “Signal” variable.

  Serial.println(Signal);                    // Send the Signal value to Serial Plotter.

  if(Signal > Threshold){                          // If the signal is above “550”, then “turn-on” Arduino’s on-Board LED.

    digitalWrite(21,HIGH);

    Beat_Count++;

    if (Time_Count+60000<millis()) {

      Serial.println("BPM ="+String(Beat_Count));

      Beat_Count = 0;
      
      Time_Count = millis();  

    }

  } else {

    digitalWrite(21,LOW);                //  Else, the sigal must be below “550”, so “turn-off” this LED.

  }

  delay(10);

}
