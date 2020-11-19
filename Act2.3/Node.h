//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220
template<class T>
class Node{
  public:
  Node(T data,Node<T>* prev, Node<T>* next);
  Node(T data);
  T getData();
  void setData(T data);
  Node<T>* getNext();
  void setNext(Node<T>* next);
  void setPrev(Node<T>* prev);
  Node<T>* getPrev();
  


  private:
  Node<T>* next;
  Node<T>* prev;
  T data;
};

// O(1)
// Constructor
template<class T>
Node<T> :: Node(T data){
  this->data = data;
  next = nullptr;
  prev = nullptr;
}

// O(1)
// Constructor
template<class T>
Node<T> :: Node(T data,Node<T>* prev, Node<T>* next){
this->data = data;
this->prev = prev;
this->next = next;
}
// O(1)
// Regresa el contenido del nodo
template <class T>
T Node<T> :: getData(){
  return this->data;
}
// O(1)
// Asigna el contenido al nodo
template <class T>
void Node<T> :: setData(T data){
  this->data = data;
}
// O(1)
// Asigna el siguiente nodo al nodo
template <class T>
void Node<T> :: setNext(Node<T>* next){
  this->next = next;
}
// O(1)
// Regresa el proximo nodo
template <class T>
Node<T>* Node<T> :: getNext(){
  return this->next;
}
// O(1)
// Asigna el nodo previo
template <class T>
void Node<T> :: setPrev(Node<T>* prev){
  this->prev = prev;
}
// O(1)
// Regresa el nodo previo
template <class T>
Node<T>* Node<T> :: getPrev(){
  return this->prev;
}