// Semáforo - Arduino UNO
// Pinos conforme o circuito
const int LED_VERDE   = 11;
const int LED_AMARELO = 12;
const int LED_VERMELHO = 13;

void setup() {
  pinMode(LED_VERDE,    OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  // Faz com que todos começam apagados
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

void loop() {
  // --- VERDE: sinal aberto ---
  digitalWrite(LED_VERDE,    HIGH);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, LOW);
  delay(5000); // 5 segundos

  // --- AMARELO: atenção ---
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  delay(2000); // 2 segundos

  // --- VERMELHO: parado ---
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(5000); // 5 segundos
  delay(2000); // 2 segundos
}
