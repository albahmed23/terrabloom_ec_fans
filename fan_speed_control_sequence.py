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
            # Spin fan at 20% duty cycle for 4 seconds
            setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, 20)
            time.sleep(4)
            # Spin fan at 50% duty cycle for 2 seconds
            setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, 50)
            time.sleep(2)
            # Sping fan at 100% duty cycle for 2 seconds
            setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, 100)
            time.sleep(8)
        except(KeyboardInterrupt):
            # When a Ctrl-C is detected on the keyboard, the program will turn off the motor and exit
            print('Turning OFF motor')
            setPWMDutyCycle(pi, PWM_FREQ, PWM_PIN_OUT, 0)
            exit()
    
    