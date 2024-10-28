#include <stdio.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

//int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    #define MAX_CARTAS 10  // Número máximo de cartas que podem ser cadastradas

// Estrutura para representar uma cidade
typedef struct {
    char estado[3];
    char codigo[5];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;  // Propriedade calculada
    float pib_per_capita;          // Propriedade calculada
} Cidade;

// Função para calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

// Função para capturar dados da cidade
void input_city(Cidade *cidade) {
    printf("Digite o estado (Ex: SP): ");
    scanf("%2s", cidade->estado);

    printf("Digite o código da carta (Ex: A01): ");
    scanf("%4s", cidade->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade->nome);  // Lê a linha inteira para o nome

    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &cidade->area);

    printf("Digite o PIB total: ");
    scanf("%f", &cidade->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calcula as propriedades
    cidade->densidade_populacional = calcular_densidade_populacional(cidade->populacao, cidade->area);
    cidade->pib_per_capita = calcular_pib_per_capita(cidade->pib, cidade->populacao);
}

// Função para exibir dados da cidade
void display_city(Cidade cidade) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Estado: %s\n", cidade.estado);
    printf("Código da Carta: %s\n", cidade.codigo);
    printf("Nome da Cidade: %s\n", cidade.nome);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: %.2f\n", cidade.pib_per_capita);
}

// Função principal
int main() {
    int num_cidades, i;

    printf("Digite o número de cartas de cidades que deseja cadastrar (máx %d): ", MAX_CARTAS);
    scanf("%d", &num_cidades);

    if (num_cidades > MAX_CARTAS) {
        printf("Número excede o máximo permitido (%d). O programa será encerrado.\n", MAX_CARTAS);
        return 1;
    }

    // Alocação dinâmica para armazenar as cidades
    Cidade *cidades = (Cidade *)malloc(num_cidades * sizeof(Cidade));
    if (cidades == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Entrada e cálculo de dados para cada cidade
    for (i = 0; i < num_cidades; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);
        input_city(&cidades[i]);
    }

    // Exibição das informações de cada cidade
    for (i = 0; i < num_cidades; i++) {
        display_city(cidades[i]);
    }

    // Liberação da memória alocada
    free(cidades);




    return 0;
}
