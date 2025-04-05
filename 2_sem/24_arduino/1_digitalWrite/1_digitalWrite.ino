const int ledPin = 9;  // Порт, поддерживающий ШИМ
int brightness = 0; 

void setup() {
  // Инициализация пина светодиода как выходного
  pinMode(ledPin, OUTPUT);
  
  // Инициализация последовательного порта со скоростью 9600 бит/с
  Serial.begin(9600);
  Serial.println("Введите яркость светодиода (0-255):");
}

void loop() {
  // Проверка, есть ли данные, доступные для чтения по последовательному порту
  if (Serial.available() > 0) {

    String input = Serial.readStringUntil('\n');

    int newBrightness = input.toInt();

    if (newBrightness >= 0 && newBrightness <= 255) {
      brightness = newBrightness;

      // Установка яркости светодиода с использованием ШИМ
      analogWrite(ledPin, brightness);

      Serial.print("Текущая яркость: ");
      Serial.println(brightness);
    } else {
      Serial.println("Ошибка: введите значение от 0 до 255.");
    }
  }
}
