# Semana 2.2 — Entradas analógicas, potenciômetro e PWM
## 1. Objetivo da semana
Aprender a ler sinais analógicos com o Arduino utilizando o ADC, e controlar o brilho de um LED proporcionalmente ao valor lido de um potenciômetro, utilizando PWM como saída.
## 2. O que foi estudado
- Funcionamento de entradas analógicas e diferença em relação a entradas digitais;
- Como o ADC do Arduino converte tensão em valor numérico (0 a 1023);
- O que é PWM e como ele simula uma saída analógica;
- Uso das funções analogRead() e analogWrite();
- Uso da função map() para converter faixas de valores;
- Funcionamento do potenciômetro como divisor de tensão e controle de usuário;
- Montagem do circuito no Tinkercad com potenciômetro, LED e resistor;
- Uso do Serial Monitor para depuração e visualização dos valores lidos.
## 3. O que eu aprendi
### Giselly Jahel Dias
Na semana 2.2 aprendi como o Arduino consegue ler valores que variam de forma contínua, diferente das entradas digitais que só reconhecem liga ou desliga. Descobri que o ADC converte a tensão lida no pino analógico em um número entre 0 e 1023, e que isso depende da tensão de referência de 5V da placa. Também aprendi o que é PWM, técnica que liga e desliga o sinal rapidamente para simular uma tensão intermediária. Na prática, pude compreender melhor como hardware e software trabalham juntos, observando que o potenciômetro é o controle físico, e o código traduz esse controlo em um comportamento visível no LED.
### Thalisson Souza Silva
Na semana 2.2, entendi como o Arduino lida com sinais que variam de forma contínua, diferente das entradas digitais que só reconhecem liga ou desliga. O ADC converte a tensão lida em A0 (0 a 5V) em um número de 0 a 1023, e o potenciômetro fornece essa tensão variável ao funcionar como divisor de tensão. Do lado da saída, entendi que o PWM não gera uma tensão intermediária real — o pino alterna entre HIGH e LOW rápido o suficiente para simular um brilho contínuo no LED, através do duty cycle. Um ponto-chave foi perceber que a resolução de entrada (10 bits, 0–1023) é diferente da saída PWM (8 bits, 0–255), o que torna a função `map()` essencial para traduzir uma escala na outra. Comparando com a semana 2.1, onde trabalhei apenas com sinais binários, essa semana marcou pra mim a transição do mundo discreto para o contínuo, deixando mais claro como hardware e software trabalham juntos: o potenciômetro é o controle físico, e o código traduz isso em comportamento visível no LED.
## 4. Explicação técnica da atividade
O circuito conta com um potenciômetro de 10 kΩ, com um terminal externo conectado ao 5V, o outro ao GND, e o terminal central ao pino A0 do Arduino. Ao girar o eixo, a tensão no terminal central varia proporcionalmente entre 0V e 5V, funcionando como um divisor de tensão. O LED vermelho está conectado ao pino 9 (PWM) em série com um resistor de 220 Ω, e o catodo vai ao GND.
A cada 100ms, o Arduino lê o valor analógico do pino A0 com analogRead(), obtendo um número entre 0 e 1023. Esse valor é convertido para a faixa de 0 a 255 com a função map(), que é a faixa aceita pelo analogWrite(). Em seguida, o valor convertido é enviado ao pino 9 via PWM, controlando o brilho do LED. Os valores de ADC e PWM são também enviados ao Serial Monitor para acompanhamento em tempo real.
O potenciômetro é o controle físico do usuário — sua posição determina a tensão lida pelo ADC. O software converte essa leitura em um duty cycle de PWM, que define quanto tempo o pino 9 fica em nível alto por ciclo. Quanto maior o duty cycle, maior a energia média entregue ao LED e mais intenso o brilho. Assim, girar o potenciômetro para um lado apaga o LED gradualmente, e para o outro o acende no máximo brilho.
## 5. Circuito
<img width="1536" height="694" alt="image" src="https://github.com/user-attachments/assets/a529ccae-00a9-4c13-9e6a-3a4a64fb5dd6" />

## 6. Componentes utilizados
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| Arduino | Uno R3 | Ler o potenciômetro e controlar o brilho do LED via PWM |
| LED | Vermelho | Variar o brilho conforme o sinal PWM recebido |
| Resistor | 220 Ω | Limitar a corrente que passa pelo LED, evitando que queime |
| Potenciômetro | 10 kΩ | Dividir a tensão e gerar um valor analógico entre 0V e 5V |
| Multímetro | — | Medir a tensão no circuito para verificar a variação gerada pelo potenciômetro |
| Protoboard | — | Montagem do circuito  |
| Fios jumper | — | Realizar as conexões elétricas entre os componentes e o Arduino |

## 7. Código
O arquivo .ino se encontra em firmaware\arduino\
```cpp
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
```
O código define duas constantes no início: `pinoPot`, associado ao pino A0 (entrada analógica do potenciômetro), e `pinoLed`, associado ao pino 9 (saída PWM do LED). No `setup()`, o pino do LED é configurado como saída com `pinMode(pinoLed, OUTPUT)`, e a comunicação serial é iniciada com `Serial.begin(9600)` para permitir a depuração via Serial Monitor.

No `loop()`, a cada ciclo o Arduino lê a tensão no pino do potenciômetro com `analogRead(pinoPot)`, obtendo um valor bruto entre 0 e 1023 conforme a posição do eixo. Esse valor é então convertido para a faixa de 0 a 255 através de `map(leitura, 0, 1023, 0, 255)`, já que o `analogWrite()` trabalha com uma resolução de 8 bits, diferente dos 10 bits do ADC. O valor convertido é aplicado ao LED com `analogWrite(pinoLed, pwm)`, controlando o duty cycle do sinal PWM e, consequentemente, o brilho.

Em seguida, o código imprime no Serial Monitor tanto o valor bruto lido do ADC quanto o valor já convertido para PWM, usando uma sequência de `Serial.print()` e `Serial.println()`, o que permite visualizar em tempo real a correspondência entre a posição do potenciômetro e a resposta do LED. Por fim, um `delay(100)` insere uma pausa de 100ms entre as leituras, evitando sobrecarregar o Serial Monitor com atualizações excessivas.
## 8. Testes realizados
O teste foi feito na simulação do Tinkercad, com o Serial Monitor aberto (9600 baud) para acompanhar os valores em tempo real. Ao girar o potenciômetro de uma extremidade a outra, observou-se que o ADC variou de 0 a 1023 e o PWM de 0 a 255 de forma proporcional, com o LED variando o brilho de apagado a máximo de forma gradual. O multímetro foi usado para confirmar que a tensão no terminal central do potenciômetro correspondia aos valores lidos pelo Arduino.
## 9. Resultados obtidos
Apresentar leituras, imagens, vídeo curto, tabela ou observações.
## 10. Problemas encontrados
Indicar erros de montagem, código, alimentação, ruído, leitura incorreta ou instabilidade.
## 11. Correções realizadas
Explicar como os problemas foram corrigidos.
## 12. Relação com aplicações do dia a dia
Explicar como o conceito estudado na semana pode ser usado em uma solução real.
## 13. Critério de aceite
[ x ] PASSOU  
[   ] NÃO PASSOU
## 14. Link da simulação, vídeo ou evidência
https://www.tinkercad.com/things/7ftC6eeIt30-semana-22-brilho-de-um-led-com-potenciometro-/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=CHho_hSOqlJXmgqBzBvQSTK1_43bCmd16UhCwuyAVeA
