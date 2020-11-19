//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220
#include "Node.h"

template<class T>
class DoublyLinkedList{
  public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  DoublyLinkedList(Node<T>* head);

  void sort();
  Node<T>* mergeSort(Node<T>* head);
  Node<T>* merge(Node<T>* p1, Node<T>* p2);

  void push_back(T data);
  void print();
  void operator +=(T data);

  void setHead(Node<T>* head);
  void rangeSearch(int min, int max);
  int searchMin(long ip);
  int searchMax(long ip);

  int getSize(){return size;}
  Node<T>* getHead(){return head;}
  Node<T>* getTail(){return tail;}

  private:
  Node<T>* head;
  Node<T>* tail;
  int size;
};
// O(1)
// Constructor
template<class T>
DoublyLinkedList<T> :: DoublyLinkedList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}
// O(n)
// Destructor
template<class T>
DoublyLinkedList<T> :: ~DoublyLinkedList(){
  while(head){
    tail = head->getNext();
    delete head;
    head = tail;
  }
}
// O(n)
// Constructor que encuentra el tail con la head
template<class T>
DoublyLinkedList<T> :: DoublyLinkedList(Node<T>* head){
  this->head = head;
  tail = head;
  size = 1;
  while(tail->getNext()) {
    tail = tail->getNext();
    size++;
  }
}
// O(nlogn)
// Ordena una lista doblemente encadenada
template<class T>
void DoublyLinkedList<T>:: sort(){
  head = mergeSort(head);
}
// O(nlogn)
// Ordena una lista doblemente encadenada
template<class T>
Node<T>* DoublyLinkedList<T>:: mergeSort(Node<T>* head){
  if(!head || !head->getNext()) {
    return head;
    }
  Node<T>* h2 = head;
  Node<T>* fast = h2;
   
  // el fast se mueve dos cada vez y el h2 uno, h2 siempre queda en el medio
  while(fast && fast->getNext()){ 
    fast = fast->getNext()->getNext();
    h2 = h2->getNext();
  }
  h2->getPrev()->setNext(nullptr);
  h2->setPrev(nullptr);
  
  head = mergeSort(head);
  h2 = mergeSort(h2);
  return merge(head,h2);
}
// O(n)
// Junta dos listas encadenadas ordenadas
template<class T>
Node<T>* DoublyLinkedList<T>:: merge(Node<T>* p1, Node<T>* p2){
  if(!p1) return p2;
  if(!p2) return p1;

  Node<T>* first;

  if(p1->getData().ipKey<= p2->getData().ipKey){
  first = p1;
  p1 = p1->getNext();
  first->setNext(nullptr);
  }
  else{
  first = p2;
  p2 = p2->getNext();
  first->setNext(nullptr);
  }

  Node<T>* temp1 = first;

  while(p1&&p2){
    if(p1->getData().ipKey<= p2->getData().ipKey){
      temp1->setNext(p1);
      p1 = p1->getNext();
      temp1->getNext()->setPrev(temp1);
      temp1 = temp1->getNext();
    }
    else{
      temp1->setNext(p2);
      p2 = p2->getNext();
      temp1->getNext()->setPrev(temp1);
      temp1 = temp1->getNext();
    }
  }
  if(!p1){
    temp1->setNext(p2);
    temp1->getNext()->setPrev(temp1);
  }
  else if(!p2){
    temp1->setNext(p1);
    temp1->getNext()->setPrev(temp1);
  }
  return first;
}
// O(n)
// Despliega la lista (Nada mas con cosas que tengan << sobrecargado)
template<class T>
void DoublyLinkedList<T> :: print(){
  Node<T>* temp = head;
  while(temp){
    std::cout<<temp->getData()<<std::endl;
    temp = temp->getNext();
  }
  std::cout<< "Size: "<< size<< std::endl;
}
// O(1)
// Pone un valor al final de la lista
template<class T>
void  DoublyLinkedList<T> :: push_back(T data){
  if(head){
  tail->setNext(new Node<T>(data));
  tail->getNext()->setPrev(tail);
  tail = tail->getNext();
  }
  else{
    head = new Node<T>(data);
    tail = head;
  }
  size++;
}

// O(1)
// Llama el push_back con un operador
template<class T>
void  DoublyLinkedList<T> :: operator +=(T data){
  push_back(data);
}
// O(n)
// Despliega datos de un indice a otro
template<class T>
void  DoublyLinkedList<T> :: rangeSearch(int min, int max){
  Node<T>* p = head;
  for(int i=0; i < min; i++) p = p->getNext();

  while(min<=max){
    std::cout<< p->getData().mes<< " "<<p->getData().dia<< " "<<p->getData().hora<< " "<<p->getData().ip<<p->getData().rFalla<<std::endl;
    p = p->getNext();
    min++;
  }
}
// O(n)
// Encuentra el indice minimo de ip que se introduce
template<class T>
int  DoublyLinkedList<T> :: searchMin(long ip){
  Node<T>* p = head;
  long i = 0;
  while(p){
    if(p->getData().ipKey >= ip) return i;
    p=p->getNext();
    i++;
  }
  return 0;
}
// O(n)
// Encuentra el indice maximo que tenga la ip que se introduce
template<class T>
int  DoublyLinkedList<T> :: searchMax(long ip){
  Node<T>* p = head;
  long i = 0;
  while(p->getData().ipKey <= ip){
    if(!p->getNext()) return size-1;
    p = p->getNext();
    i++;
  }
  if(p->getNext()){  // No sigue si encuentra el valor al final de la lista
    while(p->getNext()->getData().ipKey == ip){
      i++;
      p = p->getNext();
    }
  }
  return i-1;
}
