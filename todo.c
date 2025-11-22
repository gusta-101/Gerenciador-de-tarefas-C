#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100

// Estrutura da Tarefa
typedef struct {
    int id;
    char descricao[100];
    int concluida; // 0 = Pendente, 1 = Concluída
} Tarefa;

// Variáveis Globais
Tarefa lista[MAX_TAREFAS];
int total = 0;

// --- FUNÇÕES ---

void adicionarTarefa() {
    if (total >= MAX_TAREFAS) {
        printf("Erro: Lista cheia!\n");
        return;
    }
    
    // Limpa o buffer do teclado
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Digite a descrição: ");
    fgets(lista[total].descricao, 100, stdin);
    
    // Remove o "enter" (\n) do final da string
    lista[total].descricao[strcspn(lista[total].descricao, "\n")] = 0;

    lista[total].id = total + 1;
    lista[total].concluida = 0;
    total++;
    
    printf("✅ Sucesso!\n");
}

void listarTarefas() {
    printf("\n--- SUAS TAREFAS ---\n");
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        char status = lista[i].concluida ? 'X' : ' ';
        printf("%d. [%c] %s\n", lista[i].id, status, lista[i].descricao);
    }
}

void concluirTarefa() {
    int id;
    printf("ID para concluir: ");
    scanf("%d", &id);

    if (id > 0 && id <= total) {
        lista[id - 1].concluida = 1;
        printf("🎉 Feito!\n");
    } else {
        printf("❌ ID inválido!\n");
    }
}

// --- MENU PRINCIPAL ---
int main() {
    int opcao = 0;

    while (opcao != 4) {
        printf("\n=== TO-DO LIST ===\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Concluir Tarefa\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarTarefa(); break;
            case 2: listarTarefas(); break;
            case 3: concluirTarefa(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    }

    return 0;
}