Gerenciador de Tarefas (CLI To-Do List)

Um gerenciador de tarefas simples e eficiente que roda diretamente no terminal, desenvolvido em linguagem C.

Objetivo Principal: Este projeto foi criado com o objetivo de me ajudar a ministrar e organizar minhas tarefas do dia a dia de forma prática, rápida e sem distrações.

Secundariamente, ele serve para demonstrar conhecimentos técnicos em Estruturas de Dados, Manipulação de Strings e lógica de programação.

Funcionalidades

Adicionar Tarefa: Cria uma nova tarefa com descrição personalizada.

Listar Tarefas: Mostra todas as tarefas cadastradas com seus IDs e status (pendente/concluída).

Concluir Tarefa: Marca uma tarefa como feita usando o ID.

Interface Interativa: Menu de navegação simples e intuitivo.

🛠️ Tecnologias Utilizadas

Linguagem C (Padrão C99)

GCC (GNU Compiler Collection) para compilação

Bibliotecas: stdio.h, stdlib.h, string.h

📦 Como Instalar e Rodar

Pré-requisitos

Você precisa ter um compilador C instalado (como o GCC).

Ubuntu/Linux: sudo apt install build-essential

Windows: MinGW ou WSL.

Passo a Passo

Clone o repositório

git clone [https://github.com/gusta-101/Gerenciador-Tarefas-C.git](https://github.com/gusta-101/Gerenciador-Tarefas-C.git)
cd Gerenciador-Tarefas-C


Compile o código

gcc todo.c -o todo


Execute o programa

No Linux/Mac:

./todo


No Windows:

todo.exe


📸 Exemplo de Uso

=== TO-DO LIST ===
1. Adicionar Tarefa
2. Listar Tarefas
3. Concluir Tarefa
4. Sair
Escolha: 1

Digite a descrição da tarefa: Estudar C as 8H
✅ Tarefa adicionada com sucesso!

--- SUAS TAREFAS ---
1. [ ] Estudar Ponteiros em C


🤝 Como Contribuir

Faça um Fork do projeto.

Crie uma nova Branch (git checkout -b feature/nova-funcionalidade).

Faça o Commit (git commit -m 'Adiciona nova funcionalidade').

Faça o Push (git push origin feature/nova-funcionalidade).

Abra um Pull Request.

Desenvolvido por Gusta-101