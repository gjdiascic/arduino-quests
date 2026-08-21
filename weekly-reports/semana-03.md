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
Cada estudante deve escrever, com suas próprias palavras, o que aprendeu.
### Giselly Jahel Dias
Texto individual do estudante.
### Thalisson Souza Silva
Texto individual do estudante.
## 4. Explicação técnica da atividade
Explicar como o circuito funciona, como o código funciona e qual é a relação entre hardware
e software.
## 5. Circuito
<img width="1536" height="694" alt="Semana 3 - Miniestação de leitura ambiental" src="https://github.com/user-attachments/assets/6d84b14c-cdb7-456a-89a3-cbd38be49650" />

## 6. Componentes utilizados
Listar componentes, valores e função no circuito.
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| LED | Vermelho | Indicar saída digital |
| Resistor | 220 Ω | Limitar corrente do LED |

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
Descrever como o teste foi executado.
## 9. Resultados obtidos
Apresentar leituras, imagens, vídeo curto, tabela ou observações.
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
