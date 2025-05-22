# 📚 Sistema de Livraria em C

Este projeto é uma aplicação de console simples para gerenciamento de livros, originalmente escrita em Python e portada para a linguagem C. Ele permite o cadastro, consulta e remoção de livros em um sistema baseado em memória.

---

## 🔧 Funcionalidades

- 📥 **Cadastrar novos livros**
- 🔍 **Consultar livros**:
  - Todos os livros
  - Por ID
  - Por autor (sem diferenciar maiúsculas e minúsculas)
- ❌ **Remover livros por ID**

---

## 🧱 Estrutura dos Dados

Cada livro é representado por uma `struct` com os seguintes campos:

```c
typedef struct {
    int id;
    char nome[100];
    char autor[100];
    char editora[100];
} Livro;
```

Os livros são armazenados em um vetor `listaLivros`, e um contador `idGlobal` é utilizado para atribuir um ID único a cada livro.

---

## ▶️ Como Usar

### 1. Compilar o código

Utilize um compilador C (ex: `gcc`):

```bash
gcc livraria.c -o livraria
```

### 2. Executar o programa

```bash
./livraria
```

### 3. Interagir com o sistema

Use o menu exibido no terminal para navegar entre as opções de cadastro, consulta e remoção de livros.

---

## 💡 Exemplo de Uso

```text
Bem-vindo à Livraria da Maria Eduarda Bernini

---------- MENU PRINCIPAL ----------
1 - Cadastrar Livro
2 - Consultar Livro(s)
3 - Remover Livro
4 - Sair
>>> 1
Id do livro: 1
Por favor, entre com o nome do livro: Dom Casmurro
Por favor, entre com o autor do livro: Machado de Assis
Por favor, entre com a editora do livro: Globo

Livro cadastrado com sucesso!
```

---

## ✅ Requisitos

- Compilador C (ex: `gcc`, `clang`)
- Terminal com suporte a entrada interativa

---

## ⚠️ Limitações

- 📌 O sistema armazena no máximo 100 livros por execução.
- 🧠 Os dados são **armazenados apenas em memória** (RAM), ou seja, **não são salvos após o programa ser encerrado**.
- 📁 Nenhuma interface gráfica ou persistência em arquivo está implementada nesta versão.

---

## 🚀 Possíveis Melhorias Futuras

- 💾 Salvar os livros em arquivos `.txt` ou `.csv` para persistência dos dados
- 🧮 Aumentar o limite de livros com alocação dinâmica
- 🖼️ Criar interface gráfica com `GTK` ou `ncurses`
- 🌐 Versão web em C com CGI ou migrar para outra linguagem como Python com Flask

---

## 👩‍💻 Autoria

Este projeto foi implementado como um exercício de lógica e estrutura de dados em linguagem C por **Maria Eduarda Bernini**.

---
