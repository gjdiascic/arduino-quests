const int pinoTransistor = 8;

void setup() {
  pinMode(pinoTransistor, OUTPUT);
}

void loop() {
  acionarCarga(pinoTransistor, 1000, 1000); // 1s ligado, 1s desligado
}

void acionarCarga(int pino, int tempoLigado, int tempoDesligado) {
  digitalWrite(pino, HIGH);
  delay(tempoLigado);
  digitalWrite(pino, LOW);
  delay(tempoDesligado);
}
