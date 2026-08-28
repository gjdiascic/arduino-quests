# Semana 5.2 — Atuadores: servo, motor DC, relé e buzzer
## 1. Objetivo da semana
Descrever o objetivo técnico da atividade.
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
Texto individual do estudante.
## 4. Explicação técnica da atividade
Explicar como o circuito funciona, como o código funciona e qual é a relação entre hardware
e software.
## 5. Circuito
<img width="1536" height="694" alt="Semana 5 2 - Atuadores_ servo, motor DC, relé e  buzzer" src="https://github.com/user-attachments/assets/7cbe054b-02de-4b84-8a50-eaa10df7b52e" />

## 6. Componentes utilizados
Listar componentes, valores e função no circuito.
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| LED | Vermelho | Indicar saída digital |
| Resistor | 220 Ω | Limitar corrente do LED |

## 7. Código

const int pinoLDR = A0;      // Sensor de luminosidade
const int pinoBuzzer = 8;    // Base do transistor (via resistor de 2,2kΩ)
const int limiteLuz = 300;   // Ajuste este valor conforme os testes no Serial Monitor

void setup() {
  pinMode(pinoBuzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int luz = analogRead(pinoLDR); // Lê o valor do LDR (0-1023)

  if (luz > limiteLuz) {
    // Ambiente escuro (resistência do LDR alta) -> aciona o buzzer
    digitalWrite(pinoBuzzer, HIGH);
    Serial.print("ESCURO -> Buzzer ligado | ");
  } else {
    // Ambiente claro -> mantém desligado
    digitalWrite(pinoBuzzer, LOW);
    Serial.print("CLARO  -> Buzzer desligado | ");
  }

  Serial.print("Luz (ADC): ");
  Serial.println(luz);

  delay(200);
}
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
