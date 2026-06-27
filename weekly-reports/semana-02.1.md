# Semana 2.1 — Entradas digitais, botões e pull-up/pull-down
## 1. Objetivo da semana
Aprender a usar entradas digitais no Arduino, compreender o problema do sinal flutuante em pinos de entrada, aplicar resistores pull-up (interno) e pull-down (externo) para estabilizar o sinal, e implementar debounce por software para evitar múltiplos disparos indevidos ao pressionar um botão.
## 2. O que foi estudado
Listar os principais conteúdos estudados na semana.
Exemplo:
- Funcionamento de entradas digitais com digitalRead().
- Nível lógico alto (HIGH / 5V) e nível lógico baixo (LOW / 0V).
- Por que pinos de entrada ficam flutuando sem referência de tensão.
- Diferença entre resistor pull-up e pull-down.
- Como o INPUT_PULLUP interno do Arduino funciona.
- O fenômeno de bounce mecânico em botões e como o debounce por software resolve o problema.
- Detecção de borda de descida (HIGH → LOW) para registrar apenas um evento por pressão.
## 3. O que eu aprendi
### Giselly Jahel Dias

### Thalisson Souza
Aprendi que um pino configurado como entrada, sem nenhuma referência de tensão, fica em estado indefinido — ele pode ler HIGH ou LOW aleatoriamente dependendo de interferências elétricas ao redor. O resistor pull-up resolve isso conectando o pino ao VCC (5V) quando o botão está solto, garantindo sempre uma leitura estável. Também entendi que o botão não é ideal mecanicamente: quando pressionado, ele "quica" (bounce) e gera múltiplos pulsos em milissegundos, o que faria o LED acender e apagar várias vezes. O debounce por software espera o sinal estabilizar antes de registrar a ação.

## 4. Explicação técnica da atividade
O botão é conectado entre o pino 2 do Arduino e o GND. O INPUT_PULLUP interno mantém o pino em 5V (HIGH) enquanto o botão está solto. Ao pressionar o botão, o pino é conectado ao GND e a leitura cai para LOW. O LED está no pino 13 com um resistor de 220 Ω em série para limitar a corrente.

Por que usar INPUT_PULLUP?

Sem um resistor de referência, o pino de entrada fica eletricamente "no ar" (flutuando). Qualquer campo elétrico ao redor pode induzir tensão no pino, causando leituras aleatórias. O INPUT_PULLUP conecta o pino ao VCC através de um resistor interno, garantindo que a leitura padrão seja HIGH e só vá a LOW quando o botão realmente fechar o circuito com o GND.

Diferença pull-up × pull-down:

- Pull-up: resistor entre o pino e VCC. Pino padrão = HIGH. Botão conecta ao GND → LOW.
- Pull-down: resistor entre o pino e GND. Pino padrão = LOW. Botão conecta ao VCC → HIGH.
O INPUT_PULLUP usa pull-up interno, dispensando o resistor externo.

Debounce por software:

Botões mecânicos produzem oscilações rápidas ao serem pressionados (bounce), que duram tipicamente entre 5 ms e 50 ms. Sem tratamento, o Arduino registraria vários eventos em cada pressão. A estratégia usada:

- Detecta qualquer mudança na leitura → reinicia um contador de tempo.
- Aguarda 50 ms sem nova mudança → considera o sinal estável.
- Só então confirma o novo estado e executa a ação.

Detecção de borda:

O código detecta a borda de descida (HIGH → LOW), ou seja, o momento exato em que o botão é pressionado. Isso garante que o LED alterne uma única vez por pressão, mesmo que o botão fique pressionado por vários segundos.
## 5. Circuito
<img width="1536" height="694" alt="image" src="https://github.com/user-attachments/assets/922ca9dc-7ca6-4a90-b8cb-c8e44650cd71" />

