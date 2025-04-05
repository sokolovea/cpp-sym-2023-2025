const int potPin = A0; // Пин потенциометра
const int ledPin = 9;  // Пин светодиода, поддерживающий ШИМ

void setup() {
  // Инициализация пина светодиода как выходного
  pinMode(ledPin, OUTPUT);
  
  // Инициализация последовательного порта со скоростью 9600 бит/с
  Serial.begin(9600);
  Serial.println("АЦП начальная настройка завершена.");
}

void loop() {
  // Чтение значения с потенциометра
  int sensorValue = analogRead(potPin);
  
  // Преобразование значения потенциометра в диапазон 0-255 для ШИМ
  int brightness = map(sensorValue, 0, 1023, 0, 255);
  
  // Установка яркости светодиода с использованием ШИМ
  analogWrite(ledPin, brightness);
  
  // Вывод значений потенциометра и яркости в последовательный порт
  Serial.print("Значение потенциометра: ");
  Serial.print(sensorValue);
  Serial.print("\tЯркость светодиода: ");
  Serial.println(brightness);
  
  // Задержка для стабильного чтения значений
  delay(100);
}