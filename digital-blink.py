import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
led = 26
GPIO.setup(led, GPIO.OUT)
state = 0
period = 0.5
while True:
    GPIO.output(led, state)
    time.sleep(period)
    state = not state

