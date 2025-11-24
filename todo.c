// 1. Bibliotecas (Cabeçalhos)
#include <stdio.h>  // Permite entrada e saída (printf, scanf, etc.)
#include <stdlib.h> // Funções utilitárias (não estamos usando muito aqui, mas é padrão)
#include <string.h> // Funções para manipular texto (strings), como strcspn

// 2. Constante (Macro)
#define MAX_TAREFAS 100 // Define um valor fixo para o tamanho máximo da lista.
                        // Onde aparecer MAX_TAREFAS, o compilador troca por 100.

// 3. Definição da Estrutura (Struct) 'Tarefa'
typedef struct {
    int id;              // Número único para identificar a tarefa (1, 2, 3...)
    char descricao[100]; // Texto da tarefa (ex: "Comprar leite"), max 100 caracteres
    int concluida;       // Estado da tarefa: 0 = Pendente, 1 = Concluída
} Tarefa; // O nome desse novo tipo de dado é 'Tarefa'

// 4. Variáveis Globais (Visíveis em todo o programa)
Tarefa lista[MAX_TAREFAS]; // Cria um array (vetor) chamado 'lista' que pode guardar até 100 'Tarefas'
int total = 0;             // Contador que diz quantas tarefas existem atualmente na lista

// --- FUNÇÕES ---

// 5. Função Adicionar Tarefa
void adicionarTarefa() {
    // Verifica se a lista já está cheia
    if (total >= MAX_TAREFAS) {
        printf("Erro: Lista cheia!\n");
        return; // Sai da função se não couber mais nada
    }
    
    // Limpa o "lixo" do buffer do teclado
    // Quando você digita um número no menu e aperta Enter, o Enter (\n) fica no buffer.
    // Se não limparmos, o próximo comando de ler texto (fgets) vai ler esse Enter vazio e pular.
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Digite a descrição: ");
    
    // fgets: Lê uma linha inteira de texto (incluindo espaços) do teclado (stdin)
    // Armazena na posição 'total' da lista, dentro do campo 'descricao'
    fgets(lista[total].descricao, 100, stdin);
    
    // O fgets lê o Enter que você aperta no final. Isso remove esse Enter.
    // strcspn conta quantos caracteres tem até achar o "\n" e substitui por 0 (fim de string).
    lista[total].descricao[strcspn(lista[total].descricao, "\n")] = 0;

    // Preenche os outros dados da nova tarefa
    lista[total].id = total + 1; // ID começa em 1 (total 0 + 1)
    lista[total].concluida = 0;  // Começa como pendente (0)
    
    total++; // Aumenta o contador de tarefas (0 vira 1, 1 vira 2...)
    
    printf("✅ Sucesso!\n");
}

// 6. Função Listar Tarefas
void listarTarefas() {
    printf("\n--- SUAS TAREFAS ---\n");
    
    // Se o contador 'total' for 0, a lista está vazia
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    // Loop para percorrer todas as tarefas cadastradas (de 0 até total-1)
    for (int i = 0; i < total; i++) {
        // Operador Ternário: (condição) ? valor_se_verdadeiro : valor_se_falso
        // Se concluida for 1 (verdadeiro), 'status' recebe 'X'. Senão, recebe ' '.
        char status = lista[i].concluida ? 'X' : ' ';
        
        // Imprime: ID. [Status] Descrição
        // Ex: 1. [ ] Comprar pão
        printf("%d. [%c] %s\n", lista[i].id, status, lista[i].descricao);
    }
}

// 7. Função Concluir Tarefa
void concluirTarefa() {
    int id;
    printf("Digite o ID da tarefa para concluir: ");
    scanf("%d", &id); // Lê o número do ID que o usuário digitou

    // Verifica se o ID é válido (tem que ser maior que 0 e menor ou igual ao total)
    if (id > 0 && id <= total) {
        // Arrays em C começam no 0, mas nossos IDs começam no 1.
        // Então a tarefa ID 1 está na posição 0 da lista. Por isso usamos [id - 1].
        lista[id - 1].concluida = 1; // Muda o estado para 1 (Concluída)
        printf("🎉 Tarefa %d marcada como concluída!\n", id);
    } else {
        printf("X ID inválido!\n");
    }
}

// 8. Função Principal (Main) - Onde o programa começa
int main() {
    int opcao = 0; // Variável para guardar a escolha do menu

    // Loop infinito: O programa roda enquanto a opção não for 4 (Sair)
    while (opcao != 4) {
        // Mostra o menu na tela
        printf("\n=== TO-DO LIST ===\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Concluir Tarefa\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        
        scanf("%d", &opcao); // Lê a opção escolhida

        // Switch: Decide qual função chamar baseada na opção
        switch (opcao) {
            case 1: adicionarTarefa(); break; // Se for 1, chama adicionar e para (break)
            case 2: listarTarefas(); break;   // Se for 2, chama listar...
            case 3: concluirTarefa(); break;  // Se for 3, chama concluir...
            case 4: printf("Saindo...\n"); break; // Se for 4, dá tchau e o loop while termina
            default: printf("Opção inválida!\n"); // Se digitar qualquer outra coisa
        }
    }

    return 0; // Avisa ao sistema operacional que o programa terminou com sucesso
}