# EXG3_2023

Exercício em Grupo 3 - Analisador sintático avançado

## Descrição

Escreva um programa em C que realiza a análise sintática avançada de um ficheiro no formato [JavaScript Object Notation - JSON](https://pt.wikipedia.org/wiki/JSON "JSON - Wikipedia").

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

Seu programa começa por apresentar um menu ao utilizador com as seguintes opções:

* `1 - Analise sintatica`
* `2 - Mostrar stack de simbolos`
* `3 - Sair`

---

# Requisitos:

O código deve compilar sem erros ou *warnings* utilizando o **`gcc`** com as seguintes flags:

- `-g -Wvla -Wall -Wpedantic -Wextra -Wdeclaration-after-statement`

A análise sintática deve ser realizada pelo uso de `stacks` (pilhas) que devem ser capazes de efetuar as operações básicas dessa estrutura de dados como `push`, ,`pop`, `is_empty` (verificar se está vazia), `print` (imprimir a stack no ecrã).

---

### Opção 1:

A opção `1 - Analise sintatica` deve começar por pedir ao utilizador informações sobre o tamanho da stack que será utilizada para a análise sintática. O que deve ser feito através da seguinte mensagem: `Informe o tamanho da stack: `

Em seguida, o programa dever perguntar qual o nome do ficheiro no formato `JSON` para realizar a análise sintática será lido, fazendo a pergunta `Informe o nome do ficheiro a analisar:`. O programa deve verificar se o ficheiro existe e se está bem formado e exibir a mensagem apropriada para os seguintes casos:

- `FBF - Ficheiro bem formado!` se o ficheiro estiver bem formado
- `FMF - Ficheiro mal formado!` caso contrário
- `FNE - Ficheiro não existe!` se o ficheiro não existir

Desta forma, quando for encontrado um dos símbolos que delimitam um bloco de código, isto é ao encontrar os símbolos `{` e `[` realizam-se as seguintes operações:

* `push` do símbolo `{` ou `[` na stack

Quando for encontrado um símbolo que fecha um bloco de código, isto é, `}` ou `]`, deve ser efetuada a seguinte operação:

* `pop` do símbolo `{` ou `[` com o indicativo desta operação no ecrã no seguinte formato: `pop {` ou `pop [`

De modo semelhante deverá ser feito quando se encontra o inicio e fim de strings, quando se encontra o primeiro símbolo `"`  faz push do simbolo, e ao encontrar de novo outro simbolo igual faz pop na stack.

### Erros:

Quando, durante a execução **desta opção** no programa, ocorrerem os seguintes erros:

- `push` e a `stack` estiver com sua **capacidade esgotada**, imprima `erro 01: stack overflow!` e imprime `FMF - Ficheiro mal formado!` e volta ao menu principal.
- `pop` e a `stack` estiver **vazia**, imprima `erro 02: stack underflow!` e imprime `FMF - Ficheiro mal formado!` e volta ao menu principal.

---

### Opção 2:

A opção deve permitir ao utilizador visualizar o conteúdo da stack de símbolos.

A stack de símbolos vai ser composta por todos os símbolos `{`, `}`, `[`, `]`, `:` e `,` que foram encontrados no ficheiro `JSON`.

Caso a stack esteja vazia ou nao for feito a analise sintatica, deve ser apresentada a seguinte mensagem: `Stack vazia!` e, caso contrário, deve ser apresentada a seguinte mensagem: `Stack: ` e, em seguida, os símbolos que estão na stack.

---

### Opção 3:

A opção `3 - Sair` deve permitir ao utilizador sair do programa.

---

# Dicas:

- Organizar e modularizar seu código fazendo o uso de funções
- Atenção para a exigência de leitura da **dimensão da stack**
- Apenas a operação de `pop` está a exigir a impressão no **console**, mas em fase de desenvolvimento pode ser útil imprimir o conteúdo da stack a cada operação.

# Exemplo de execução:

- Exemplo 1
```console
1 - Analise sintatica
2 - Mostrar stack de simbolos
3 - Sair
> 1
Informe o tamanho da stack: 10
Informe o nome do ficheiro a analisar: experiencia.json
push {
push {
push [
pop  ]
pop  }
pop  }
FBF - Ficheiro bem formado!
1 - Analise sintatica
2 - Mostrar stack de simbolos
3 - Sair
> 2
Informe o tamanho da stack: 34
Stack: }]}:,:,:,:{,}:,:,:,:{,}:,:,:,:{[:{
1 - Analise sintatica
2 - Mostrar stack de simbolos
3 - Sair
>3
```
- Exemplo 2
```console
1 - Analise sintatica
2 - Mostrar stack de simbolos
3 - Sair
>1
Informe o tamanho da stack: 3
Informe o nome do ficheiro a analisar: experiencia.json
push }
push "
pop  "
push }
push "
pop  "
push }
push "
pop  "
push }
erro 01: stack overflow!
FMF - Ficheiro mal formado!

1 - Analise sintatica
2 - Mostrar stack de simbolos
3 - Sair
>3
```
