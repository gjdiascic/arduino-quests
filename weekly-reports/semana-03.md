# Semana 3 — Sensores básicos e comunicação serial
## 1. Objetivo da semana
Aprender como sensores básicos (resistivos e ativos) e comunicação serial funcionam, construindo uma miniestação de leitura ambiental capaz de medir luminosidade e temperatura, exibindo os valores em tempo real no Serial Monitor.
## 2. O que foi estudado
- Diferença entre sensores passivos (resistivos) e sensores ativos.
- Funcionamento do LDR (fotorresistor) e sua relação entre luz e resistência.
- Divisor de tensão como forma de converter variação de resistência em variação de tensão.
- Funcionamento do sensor de temperatura TMP36, que já entrega tensão de saída proporcional à temperatura, sem necessidade de resistor.
- Leitura analógica via analogRead() e conversão de tensão a partir do valor do ADC (0–1023).
- Fórmula de conversão do TMP36 para graus Celsius: (tensão - 0.5) * 100.
- Uso do Serial Monitor para depuração e registro de leituras.
- Simulação no Tinkercad, incluindo o uso dos controles deslizantes (sliders) de luz e temperatura para testar os sensores virtualmente.
## 3. O que eu aprendi
### Giselly Jahel Dias
Texto individual do estudante.
### Thalisson Souza Silva
Texto individual do estudante.
## 4. Explicação técnica da atividade
O circuito é composto por dois sensores lidos por entradas analógicas do Arduino:

*LDR (A0):* por ser um componente resistivo de 2 pinos, sozinho ele não gera uma tensão que possa ser lida diretamente. Por isso é montado em um divisor de tensão: um pino do LDR é ligado ao 5V, e o outro pino é ligado simultaneamente ao pino A0 e a um resistor de 10 kΩ, cuja outra ponta vai ao GND. Como a resistência do LDR muda com a luminosidade, a tensão no ponto de junção (onde está o A0) também muda, permitindo a leitura pelo ADC.

*TMP36 (A1):* é um sensor ativo de 3 pinos (5V, saída, GND) que já realiza a conversão de temperatura em tensão internamente, sem necessidade de resistor externo. O pino central é ligado diretamente ao A1.

No código, o Arduino lê os dois valores analógicos (0–1023) a cada 200 ms. O valor do LDR é usado bruto (ADC) para indicar luminosidade relativa, enquanto o valor do TMP36 é convertido primeiro em tensão (leitura * 5.0 / 1023.0) e depois em graus Celsius pela fórmula do fabricante. Os resultados são impressos no Serial Monitor.
## 5. Circuito
<img width="1536" height="694" alt="Semana 3 - Miniestação de leitura ambiental" src="https://github.com/user-attachments/assets/6d84b14c-cdb7-456a-89a3-cbd38be49650" />

## 6. Componentes utilizados
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| LDR (fotorresistor) | — | Varia resistência conforme a luz incidente |
| Resistor | 10 kΩ | Forma o divisor de tensão com o LDR (pull-down) |
| Sensor de temperatura | TMP36 | Fornece tensão de saída proporcional à temperatura |
| Arduino Uno | — | Lê os sinais analógicos e envia dados via serial |

## 7. Código
O arquivo principal do firmware é ligabotao.ino, localizado em firmware/arduino/miniestacao.ino
```cpp
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
```
## 8. Testes realizados
Testes feitos diretamente na simulação do Tinkercad, utilizando os controles deslizantes (sliders) de cada componente:

- Ao clicar no LDR durante a simulação e mover o slider de luminosidade, verificou-se se o valor "Luz (ADC)" no Serial Monitor aumentava ou diminuía de forma coerente.
- Ao clicar no TMP36 e mover o slider de temperatura, verificou-se se o valor em °C acompanhava a mudança de forma proporcional.
- Conferência do baud rate do Serial Monitor (9600), garantindo compatibilidade com Serial.begin(9600) do código.
## 9. Resultados obtidos

| Teste | Condição do slider | Luz (ADC) | Tensão TMP36 (V) | Temperatura (°C) | Observação |
|---|---|---|---|---|---|
| 1 | Luz mínima (escuro) | ~950–1023 | — | — | Resistência do LDR alta → tensão no A0 próxima de 5V |
| 2 | Luz intermediária | ~400–600 | — | — | Valor do ADC varia proporcionalmente ao nível de luz |
| 3 | Luz máxima (claro) | ~0–100 | — | — | Resistência do LDR baixa → tensão no A0 próxima de 0V |
| 4 | Temperatura mínima do slider | — | ~0,25 | ~-25 | Tensão de saída do TMP36 no limite inferior |
| 5 | Temperatura ambiente (~25 °C) | — | ~0,75 | ~25 | Valor de referência do sensor (0,75V = 25°C) |
| 6 | Temperatura máxima do slider | — | ~1,25 | ~75 | Tensão de saída do TMP36 no limite superior |

## 10. Problemas encontrados
Nenhum problema foi encontrado.
## 11. Correções realizadas
Não foi necessário realizar correções.
## 12. Relação com aplicações do dia a dia
Esse tipo de leitura ambiental combinando luminosidade e temperatura é a base de sistemas de automação residencial e agrícola, como estufas automatizadas, iluminação inteligente que se ajusta à luz ambiente, ou sistemas de monitoramento climático simples. A lógica de sensor e Conversor Analógico-Digital é a mesma usada em termostatos, sistemas de irrigação automática e monitoramento de ambientes controlados.
## 13. Critério de aceite
[ x ] PASSOU  
[   ] NÃO PASSOU
## 14. Link da simulação, vídeo ou evidência
https://www.tinkercad.com/things/iVuMSIq6Bfl-semana-3-miniestacao-de-leitura-ambiental/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=RGbXiJ2w4LbbYE6k2Vtut6DHqtmYVGywYhjnmj0bPk0
