//define em quais pinos do Arduino os componentes estão ligados
const int PINO_BOTAO = 2;
const int PINO_LED   = 13;

bool estadoLed        = false; //armazena o estado atual do LED (false = desligado, true = ligado)
bool leituraAnterior  = LOW;   //guarda o último estado lido do botão no ciclo passado do código (começa em LOW devido ao pull-down)

void setup() {
  pinMode(PINO_BOTAO, INPUT); //configura o pino do botão como entrada simples (usa resistor pull-down externo)
  pinMode(PINO_LED,   OUTPUT); //configura o pino do LED como saída
  Serial.begin(9600); //abre a comunicação com o monitor serial do computador para enviar textos
}

void loop() {
  bool leituraAtual = digitalRead(PINO_BOTAO); //faz a leitura instantânea do pino do botão (guarda se está HIGH ou LOW agora)

  //detecta a borda de subida: o botão mudou de solto (LOW) para pressionado (HIGH)
  if (leituraAtual == HIGH && leituraAnterior == LOW) {
    //inverte o estado do LED usando o operador NOT (!)
    //se era falso (desligado) vira verdadeiro (ligado), e vice-versa
    estadoLed = !estadoLed;

    if (estadoLed == true) { //se a inversão acima resultou em verdadeiro (true)
      digitalWrite(PINO_LED, HIGH); //envia 5V para o pino 13, acendendo o LED
      Serial.println("LED: LIGADO"); //escreve no monitor serial do computador
    } else { //se resultou em falso (false)
      digitalWrite(PINO_LED, LOW); //corta a energia do pino 13, apagando o LED
      Serial.println("LED: DESLIGADO"); //escreve no monitor serial do computador
    }
  }

  leituraAnterior = leituraAtual; //atualiza a variável 'leituraAnterior' com o valor deste ciclo
}
