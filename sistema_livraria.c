#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct {
    int id;
    char nome[100];
    char autor[100];
    char editora[100];
} Livro;

Livro lista_livro[TAM];
int total_livros = 0;
int id_global = 1;

void cadastrar_livro() {
    if (total_livros >= TAM) {
        printf("\nLimite de livros atingido.\n\n");
        return;
    }

    Livro l;
    l.id = id_global++;
    printf("Id do livro: %d\n", l.id);

    printf("Por favor, entre com o nome do livro: ");
    fgets(l.nome, sizeof(l.nome), stdin);
    strtok(l.nome, "\n");

    printf("Por favor, entre com o autor do livro: ");
    fgets(l.autor, sizeof(l.autor), stdin);
    strtok(l.autor, "\n");

    printf("Por favor, entre com a editora do livro: ");
    fgets(l.editora, sizeof(l.editora), stdin);
    strtok(l.editora, "\n");

    lista_livro[total_livros++] = l;
    printf("Livro cadastrado com sucesso!\n\n");
}

void consultar_livro() {
    int opcao;
    while (1) {
        printf("------------------------------------------\n");
        printf("---------- MENU CONSULTAR LIVRO ----------\n");
        printf("Escolha a opcao desejada:\n");
        printf("1 - Consultar todos os Livros\n");
        printf("2 - Consultar Livro por id\n");
        printf("3 - Consultar Livro(s) por autor\n");
        printf("4 - Retornar\n");
        printf(">>> ");
        scanf("%d", &opcao);
        getchar();
        printf("------------------------------------------\n");

        if (opcao == 1) {
            for (int i = 0; i < total_livros; i++) {
                printf("---------------------------\n");
                printf("ID: %d\n", lista_livro[i].id);
                printf("Nome: %s\n", lista_livro[i].nome);
                printf("Autor: %s\n", lista_livro[i].autor);
                printf("Editora: %s\n", lista_livro[i].editora);
            }
            printf("\n");
        } else if (opcao == 2) {
            int id_desejado, encontrado = 0;
            printf("Digite o ID do livro: ");
            scanf("%d", &id_desejado);
            getchar();
            for (int i = 0; i < total_livros; i++) {
                if (lista_livro[i].id == id_desejado) {
                    printf("---------------------------\n");
                    printf("ID: %d\n", lista_livro[i].id);
                    printf("Nome: %s\n", lista_livro[i].nome);
                    printf("Autor: %s\n", lista_livro[i].autor);
                    printf("Editora: %s\n", lista_livro[i].editora);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
                printf("Este ID nao foi cadastrado na livraria.\n\n");
        } else if (opcao == 3) {
            char autor[100];
            int encontrado = 0;
            printf("Digite o autor do(s) livro(s): ");
            fgets(autor, sizeof(autor), stdin);
            strtok(autor, "\n");
            for (int i = 0; i < total_livros; i++) {
                if (strcasecmp(lista_livro[i].autor, autor) == 0) {
                    printf("---------------------------\n");
                    printf("ID: %d\n", lista_livro[i].id);
                    printf("Nome: %s\n", lista_livro[i].nome);
                    printf("Autor: %s\n", lista_livro[i].autor);
                    printf("Editora: %s\n", lista_livro[i].editora);
                    encontrado = 1;
                }
            }
            if (!encontrado)
                printf("Nenhum livro cadastrado para esse autor na livraria.\n\n");
        } else if (opcao == 4) {
            break;
        } else {
            printf("Escolha invalida, escolha uma opcao novamente\n\n");
        }
    }
}

void remover_livro() {
    int id_remocao, encontrado = 0;
    printf("Digite o ID do livro que deseja remover: ");
    scanf("%d", &id_remocao);
    getchar();
    for (int i = 0; i < total_livros; i++) {
        if (lista_livro[i].id == id_remocao) {
            for (int j = i; j < total_livros - 1; j++) {
                lista_livro[j] = lista_livro[j + 1];
            }
            total_livros--;
            printf("Livro removido com sucesso!\n\n");
            return;
        }
    }
    printf("Este ID nao foi cadastrado na livraria.\n\n");
}

int main() {
    int opcao;
    printf("Bem-vindo a Livraria da Maria Eduarda Bernini\n\n");
    while (1) {
        printf("------------------------------------\n");
        printf("---------- MENU PRINCIPAL ----------\n");
        printf("Escolha a opcao desejada:\n");
        printf("1 - Cadastrar Livro\n");
        printf("2 - Consultar Livro(s)\n");
        printf("3 - Remover Livro\n");
        printf("4 - Sair\n");
        printf(">>> ");
        scanf("%d", &opcao);
        getchar();
        printf("------------------------------------\n");

        if (opcao == 1) {
            cadastrar_livro();
        } else if (opcao == 2) {
            consultar_livro();
        } else if (opcao == 3) {
            remover_livro();
        } else if (opcao == 4) {
            printf("Volte sempre!\n");
            break;
        } else {
            printf("Escolha invalida, escolha uma opcao novamente\n\n");
        }
    }
    return 0;
}