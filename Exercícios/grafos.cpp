#include <bits/stdc++.h>

// Atalhos
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define l length()
#define forn(i, n) for ( int i = 0; i < (n); ++i )
#define fornx(i, x, n) for ( int i = (x); i < (n); ++i )

using namespace std;

typedef struct Aresta{
		int origem;
    int destino;
    int peso;
}Aresta;

class Grafo {
   public:
  		virtual void adicionarAresta(int origem, int destino);
  		virtual void adicionarAresta(int origem, int destino, int peso);
  		virtual bool existeAresta(int origem, int destino);
  		// Grau do vértice = número de arestas incidentes (entrada e saída).
  		virtual int grauDoVertice(int vertice);
		virtual int numeroDeVertices();
  		// Retorna o número total de arestas no grafo.
        virtual int numeroDeArestas();
        virtual void setarPesoAresta(int origem, int destino, int peso);
        virtual Aresta* getArestas();
        virtual int* adjacentesDe(int vertice);
        virtual Aresta arestaEntre(int origem, int destino);
        
};

class MatrizAdj : public Grafo {
    int **matriz;
    int ARESTA_NULA = 0; // Indica que não exite uma aresta entre dois vértices.
    int nVertices;

    public:
  		// Construtor
        MatrizAdj(int nVertices) {
			this->nVertices = nVertices;
          	// Alocando a matriz dinamicamente
        	matriz = new int *[nVertices];
          	for(int i = 0; i < nVertices; i++) {
      			matriz[i] = new int[nVertices];
              	memset(matriz[i], ARESTA_NULA, nVertices);
            }
        }

  		void adicionarAresta(int origem, int destino) {
        	matriz[origem][destino] = 1;
        }

        void adicionarAresta(int origem, int destino, int peso) {
      		matriz[origem][destino] = peso;
    	}
  
  		bool existeAresta(int origem, int destino) {
          	if((origem > destino ? origem : destino) < numeroDeVertices()) {
              	if(matriz[origem][destino] != ARESTA_NULA)
                  	return true;
              	return false;
            }
          	return false;
        }
  
  		int grauDoVertice(int vertice) {
          	if(vertice < numeroDeVertices()) {
              	int grau = 0;
              	for(int i = 0; i < numeroDeVertices(); i++) {
                  	if(matriz[vertice][i] != ARESTA_NULA)
                      	grau++;
                }
              	for(int i = 0; i < numeroDeVertices(); i++) {
                  	if(matriz[i][vertice] != ARESTA_NULA)
                      	grau++;
                }
            }
          	return -1;
        }
  
  		int numeroDeVertices(){
        	return nVertices;
        }
  
  		int numeroDeArestas() {
          	int arestas = 0;
        	for(int i = 0; i < nVertices; ++i) {
              	for(int j = 0; j < nVertices; ++j) {
                	if(matriz[i][j] != ARESTA_NULA) {
                    	arestas++;
                    }
                }
            }
          	return arestas;
        }
  
  		void setarPesoAresta(int origem, int destino, int peso){
        	matriz[origem][destino] = peso;
        }
  
      	Aresta* getArestas() {
          	Aresta *arestas = new Aresta[numeroDeArestas()];
          	int count = 0;
          	for(int i = 0; i < nVertices; ++i) {
            	for(int j = 0; j < nVertices; ++j) {
                  	Aresta aresta;
                  	aresta.origem = i;
                    aresta.destino = j;
                  	aresta.peso = matriz[i][j];
                  	arestas[count] = aresta;
                  	count++;
                }
            }
          	return arestas;
        }
  		
  		int* adjacentesDe(int vertice){
        	int *adjacentes = new int[nVertices];
            memset(adjacentes,-1,sizeof adjacentes);
          	int contador_adjacentes = 0;
            for(int i = 0; i < nVertices; i++){
                if(matriz[vertice][i] != ARESTA_NULA){
                  	adjacentes[contador_adjacentes++] = i;
                }
            }
        	return adjacentes;
        }
  
        Aresta arestaEntre(int origem, int destino){
            Aresta a;
            a.origem = origem;
            a.destino = destino;
            a.peso = matriz[origem][destino];
          	return a;
        }
};

