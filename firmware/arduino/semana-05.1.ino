const int pinoMosfet = 9; //Pino PWM ligado ao resistor de gate

void setup() {
  pinMode(pinoMosfet, OUTPUT);
}

void loop() {
  //Acelera gradualmente de 0 a 255
  for (int velocidade = 0; velocidade <= 255; velocidade++) {
    analogWrite(pinoMosfet, velocidade);
    delay(10);
  }

  delay(1000); //Mantém na velocidade máxima por 1s

  //Desacelera gradualmente de 255 a 0
  for (int velocidade = 255; velocidade >= 0; velocidade--) {
    analogWrite(pinoMosfet, velocidade);
    delay(10);
  }

  delay(1000); //Motor parado por 1s
}
