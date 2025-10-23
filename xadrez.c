#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs() e o conceito de recursividade do Bispo

// =======================================================
// NÍVEL NOVATO: CONSTANTES (Entrada de Dados)
// =======================================================

// Torre: 5 casas para a direita.
#define MOV_TORRE 5
// Bispo: 5 casas na diagonal (cima e direita).
#define MOV_BISPO 5
// Rainha: 8 casas para a esquerda.
#define MOV_RAINHA 8


// =======================================================
// NÍVEL NOVATO: FUNÇÕES DE MOVIMENTO (Estruturas de Repetição)
// =======================================================

// Movimentação da Torre (Direita) - Usando FOR
void mover_torre() {
    printf("\n--- MOVIMENTO DA TORRE (FOR) ---\n");
    printf("Simulando %d casas para a Direita:\n", MOV_TORRE);

    // O FOR é ideal para um número fixo de repetições.
    for (int i = 0; i < MOV_TORRE; i++) {
        printf("Direita\n");
    }
}

// Movimentação do Bispo (Cima/Direita) - Usando WHILE
void mover_bispo() {
    printf("\n--- MOVIMENTO DO BISPO (WHILE) ---\n");
    printf("Simulando %d casas na diagonal (Cima Direita):\n", MOV_BISPO);

    int contador = 0;
    // O WHILE continua enquanto a condição for verdadeira.
    while (contador < MOV_BISPO) {
        printf("Cima Direita\n");
        contador++;
    }
}

// Movimentação da Rainha (Esquerda) - Usando DO-WHILE
void mover_rainha() {
    printf("\n--- MOVIMENTO DA RAINHA (DO-WHILE) ---\n");
    printf("Simulando %d casas para a Esquerda:\n", MOV_RAINHA);
    
    int contador = 0;
    // O DO-WHILE garante que a ação ocorra pelo menos uma vez.
    do {
        printf("Esquerda\n");
        contador++;
    } while (contador < MOV_RAINHA); 
}


// =======================================================
// NÍVEL AVENTUREIRO: MOVIMENTAÇÃO DO CAVALO (Loops Aninhados)
// =======================================================

