//define em quais pinos do Arduino os componentes estão ligados
const int PINO_BOTAO = 2;
const int PINO_LED   = 13;

const unsigned long TEMPO_DEBOUNCE = 50; //tempo de espera para garantir que o botão estabilizou

bool estadoLed        = false; //armazena o estado atual do LED (false = desligado, true = ligado)
bool leituraAnterior  = HIGH; //guarda o último estado lido do botão no ciclo passado do código
bool estadoBotao      = HIGH; //guarda o estado final "filtrado" e estável do botão
unsigned long ultimoTempo = 0; //armazena o exato momento em que o botão mudou de estado pela última vez

void setup() {
  pinMode(PINO_BOTAO, INPUT_PULLUP); //ativa o resistor interno do Arduino para o botão
  pinMode(PINO_LED,   OUTPUT); //configura o pino do LED como saída
  Serial.begin(9600); //abre a comunicação com o monitor serial do computador para enviar textos
}

void loop() {
  bool leituraAtual = digitalRead(PINO_BOTAO); //faz a leitura instantânea do pino do botão (guarda se está HIGH ou LOW agora)
	
  //se a leitura atual for diferente da leitura anterior, significa que o botão mudou
  if (leituraAtual != leituraAnterior) {
    ultimoTempo = millis(); //atualiza o cronômetro salvando o tempo atual do Arduino
  }

  if ((millis() - ultimoTempo) >= TEMPO_DEBOUNCE) {//se o tempo atual menos o tempo da última mudança for maior ou igual a 50ms, significa que o sinal do botão já estabilizou
    if (leituraAtual != estadoBotao) {
      estadoBotao = leituraAtual; //atualiza o estado oficial do botão com a nova leitura estável

      if (estadoBotao == LOW) { //se o estado oficial do botão mudou para LOW, significa que ele foi pressionado
        //inverte o estado do LED usando o operador NOT (!)
        //se era falso (desligado) vira verdadeiro (ligado), e vice-versa
        estadoLed = !estadoLed;

        if (estadoLed == true) { //se a inversão acima resultou em verdadeiro (true)
          digitalWrite(PINO_LED, HIGH); //envia 5V para o pino 13, acendendo o LED
          Serial.println("LED: LIGADO"); //escreve no monitor serial do computador
        } else {//se resultou em falso (false)
          digitalWrite(PINO_LED, LOW); //corta a energia do pino 13, apagando o LED
          Serial.println("LED: DESLIGADO"); //escreve no monitor serial do computador
        }
      }
    }
  }
  leituraAnterior = leituraAtual; //atualiza a variável 'leituraAnterior' com o valor deste ciclo
}
