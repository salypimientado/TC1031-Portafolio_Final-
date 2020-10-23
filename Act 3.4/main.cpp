//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#include "BST.h"


// O(n)
// Convierte una ip a un int sin contar el puerto
long ipToLong(string ip){
  long i = 0, result = 0;

  while(ip[i] != ':'){
    if(ip[i] != '.'){

    result = (result*10) + (ip[i] - '0') % 48;
    }
    i++;
    //cout<< result<< ":" << ip[i] << endl;
  }
  return result;
}

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
  arch.open("bitacoraOrdenada.txt");
  
  long numIp, ipPrev , cantidadVecesQueAparece = 0;
  string ip, strIpPrev, d; // d = Dato Innecesario para la resolucion de este problema
  BST Arbol;

  // Lee el archivo y cuenta cantidad de accesos de cada IP utilizando add 
  while(!arch.eof()){
    arch>> d >> d >> d >> ip;
    getline(arch,d);
    numIp = ipToLong(ip);

    if(numIp != ipPrev){
      if(cantidadVecesQueAparece != 0) Arbol.add(cantidadVecesQueAparece, ipSinPuerto(strIpPrev), ipPrev);
      cantidadVecesQueAparece = 1;
    }
    else{
      cantidadVecesQueAparece++;
    }
    ipPrev = numIp;
    strIpPrev = ip;
    
  }
  Arbol.add(cantidadVecesQueAparece, ipSinPuerto(strIpPrev), ipPrev);

  cout << "Las 5 ips mas accesadas son las siguientes (en orden de mas accesos a menos accesos)"<<endl;

  cout<<endl;

  Arbol.top5();

  cout<<endl;

}
