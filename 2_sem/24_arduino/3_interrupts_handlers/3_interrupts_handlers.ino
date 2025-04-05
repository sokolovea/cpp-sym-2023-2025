// Подключаем библиотеку для работы с Arduino
#include <Arduino.h>

volatile int buttonState = LOW;
volatile int lastButtonState = LOW;

// Объявляем переменные для хранения времени последнего изменения состояния кнопки
volatile unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // Время для устранения дребезга

const int ledPin = 13;
const int buttonPin = 2;

// Функция обработчика прерывания для кнопки
void buttonISR() {
  int reading = digitalRead(buttonPin);
//  buttonState = reading; //???

  // Проверяем, прошло ли достаточное время для устранения дребезга
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    
    if (reading != buttonState) {
      buttonState = reading;
      Serial.print("Состояние кнопки изменилось: ");
      Serial.println(buttonState);
    }
  }
  
}

void setup() {
  // Инициализируем Serial порт для отладочной печати
  Serial.begin(9600);
  
  // Инициализируем пины светодиода и кнопки
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Подключаем внутренний резистор к 5V
  
  // Настраиваем прерывание для кнопки
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, CHANGE);
}

void loop() {
  // Проверяем, изменилось ли состояние кнопки
  if (buttonState != lastButtonState) {
    // Если состояние изменилось, меняем состояние светодиода
    if (buttonState == HIGH) {
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
    
    // Запоминаем текущее состояние кнопки
    lastButtonState = buttonState;
  }
}
