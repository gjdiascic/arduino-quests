# Semana 1.2 — Protoboard virtual, resistores e LEDs externos
## 1. Objetivo da semana
Compreender os fundamentos do Arduino, configurar o ambiente de simulação virtual no Tinkercad, aprender a manipular pinos digitais de saída, utilizar o GitHub para o controle de versão e documentação do projeto e se familiarizar com o funcionamento do código no Arduino.
## 2. O que foi estudado
Listar os principais conteúdos estudados na semana.
Exemplo:
- Uso de pinos digitais.
- Funcionamento de LED e resistor.
- Estrutura básica de um programa Arduino.
- Simulação no Tinkercad.
- Registro da atividade no GitHub.
## 3. O que eu aprendi
Cada estudante deve escrever, com suas próprias palavras, o que aprendeu.
### Estudante 1
Texto individual do estudante.
### Estudante 2
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
Imagem do circuito no Tinkercad ou foto do hardware real.
<img width="1707" height="828" alt="semaforo" src="https://github.com/user-attachments/assets/162f5ea6-5732-42e4-84f4-d991ab0f8ff5" />

## 6. Componentes utilizados
Listar componentes, valores e função no circuito.
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| LED | Vermelho | Saída - pino 13 |
| Resistor | 330 Ω | Limitar corrente do LED |
| LED | Verde | Saída - pino 11 |
| Resistor | 330 Ω | Limitar corrente do LED |
| LED | Amarelo | Saída - pino 12 |
| Resistor | 330 Ω | Limitar corrente do LED |

## 7. Código
O arquivo principal do firmware é semaforo.ino, localizado em firmware/src/.

O código é organizado em duas funções obrigatórias do Arduino:

setup() — executada uma única vez na inicialização. Configura os três pinos como saída (OUTPUT) usando pinMode(), preparando o Arduino para enviar sinais elétricos a cada LED.

loop() — executada continuamente em ciclo. Contém a sequência do semáforo: a cada fase, um LED é ligado com HIGH enquanto os demais são explicitamente desligados com LOW. 

O delay() define o tempo de permanência em cada fase, em milissegundos. As constantes LED_VERDE, LED_AMARELO e LED_VERMELHO foram usadas no lugar de números diretos para tornar o código mais legível e fácil de manter — se o circuito mudar de pino, é só alterar a constante.
## 8. Testes realizados
Descrever como o teste foi executado.
## 9. Resultados obtidos
Apresentar leituras, imagens, vídeo curto, tabela ou observações.
## 10. Problemas encontrados
Indicar erros de montagem, código, alimentação, ruído, leitura incorreta ou instabilidade.
## 11. Correções realizadas
Explicar como os problemas foram corrigidos.
## 12. Relação com aplicações do dia a dia
Explicar como o conceito estudado na semana pode ser usado em uma solução real.
## 13. Critério de aceite
Informar se a entrega passou ou não passou no critério técnico definido.
## 14. Link da simulação, vídeo ou evidência
Inserir link do Tinkercad, vídeo, imagem, commit ou pasta do GitHub.
