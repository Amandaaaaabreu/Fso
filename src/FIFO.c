#include <stdio.h>

int main() {
    int num_quadros, num_referencias;
    int pagina_referenciada, i, j;
    int page_faults = 0;
    int *quadros;

    // Lê a quantidade de quadros e a quantidade de referências
    scanf("%d", &num_quadros);
    scanf("%d", &num_referencias);

    // Aloca espaço para os quadros na memória RAM
    quadros = (int *) malloc(num_quadros * sizeof(int));

    // Inicializa os quadros com -1 para indicar que estão vazios
    for (i = 0; i < num_quadros; i++) {
        quadros[i] = -1;
    }

    // Lê as referências às páginas e executa o algoritmo FIFO
    for (i = 0; i < num_referencias; i++) {
        scanf("%d", &pagina_referenciada);

        // Verifica se a página já está presente nos quadros
        int presente = 0;
        for (j = 0; j < num_quadros; j++) {
            if (quadros[j] == pagina_referenciada) {
                presente = 1;
                break;
            }
        }

        // Se a página não está presente, ocorreu um page fault
        if (!presente) {
            page_faults++;

            // Substitui a página mais antiga (primeiro a entrar) usando a política FIFO
            quadros[page_faults % num_quadros] = pagina_referenciada;
        }
    }

    // Libera a memória alocada para os quadros
    free(quadros);

    // Imprime a quantidade de page faults
    printf("%d\n", page_faults);

    return 0;
}