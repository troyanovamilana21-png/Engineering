import RPi.GPIO as GPIO

R2R = [22, 27, 17, 26, 25, 21, 20, 16]
GPIO.setmode(GPIO.BCM)
GPIO.setup(R2R, GPIO.OUT)

class R2R_DAC:
    def __init__(self, gpio_bits, dynamic_range, verbose = False):
        self.gpio_bits = gpio_bits
        self.dynamic_range = dynamic_range
        self.verbose = verbose
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.gpio_bits, GPIO.OUT, initial = 0)
def deinit(self):
    GPIO.output(self.gpio_bits, 0)
    GPIO.cleanup()
def number_to_dac(number):
    for i in range(DAC_BITS):
        bit = (number >> i) & 1
        GPIO.output(R2R[i], bit)
def voltage_to_number(voltage):
    if not (0.0 <= voltage <= DAC_VREF):
        print(f"Напряжение выходит за динамический диапазон ЦАП (0..{DAC_VREF} B)")
        print("Устанавливаем 0.0 B")
        return 0
    return int(voltage / DAC_VREF * 255)
if name == "__main__":
    try:
        dac = R2R_DAC([16, 20, 21, 25, 26, 17, 27, 22], 3.183, True)
        
        while True:
            try:
                voltage = float(input("Введите напряжение в Вольтах: "))
                dac.set_voltage(voltage)

            except ValueError:
                print("Вы ввели не число. Попробуйте ещё раз\n")

    finally:
        dac.deinit()