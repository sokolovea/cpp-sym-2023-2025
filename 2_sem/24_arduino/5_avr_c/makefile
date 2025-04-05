# Настройки компилятора
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
MCU = attiny88
F_CPU = 8000000UL
TARGET = main

CFLAGS = -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

SRC_DIR = .
INC_DIR = inc

# Список исходных файлов
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(TARGET).hex

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(TARGET).elf: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f $(TARGET).elf $(TARGET).hex $(OBJ_FILES)
	$(AVRDUDE) -p $(MCU) -c usbasp -e

# Загрузка прошивки в микроконтроллер
flash: $(TARGET).hex
	$(AVRDUDE) -p $(MCU) -c usbasp -U flash:w:$<

.PHONY: all clean flash
