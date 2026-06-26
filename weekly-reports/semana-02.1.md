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
Cada estudante deve escrever, com suas próprias palavras, o que aprendeu.
### Thalisson Souza
Aprendi que um pino configurado como entrada, sem nenhuma referência de tensão, fica em estado indefinido — ele pode ler HIGH ou LOW aleatoriamente dependendo de interferências elétricas ao redor. O resistor pull-up resolve isso conectando o pino ao VCC (5V) quando o botão está solto, garantindo sempre uma leitura estável. Também entendi que o botão não é ideal mecanicamente: quando pressionado, ele "quica" (bounce) e gera múltiplos pulsos em milissegundos, o que faria o LED acender e apagar várias vezes. O debounce por software espera o sinal estabilizar antes de registrar a ação.
### Estudante 2
Texto individual do estudante.
## 4. Explicação técnica da atividade
O botão é conectado entre o pino 2 do Arduino e o GND. O INPUT_PULLUP interno mantém o pino em 5V (HIGH) enquanto o botão está solto. Ao pressionar o botão, o pino é conectado ao GND e a leitura cai para LOW. O LED está no pino 13 com um resistor de 220 Ω em série para limitar a corrente.

Por que usar INPUT_PULLUP?

Sem um resistor de referência, o pino de entrada fica eletricamente "no ar" (flutuando). Qualquer campo elétrico ao redor pode induzir tensão no pino, causando leituras aleatórias. O INPUT_PULLUP conecta o pino ao VCC através de um resistor interno, garantindo que a leitura padrão seja HIGH e só vá a LOW quando o botão realmente fechar o circuito com o GND.

Diferença pull-up × pull-down:

- Pull-up: resistor entre o pino e VCC. Pino padrão = HIGH. Botão conecta ao GND → LOW.
- Pull-down: resistor entre o pino e GND. Pino padrão = LOW. Botão conecta ao VCC → HIGH.
O INPUT_PULLUP usa pull-up interno, dispensando o resistor externo.

Debounce por software

Botões mecânicos produzem oscilações rápidas ao serem pressionados (bounce), que duram tipicamente entre 5 ms e 50 ms. Sem tratamento, o Arduino registraria vários eventos em cada pressão. A estratégia usada:

- Detecta qualquer mudança na leitura → reinicia um contador de tempo.
- Aguarda 50 ms sem nova mudança → considera o sinal estável.
- Só então confirma o novo estado e executa a ação.

Detecção de borda

O código detecta a borda de descida (HIGH → LOW), ou seja, o momento exato em que o botão é pressionado. Isso garante que o LED alterne uma única vez por pressão, mesmo que o botão fique pressionado por vários segundos.
## 5. Circuito
<img width="1198" height="532" alt="image" src="https://github.com/user-attachments/assets/10cfc825-745a-4625-a737-ee118a5957cb" />

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
Informar se a entrega passou ou não passou no critério técnico definido.
## 14. Link da simulação, vídeo ou evidência
Inserir link do Tinkercad, vídeo, imagem, commit ou pasta do GitHub.
