//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

struct Entrada{
    Entrada(string dia, string mes, string hora, string razon){
        this->dia = dia;
        this->mes = mes;
        this->hora = hora;
        this->razon = razon;
    }
    
    // Complejidad: O(1)
    string toString(){
        return "El " + dia + " de " + mes + " a las " + hora + " con el motivo:"+ razon;
    }

    string mes, dia, hora, razon; 
};

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
  ifstream arch;
  arch.open("bitacoraACT5_2.txt");
  unordered_map<string, vector<Entrada>> mapa;
  string mes, dia, hora, razon, ip;

  while(!arch.eof()){
      arch>>mes>>dia>>hora>>ip;
      getline(arch,razon); 
      Entrada temp(dia,mes,hora,razon);
      ip = ipSinPuerto(ip);
      mapa[ip].push_back(temp);
  }

  do{
      cout<< "Introduzca una ip a acceder: ";
      cin>> ip;
      for(auto i: mapa[ip]){
      cout<<i.toString()<<endl;;
      }
      cout<< "Número de accesos de esta ip: " <<mapa[ip].size() << endl;
      cout<<"\n¿Desea seguir buscando? (y/n)"<<endl;
      cin>>razon;
  }while(razon != "n");
    return 0;
}

/*casos de prueba
60.101.181.6 6 veces
9.133.23.42 2 veces
89.217.55.221 14 veces
*/