#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100
#define TAMANHO_MAXIMO 50

typedef struct {
    char descricao[TAMANHO_MAXIMO];
    int concluida;
} Tarefa;

void adicionar_tarefa(Tarefa tarefas[], int *quantidade) {
    if (*quantidade >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    printf("Digite a descrição da tarefa: ");
    scanf(" %[^\n]", tarefas[*quantidade].descricao);
    tarefas[*quantidade].concluida = 0;
    (*quantidade)++;

    printf("Tarefa adicionada com sucesso.\n");
}

void listar_tarefas(Tarefa tarefas[], int quantidade) {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. [%s] %s\n", i + 1, tarefas[i].concluida ? "X" : " ", tarefas[i].descricao);
    }
}

void marcar_concluida(Tarefa tarefas[], int quantidade, int indice) {
    if (indice < 1 || indice > quantidade) {
        printf("Índice inválido.\n");
        return;
    }

    tarefas[indice - 1].concluida = 1;
    printf("Tarefa marcada como concluída.\n");
}

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int quantidade = 0;
    int opcao;
    int indice;

    printf("Bem-vindo ao seu To-Do List!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Marcar Tarefa como Concluída\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_tarefa(tarefas, &quantidade);
                break;
            case 2:
                listar_tarefas(tarefas, quantidade);
                break;
            case 3:
                printf("Digite o índice da tarefa a ser marcada como concluída: ");
                scanf("%d", &indice);
                marcar_concluida(tarefas, quantidade, indice);
                break;
            case 4:
                printf("Obrigado por usar o To-Do List. Até mais!\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