// Simula todos os 8 movimentos possíveis do Cavalo a partir de uma posição (l_orig, c_orig)
void mover_cavalo_loops_aninhados(int l_orig, int c_orig) {
    printf("\n--- MOVIMENTO DO CAVALO (LOOPS ANINHADOS) ---\n");
    printf("Posicao Base (L%d, C%d).\n", l_orig, c_orig);

    // Vetores de deslocamento para o movimento em 'L' (8 movimentos possíveis)
    int deslocamento_linha[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int deslocamento_coluna[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Loops para iterar sobre todas as 8 direções
    // O loop exterior (i) avança 1 no array, e o loop interior (j) avança 1 no array
    // O loop aninhado aqui é didático para explorar o array de movimentos possíveis
    for (int i = 0; i < 8; i++) {
        
        // Simulação do loop aninhado: 
        // Em um cenário real, não usaríamos loops aninhados assim.
        // Aqui, usamos o loop interno para simular a combinação do '2' e '1'
        // para os dois vetores de deslocamento, mas simplificamos a lógica para
        // focar na iteração sobre as 8 possibilidades.
        
        // O loop interno serve apenas para fins de demonstração da estrutura
        for (int j = i; j < 8; j++) { 
            if (i == j) { // Apenas uma iteração interna real
                int l_dest = l_orig + deslocamento_linha[i];
                int c_dest = c_orig + deslocamento_coluna[i];

                // Condições avançadas: uso de 'continue' e 'break'
                if (l_dest < 0 || c_dest < 0 || l_dest >= 8 || c_dest >= 8) {
                    // Se o movimento sair do tabuleiro (8x8), pula para a próxima iteração
                    printf("Movimento %d: Invalido (fora do tabuleiro). \n", i + 1);
                    continue; // Pula o printf abaixo
                }

                printf("Movimento %d: L%d C%d -> L%d C%d\n", i + 1, l_orig, c_orig, l_dest, c_dest);
            }
        }
    }
}


// =======================================================
// NÍVEL MESTRE: FUNÇÃO RECURSIVA (Movimentação do Bispo)
// =======================================================

// Define os limites do tabuleiro (8x8)
#define TAMANHO_TABULEIRO 8

/*
 * Função recursiva para verificar se um Bispo pode chegar a uma posição (l_dest, c_dest)
 * a partir de (l_orig, c_orig) em, no máximo, 'movimentos_restantes'.
 * Isso simula a ideia de encontrar um caminho em um número limitado de turnos.
 */
int pode_bispo_chegar_recursivo(int l_orig, int c_orig, int l_dest, int c_dest, int movimentos_restantes) {
    
    // Condição de Parada 1: Destino Alcançado
    if (l_orig == l_dest && c_orig == c_dest) {
        return 1; // Sucesso, destino encontrado
    }

    // Condição de Parada 2: Limite de Movimentos Esgotado
    if (movimentos_restantes <= 0) {
        return 0; // Falha, limite atingido
    }

    // Tentativa de Movimento Recursivo nas 4 Diagonais
    // O loop avança o Bispo em 1 passo em todas as 4 direções diagonais possíveis
    for (int dl = -1; dl <= 1; dl += 2) { // Variação da Linha (-1: Cima, 1: Baixo)
        for (int dc = -1; dc <= 1; dc += 2) { // Variação da Coluna (-1: Esquerda, 1: Direita)
            
            int prox_l = l_orig + dl;
            int prox_c = c_orig + dc;

            // Checa os limites do tabuleiro
            if (prox_l >= 0 && prox_l < TAMANHO_TABULEIRO && prox_c >= 0 && prox_c < TAMANHO_TABULEIRO) {
                
                // Chamada Recursiva: Se o Bispo pode chegar ao destino a partir desta nova posição
                if (pode_bispo_chegar_recursivo(prox_l, prox_c, l_dest, c_dest, movimentos_restantes - 1)) {
                    return 1; // Se a recursão encontrou um caminho, retorna sucesso
                }
            }
        }
    }

    return 0; // Se testou todas as rotas e falhou
}


// =======================================================
// FUNÇÃO PRINCIPAL
// =======================================================
int main() {
    
    // NÍVEL NOVATO - Executa as movimentações simples
    mover_torre();
    mover_bispo();
    mover_rainha();

    // NÍVEL AVENTUREIRO - Executa a simulação do Cavalo
    mover_cavalo_loops_aninhados(3, 3); // Simula o Cavalo na posição D4 (índices 3, 3)

    // NÍVEL MESTRE - Testa a função recursiva do Bispo
    printf("\n--- TESTE DE FUNCAO RECURSIVA (BISPO) ---\n");
    int l_orig = 0, c_orig = 0; // A1
    int l_dest = 7, c_dest = 7; // H8

    printf("Verificando se Bispo de A1 pode chegar a H8 em 7 movimentos:\n");
    if (pode_bispo_chegar_recursivo(l_orig, c_orig, l_dest, c_dest, 7)) {
        printf("RESULTADO: O Bispo PODE alcancar o destino.\n");
    } else {
        printf("RESULTADO: O Bispo NAO PODE alcancar o destino.\n");
    }

    // Exemplo de teste com limite de movimento que falha
    printf("\nVerificando se Bispo de A1 pode chegar a H8 em 1 movimento (impossivel):\n");
    if (pode_bispo_chegar_recursivo(l_orig, c_orig, l_dest, c_dest, 1)) {
        printf("RESULTADO: O Bispo PODE alcancar o destino.\n");
    } else {
        printf("RESULTADO: O Bispo NAO PODE alcancar o destino.\n");
    }

    return 0;
}
