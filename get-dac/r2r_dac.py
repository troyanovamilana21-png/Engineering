import RPi.GPIO as GPIO

DAC_VREF = 3.3
DAC_BITS = 8
DAC_MAX = 255

class R2R_DAC:
    def init(self, gpio_bits, dynamic_range, verbose=False):  # Исправлено: init
        self.gpio_bits = gpio_bits
        self.dynamic_range = dynamic_range
        self.verbose = verbose
        
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.gpio_bits, GPIO.OUT, initial=0)
        
        if self.verbose:
            print(f"R2R DAC инициализирован на пинах: {gpio_bits}")
            print(f"Динамический диапазон: {dynamic_range} В")
    
    def deinit(self):
        GPIO.output(self.gpio_bits, 0)
        GPIO.cleanup()
        if self.verbose:
            print("R2R DAC деинициализирован")
    
    def number_to_dac(self, number):
        for i in range(len(self.gpio_bits)):
            bit = (number >> i) & 1
            GPIO.output(self.gpio_bits[i], bit)
    
    def voltage_to_number(self, voltage):
        if not (0.0 <= voltage <= self.dynamic_range):
            print(f"Напряжение выходит за динамический диапазон ЦАП (0..{self.dynamic_range} B)")
            print("Устанавливаем 0.0 B")
            return 0
        return int(voltage / self.dynamic_range * DAC_MAX)  # Исправлено: используем DAC_MAX
    
    def set_voltage(self, voltage):
        number = self.voltage_to_number(voltage)
        self.number_to_dac(number)
        if self.verbose:
            print(f"Установлено напряжение: {voltage:.3f} В (код: {number})")

if name == "main":
    try:
        dac = R2R_DAC([16, 20, 21, 25, 26, 17, 27, 22], 3.183, True)  # Теперь правильно создается объект
        
        while True:
            try:
                voltage = float(input("Введите напряжение в Вольтах: "))
                dac.set_voltage(voltage)
                print()  # Пустая строка для читаемости

            except ValueError:
                print("Вы ввели не число. Попробуйте ещё раз\n")
            except KeyboardInterrupt:
                print("\nПрограмма завершена пользователем")
                break

    except Exception as e:
        print(f"Произошла ошибка: {e}")
    finally:
        dac.deinit()
