#include <stdio.h>
#include <string.h>

struct Carta {
    char estado;                
    char codigo[4];             
    char nomeCidade[50];        
    int populacao;              
    float area;                 
    double pib;                 // PIB em unidades
    int numPontosTuristicos;    
    float densidadePopulacional;
    double pibPerCapita;
};

// Função para comparar o atributo escolhido
void compararAtributoEscolhido(struct Carta c1, struct Carta c2) {
    // Escolha do atributo: "populacao", "area", "pib", "pibPerCapita", "densidade", "pontos"
    const char *atributoEscolhido = "densidade"; // <- altere aqui conforme desejar

    printf("\n=== Comparação do atributo escolhido: %s ===\n", atributoEscolhido);

    if (strcmp(atributoEscolhido, "populacao") == 0) {
        printf("%s: %d\n", c1.nomeCidade, c1.populacao);
        printf("%s: %d\n", c2.nomeCidade, c2.populacao);
        if (c1.populacao > c2.populacao)
            printf("Vencedor: %s\n", c1.nomeCidade);
        else if (c2.populacao > c1.populacao)
            printf("Vencedor: %s\n", c2.nomeCidade);
        else
            printf("Empate!\n");
    }
    else if (strcmp(atributoEscolhido, "area") == 0) {
        printf("%s: %.2f\n", c1.nomeCidade, c1.area);
        printf("%s: %.2f\n", c2.nomeCidade, c2.area);
        if (c1.area > c2.area)
            printf("Vencedor: %s\n", c1.nomeCidade);
        else if (c2.area > c1.area)
            printf("Vencedor: %s\n", c2.nomeCidade);
        else
            printf("Empate!\n");
    }
    else if (strcmp(atributoEscolhido, "pib") == 0) {
        printf("%s: %.2lf\n", c1.nomeCidade, c1.pib);
        printf("%s: %.2lf\n", c2.nomeCidade, c2.pib);
        if (c1.pib > c2.pib)
            printf("Vencedor: %s\n", c1.nomeCidade);
        else if (c2.pib > c1.pib)
            printf("Vencedor: %s\n", c2.nomeCidade);
        else
            printf("Empate!\n");
    }
    else if (strcmp(atributoEscolhido, "pibPerCapita") == 0) {
        printf("%s: %.2lf\n", c1.nomeCidade, c1.pibPerCapita);
        printf("%s: %.2lf\n", c2.nomeCidade, c2.pibPerCapita);
        if (c1.pibPerCapita > c2.pibPerCapita)
            printf("Vencedor: %s\n", c1.nomeCidade);
        else if (c2.pibPerCapita > c1.pibPerCapita)
            printf("Vencedor: %s\n", c2.nomeCidade);
        else
            printf("Empate!\n");
    }
    else if (strcmp(atributoEscolhido, "densidade") == 0) {
        printf("%s: %.2f\n", c1.nomeCidade, c1.densidadePopulacional);
        printf("%s: %.2f\n", c2.nomeCidade, c2.densidadePopulacional);
        if (c1.densidadePopulacional < c2.densidadePopulacional)
            printf("Vencedor: %s\n", c1.nomeCidade);
        else if (c2.densidadePopulacional < c1.densidadePopulacional)
            printf("Vencedor: %s\n", c2.nomeCidade);
        else
            printf("Empate!\n");
    }
    else if (strcmp(atributoEscolhido, "pontos") == 0) {
        printf("%s: %d\n", c1.nomeCidade, c1.numPontosTuristicos);
        printf("%s: %d\n", c2.nomeCidade, c2.numPontosTuristicos);
        if (c1.numPontosTuristicos > c2.numPontosTuristicos)
            printf("Vencedor: %s\n", c1.nomeCidade);
        else if (c2.numPontosTuristicos > c1.numPontosTuristicos)
            printf("Vencedor: %s\n", c2.nomeCidade);
        else
            printf("Empate!\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("=== Cadastro de Cartas Super Trunfo (Cidades) ===\n");
    printf("=====ATENÇÃO: NÃO USAR CARACTERES ESPECIAIS OU ACENTOS=====\n");

    // Cadastro da primeira carta
    printf("\n--- Primeira Carta ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    getchar(); // limpa buffer
    printf("Nome da Cidade: ");
    fgets(carta1.nomeCidade, sizeof(carta1.nomeCidade), stdin);
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = 0;
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%lf", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.numPontosTuristicos);

    // Calculando métricas da primeira carta
    carta1.pib = carta1.pib * 1000000000.0; 
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / (double)carta1.populacao;

    // Cadastro da segunda carta
    printf("\n--- Segunda Carta ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    getchar(); // limpa buffer
    printf("Nome da Cidade: ");
    fgets(carta2.nomeCidade, sizeof(carta2.nomeCidade), stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = 0;
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%lf", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.numPontosTuristicos);

    // Calculando métricas da segunda carta
    carta2.pib = carta2.pib * 1000000000.0; 
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / (double)carta2.populacao;

    // Exibindo cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");
    printf("\nCarta 1:\nEstado: %c\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2lf\nPontos Turísticos: %d\nDensidade Populacional: %.2f\nPIB per Capita: %.2lf\n",
           carta1.estado, carta1.codigo, carta1.nomeCidade, carta1.populacao, carta1.area, carta1.pib, carta1.numPontosTuristicos, carta1.densidadePopulacional, carta1.pibPerCapita);
    printf("\nCarta 2:\nEstado: %c\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2lf\nPontos Turísticos: %d\nDensidade Populacional: %.2f\nPIB per Capita: %.2lf\n",
           carta2.estado, carta2.codigo, carta2.nomeCidade, carta2.populacao, carta2.area, carta2.pib, carta2.numPontosTuristicos, carta2.densidadePopulacional, carta2.pibPerCapita);

    // Comparação do atributo escolhido
    compararAtributoEscolhido(carta1, carta2);

    return 0;
}
