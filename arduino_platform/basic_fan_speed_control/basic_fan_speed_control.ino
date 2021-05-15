#define FAN_PIN   11 

// Function to set and covert the duty cycle from 0-100% to 0-255
void setDutyCycle(int pin, int dutyCycle) {
  int newDutyCycle = dutyCycle*2.55;
  analogWrite(pin, newDutyCycle);
}

// Ramp function to ramp up/down the speed of the fan
// INPUT: rampSpeed - the total amount of time it takes to ramp up/down to the maxDutyCycle
void rampFanSpeed(int pin, int minDutyCycle, int maxDutyCycle, int rampSpeed) {
  if(maxDutyCycle < minDutyCycle) {
    for(int i = minDutyCycle; i >= maxDutyCycle; i--) {
        setDutyCycle(pin, i);
        delay(rampSpeed/100);
    }
  } else {
    for(int i = minDutyCycle; i <= maxDutyCycle; i++) {
        setDutyCycle(pin, i);
        delay(rampSpeed/100);
    }
  }
  
}

void setup() {
  // put your setup code here, to run once:
  TCCR2B = TCCR2B & B11111000 | B00000001; // to set the PWM frequency of 31372.55 Hz
  Serial.begin(9600);
  rampFanSpeed(FAN_PIN, 0, 100, 20000); // Go from 0 to 100 % duty cycle in approx. 20 seconds
  rampFanSpeed(FAN_PIN, 100, 0, 500); // Ramp back down from 100 % to 0 duty cycle in approx. 500 ms
}


void loop() {
  // put your main code here, to run repeatedly:
  
}
