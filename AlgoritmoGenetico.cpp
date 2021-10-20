#include <time.h>
#include <iostream>
#include <random>
#include <vector>
#define _null NULL

using namespace std;

int Roleta(vector<float> fitnes);

int gerarAleatorio(int valorInicial, int valorFinal);

vector<float> somaCumulativa(vector<float> v);


int main(){
    // semente
    srand (static_cast <unsigned> (time(0)));

	int n=10, popSize=5;
    vector<vector<int>> populacao;
    vector<vector<int>> novaGeracao;
    vector<int> sort;
    vector<float> fitness;
    fitness.push_back(0.12);
    fitness.push_back(0.534);
    fitness.push_back(0.348);
    fitness.push_back(0.15);
    fitness.push_back(0.851);
    fitness.push_back(0.1523);
    vector<vector<int>> indCruza;
    int sorteado;
    int b = 20;
    vector<int> p, a;

    for(int i=0;i<n;i++){
        p.push_back(i+1);
        a.push_back(n-i);
    }

    vector<float> copfitness;
    for(int i=0;i<fitness.size();i++){
        copfitness.push_back(fitness[i]);
    }

    //cout << "sise copfitness: " << copfitness.size()/2 <<endl;

    
    for(int i=0;i<=copfitness.size()/2;i++){

        cout << "indo p/ Roleta: " << i << endl;
   
    		sorteado = Roleta(copfitness);
            sort.push_back(sorteado);
            copfitness.insert(copfitness.begin()+ sorteado,0);
            copfitness.erase(copfitness.begin()+ sorteado);
    		
    		sorteado = Roleta(copfitness);
            
            sort.push_back(sorteado);
            copfitness.insert(copfitness.begin() + sorteado,0);
            copfitness.erase(copfitness.begin()+ sorteado);
    		indCruza.push_back(sort);
            sort.clear(); 
    }

    for(int i=0;i<popSize;i++){    
    	cout << "Pai: " <<indCruza[i][0] << " Mãe: "<<indCruza[i][1]<< endl;

    }

}

/// realiza o sorteio dos valores passados
int Roleta(vector<float> fitnes){
    
    int sorteado;
    int p;
    vector<float> numerosDaSorte = somaCumulativa(fitnes);
    

	float random;
    random = numerosDaSorte.back();
    
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/random+1);
    cout <<  "valor r: " << r << endl;
    
	sorteado = -1;
    
	for(int i=0;i<numerosDaSorte.size();i++){
		if(numerosDaSorte[i] > r){
			sorteado = i;
			break;
		}
	}
    numerosDaSorte.clear();
    //numInt.clear();
    //cout << "sort "<< sorteado <<endl;
    return sorteado;

}

// constroi o range da roleta
vector<float> somaCumulativa(vector<float> v){
    
    vector<float> acumulacao;
    acumulacao.push_back(v[0]);
    for(int i=0; i<v.size()-1;i++){
        acumulacao.push_back(acumulacao[0+i]+v[1+i]);
    }
    return acumulacao;

}

// Referência https://www.cplusplus.com/reference/random/
int gerarAleatorio(int valorInicial, int valorFinal){
  random_device semente;
  default_random_engine gerador(semente());
  uniform_int_distribution<default_random_engine::result_type> intervalo(valorInicial, valorFinal); 

  return intervalo(gerador);
}