//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220

#include "NodeT.h"
class BST{
	public:
		BST();
		~BST();
		void add(int cantidad, string ip, long numIp);
    NodeT* getRoot(){return this->root;}
    void top5();
  
	private:
    void topHelper(NodeT* r, int& contador);
		NodeT *root;	
		void destruye(NodeT *r);
};


BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye(root);
}
//Complejidad: O(n)
void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}
 
// Complejidad: O(logn) 
// Mete un nodo con la cantidad e ip al BST
void BST::add(int cantidad, string ip, long numIp){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
    father = curr;
		if (curr->getCant() == cantidad){
			curr = (curr->getNumIp() < numIp) ? curr->getLeft() : curr->getRight();
		}
    else{
		curr = (curr->getCant() > cantidad) ? curr->getLeft() : curr->getRight();
    }
	}
	if (father == nullptr){
		root = new NodeT(cantidad, ip);
	}
	else{
    if (father->getCant() == cantidad){
			(father->getNumIp() < numIp) ? father->setLeft(new NodeT(cantidad, ip)) : father->setRight(new NodeT(cantidad, ip));
		}
    else{ 
      (father->getCant() > cantidad) ? father->setLeft(new NodeT(cantidad, ip)) : father->setRight(new NodeT(cantidad, ip));
    }
		
	}

}

// Llama una funcion recursiva que imprime los 5 valores que estan mas hacia la derecha
//Complejidad: O(logn)
void BST:: top5(){
  int contador = 1;
  topHelper(root, contador);
}

// Imprime los valores viajando por el arbol en modo Inorder inverso, imprimiendo valores mientras el contador sea menor que 6
//Complejidad: O(logn)
void BST:: topHelper(NodeT* r, int& contador){
  if(!r) return;

  topHelper(r->getRight(), contador);
  if(contador < 6) cout <<"Numero " << contador<< " con " << r->getCant() << " accesos: "<< r->getIp()<<endl;
    contador++;
  topHelper(r->getLeft(), contador);
}