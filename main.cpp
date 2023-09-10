#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <map>

using namespace std;

// A classe abaixo define um grafo que tem como principal dado um conjunto de maps, que representam vértices adjacentes.
// Decidi criar um ponteiro de maps, pois assim posso atribuir uma chave a um evento do jogo. Ex: 2 = "Enter room".
class Grafo {
public:
    typedef map<int, std::string> Vertices;

private:
    int V;
    Vertices* adj;

    Vertices vertices;

public:
    Grafo(int V);
    void adicionarAresta(int v, int w);
    Vertices* getList(){
        return adj;
    }

    Vertices getVertices(){
        return vertices;
    }
};

Grafo::Grafo(int V) {
    this->V = V;
    
    // Aqui defino o que cada chave representa. São dados imutáveis.
    adj = new Vertices[V];

    vertices[0] = "Has Steal Skill";
    vertices[1] = "Steal first guard's key";
    vertices[2] = "Enter room";
    vertices[3] = "Steal second guard's key";
    vertices[4] = "Has inventory space";
    vertices[5] = "Take treasure from chest";
    vertices[6] = "Buy armor";
}

// Aqui adicionamos o evento w ao mapa que está na posição v do ponteiro adj, ou seja,
// o evento w agora depende do evento v (v agora tem w como vértice adjacente).
void Grafo::adicionarAresta(int v, int w) {
    adj[v][w] = getVertices()[w];
}

int main() {

    Grafo g(7);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 3);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(4, 5);
    g.adicionarAresta(3, 5);
    g.adicionarAresta(5, 6);
    g.adicionarAresta(4, 6);

    cout << '\n';

    Grafo::Vertices* list = g.getList();
    int evento = 0;
    // Para cada i sendo um vértice que depende de vertices[evento]
    // Print vertice
    cout << "'" << g.getVertices()[evento] << "' é necessário para:\n";
    for(auto i=list[evento].begin(); i!=list[evento].end(); i++){
        cout << g.getVertices()[i->first] << "\n";
    }

    return 0;
}