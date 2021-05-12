# Raspberry Pi Platform
Use this sample to quickly setup your Raspberry Pi and start controlling TerraBloom's EC fan's speed. Python code samples are given here and they are based on [pigpio](http://abyz.me.uk/rpi/pigpio/) library.

## fan_speed_control_ramp.py
This script will ramp up the speed of the fan based on the time delay between each increase of the PWM duty cycle.

## fan_speed_control_sequence.py
Control the fan speed sequentially, in other words, change the speed in steps rather than ramping.