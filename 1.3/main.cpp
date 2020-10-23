// Actividad 1.3
// Entregado 11/09/2020
// Equipo #21
// Juan Pablo Salazar A01740200
// Valeria Conde A01281637
// Melissa Vélez Martínez A00827220

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Struct Datos para guardar objetos de cada dato en el archivo
// O(1)
struct Datos{
  
  Datos(int fecha, string mes, int dia, string hora, string ip, string rFalla){
    this->fecha = fecha;
    this->hora = hora;
    this->dia = dia;
    this->mes = mes;
    this->ip = ip;
    this->rFalla = rFalla;
  }
  int fecha,dia;
  string mes, hora, ip,rFalla;
};

// funcion para convertir el mes al formato numerico
// O(1)
int monthInNum(string mes){
  if(mes == "Jan") return 1;
  if(mes == "Feb") return 2;
  if(mes == "Mar") return 3;
  if(mes == "Apr") return 4;
  if(mes == "May") return 5;
  if(mes == "Jun") return 6;
  if(mes == "Jul") return 7;
  if(mes == "Aug") return 8;
  if(mes == "Sep") return 9;
  if(mes == "Oct") return 10;
  if(mes == "Nov") return 11;
  if(mes == "Dec") return 12;
  return 0;
}

// Busca partiendo el area de busqueda a la mitad cada iteracion
// O(logn)
int binSearch(vector<Datos> vDatos, int ind, int mode) {
        if(mode == 2) ind++;
        int left = 0, right = vDatos.size()-1, mid;
        while(left<right){
            mid = (left + right) /2;
            if (vDatos[mid].fecha >= ind){
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        if(mode==2) return left-1;
        return left;
    }
    
// Ordena la bitacora y deja buscar en ella
int main() {
  //abre el archivo
  ifstream arch;
  arch.open("bitacora.txt");
  
  int dia, fecha, min, max;
  string rFalla, ip, mes, hora;
  bool rep = true, save;
  vector<Datos> vDatos;
  char v;
  
  // Lee el archivo y crea un vector con objetos de tipo Datos
  while(!arch.eof()){
    arch>> mes>> dia>>hora>> ip;
    getline(arch,rFalla);
    fecha = monthInNum(mes)*100 + dia;
    Datos dato(fecha, mes, dia, hora, ip, rFalla);
    vDatos.push_back(dato);
  }
  cout<< vDatos.size()<< " datos size "<< endl;

  // ordena datos por fecha
  //O(nlogn)
  sort(vDatos.begin(), vDatos.end(), [](const Datos& lhs, const Datos& rhs) {
    return lhs.fecha < rhs.fecha;
  });

// repite mientras el usuario decida seguir buscando
while(rep){
  // pide al usuario fechas minima y maxima
  cout << "BUSQUEDA DE INFORMACION POR FECHA\nFecha de inicio (Mes y dia): ";
  cin >> mes >> dia;
  min = monthInNum(mes)*100 + dia;
  cout << "Fecha de fin (Mes y dia): ";
  cin >> mes >> dia;              
  max = monthInNum(mes)*100 + dia;

  min = binSearch(vDatos,min,0);
  max = binSearch(vDatos,max,2);

  // despliega los registros entre esas fechas
  for(int i = min; i<= max; i++){
  cout<<  vDatos[i].mes << " "<< vDatos[i].dia<< " "<< vDatos[i].hora << " "<< vDatos[i].ip<< vDatos[i].rFalla<<endl;
  }

  // genera un archivo con los registros solicitados
  cout<< "Desea guardar la busqueda? (escriba S para si y N para no)"<<endl;
  cin>>v;
  if(v == 'S'){
    cout<< "Escriba el nombre del archivo que desea: ";
    cin >> ip;        // reusamos variable ip para guardar espacio
    ip.append(".txt");
    ofstream out(ip);
    for (int i = min; i<= max; i++) {       // escribe los datos al archivo
    out<<  vDatos[i].mes << " "<< vDatos[i].dia<< " "<< vDatos[i].hora << " "<< vDatos[i].ip<< vDatos[i].rFalla<<endl;
    }
    out.close();
  }

  cout<< "Desea volver a buscar? (escriba S para si y N para no)" << endl;
  cin >> v;
  rep = (v == 'S' ? 1:0);
}

cout<< "Escriba el nombre del archivo en el que desea la lista ordenada: ";
cin >> ip; 
ip.append(".txt");
ofstream out(ip);
for (int i = 0; i<= vDatos.size()-1; i++) {       // escribe los datos al archivo
    out<<  vDatos[i].mes << " "<< vDatos[i].dia<< " "<< vDatos[i].hora << " "<< vDatos[i].ip<< vDatos[i].rFalla<<endl;
    }
}