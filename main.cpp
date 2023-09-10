#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <map>

using namespace std;

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
    adj = new Vertices[V];

    vertices[0] = "Has Steal Skill";
    vertices[1] = "Steal first guard's key";
    vertices[2] = "Enter room";
    vertices[3] = "Steal second guard's key";
    vertices[4] = "Has inventory space";
    vertices[5] = "Take treasure from chest";
    vertices[6] = "Buy armor";
}

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

    // Para cada i sendo um vértice que depende de vertices[3]
    // Print vertice
    for(auto i=list[0].begin(); i!=list[0].end(); i++){
        cout << g.getVertices()[i->first] << "\n";
    }

    return 0;
}