# Semana 4.1 — Capacitores, ruído, temporização e debounce físico
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
### Giselly Jahel Dias
Texto individual do estudante.
### Thalisson Souza Silva
Texto individual do estudante.
## 4. Explicação técnica da atividade
Explicar como o circuito funciona, como o código funciona e qual é a relação entre hardware
e software.
## 5. Circuito
<img width="1536" height="694" alt="Semana 4 1 - Circuito do botão usando capacitor " src="https://github.com/user-attachments/assets/5b6bdc93-22d0-46ff-a91f-31c0d4f43e60" />

## 6. Componentes utilizados
Listar componentes, valores e função no circuito.
| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| LED | Vermelho | Indicar saída digital |
| Resistor | 220 Ω | Limitar corrente do LED |

## 7. Código
O arquivo principal do firmware é semana-04.1.ino, localizado em firmware/arduino/semana-04.1.ino
```cpp
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
```
## 8. Testes realizados
Descrever como o teste foi executado.
## 9. Resultados obtidos
Apresentar leituras, imagens, vídeo curto, tabela ou observações.
## 10. Problemas encontrados
Nenhum problema encontrado.
## 11. Correções realizadas
Não foi necessário realizar correções.
## 12. Relação com aplicações do dia a dia
Explicar como o conceito estudado na semana pode ser usado em uma solução real.
## 13. Critério de aceite
[ x ] PASSOU  
[   ] NÃO PASSOU
## 14. Link da simulação, vídeo ou evidência
[Inserir link do Tinkercad, vídeo, imagem, commit ou pasta do GitHub.](https://www.tinkercad.com/things/0oWxjqt3F39-semana-41-circuito-do-botao-usando-capacitor-/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=5A34SmmjxDCmlZ-DNkELY4L8rBkCAbuqqyfPD_jdIl4)
