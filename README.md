# automatodepilha
# Autômato de Pilha em C++

Este projeto apresenta a implementação de um **Autômato de Pilha** em linguagem **C++**, desenvolvido para reconhecer uma linguagem livre de contexto.

O arquivo principal do projeto é:

```text
main.cpp
```

A linguagem reconhecida pelo autômato é:

```text
L = {0^n1^n | n >= 1}
```

Ou seja, o algoritmo aceita cadeias formadas por uma quantidade de símbolos `0` seguida pela mesma quantidade de símbolos `1`.

## Objetivo

O objetivo deste projeto é demonstrar, de forma prática, o funcionamento de um autômato de pilha utilizando a linguagem C++.

O autômato utiliza uma pilha como memória auxiliar para verificar se a quantidade de símbolos `0` é igual à quantidade de símbolos `1`.

## Alfabeto

O alfabeto da linguagem é:

```text
Σ = {0, 1}
```

## Linguagem reconhecida

A linguagem reconhecida é:

```text
L = {0^n1^n | n >= 1}
```

Exemplos de cadeias aceitas:

```text
01
0011
000111
00001111
```

Exemplos de cadeias rejeitadas:

```text
0
1
011
001
0101
00011
```

## Gramática livre de contexto

Uma gramática livre de contexto que gera essa linguagem é:

```text
S -> 0S1
S -> 01
```

A produção `S -> 0S1` adiciona um símbolo `0` no início e um símbolo `1` no final da cadeia.

A produção `S -> 01` encerra a geração da palavra.

## Funcionamento do autômato

O autômato funciona da seguinte forma:

1. Enquanto lê símbolos `0`, empilha o símbolo `x`.
2. Ao encontrar o primeiro símbolo `1`, muda para o estado de leitura dos símbolos `1`.
3. Para cada símbolo `1` lido, desempilha um `x`.
4. A cadeia é aceita se, ao final da leitura, a pilha estiver vazia.
5. A cadeia é rejeitada se houver símbolos inválidos, se aparecer `0` depois de `1`, ou se a quantidade de `0` e `1` for diferente.

## Exemplo de funcionamento da pilha

Para a cadeia `000111`:

| Símbolo lido | Ação na pilha | Pilha |
| ------------ | ------------- | ----- |
| 0            | empilha x     | x     |
| 0            | empilha x     | x x   |
| 0            | empilha x     | x x x |
| 1            | desempilha x  | x x   |
| 1            | desempilha x  | x     |
| 1            | desempilha x  | vazia |

Como a pilha termina vazia, a cadeia `000111` é aceita.

## Estados utilizados

O algoritmo utiliza dois estados principais:

| Estado | Descrição                                                 |
| ------ | --------------------------------------------------------- |
| q0     | Estado inicial, responsável pela leitura dos símbolos `0` |
| q1     | Estado responsável pela leitura dos símbolos `1`          |

## Código em C++

O código-fonte está no arquivo:

```text
main.cpp
```

## Saída esperada

Ao executar o programa, a saída esperada é:

```text
01 => aceita
0011 => aceita
011 => rejeitada
001 => rejeitada
000111 => aceita
0111 => rejeitada
00011 => rejeitada
a1 => rejeitada
(1 => rejeitada
0) => rejeitada
00001111 => aceita
```

## Como executar

Para compilar o arquivo `main.cpp`, utilize o comando:

```bash
g++ main.cpp -o automato_pilha
```

Para executar no Linux ou no terminal do OnlineGDB:

```bash
./automato_pilha
```

No Windows, após compilar, a execução pode ser feita com:

```bash
automato_pilha.exe
```

Também é possível executar o código em compiladores online, como o OnlineGDB, selecionando a linguagem **C++**.

## Tecnologias utilizadas

* Linguagem C++
* Biblioteca `iostream`
* Biblioteca `stack`
* Biblioteca `vector`
* Biblioteca `string`

## Autor

Paulo Sérgio Theodoro
