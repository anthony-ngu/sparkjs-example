String pin0 = "D0";
String pin1 = "D1";
String pin2 = "D2";
String pin3 = "D3";
String pin4 = "D4";
String pin5 = "D5";
String pin6 = "D6";
String pin7 = "D7";
int led = -1;
bool blinky_switch = false;
// This routine runs only once upon reset
void setup() {
  Spark.function("blinky", blinky);
}

// This routine gets called repeatedly, like once every 5-15 milliseconds.
// Spark firmware interleaves background CPU activity associated with WiFi + Cloud activity with your code. 
// Make sure none of your code delays or blocks for too long (like more than 5 seconds), or weird things can happen.
void loop() {
    if(blinky_switch)
    {
        digitalWrite(led, HIGH);
        delay(1000);               // Wait for 1000mS = 1 second
        digitalWrite(led, LOW);
        delay(1000);               // Wait for 1 second in off mode   
    }
}

int blinky(String command)
{
    if(command == pin0)
        led = D0;
    else if(command == pin1)
        led = D1;
    else if(command == pin2)
        led = D2;
    else if(command == pin3)
        led = D3;
    else if(command == pin4)
        led = D4;
    else if(command == pin5)
        led = D5;
    else if(command == pin6)
        led = D6;
    else if(command == pin7)
        led = D7;
    else
        return -1;
    
    pinMode(led, OUTPUT);
    
    blinky_switch = !blinky_switch;
}