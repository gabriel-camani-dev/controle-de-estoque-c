# 📦 Sistema de Controle de Estoque em C

Sistema de gerenciamento de estoque desenvolvido em linguagem C, com interface de linha de comando (CLI).

O projeto permite cadastrar produtos, consultar informações, registrar movimentações de entrada e saída e calcular o valor total dos itens armazenados.

## 🎯 Objetivo

Desenvolver uma aplicação prática para consolidar conhecimentos de lógica de programação e fundamentos da linguagem C, trabalhando com funções, vetores, estruturas de repetição, condicionais, manipulação de strings e validação de entradas.

## ⚙️ Funcionalidades

- **Cadastro de produtos:** registro de nome, quantidade e preço unitário.
- **Listagem de produtos:** exibição dos produtos cadastrados em formato de tabela.
- **Busca por nome:** localização de produtos utilizando comparação de strings.
- **Entrada de estoque:** adição de unidades a um produto existente.
- **Saída de estoque:** retirada de unidades com verificação de disponibilidade.
- **Valor total do estoque:** cálculo da soma dos valores dos produtos, considerando preço unitário e quantidade disponível.
- **Validação de entradas:** tratamento de entradas numéricas inválidas em operações de cadastro e movimentação.

## 🛠️ Tecnologias utilizadas

- **Linguagem:** C
- **Bibliotecas:** `stdio.h` e `string.h`
- **Compilador:** GCC
- **Ambiente de desenvolvimento:** Visual Studio Code

## 🚀 Como executar

**1. Clone o repositório**

```bash
git clone https://github.com/SEU-USUARIO/controle-de-estoque-c.git
```

**2. Acesse a pasta do projeto**

```bash
cd controle-de-estoque-c
```

**3. Compile o programa com GCC**

```bash
gcc main.c -o main
```

**4. Execute o programa**

No Windows (PowerShell):

```powershell
.\main.exe
```

No Linux:

```bash
./main
```

## 💻 Exemplo de utilização

Ao iniciar o programa, o seguinte menu será apresentado:

```text
=====================
CONTROLE DE ESTOQUE
=====================
1. Cadastrar produtos
2. Listar produtos
3. Buscar produto pelo nome
4. Registrar entrada no estoque
5. Registrar saido do estoque
6. Mostrar valor total do estoque
0. Sair

Selecione uma opcao:
```

Exemplo de listagem após cadastrar dois produtos:

```text
--- TODOS OS PRODUTOS ---

Produto              | Preco      | Quantidade
---------------------------------------------
Arroz                | R$ 20.00   | 10
Feijao               | R$ 8.50    | 15
```

*Os valores apresentados são apenas ilustrativos.*

## 🧠 Conceitos aplicados

Durante o desenvolvimento, foram utilizados:

- Estruturas condicionais (`if`, `else`, `switch`)
- Estruturas de repetição (`for`, `while`, `do...while`)
- Vetores e matrizes
- Funções e passagem de parâmetros
- Manipulação de strings (`strcmp`, `strlen`, `strcspn`)
- Entrada e saída de dados (`scanf`, `fgets`, `printf`)
- Validação de entradas e operações aritméticas

## 📌 Limitações da versão atual

- O sistema trabalha com uma capacidade fixa de cinco produtos, definida pela constante `PRODUTOS`.
- Os dados são mantidos em memória durante a execução e não são salvos em arquivos.
- A busca utiliza comparação exata de nomes, diferenciando letras maiúsculas e minúsculas.

## 📈 Possíveis melhorias futuras

- [ ] Cadastro de quantidade variável de produtos
- [ ] Armazenamento de dados em arquivos
- [ ] Utilização de `struct` para organizar as informações
- [ ] Edição e exclusão de produtos cadastrados
- [ ] Histórico de movimentações do estoque

## 👨‍💻 Sobre o projeto

Projeto pessoal desenvolvido como parte dos meus estudos em Engenharia da Computação, com foco na aplicação prática dos fundamentos da programação e no desenvolvimento de habilidades de resolução de problemas.

O código foi construído e aprimorado progressivamente, buscando organização, legibilidade e tratamento adequado das operações de estoque.