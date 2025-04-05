#include <avr/io.h>
#define F_CPU 8000000UL  // Установка частоты процессора в 8 МГц
#include <util/delay.h>

#define LED_PIN    PD0  // Пин, к которому подключен светодиод

void gpio_init() {
    // Установка пина как выход
    DDRD |= (1 << LED_PIN);
}

int main() {
    // Инициализация GPIO
    gpio_init();

    while (1) {
        // Включение светодиода
        PORTD |= (1 << LED_PIN);
        _delay_ms(500);
        // Выключение светодиода
        PORTD &= ~(1 << LED_PIN);
        _delay_ms(500);
    }
  return 0;
}
