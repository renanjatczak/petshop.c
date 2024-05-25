#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float peso;
} Pet;

typedef struct {
    Pet info;
    char raca[50];
    char cor[50];
} Cachorro;

typedef struct {
    Pet info;
    char raca[50];
    char cor[50];
} Gato;

int i, j;

void cadastrarCachorro(Cachorro *cachorro, int *quantidadeCachorros) {
    printf("Digite o nome do cachorro: ");
    scanf("%s", cachorro[*quantidadeCachorros].info.nome);
    printf("Digite o peso do cachorro: ");
    scanf("%f", &cachorro[*quantidadeCachorros].info.peso);
    printf("Digite a raca do cachorro: ");
    scanf("%s", cachorro[*quantidadeCachorros].raca);
    printf("Digite a cor do cachorro: ");
    scanf("%s", cachorro[*quantidadeCachorros].cor);
    (*quantidadeCachorros)++;
}

void cadastrarGato(Gato *gato, int *quantidadeGatos) {
    printf("Digite o nome do gato: ");
    scanf("%s", gato[*quantidadeGatos].info.nome);
    printf("Digite o peso do gato: ");
    scanf("%f", &gato[*quantidadeGatos].info.peso);
    printf("Digite a raca do gato: ");
    scanf("%s", gato[*quantidadeGatos].raca);
    printf("Digite a cor do gato: ");
    scanf("%s", gato[*quantidadeGatos].cor);
    (*quantidadeGatos)++;
}

void mostrarPets(Cachorro *cachorros, int quantidadeCachorros, Gato *gatos, int quantidadeGatos) {
    if (quantidadeCachorros == 0 && quantidadeGatos == 0) {
        printf("\nNenhum pet cadastrado.\n");
        return;
    }
    
    if (quantidadeCachorros > 0) {
        printf("\nCachorros cadastrados:\n");
        printf("\n");
        for (i = 0; i < quantidadeCachorros; i++) {
            printf("Nome: %s\n", cachorros[i].info.nome);
            printf("Peso: %.2f\n", cachorros[i].info.peso);
            printf("Raca: %s\n", cachorros[i].raca);
            printf("Cor: %s\n", cachorros[i].cor);
            printf("---------------------------- \n");
        }
    } else {
        printf("\nNenhum cachorro cadastrado.\n");
    }

    if (quantidadeGatos > 0) {
        printf("\nGatos cadastrados:\n");
        printf("\n");
        for (i = 0; i < quantidadeGatos; i++) {
            printf("Nome: %s\n", gatos[i].info.nome);
            printf("Peso: %.2f\n", gatos[i].info.peso);
            printf("Raca: %s\n", gatos[i].raca);
            printf("Cor: %s\n", gatos[i].cor);
        }
    } else {
        printf("\nNenhum gato cadastrado.\n");
    }
    printf("\n");
}

void removerCachorro(Cachorro *cachorros, int *quantidadeCachorros) {
    char nome[50];
    int encontrado = 0;

    if (*quantidadeCachorros == 0) {
        printf("Nenhum cachorro cadastrado para remover.\n");
        return;
    }

    printf("Digite o nome do cachorro a ser removido: ");
    scanf("%s", nome);

    for (i = 0; i < *quantidadeCachorros; i++) {
        if (strcmp(cachorros[i].info.nome, nome) == 0) {
            encontrado = 1;
            for (j = i; j < *quantidadeCachorros - 1; j++) {
                cachorros[j] = cachorros[j + 1];
            }
            (*quantidadeCachorros)--;
            printf("Cachorro removido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cachorro nao encontrado.\n");
    }
}

void removerGato(Gato *gatos, int *quantidadeGatos) {
    char nome[50];
    int encontrado = 0;

    if (*quantidadeGatos == 0) {
        printf("Nenhum gato cadastrado para remover.\n");
        return;
    }

    printf("Digite o nome do gato a ser removido: ");
    scanf("%s", nome);

    for (i = 0; i < *quantidadeGatos; i++) {
        if (strcmp(gatos[i].info.nome, nome) == 0) {
            encontrado = 1;
            for (j = i; j < *quantidadeGatos - 1; j++) {
                gatos[j] = gatos[j + 1];
            }
            (*quantidadeGatos)--;
            printf("Gato removido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Gato nao encontrado.\n");
    }
}

void menuAjuda() {
    printf("\n--------- Menu de Ajuda ---------\n");
    printf("1. Cadastrar cachorro: Permite cadastrar um novo cachorro.\n");
    printf("2. Cadastrar gato: Permite cadastrar um novo gato.\n");
    printf("3. Mostrar pets cadastrados: Exibe todos os cachorros e gatos cadastrados.\n");
    printf("4. Remover cachorro: Remove um cachorro cadastrado pelo nome.\n");
    printf("5. Remover gato: Remove um gato cadastrado pelo nome.\n");
    printf("6. Menu de ajuda: Exibe este menu de ajuda.\n");
    printf("7. Sair: Sai do programa.\n\n");
}

int main() {
    int opcao;
    int quantidadeCachorros = 0;
    int quantidadeGatos = 0;
    Cachorro cachorros[50];
    Gato gatos[50];

    do {
        printf("----------- Menu ----------- \n");
        printf("1. Cadastrar cachorro\n");
        printf("2. Cadastrar gato\n");
        printf("3. Mostrar pets cadastrados\n");
        printf("4. Remover cachorro\n");
        printf("5. Remover gato\n");
        printf("6. Menu de ajuda\n");
        printf("7. Sair\n");
        printf("---------------------------- \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Limpar a tela antes de executar a ação selecionada
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (opcao) {
            case 1:
                cadastrarCachorro(cachorros, &quantidadeCachorros);
                break;
            case 2:
                cadastrarGato(gatos, &quantidadeGatos);
                break;
            case 3:
                mostrarPets(cachorros, quantidadeCachorros, gatos, quantidadeGatos);
                break;
            case 4:
                removerCachorro(cachorros, &quantidadeCachorros);
                break;
            case 5:
                removerGato(gatos, &quantidadeGatos);
                break;
            case 6:
                menuAjuda();
                break;
            case 7:
                printf("Saindo do Programa. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

