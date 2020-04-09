#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<char,int> pairs;

vector<pairs> sortMenorMayor(vector<pairs> vec){
    sort(vec.begin(),vec.end(),
         [](const pairs& l,const pairs& r){
                 return l.second < r.second;
         });
    return vec;
}

vector<pairs> sortMayorMenor(vector<pairs> vec){
    sort(vec.begin(),vec.end(),
         [](const pairs& l,const pairs& r){
                 return l.second > r.second;
         });
    return vec;
}

vector<pairs> esta_ordenado(vector<int> cantidad_imprimir, const vector<pairs>& parejas){
    int i = 0, check = 0;
    vector<pairs> resultados;
    while ((i < cantidad_imprimir.size()-1) && (check == 0)) {
        if (cantidad_imprimir[i] > cantidad_imprimir[i+1])
            check = 1;
        i++;
    }
    if(check == 1)
        resultados = sortMayorMenor(parejas);
    else
        resultados = sortMenorMayor(parejas);
    return resultados;
}

void function(string num){
    getline(cin,num);
    int cases = stoi(num);
    string letras;
    string letras_orden;
        do{
            string space;
            getline(cin,space);
            getline(cin, letras);
            getline(cin, letras_orden);

            vector<pairs> parejas;
            while (!letras.empty()) {
                pairs p;
                char letra = letras[0];
                int contador = 1;
                for (int i = 1; i < letras.size(); i++) {
                    if (letras[i] == letra) {
                        contador++;
                        letras.erase(letras.begin()+i);
                        i--;
                    }
                }
                p.first=letra; p.second=contador;
                parejas.push_back(p);
                letras.erase(letras.begin());
            }

            vector<int> cantidad_imprimir;
            while (!letras_orden.empty()) {
                char letra = letras_orden[0];
                int contador = 1;
                for (int i = 1; i < letras_orden.size(); i++) {
                    if (letras_orden[i] == letra) {
                        contador++;
                        letras_orden.erase(letras_orden.begin()+i);
                        i--;
                    }
                }
                cantidad_imprimir.push_back(contador);
                letras_orden.erase(letras_orden.begin());
            }

            vector<pairs> resultados = esta_ordenado(cantidad_imprimir,parejas);
            for(int i=0; i<cantidad_imprimir.size();i++){
                pairs p = resultados[i];
                int cant = cantidad_imprimir[i];
                char letter = p.first;
                while(cant--){
                    cout<<letter;
                }
            }

            if(cases>1){
                cout << "\n" << endl;
            }
            else
                cout << "\n";
        }while(cases-- && cases!=0);
}

int main() {
    string num;
    function(num);
    return 0;
}

