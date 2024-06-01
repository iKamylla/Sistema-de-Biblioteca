#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 100
#define MAX_LIVROS 100
#define MAX_EMPRESTIMOS 100

typedef struct {
    int ISBN;
    char nome[100];
    char autor[100];
    float valor;
} Livro;

typedef struct {
    char cpf[12];
    char nome[100];
    int idade;
} Usuario;

typedef struct {
    int ISBNs[10]; // Maximo de 10 livros por emprestimo
    time_t dataEmprestimo;
    time_t dataDevolucao;
    float multaPorDia;
} Emprestimo;

Livro livros[MAX_LIVROS];
Usuario usuarios[MAX_USUARIOS];
Emprestimo emprestimos[MAX_EMPRESTIMOS];

int numLivros = 0, numUsuarios = 0, numEmprestimos = 0;
float taxaMulta = 0.10; // 10% inicial

void cadastrarLivro() {
    system("cls");
    if (numLivros >= MAX_LIVROS) {
        printf("\n\tLimite de livros atingido!\n");
        return;
    }
    printf("\n\tDigite o ISBN do livro: ");
    scanf("%d", &livros[numLivros].ISBN);
    printf("\n\tDigite o nome do livro: ");
    scanf(" %[^\n]", livros[numLivros].nome);
    printf("\n\tDigite o autor do livro: ");
    scanf(" %[^\n]", livros[numLivros].autor);
    printf("\n\tDigite o valor do livro: ");
    scanf("%f", &livros[numLivros].valor);
    numLivros++;
    printf("\n\tLivro cadastrado com sucesso!\n");
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void visualizarLivros() {
    system("cls");
    if (numLivros == 0) {
        printf("\n\tNenhum livro cadastrado!\n");
        return;
    }
    printf("\n\tLivros cadastrados:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("\n\t%d. ISBN: %d, Nome: %s, Autor: %s, Valor: %.2f\n", i + 1, livros[i].ISBN, livros[i].nome, livros[i].autor, livros[i].valor);
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void editarLivro() {
    system("cls");
    int isbn, found = 0;
    printf("\n\tDigite o ISBN do livro que deseja editar: ");
    scanf("%d", &isbn);
    for (int i = 0; i < numLivros; i++) {
        if (livros[i].ISBN == isbn) {
            printf("\n\tEditando livro %s:\n", livros[i].nome);
            printf("\n\tNovo ISBN (anterior %d): ", livros[i].ISBN);
            scanf("%d", &livros[i].ISBN);
            printf("\n\tNovo nome (anterior %s): ", livros[i].nome);
            scanf(" %[^\n]", livros[i].nome);
            printf("\n\tNovo autor (anterior %s): ", livros[i].autor);
            scanf(" %[^\n]", livros[i].autor);
            printf("\n\tNovo valor (anterior %.2f): ", livros[i].valor);
            scanf("%f", &livros[i].valor);
            found = 1;
            printf("\n\tLivro editado com sucesso!\n");
            break;
        }
    }
    if (!found) {
        printf("\n\tISBN nao encontrado!\n");
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void deletarLivro() {
    system("cls");
    int isbn, found = 0;
    printf("\n\tDigite o ISBN do livro que deseja deletar: ");
    scanf("%d", &isbn);
    for (int i = 0; i < numLivros; i++) {
        if (livros[i].ISBN == isbn) {
            for (int j = i; j < numLivros - 1; j++) {
                livros[j] = livros[j + 1];
            }
            numLivros--;
            found = 1;
            printf("\n\tLivro deletado com sucesso!\n");
            break;
        }
    }
    if (!found) {
        printf("\n\tISBN nao encontrado!\n");
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void cadastrarUsuario() {
    system("cls");
    if (numUsuarios >= MAX_USUARIOS) {
        printf("\n\tLimite de usuarios atingido!\n");
        return;
    }
    printf("\n\tDigite o CPF do usuario (11 caracteres): ");
    scanf("%s", usuarios[numUsuarios].cpf);
    printf("\n\tDigite o nome do usuario: ");
    scanf(" %[^\n]", usuarios[numUsuarios].nome);
    printf("\n\tDigite a idade do usuario: ");
    scanf("%d", &usuarios[numUsuarios].idade);
    numUsuarios++;
    printf("\n\tUsuario cadastrado com sucesso!\n");
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void visualizarUsuarios() {
    system("cls");
    if (numUsuarios == 0) {
        printf("\n\tNenhum usuario cadastrado!\n");
        return;
    }
    printf("\n\tUsuarios cadastrados:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("\n\t%d. CPF: %s, Nome: %s, Idade: %d\n", i + 1, usuarios[i].cpf, usuarios[i].nome, usuarios[i].idade);
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void editarUsuario() {
    system("cls");
    char cpf[12];
    int found = 0;
    printf("\n\tDigite o CPF do usuario que deseja editar: ");
    scanf("%s", cpf);
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            printf("\n\tEditando usuario %s:\n", usuarios[i].nome);
            printf("\n\tNovo CPF (anterior %s): ", usuarios[i].cpf);
            scanf("%s", usuarios[i].cpf);
            printf("\n\tNovo nome (anterior %s): ", usuarios[i].nome);
            scanf(" %[^\n]", usuarios[i].nome);
            printf("\n\tNova idade (anterior %d): ", usuarios[i].idade);
            scanf("%d", &usuarios[i].idade);
            found = 1;
            printf("\n\tUsuario editado com sucesso!\n");
            break;
        }
    }
    if (!found) {
        printf("\n\tCPF nao encontrado!\n");
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void deletarUsuario() {
    system("cls");
    char cpf[12];
    int found = 0;
    printf("\n\tDigite o CPF do usuario que deseja deletar: ");
    scanf("%s", cpf);
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            for (int j = i; j < numUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            numUsuarios--;
            found = 1;
            printf("\n\tUsuario deletado com sucesso!\n");
            break;
        }
    }
    if (!found) {
        printf("\n\tCPF nao encontrado!\n");
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void visualizarEmprestimos() {
    system("cls");
    if (numEmprestimos == 0) {
        printf("\n\tNenhum emprestimo cadastrado!\n");
        return;
    }
    printf("\n\tEmprestimos cadastrados:\n");
    char buf[20];
    for (int i = 0; i < numEmprestimos; i++) {
        printf("\n\tEmprestimo %d:\n", i + 1);
        printf("\n\tLivros emprestados: ");
        for (int j = 0; j < 10 && emprestimos[i].ISBNs[j] != 0; j++) {
            printf("%d ", emprestimos[i].ISBNs[j]);
        }
        printf("\n");
        strftime(buf, 20, "%Y-%m-%d %H:%M:%S", localtime(&emprestimos[i].dataEmprestimo));
        printf("\tData do emprestimo: %s\n", buf);
        strftime(buf, 20, "%Y-%m-%d %H:%M:%S", localtime(&emprestimos[i].dataDevolucao));
        printf("\tData de devolucao: %s\n", buf);
        printf("\tMulta por dia: %.2f\n", emprestimos[i].multaPorDia);
    }
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void cadastrarEmprestimo() {
    system("cls");
    if (numEmprestimos >= MAX_EMPRESTIMOS) {
        printf("\n\tLimite de emprestimos atingido!\n");
        return;
    }
    printf("\n\tDigite o numero de livros do emprestimo: ");
    int numLivrosEmprestimo;
    scanf("%d", &numLivrosEmprestimo);
    for (int i = 0; i < numLivrosEmprestimo; i++) {
        printf("\n\tDigite o ISBN do livro %d: ", i + 1);
        scanf("%d", &emprestimos[numEmprestimos].ISBNs[i]);
    }
    emprestimos[numEmprestimos].dataEmprestimo = time(NULL);
    printf("\n\tDigite o numero de dias de emprestimo: ");
    int diasEmprestimo;
    scanf("%d", &diasEmprestimo);
    emprestimos[numEmprestimos].dataDevolucao = emprestimos[numEmprestimos].dataEmprestimo + (diasEmprestimo * 86400);

    // Calculando a multa por dia
    emprestimos[numEmprestimos].multaPorDia = 0;
    for (int i = 0; i < numLivrosEmprestimo; i++) {
        for (int j = 0; j < numLivros; j++) {
            if (emprestimos[numEmprestimos].ISBNs[i] == livros[j].ISBN) {
                emprestimos[numEmprestimos].multaPorDia += livros[j].valor * taxaMulta;
                break;
            }
        }
    }
    numEmprestimos++;
    printf("\n\tEmprestimo cadastrado com sucesso!\n");
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

void modificarMulta() {
    system("cls");
    printf("\n\tDigite a nova taxa de multa por dia (formato decimal, ex: 0.20 para 20%%): ");
    scanf("%f", &taxaMulta);
    printf("\n\tTaxa de multa modificada para %.2f%%\n", taxaMulta * 100);
    printf("\n\tPressione ENTER para continuar.\n");
    getchar();
    getchar();
}

int main() {
    int opcao;
    do {
        system("cls");
        printf("\n\t\tSistema de Biblioteca\n\n\n");
        printf("\t\t1 - Cadastrar novo usuario\n");
        printf("\t\t2 - Cadastrar novo livro\n");
        printf("\t\t3 - Cadastrar novo emprestimo\n");
        printf("\t\t4 - Modificar taxa de multa por dia\n");
        printf("\t\t5 - Visualizar todos os livros\n");
        printf("\t\t6 - Visualizar todos os usuarios\n");
        printf("\t\t7 - Editar livro\n");
        printf("\t\t8 - Editar usuario\n");
        printf("\t\t9 - Deletar livro\n");
        printf("\t\t10 - Deletar usuario\n");
        printf("\t\t11 - Visualizar emprestimos\n");
        printf("\t\t12 - Sair\n");
        printf("\t\t");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                cadastrarLivro();
                break;
            case 3:
                cadastrarEmprestimo();
                break;
            case 4:
                modificarMulta();
                break;
            case 5:
                visualizarLivros();
                break;
            case 6:
                visualizarUsuarios();
                break;
            case 7:
                editarLivro();
                break;
            case 8:
                editarUsuario();
                break;
            case 9:
                deletarLivro();
                break;
            case 10:
                deletarUsuario();
                break;
            case 11:
                visualizarEmprestimos();
                break;
            case 12:
                printf("\n\tSaindo do sistema...\n");
                break;
            default:
                printf("\n\tOpcao invalida!\n");
        }
    } while (opcao != 12);

    return 0;
}
