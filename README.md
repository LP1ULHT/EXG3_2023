# EXG3_2023

Exercício em Grupo 3 - Analisador sintático

### Descrição

Escreva um programa em C que realiza a análise sintática de um ficheiro no formato [JavaScript Object Notation - JSON](https://pt.wikipedia.org/wiki/JSON "JSON - Wikipedia").

Este tipo de ficheiro apresenta a seguinte estrutura:

```json
{
  "alunos": [
    {
      "nome": "João da Silva",
      "idade": 18,
      "curso": "Engenharia Informatica",
      "matricula": "123456"
    },
    {
      "nome": "Maria Souza",
      "idade": 20,
      "curso": "Licenciatura em Informatica e Gestao",
      "matricula": "789012"
    },
    {
      "nome": "Pedro Santos",
      "idade": 19,
      "curso": "Licenciatura em Informatica e Ensino",
      "matricula": "345678"
    }
  ]
}
```

Esta análise consiste em verificar se o ficheiro está bem formado, ou seja, se respeita a estrutura apresentada acima.

Este programa deve começar por pedir ao usuário informações sobre o tamanho da stack que será utilizada para a análise sintática. O que deve ser feito através da seguinte mensagem: `Informe o tamanho da stack: `

Em seguida, um menu deve ser apresentado ao utilizador com as seguintes opções:

* `1 - Analise sintatica`
* `2 - Mostrar stack de simbolos`
* `3 - Sair`

---

A opção `1 - Analise sintatica` deve permitir ao utilizador escolher um ficheiro no formato JSON para realizar a análise sintática. O programa deve verificar se o ficheiro existe e se está bem formado. Caso o ficheiro esteja bem formado, deve ser apresentada a seguinte mensagem: `FBF - Ficheiro bem formado!` e, caso contrário, deve ser apresentada a seguinte mensagem: `FMF - Ficheiro mal formado!`

---

A opção `2 - Mostrar stack de simbolos` deve permitir ao utilizador visualizar o conteúdo da stack de símbolos. Caso a stack esteja vazia, deve ser apresentada a seguinte mensagem: `A stack está vazia!` e, caso contrário, deve ser apresentada a seguinte mensagem: `A stack contem os seguintes símbolos: ` e, em seguida, os símbolos que estão na stack.

---

A opção `3 - Sair` deve permitir ao utilizador sair do programa.

---

Esta análise deve ser realizada pelo uso de `stacks` (pilhas) que devem ser capazes de efetuar as operações básicas dessa estrutura de dados como `push`, ,`pop`, `is_empty` (verificar se está vazia), `print` (imprimir a stack no ecrã).

Desta forma, para este exercício, quando os símbolos que delimitam o escopo de um bloco de código "abrirem", isto é ao encontrar os símbolos `{` e `[` realizam-se as seguintes operações:

* `push` do símbolo `{` ou `[` na stack

Quando for encontrado um símbolo que fecha um bloco de código, isto é, `}` ou `]`, deve ser efetuada a seguinte operação:

* `pop` do símbolo `{` ou `[` com o indicativo desta operaçao no ecrã no seguinte formato: `pop {` ou `pop [`
