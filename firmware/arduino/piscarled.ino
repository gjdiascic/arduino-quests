void piscarLed(int pino, int tempoLigado, int tempoDesligado){
  	digitalWrite(pino, HIGH); //liga o led
  	delay(tempoLigado); //espera o tempo ligado
	digitalWrite(pino, LOW); //desliga o led
	delay(tempoDesligado); //espera o tempo desligado
}

void setup() {
	pinMode(13, OUTPUT); //configura o pino 13 como saída 
}

void loop() {
	piscarLed(13, 1200, 1500); //pisca lento
	piscarLed(13, 3, 7); //pisca rápido
	piscarLed(13, 700, 900); //sequência personalizada
}
