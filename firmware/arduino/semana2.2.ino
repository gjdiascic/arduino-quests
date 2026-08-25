const int pinoPot = A0; //pino analógico
const int pinoLed = 9; //pino PWM

void setup() { 
	pinMode(pinoLed, OUTPUT); //LED como saída
	Serial.begin(9600); //monitor serial para depuração
}

void loop() { 
	int leitura = analogRead(pinoPot); //lê 0 a 1023 do ADC
	int pwm = map(leitura, 0, 1023, 0, 255); //converte para 0 a 255
	analogWrite(pinoLed, pwm); //aplica PWM no LED
	Serial.print("ADC: "); //imprime ADC na tela
	Serial.print(leitura); //imprime o valor bruto lido do potenciômetro (0 a 1023)
	Serial.print(" PWM: "); //imprime PWM na tela
	Serial.println(pwm); //imprime o valor convertido (0 a 255)
	delay(100); //aguarda 100ms para não sobrecarregar o Serial Monitor
}
