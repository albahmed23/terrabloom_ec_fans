# Arduino Platform
This subfolder will contain the sample codes and projects for the ARDUINO platform.

## basic_fan_speed_control
This code demonstrates the use of a simple analogWrite function to produce a PWM signal that controls the speed of a TerraBloom EC fan. Please be sure to use a Level shifter circuit to shift the level from 0-5V from Arduino to 0-10V in order to control the TerraBloom EC fan.

I recommend that you use the `rampFanSpeed` function to ramp up the speed of the EC fan to the desired Duty Cycle.

