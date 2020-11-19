//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220

#include <iostream>
#include <fstream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;

// Struct Datos para guardar objetos de cada dato en el archivo
struct Datos{
  Datos(){
    dia = 0;
    ipKey = 0;
    mes = "Jan";
    hora = "00:00:00";
    ip = "000:00:0000";
    rFalla = "Nada";
  }
  // O(1)
  Datos(long ipKey, string mes, int dia, string hora, string ip, string rFalla){
    this->ipKey = ipKey;
    this->hora = hora;
    this->dia = dia;
    this->mes = mes;
    this->ip = ip;
    this->rFalla = rFalla;
  }
  int dia;
  long ipKey;
  string mes, hora, ip,rFalla;
};

// O(n)
// Convierte una ip a un long
long ipToLong(string ip){
  int idx = 0;
  long datoFinal= 0, dato = 0;
  while (idx < ip.size()){
    if (ip[idx]!= '.' && ip[idx]!=':'){
      dato = dato*10 + ip[idx]-'0';
      }
      else{
        datoFinal = datoFinal*1000 + dato;
        dato = 0;
      }
      idx++;
    }
    datoFinal = datoFinal*10000 + dato;
    return datoFinal;
  }

int main() {
  DoublyLinkedList<Datos> lista;
  ifstream arch;
  arch.open("bitacora.txt");
  
  long dia, ipKey, min, max;
  string rFalla, ip, mes, hora;
  while(!arch.eof()){
    arch>> mes>> dia>>hora>> ip;
    getline(arch,rFalla);
    ipKey = ipToLong(ip);
    Datos dato(ipKey, mes, dia, hora, ip, rFalla);
    lista += dato;
  }
  lista.sort();

  cout << "BUSQUEDA DE INFORMACION POR IP\nPrimer IP: ";
  cin >> ip;
  cout << "Segunda IP: ";
  cin >> mes;  // reusamos variables para ahorrar espacio

  dia = ipToLong(ip);
  ipKey = ipToLong(mes);
  min = (dia < ipKey) ? dia: ipKey;
  max = (dia < ipKey) ? ipKey:dia;
  min = lista.searchMin(min);
  max = lista.searchMax(max);
  lista.rangeSearch(min,max);
  cout<< "Escriba el nombre del archivo en el que desea los datos ordenados: ";
  cin >> ip; 
  ip.append(".txt");
  ofstream out(ip);
  Node<Datos>* temp = lista.getHead();
  while(temp){
    out<< temp->getData().mes<< " "<<temp->getData().dia<< " "<<temp->getData().hora<< " "<<temp->getData().ip<<temp->getData().rFalla<<std::endl;
    temp = temp->getNext();
  }
}