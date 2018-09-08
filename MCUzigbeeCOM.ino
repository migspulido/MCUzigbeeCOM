//Miguel Pulido - Systems Architect
//Micro Controller Unit (MCU) Zigbee/XBEE Communication Application

int myData = 0; 	// declare variable
int const ledpin = 13;	// declare an ledpin
void setup(){
// Start up our serial port, we configured our XBEE devices for 9600 bps.
   Serial.begin(9600);  // set baud rate
   pinMode(ledpin, OUTPUT); // declare LED Pin 13 to be an output….
}
void loop(){
    if(Serial.available() > 0){ 	// This looks at serial code and compares against 0 - nothing
        myData = Serial.read();	        // If greater than 0, it goes into a serial read of myData
        if(myData == '1'){		// it will read myData and if it is 1, do the next lines
        digitalWrite(ledpin, HIGH);	// any time myData is equal to 1, it will light LED HIGH and turn it on
        Serial.write(myData);	        // anytime myData is equal to 1, it will type out my serial data "Serial.print(myData,BYTE); no longer supported
        }
        if(myData == '2'){		// this will check for absolute value of 2
        digitalWrite(ledpin, LOW);	// sets LED pin to LOW or turns it off
        Serial.write(myData);	        // anytime myData is equal to 1, it will type out my serial data "Serial.print(myData,BYTE); no longer supported
    }
    else{
    Serial.write(myData);		// if any other character data comes through, all it will do is type the data coming through.
    }
}
}

