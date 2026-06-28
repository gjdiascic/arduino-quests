# Semana 2.2 — Entradas analógicas, potenciômetro e PWM
## 1. Objetivo da semana
Aprender a ler sinais analógicos com o Arduino utilizando o ADC, e controlar o brilho de um LED proporcionalmente ao valor lido de um potenciômetro, usando PWM como saída.
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
Texto individual do estudante.
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
Indicar o arquivo principal do firmware e explicar a lógica usada.
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
[ x ] PASSOU  
[   ] NÃO PASSOU
## 14. Link da simulação, vídeo ou evidência
https://www.tinkercad.com/things/7ftC6eeIt30-semana-22-brilho-de-um-led-com-potenciometro-/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=CHho_hSOqlJXmgqBzBvQSTK1_43bCmd16UhCwuyAVeA
