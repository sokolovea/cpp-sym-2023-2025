#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; } // Ждем, пока последовательное соединение инициализируется

  Serial.println("Управление EEPROM");
  Serial.print("Кол-во ячеек EEPROM = ");
  Serial.println(EEPROM.length());
  printMenu();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    unsigned long startTime = micros();
    switch (command) {
      case 'r': // Чтение EEPROM
        readEEPROM();
        break;
      case 'a': // Чтение EEPROM
        readAllEEPROM();
        break;
      case 'w': // Запись в EEPROM
        writeEEPROM();
        break;
      case 'c': // Очистка EEPROM
        clearEEPROM();
        break;
      case 's': // Установка значения по номеру ячейки
        setEEPROMValue();
        break;
      default:
        Serial.println("Неизвестная команда");
        printMenu();
        break;
    }
    unsigned long endTime = micros();
    Serial.print("Время выполнения: ");
    Serial.print((endTime - startTime) / 1000.0);
    Serial.println(" мс");
    Serial.flush();
  }
}

void printMenu() {
  Serial.println("Доступные команды:");
  Serial.println("r - Чтение EEPROM");
  Serial.println("a - Чтение всего EEPROM");
  Serial.println("w - Запись в EEPROM");
  Serial.println("c - Очистка EEPROM");
  Serial.println("s - Установка значения по адресу");
}

void readAllEEPROM() {
  Serial.println("Содержимое EEPROM:");
  for (int i = 0; i < EEPROM.length(); i++) {
    byte value = EEPROM.read(i);
    Serial.print("Адрес ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(value, DEC);
  }
}

void writeEEPROM() {
  Serial.println("Введите адрес и значение (через пробел): ");
  while (Serial.available() == 0) { ; }
  int address = Serial.parseInt();
  int value = Serial.parseInt();
  if (address >= 0 && address < EEPROM.length() && value >= 0 && value <= 255) {
    EEPROM.write(address, value);
    Serial.print("Записано ");
    Serial.print(value);
    Serial.print(" в адрес ");
    Serial.println(address);
  } else {
    Serial.println("Неверный адрес или значение");
  }
}

void readEEPROM() {
  Serial.println("Введите адрес:");
  while (Serial.available() == 0) { ; }
  int address = Serial.parseInt();
  if (address >= 0 && address < EEPROM.length()) {
    byte value = EEPROM.read(address);
    Serial.print("Прочитано ");
    Serial.print(value);
    Serial.print(" из адреса ");
    Serial.println(address);
  } else {
    Serial.println("Неверный адрес");
  }
}

void clearEEPROM() {
  for (int i = 0; i < EEPROM.length(); i++) {
    EEPROM.write(i, 0);
  }
  Serial.println("EEPROM очищен");
}

void setEEPROMValue() {
  Serial.println("Введите адрес и значение (через пробел): ");
  while (Serial.available() == 0) { ; }
  int address = Serial.parseInt();
  int value = Serial.parseInt();
  if (address >= 0 && address < EEPROM.length() && value >= 0 && value <= 255) {
    EEPROM.write(address, value);
    Serial.print("Установлено значение ");
    Serial.print(value);
    Serial.print(" по адресу ");
    Serial.println(address);
  } else {
    Serial.println("Неверный адрес или значение");
  }
}
