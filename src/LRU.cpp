#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int lruPageFaults(int qtdQuadros, int qtdPaginas, int paginas[]) {
    list<int> quadros;                          // Lista para armazenar os quadros de memória
    unordered_map<int, list<int>::iterator> map; // Mapeamento de página para sua posição na lista
    int pageFaults = 0;                         // Contador de page faults

    for (int i = 0; i < qtdPaginas; i++) {
        int pagina = paginas[i];

        // Verifica se a página já está nos quadros
        if (map.find(pagina) != map.end()) {
            // Move a página para o início da lista (o mais recentemente usado)
            quadros.erase(map[pagina]);
        } else {
            // Verifica se a lista de quadros está cheia
            if (quadros.size() >= qtdQuadros) {
                // Remove a página mais antiga (a do final da lista)
                int paginaRemovida = quadros.back();
                quadros.pop_back();
                map.erase(paginaRemovida);
            }
            pageFaults++; // Incrementa o contador apenas quando ocorre um page fault
        }

        // Insere a página no início da lista (o mais recentemente usado)
        quadros.push_front(pagina);
        map[pagina] = quadros.begin();
    }

    return pageFaults;
}

int main() {
    int qtdQuadros, qtdPaginas;
    cin >> qtdQuadros >> qtdPaginas;

    int paginas[qtdPaginas];
    for (int i = 0; i < qtdPaginas; i++) {
        cin >> paginas[i];
    }

    int pageFaults = lruPageFaults(qtdQuadros, qtdPaginas, paginas);
    cout << pageFaults << endl;

    return 0;
}
