# Semana 1.1 — Introdução ao Arduino, GitHub e simulação
## 1. Objetivo da semana
Compreender os fundamentos do Arduino, configurar o ambiente de simulação virtual no Tinkercad, aprender a manipular pinos digitais de saída, utilizar o GitHub para o controle de versão e documentação do projeto e se familiarizar com o funcionamento do código no Arduino.
## 2. O que foi estudado
- Manipulação de pinos digitais (`pinMode()`, `digitalWrite()` e `delay()`);
- Estrutura fundamental de um firmware (`setup()` e `loop()`);
- Funcionamento de LED e resistor;
- Conceitos básicos de hardware do Arduino Uno;
- Uso da plataforma Tinkercad para simulação de circuitos;
- Estruturação de repositórios no GitHub.
## 3. O que eu aprendi

### Giselly Jahel Dias
Na semana 1.1, eu aprendi a realizar simulações na plataforma Tinkercad, bem como a manipular pinos digitais e LED's, através do uso de funções. Também compreendi conceitos básicos acerca do hardware Arduino Uno essenciais para o desenvolvimento deste projeto.
### Thalisson Souza Silva
Aprendi coisas fundamentais para um bom funcionamento de um projeto Arduino que envolva Led, como os resistores por exemplo. E a lógica por trás do próprio código do projeto em questão.
## 4. Explicação técnica da atividade
O circuito consiste em um LED conectado a um pino digital do Arduino, protegido por um resistor limitador de corrente para evitar curto circuito. No software, configuramos o pino como saída (`OUTPUT`). 
Para cumprir o critério de aceite de criar três padrões de pisca (lento, rápido e personalizado), foi desenvolvida uma função customizada chamada `piscarLed()`. Esta função recebe como parâmetros o pino do LED, o tempo que ele deve permanecer ligado e o tempo que deve permanecer desligado. O loop principal executa sequencialmente esses três padrões, criando a transição visual exigida.
## 5. Circuito

<img width="1536" height="694" alt="Semana 1 1 - LED (piscar com três padrões diferentes )" src="https://github.com/user-attachments/assets/f1a29b1d-d129-4d06-aa5b-356fcb8d6116" />

## 6. Componentes utilizados

| Componente | Valor/modelo | Função no circuito |
|---|---|---|
| LED | Vermelho | Indicar saída digital |
| Resistor | 220 Ω | Limitar corrente do LED |
| Arduino | Uno R3 | Controlar o circuito e processar o código|

## 7. Código
O arquivo principal do firmware é piscarled.ino, localizado em firmware/src/.

O código foi modularizado utilizando a função obrigatória `piscarLed`, permitindo alternar de forma limpa entre os três padrões exigidos (lento, rápido e sequência personalizada).

## 8. Testes realizados
O teste foi executado diretamente no ambiente virtual do Tinkercad. Foram validados de forma cronometrada os três estágios de funcionamento do LED, garantindo que o programa realizasse a transição automática entre o modo lento, o modo rápido e a sequência personalizada sem erros.
## 9. Resultados obtidos
Os testes foram validados cronometrando os ciclos de piscada na simulação do Tinkercad. Os resultados observados foram mapeados na tabela abaixo:

| Padrão Testado | Parâmetros Utilizados (Ligado / Desligado) | Comportamento Esperado | Resultado Observado na Simulação | Status |
| :--- | :--- | :--- | :--- | :--- |
| **1. Pisca Lento** | `1200ms` / `1500ms` | LED pisca de forma bem compassada e lenta. | O LED permaneceu aceso por 1,2s e apagado por 1,5s, repetindo o ciclo. | Correspondente |
| **2. Pisca Rápido** | `3ms` / `7ms` | Oscilação rápida e contínua (efeito estroboscópico). | O LED piscou rapidamente 1 vez de forma perfeitamente visível. | Correspondente |
| **3. Personalizado** | `700ms` / `900ms` | Ritmo intercalado (sinalização assíncrona). | Transição suave com tempo de brilho intermediário e apagamento mais longo. | Correspondente |
## 10. Problemas encontrados
Nenhum problema foi encontrado durante a montagem do circuito.
## 11. Correções realizadas
Não foi necessário realizar correções.
## 12. Relação com aplicações do dia a dia
O conceito de fazer um LED piscar com três padrões e modularizar funções é a base para criar sinalizadores de trânsito (semáforos), luzes de emergência de prédios, pisca-alerta de automóveis e sistemas de temporização industrial.
## 13. Critério de aceite
[ x ] PASSOU  
[   ] NÃO PASSOU  

Justificativa: O LED executou perfeitamente os três padrões exigidos (lento, rápido e personalizado), o código está documentado, utiliza a função obrigatória parametrizada e o repositório foi estruturado corretamente.
## 14. Link da simulação, vídeo ou evidência
https://www.tinkercad.com/things/14zNVky9oI3-semana-11-led-piscar-com-tres-padroes-diferentes-/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall&sharecode=4ZcxleuZkFGPVpisu3SBVB_b_pb7cltN-lxQ6pYCFd8
