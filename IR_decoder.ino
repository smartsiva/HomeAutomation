#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>


int IRpin = 12;

IRrecv irrecv(IRpin);

decode_results results;

void setup()

{ Serial.begin(9600);

irrecv.enableIRIn(); // Start the receiver

}

void loop()

{

if (irrecv.decode(&results))

{ Serial.println(results.value, DEC);

// Print the Serial 'results.value'

irrecv.resume(); // Receive the next value

}

}
