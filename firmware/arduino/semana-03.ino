const int pinoLDR = A0;
const int pinoTMP36 = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(pinoLDR);
  int leituraTemp = analogRead(pinoTMP36);

  float tensao = leituraTemp * (5.0 / 1023.0);
  float temperaturaC = (tensao - 0.5) * 100.0;

  Serial.print("Luz (ADC): ");
  Serial.print(luz);
  Serial.print(" | Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" °C");

  delay(200);
}
