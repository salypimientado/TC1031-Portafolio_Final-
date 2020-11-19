//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

// Convierte una ip a un string excluyendo el puerto
// Complejidad: O(n)
string ipSinPuerto(string ip){
  string result;
  int i = 0;
  while(ip[i] != ':'){
    result = result + ip[i];
    i++;
  }
  return result;
}

int main() {
  // Declaracion de variables y lectura de archivo
  ifstream arch;
  arch.open("bitacora.txt");

  int n, m; 
  vector<string> max;
  int outMax;
  
  string ipin, ipout, x;
  unordered_map<string,pair<int,int>> mapa;
  arch >> n >> m;
  vector<vector<int>> listAdj(n);
  for(int i = 0; i< n; i++){
      arch >> ipin;
      mapa[ipin] = make_pair(i, 0); 
  }
  for(int i = 0; i< m; i++){
      arch >> x >> x >> x >> ipout >> ipin;
      getline(arch,x); // Eliminación de datos innecesarios
      // Agrega el elemento key de la lista de adyacencia al vector
      listAdj[mapa[ipSinPuerto(ipout)].first].push_back(mapa[ipSinPuerto(ipin)].first);
      mapa[ipSinPuerto(ipout)] =make_pair(mapa[ipSinPuerto(ipout)].first,mapa[ipSinPuerto(ipout)].second+1); 
       //cout<<i<< " "<<mapa[ipSinPuerto(ipout)].second<< " "<< outMax<<endl;
      // Guarda el nodo en el vector si tiene el mismo fanout que el maximo o sustituye el vector si es mayor al fanout
      if(mapa[ipSinPuerto(ipout)].second>= outMax){
          if(mapa[ipSinPuerto(ipout)].second== outMax){
            max.push_back(ipSinPuerto(ipout));
          }
          else{
              outMax = mapa[ipSinPuerto(ipout)].second;
            max = {ipSinPuerto(ipout)};
          }
      }
  }
  
  cout<<"Los nodos con mas posibilidad de ser el botmaster son los siguientes con "<<outMax << " de fanout: "<<endl;
  for(auto i:max){
      cout<<i<<endl;
  }
}
