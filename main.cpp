#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Vertice{
    public:
    int value;
    bool visitado = false;

    Vertice(int v){
        value = v;
    }
};

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
    list<Vertice> ordenacaoTopologica();
    void visite(Vertice& v, list<Vertice>* o);
    int getSize(){
        return V;
    }
    Vertices* getList(){
        return adj;
    }

    Vertices getVertices(){
        return vertices;
    }

    Vertices getAdjacentes(int n){
        return adj[n];
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

void Grafo::visite(Vertice& v, list<Vertice>* o){
    if(!v.visitado){
        v.visitado = true;
        Vertices adjacents = getAdjacentes(v.value);

        for(auto it=adjacents.begin(); it!=adjacents.end(); it++){ // Para cada vertice V adjacente a v...
            Vertice V(it->first);
            visite(V, o);
        }
        o->push_front(V); // Adicione V ao inicio da lista o
    }
}

list<Vertice> Grafo::ordenacaoTopologica(){
    list<Vertice> * o;
    o = new list<Vertice>();
    Vertices* adj = getList();
    for(int i=0; i<getSize(); i++){ // Para cada vertice em adj...
        Vertices* vList = getList();
        bool depends = false;

        for(int j=0; j<getSize(); j++){ // se vertice for encontrado em algum elemento da lista, é dependente...
            if(vList[j].find(i) != vList[j].end()) depends = true;
        }

        if(!depends){
            Vertice vertice(i);
            visite(vertice, o);
        }
        
    }
    return *o;
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

    Grafo::Vertices* vList = g.getList();
    int evento = 2;
    // Para cada i sendo um vértice que depende de vertices[evento]
    // Print vertice
    cout << "'" << g.getVertices()[evento] << "' é necessário para:\n";
    for(auto i=vList[evento].begin(); i!=vList[evento].end(); i++){
        cout << g.getVertices()[i->first] << "\n";
    }

    list<Vertice> listFinal = g.ordenacaoTopologica();
    cout << listFinal.front().value;

    for(auto it = listFinal.begin(); it != listFinal.end(); ++it){
        cout << it->value << " ";
    }
    return 0;
}