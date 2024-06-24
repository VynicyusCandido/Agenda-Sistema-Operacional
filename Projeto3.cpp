#include <stdio.h>
#include <stdlib.h>

// Definição de um contato
typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

// Prototipação das funções
void adicionarContato();
void pesquisarContato();
void excluirContato();
void carregarContatos();
void salvarContatos();
void exibirMenu();
void removeNovaLinha(char *str);
int comparaStrings(const char *str1, const char *str2);

// Definição do arquivo onde os contatos serão salvos
#define ARQUIVO_CONTATOS "contatos.txt"
#define MAX_CONTATOS 100

// Lista de contatos
Contato contatos[MAX_CONTATOS];
int numeroDeContatos = 0;

int main() {
    // Carrega os contatos do disco na inicialização do programa
    carregarContatos();
    
    int escolha;
    
    // Loop principal do programa para exibir o menu e executar as funções escolhidas
    do {
        exibirMenu();
        scanf("%d", &escolha);
        getchar(); // Limpa o buffer do teclado
        
        switch (escolha) {
            case 1:
                adicionarContato();
                break;
            case 2:
                pesquisarContato();
                break;
            case 3:
                excluirContato();
                break;
            case 4:
                salvarContatos();
                printf("Contatos salvos. Saindo...\n");
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (escolha != 4);
    
    return 0;
}

// Função para adicionar um novo contato
void adicionarContato() {
    if (numeroDeContatos >= MAX_CONTATOS) {
        printf("Catálogo cheio! Não é possível adicionar mais contatos.\n");
        return;
    }
    
    Contato novoContato;
    
    printf("Digite o nome: ");
    fgets(novoContato.nome, 50, stdin);
    removeNovaLinha(novoContato.nome); // Remove o caractere de nova linha
    
    printf("Digite o telefone: ");
    fgets(novoContato.telefone, 20, stdin);
    removeNovaLinha(novoContato.telefone); // Remove o caractere de nova linha
    
    contatos[numeroDeContatos++] = novoContato;
    
    printf("Contato adicionado com sucesso!\n");
}

// Função para pesquisar um contato pelo nome
void pesquisarContato() {
    char nome[50];
    
    printf("Digite o nome para pesquisar: ");
    fgets(nome, 50, stdin);
    removeNovaLinha(nome); // Remove o caractere de nova linha
    
    for (int i = 0; i < numeroDeContatos; i++) {
        if (comparaStrings(contatos[i].nome, nome) == 0) {
            printf("Contato encontrado: %s - %s\n", contatos[i].nome, contatos[i].telefone);
            return;
        }
    }
    
    printf("Contato não encontrado.\n");
}

// Função para excluir um contato pelo nome
void excluirContato() {
    char nome[50];
    
    printf("Digite o nome para excluir: ");
    fgets(nome, 50, stdin);
    removeNovaLinha(nome); // Remove o caractere de nova linha
    
    for (int i = 0; i < numeroDeContatos; i++) {
        if (comparaStrings(contatos[i].nome, nome) == 0) {
            for (int j = i; j < numeroDeContatos - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            numeroDeContatos--;
            printf("Contato excluído com sucesso.\n");
            return;
        }
    }
    
    printf("Contato não encontrado.\n");
}

// Função para carregar os contatos do disco
void carregarContatos() {
    FILE *arquivo = fopen(ARQUIVO_CONTATOS, "r");
    if (arquivo == NULL) {
        printf("Arquivo de contatos não encontrado. Criando um novo...\n");
        return;
    }
    
    while (fread(&contatos[numeroDeContatos], sizeof(Contato), 1, arquivo)) {
        numeroDeContatos++;
    }
    
    fclose(arquivo);
    printf("Contatos carregados com sucesso.\n");
}

// Função para salvar os contatos no disco
void salvarContatos() {
    FILE *arquivo = fopen(ARQUIVO_CONTATOS, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    
    for (int i = 0; i < numeroDeContatos; i++) {
        fwrite(&contatos[i], sizeof(Contato), 1, arquivo);
    }
    
    fclose(arquivo);
}

// Função para exibir o menu
void exibirMenu() {
    printf("\n---- Catálogo de Contatos ----\n");
    printf("1. Adicionar Contato\n");
    printf("2. Pesquisar Contato\n");
    printf("3. Excluir Contato\n");
    printf("4. Salvar e Sair\n");
    printf("Escolha uma opção: ");
}

// Função para remover o caractere de nova linha de uma string
void removeNovaLinha(char *str) {
    while (*str) {
        if (*str == '\n') {
            *str = '\0';
            return;
        }
        str++;
    }
}

// Função para comparar duas strings
int comparaStrings(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
