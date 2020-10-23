//Equipo 21
//Juan Pablo Salazar A01740200
//Melissa Vélez A00827220

class NodeT{
	public:
  NodeT(int cant, string ip){
    this->cant = cant;
    this->ip = ip;
  }
  void setLeft(NodeT* left) { this->left = left; } 
  NodeT* getLeft() { return this->left; }
  void setRight(NodeT* right) { this->right = right; } 
  NodeT* getRight() { return this->right; }
  int getCant() {  return this->cant; }
  string getIp() { return this->ip; }
  long getNumIp();
  friend ostream& operator<<(ostream& os, const NodeT& node){
    os<< node.ip<< ": "<< node.cant;
    return os;
  }

	private:
  int cant;
  string ip;
  NodeT* left;
  NodeT* right;
};

  // O(n)
  // Regresa la ip como long
long NodeT :: getNumIp(){
    long i = 0, result = 0;

    while(i < ip.size() && ip[i] != ':'){
      if(ip[i] != '.'){

      result = (result*10) + (ip[i] - '0') % 48;
      }
      i++;
      //cout<< result<< ":" << ip[i] << endl;
    }
    return result;
  }