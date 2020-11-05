#include <IRremote.h>
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int relay_pin1 = 8;
int relay_pin2 = 9;
int relay_pin3 = 10;
int relay_pin4 = 11;
int recv_pin = 12;
int actual_state1 = LOW;
int actual_state2 = LOW;
int actual_state3 = LOW;
int actual_state4 = LOW;
int actual_state5 = LOW;
#define echoPin 7 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 6 //attach pin D3 Arduino to pin Trig of HC-SR04
IRrecv irrecv(recv_pin);
decode_results results;


void setup() {

    pinMode(relay_pin1, OUTPUT);
    pinMode(relay_pin2, OUTPUT);
    pinMode(relay_pin3, OUTPUT);
    pinMode(relay_pin4, OUTPUT); 
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    Serial.begin(9600);
    irrecv.enableIRIn(); 
}

void loop() {
    digitalWrite(trigPin, LOW);
    delay(500);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    if (distance >2 and distance < 20){
        actual_state3 = HIGH;
        digitalWrite(relay_pin3, actual_state3);
    }
    else if (distance >21 and distance < 40){
        actual_state3 = LOW;
        digitalWrite(relay_pin3, actual_state3);
    }
    if (irrecv.decode(&results)) {
        Serial.println(results.value, DEC);

        if (results.value == 16191727) { 
            actual_state1 = (actual_state1 == LOW) ? HIGH : LOW;
            digitalWrite(relay_pin1, actual_state1);
        }
        else if (results.value == 16208047) { 
            actual_state2 = (actual_state2 == LOW) ? HIGH : LOW;
            digitalWrite(relay_pin2, actual_state2);
        }
        else if (results.value == 16197847) { 
            actual_state3 = (actual_state3 == LOW) ? HIGH : LOW;
            digitalWrite(relay_pin3, actual_state3);
        }
                else if (results.value == 16214167) { 
            actual_state4 = (actual_state4 == LOW) ? HIGH : LOW;
            digitalWrite(relay_pin4, actual_state4);
        }
        irrecv.resume();
 
    }
}
