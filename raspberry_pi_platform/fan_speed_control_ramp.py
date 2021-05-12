# Control a TerraBloom's EC fan using Hardware percise PWM

# Import the pigpio library
import pigpio
import time

# PWM GPIO Pin Number (connect TerraBloom's BLUE wire to this GPIO#12)
PWM_PIN_OUT = 12

# Set PWM frequency in Hz (10 kHz is good to start)
PWM_FREQ = 10000

# Function to change the PWM Duty Cycle
def setPWMDutyCycle(pi_instance, PWM_FREQ_VALUE, GPIO_NUM, DutyCycle):
    correctedDutyCycle = DutyCycle*10000 # pigpio lib requires Duty Cycle to be in Mega
    pi_instance.hardware_PWM(PWM_PIN_OUT, PWM_FREQ_VALUE, correctedDutyCycle)
    print('PWM Duty Cycle Set to = ', DutyCycle)

# Main Start
if __name__ == "__main__":
    # You need only one instance of pigpio
    pi = pigpio.pi()
    
    print('Start of Control Sequence')
    # Let us change speed sequentially
    while True:
        try:
            # Ramp up the fan speed 5% duty cycle every one second
            for dutyCycleValue in range(0, 105, 5):
                setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, dutyCycleValue)
                time.sleep(1) # You can change this time delay to speed up or slow down your ramping
                print(dutyCycleValue)
                
            time.sleep(8)
            
            # Slow down until complete stop
            for dutyCycleValue in range(100, -5, -5):
                setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, dutyCycleValue)
                time.sleep(1) # You can change this time delay to speed up or slow down your ramping
                print(dutyCycleValue)
                
            # Repeat these ramping every 5 seconds
            time.sleep(5)
            
        except(KeyboardInterrupt):
            # When a Ctrl-C is detected on the keyboard, the program will turn off the motor and exit
            print('Turning OFF motor')
            setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, 0)
            exit()
    
    