## 6. Componentes utilizados
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| Arduino Uno |---| Microcontrolador principal |
| Protoboard |---| Placa que faz a conexão entre os componentes |
| Botão (push-button) |---| Entrada digital do usuário |
| LED | Vermelho | Indicar saída digital |
| Resistor | 220 Ω | Limitar corrente do LED |
| Push-up interno | ~20 kΩ (via INPUT_PULLUP) | Manter pino 2 em estado definido (HIGH) quando botão solto |

## 7. Código
O arquivo principal do firmware é ligabotao.ino, localizado em firmware/arduino/ligabotao.ino
```cpp
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
```
O algoritmo foi desenvolvido na linguagem C/C++ (padrão Arduino) e implementa o controle de um LED atuando como um interruptor do tipo toggle (alterna o estado a cada clique). A lógica do firmware baseia-se em três pilares principais:

- Uso de Resistor Interno: a configuração INPUT_PULLUP garante que o pino do botão permaneça em nível lógico alto ($5\text{ V}$) enquanto em repouso, evitando flutuações de ruído elétrico;
- Filtro de Debounce por Software: utilizando a função nativa millis(), o programa cria uma janela de temporização de 50ms. Qualquer oscilação mecânica provocada pelo impacto das lâminas internas do botão dentro desse intervalo é ignorada, prevenindo múltiplos acionamentos erráticos;
- Detecção de Borda de Descida: o estado do LED só é efetivamente invertido no momento exato em que o botão passa de solto (HIGH) para pressionado (LOW), garantindo uma transição limpa e precisa a cada comando do usuário. Além disso, o status atual do sistema é transmitido via comunicação serial para fins de monitoramento e depuração.

## 8. Testes realizados
O circuito foi montado e testado primeiramente no Tinkercad, onde foi possível verificar a sequência de acionamento dos LEDs e os tempos de cada fase. Em seguida, utilizando a Arduino IDE, o código final com a lógica de debounce foi compilado e gravado no microcontrolador físico para a validação do comportamento dos componentes em tempo real.
## 9. Resultados obtidos
A tabela abaixo consolida os estados elétricos e lógicos observados durante o funcionamento prático do circuito:

| Componente | Ação Física do Usuário | Estado do LED | Sinal Lido no Pino do Arduino | Mensagem no Monitor Serial |
| :--- | :--- | :--- | :--- | :--- |
| **Botão (Push-button)** | Solto (Em repouso) | Mantém o estado anterior | `HIGH` (5V via Pull-Up) | *Nenhuma (Aguardando evento)* |
| **Botão (Push-button)** | Pressionado (Clique) | Inverte o estado (Liga/Desliga) | `LOW` (0V / GND) | `"LED: LIGADO"` ou `"LED: DESLIGADO"` |
| **LED Indicador** | — | **Aceso** (Recebendo 5V) | `HIGH` (Pino 13 como saída) | `"LED: LIGADO"` |
| **LED Indicador** | — | **Apagado** (0V) | `LOW` (Pino 13 como saída) | `"LED: DESLIGADO"` |

## 10. Problemas encontrados
Nenhum erro foi encontrado.
## 11. Correções realizadas
Não foi necessário realizar correções.
## 12. Relação com aplicações do dia a dia
A combinação de leituras de entradas digitais, resistores de pull-up/pull-down e debounce é a base de controle para qualquer interface física humana na eletrônica moderna. Esse conceito pode ser aplicado em:

Teclados de computador: evitando que uma tecla qualquer, ao ser pressionado, adicione inúmeros caracteres na tela, apenas com um clique rápido.

## 13. Critério de aceite
[ x ] PASSOU  
[   ] NÃO PASSOU

## 14. Link da simulação, vídeo ou evidência
https://www.tinkercad.com/things/bMzEF1l7QmI-semana-21-sistema-ligadesliga-com-botao/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall&sharecode=blzUgx7yR6jIgNLscghMGClKAv5awgwIpE3p18OPVko
