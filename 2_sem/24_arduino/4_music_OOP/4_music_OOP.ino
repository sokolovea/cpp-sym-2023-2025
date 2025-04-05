// Подключаем библиотеку для работы с Arduino
#include <Arduino.h>

#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

#define COUNT_NUMBERS 5
const int piezoPin = 9;


const int marioNotes[] = { NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 0, NOTE_G5, 0, 0, 0, NOTE_G4, 0, 0, 0 };
const int marioDurations[] = { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 };

const int forestNotes[] = {   NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4,
                                  NOTE_A4, NOTE_F4, NOTE_C4, NOTE_C4,
                                  NOTE_C4, NOTE_A4, NOTE_A4, NOTE_AS4,
                                  NOTE_G4, NOTE_C5, NOTE_C5, NOTE_D4,
                                  NOTE_D4, NOTE_AS4,NOTE_AS4,NOTE_A4,
                                  NOTE_G4, NOTE_F4, NOTE_C4, NOTE_A4,
                                  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4};
const int forestDurations[] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };

class Music {
  protected:
    virtual float getPauseLength() {
      return 1.30;  
    }
  public:
    // Функция для воспроизведения мелодии
    void playMelody(const int notes[], const int durations[], int length) {
      for (int i = 0; i < length; i++) {
        int noteDuration = 1000 / durations[i];
        tone(piezoPin, notes[i], noteDuration);
        int pauseBetweenNotes = noteDuration * getPauseLength(); // Добавляем небольшую паузу между нотами
        delay(pauseBetweenNotes);
        noTone(piezoPin);
      }
    }
    static void printMenu()
    {
      Serial.println("Выберите мелодию или настройку: ");
      Serial.println("1 - Мелодия из игры \"Супер Марио\"");
      Serial.println("2 - В лесу родилась ёлочка");
      Serial.println("---");
      Serial.println("3 - Обычная музыка");
      Serial.println("4 - Ускоренная музыка");
      Serial.println("5 - Замедленная музыка");

    }
    static int getSelectedMelody()
    {
      while (!Serial.available()); // Ждем, пока пользователь введет данные
      int itemChoice = Serial.readStringUntil('\n').toInt(); // Считываем выбор пользователя
      if (itemChoice < 1 || itemChoice > COUNT_NUMBERS)
      {
        Serial.println("Неверный выбор. Попробуйте еще раз.");
        return -1;
      }
      return itemChoice;
    }
};

class SlowMusic : public Music {
  protected:
    float getPauseLength() {
      return 1.3 * 1.5;
    }
};

class FastMusic : public Music {
  protected:
    float getPauseLength() {
      return 1.3 / 1.5;
    }
};

Music* music;

void setup() {
  Serial.begin(9600);
  pinMode(piezoPin, OUTPUT);
  music = new Music();
}

void loop() {
  // Просим пользователя выбрать мелодию
  Music::printMenu();
  int itemChoice = Music::getSelectedMelody();

  if (itemChoice == 1) {
    // Мелодия из игры "Марио"
    music->playMelody(marioNotes, marioDurations, sizeof(marioNotes)/sizeof(marioNotes[0]));
  } else if (itemChoice == 2) {
    // Песенка "В лесу родилась ёлочка"
    music->playMelody(forestNotes, forestDurations, sizeof(forestNotes)/sizeof(forestNotes[0]));
  } else if (itemChoice == 3) {
    delete music;
    music = new Music();
  } else if (itemChoice == 4) {
    delete music;
    music = new FastMusic();
  } else {
    delete music;
    music = new SlowMusic();
  } 
  Serial.flush();
  // Ждем некоторое время перед повторением процесса
  delay(100);
}
