//Закрепитель для шилака
#include <util/delay.h>//Библиотека для задержки _delay_ms
#define light 7//Порт реле светодиодов
void launch(int mode) {
  PORTD |= (1 << light); //Включаем реле
  if (mode == 6) {
    _delay_ms(30000);//Ждем 30(сек)
  } else if (mode == 4) {
    _delay_ms(60000);//Ждем 60(сек)
  } else if (mode == 2) {
    _delay_ms(180000);//Ждем 180(сек)
  }
  PORTD &= ~(1 << light); //Выключаем реле
  _delay_ms(1000); //Ждем 1(сек)
}
int main(void) {
  bool chk = false; //проверка на включение кнопки START
  int mode = 0; //режим переключателя
  DDRB = DDRB | 0b100000; //ВХОД 8-12
  DDRD = DDRD | 0b10000010; // реле7, программныйТХ1 в режим вывода
  PORTD = PORTD | 0b00000000; //реле7(-)
  PORTB = PORTB | 0b000111; //режим pullup pin 8-10
  while (1) {
    mode = PINB;
    if (mode == 6 || mode == 4 || mode == 2) {
      chk = true;
    }
    if (chk) {
      launch(mode);
      chk = false;
    }
  }
}