class ListaAdj : public Grafo{
	vector<Aresta> *lista;
  	int nVertices;
  	int nArestas = -1;
  
  	public:
        ListaAdj(int nVertices){
          	this->nVertices = nVertices;
          	lista = new vector<Aresta>[nVertices];
        }
  		void adicionarAresta(int origem, int destino) {
          	Aresta a;
            a.origem = origem;
            a.destino = destino;
            a.peso = 1;
        	lista[origem].pb(a);
        }

        void adicionarAresta(int origem, int destino, int peso) {
          	Aresta a;
            a.origem = origem;
            a.destino = destino;
            a.peso = peso;
      		lista[origem].pb(a);
    	}
  		bool existeAresta(int origem, int destino){
          	for(int i = 0; i < lista[origem].size(); i++){
              	if(lista[origem].at(i).destino == destino){
                  	return true;
                }
            }
            return false;
        }
  		int grauDoVertice(int vertice) {
          	 int grau = 0;
        	 for(int i = 0; i < nVertices; i++){
              	for(int j = 0; j < lista[i].size(); j++){
              		if(lista[i].at(j).destino == vertice)
                      grau++;
                    if(lista[i].at(j).origem == vertice)
                      grau++;
                }
             }
             return grau;
        }
		int numeroDeVertices(){
          	return nVertices;
        }
        int numeroDeArestas(){
          	if(nArestas == -1){
                int n_vertices = 0;
                for(int i = 0; i < nVertices; i++){
                    n_vertices+=lista[i].size();
                }
            }
			return nArestas;
        }
        void setarPesoAresta(int origem, int destino, int peso){
          	for(int i = 0; i < lista[origem].size(); i++){
              	if(lista[origem].at(i).destino == destino){
                  	lista[origem].at(i).peso = peso;
                }
            }
        }
        Aresta* getArestas(){
          	Aresta *arestas = new Aresta[numeroDeArestas()];
          	int contador_arestas = 0;
          	for(int i = 0; i < nVertices; i++){
              	for(int j = 0; j < lista[i].size(); j++){
                  	arestas[contador_arestas++] = lista[i].at(j);
                }
            }
          	return arestas;
        }
        int* adjacentesDe(int vertice){
            int *adjacentes = new int[lista[vertice].size()];
          	int contador_adjacentes = 0;
          	for(int i = 0; i < lista[vertice].size(); i++){
              	adjacentes[contador_adjacentes++] = lista[vertice].at(i).destino;
            }
            return adjacentes;
        }
        Aresta arestaEntre(int origem, int destino){
        	for(int i = 0; i < lista[origem].size(); i++){
              	if(lista[origem].at(i).destino == destino){
                  	return lista[origem].at(i);
                }
            }
          	Aresta nula;
            nula.origem = -1;
            nula.destino = -1;
            nula.peso = -1;
            return nula;
        }
};


class Algoritmos{
    Grafo *g;
    public:
    	// tipo 0 = Matriz de Adjacência, tipo 1 = Lista de Adjacência
  		Algoritmos(int tipo_representacao){
          	if(tipo_representacao == 0){
            	g = new MatrizAdj(1);
            }else{
                g = new ListaAdj(1);
            }
        }
  
  		// Busca em largura.
      	void BFS(int origem){
						
        }
  
  		void buscaEmProfundidadeVisita(int vertice, string* cor, int* d, int* f, Aresta* arestasFlorestaResultante, int tempo) {
          
        }
  
        // Busca em profundidade.
        void DFS(int origem) {

        }
  
        // Árvore geradora mínima utilizando algoritmo de Kruskall
        Aresta* agmUsandoKruskall() {

        }

        // Custo da árvore geradora
        double custoDaArvoreGeradora(Aresta *arestas) {

        }

        // Caminho mínimo - Dijkstra
        Aresta* dijkstra(int origem, int destino) {

        }
  
        Aresta* arestasDeArvore() { // precisa?

          }

        Aresta* arestasDeRetorno() { // precisa?

          }

        Aresta* arestasDeAvanco() { // precisa?

          }

        Aresta* arestasDeCruzamento() { // precisa?

          }
  
          
};

int main(){

    


    return 0;
}