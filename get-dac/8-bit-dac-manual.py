import RPi.GPIO as GPIO

R2R = [22, 27, 17, 26, 25, 21, 20, 16]
GPIO.setmode(GPIO.BCM)
GPIO.setup(R2R, GPIO.OUT)

DAC_VREF = 3.3
DAC_BITS = 8
DAC_MAX = 255
DAC_RESOLUTION = DAC_VREF / DAC_MAX

dac_range = (0.0, DAC_VREF)

def dac_v(code):
    return (code / DAC_MAX) * DAC_VREF

def dac_code(voltage):
    return int((voltage / DAC_VREF) * DAC_MAX)

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


try:
    while True:
        try:
            voltage = float(input("Введите напряжение в Вольтах: "))
            number = voltage_to_number(voltage)
            number_to_dac(number)
            print(f"Установлено напряжение: {voltage:.2f} В, код ЦАП: {number}")

        except ValueError:
            print("Вы введи не число. Попробуйте еще раз\n")
except KeyboardInterrupt:
    print("\nПрограмма завершена пользователем")
finally:
    GPIO.output(R2R, 0)
    GPIO.cleanup()

