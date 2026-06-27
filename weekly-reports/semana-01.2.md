# Semana 1.2 — Protoboard virtual, resistores e LEDs externos
## 1. Objetivo da semana
Montar um semáforo simples com três LEDs (verde, amarelo e vermelho) na protoboard, calcular os resistores limitadores de corrente usando a Lei de Ohm e programar a sequência correta de acionamento no Arduino.
## 2. O que foi estudado
- Organização elétrica da protoboard;
- Função do resistor limitador de corrente em circuitos com LED;
- Cálculo de resistor usando a Lei de Ohm;
- Pinos digitais do Arduino e função digitalWrite();
- Estrutura básica de um programa Arduino (setup() e loop());
- Simulação do circuito no Tinkercad;
- Registro da atividade no GitHub.
## 3. O que eu aprendi
### Giselly Jahel Dias
Na semana 01.2, o projeto evoluiu para um circuito com três LEDs na protoboard, simulando um semáforo. Tive meu primeiro contato real com a organização elétrica da protoboard; entender como os rails positivo e negativo funcionam e como os furos são interligados internamente foi essencial para montar o circuito corretamente.
Aprendi também a calcular o resistor limitador de corrente usando a Lei de Ohm. Com uma tensão de alimentação de 5V, tensão de queda do LED de 2V e corrente desejada de 9 mA, o cálculo resultou em aproximadamente 330 Ω, valor que garante o funcionamento seguro do LED sem danificá-lo.
No código, trabalhei com a lógica de acionamento exclusivo: a cada fase do semáforo, um LED é ligado com HIGH enquanto os outros dois são explicitamente desligados com LOW. Isso garante que apenas um LED esteja aceso por vez, reproduzindo o comportamento real de um semáforo.
### Thalisson Souza Silva
Nessa semana 1.2, pude aprender como funciona a lógica do código em relação à alternância de funções (ligar um led, desligar outro led etc). E também aprendi como o Arduino "conversa" com o protoboard.
## 4. Explicação técnica da atividade
O circuito é composto por três LEDs (verde, amarelo e vermelho) conectados aos pinos digitais 11, 12 e 13 do Arduino UNO, respectivamente. Cada LED possui um resistor de 330 Ω em série entre seu cátodo e o rail negativo da protoboard, que por sua vez está conectado ao GND do Arduino. Essa configuração limita a corrente que passa pelo LED a aproximadamente 9 mA, calculado pela Lei de Ohm:
R = (Vcc - Vf) / I = (5V - 2V) / 0,009A ≈ 330 Ω.
O ânodo de cada LED recebe o sinal de saída do respectivo pino digital do Arduino.

O código configura os pinos 11, 12 e 13 como saída no setup(). No loop(), os LEDs são acionados em sequência usando digitalWrite() e delay():

Verde acende por 5 segundos — sinal aberto
Amarelo acende por 2 segundos — atenção
Vermelho acende por 5 segundos — parado

A cada fase, os outros dois LEDs são explicitamente apagados com LOW para garantir que apenas um esteja aceso por vez.

O software controla diretamente o estado elétrico dos pinos. Quando o Arduino executa digitalWrite(pino, HIGH), aplica 5V no ânodo do LED correspondente, completando o circuito e acendendo-o. O delay() determina por quanto tempo cada estado se mantém antes de avançar para o próximo, reproduzindo o comportamento temporal de um semáforo real.
## 5. Circuito
Imagem do circuito no Tinkercad.

<img width="1536" height="694" alt="Semana 1 2 - Semáforo simples" src="https://github.com/user-attachments/assets/840188a5-e709-4aae-8933-28fe3b88bf86" />

## 6. Componentes utilizados
Listar componentes, valores e função no circuito.
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| Arduino | Uno R3 | Microcontrolador, gera os sinais digitais |
| LED | Verde | Indicar sinal aberto |
| LED | Vermelho| Indicar sinal fechado |
| LED | Amarelo | Indicar atenção |
| Resistor | 330 Ω | Limitar corrente do LED |
| Protoboard | - | Organizar as conexões do circuito |
| Fios/Jumpers | - | Realizar conexões dos componentes |

## 7. Código
O arquivo principal do firmware é semaforo.ino, localizado em firmware/arduino/semaforo.ino
```cpp
const int LED_VERDE    = 11;
const int LED_AMARELO  = 12;
const int LED_VERMELHO = 13;

void setup() {
  pinMode(LED_VERDE,    OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop() {
  // VERDE — sinal aberto
  digitalWrite(LED_VERDE,    HIGH);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, LOW);
  delay(5000);

  // AMARELO — atenção
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  HIGH);
  digitalWrite(LED_VERMELHO, LOW);
  delay(2000);

  // VERMELHO — parado
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(5000);
}
```
O código é organizado em duas funções obrigatórias do Arduino:

setup() — executada uma única vez na inicialização. Configura os três pinos como saída (OUTPUT) usando pinMode(), preparando o Arduino para enviar sinais elétricos a cada LED.

loop() — executada continuamente em ciclo. Contém a sequência do semáforo: a cada fase, um LED é ligado com HIGH enquanto os demais são explicitamente desligados com LOW. 

O delay() define o tempo de permanência em cada fase, em milissegundos. As constantes LED_VERDE, LED_AMARELO e LED_VERMELHO foram usadas no lugar de números diretos para tornar o código mais legível e fácil de manter — se o circuito mudar de pino, é só alterar a constante.
## 8. Testes realizados
O circuito foi montado e testado primeiramente no Tinkercad, onde foi possível verificar a sequência de acionamento dos LEDs e os tempos de cada fase. E o código foi implantado via Arduino IDE.
## 9. Resultados obtidos
O semáforo funcionou corretamente tanto na simulação. Os três LEDs acenderam na sequência verde → amarelo → vermelho, com os tempos definidos de 5s, 2s e 5s respectivamente, repetindo o ciclo continuamente.
## 10. Problemas encontrados
O fio de GND foi conectado inicialmente ao rail positivo da protoboard em vez do negativo, impedindo o funcionamento do circuito.
## 11. Correções realizadas
O fio de GND foi movido para o rail negativo (–) da protoboard.
## 12. Relação com aplicações do dia a dia
O semáforo é a aplicação mais direta deste conceito, presente em qualquer cenário urbano. Além disso, o mesmo princípio de acionamento sequencial de saídas digitais com temporização é usado em painéis de sinalização industrial, sistemas de alarme com LEDs de status, e qualquer equipamento que precise indicar estados diferentes ao usuário por meio de sinais visuais.
## 13. Critério de aceite
[ x ] PASSOU  
[   ] NÃO PASSOU  

Justificativa: os LEDs vermelho, amarelo e verde acendem em sequência correta com os tempos definidos.
## 14. Link da simulação, vídeo ou evidência
https://www.tinkercad.com/things/lKOdWLHA2Kc-semana-12-semaforo-simples/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits%3Fsort%3Dname&sharecode=0aVT4CdIXVCetW64FcU1zYfuUWYX6P9H7nkKYiI_XOA
