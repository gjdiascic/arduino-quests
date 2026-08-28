const int pinoLDR = A0;      // Sensor de luminosidade
const int pinoBuzzer = 8;    // Base do transistor (via resistor de 2,2kΩ)
const int limiteLuz = 300;   // Ajuste este valor conforme os testes no Serial Monitor

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(pinoLDR); // Lê o valor do LDR (0-1023)

  if (luz > limiteLuz) {
    // Ambiente escuro (resistência do LDR alta) -> aciona o buzzer
    digitalWrite(pinoBuzzer, HIGH);
    Serial.print("ESCURO -> Buzzer ligado | ");
  } else {
    // Ambiente claro -> mantém desligado
    digitalWrite(pinoBuzzer, LOW);
    Serial.print("CLARO  -> Buzzer desligado | ");
  }

  Serial.print("Luz (ADC): ");
  Serial.println(luz);

  delay(200);
}
