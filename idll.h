/*
** file: idll.h
**
** Integer Double Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2023-24
**
** 
*/

// Defina:
//   Em idll.h as classes da estrutura de dados
//   Em idll.cpp a implementação dos métodos das classes da estrutura de dados
// Não altere o nome das classes nem dos atributos obrigatórios!

// definir nó
struct INode {
   // atributos obrigatórios
   int item;             // informação em cada nó
   // outros atributos e métodos (protótipos) livres
   INode* next;
   INode* before;
   
   INode(int valor) {
       item = valor;
       next = nullptr;
       before = nullptr;
   }

};
// definir lista duplamente ligada
class IDll {
public:
   // atributos obrigatórios
   int n;                // dimensão atual da lista
   // outros atributos e métodos (protótipos) livres
   INode* first;
   INode* last;
   
    ///////////////// Inserçoes
   // Inserção de um valor no ultimo Node
   void insertLast(int valor);
   // Inserção de um valor no primeiro Node
   void insertFirst(int valor);
   ///////////////// Eliminaçoes
   // Eliminaçao do ultimo valor na lista
   void deleteLast();
   // Eliminaçao do primeiro valor na lista
   void deleteFirst();
   // Eleminaçao de um Node especifico;
   void deleteAt(int index);
   //Eleminaçao de todos os elementos na lista
   void clear();
   ////////////////// Outros
   // Procura da existencia de um node com valor especifico
   void nodeCheck(int valor);
   //Amostra do ultimo valor na lista
   void printLast();
   //Amostra do primeiro valor na lista
   void printFirst();
   //Amostra do valor atual de n
   void printN();
   //Amostra de todos os valores
   void print();
   //Inverçao de elementos
   void invertNodes(int x,int y);
   //Seleção de valor maximo
   void max();
   //Copia de Node em posicao especifco
   INode* getNodeAt(int posicao);
public:
 //Destructor e Construtor
   ~IDll();
   IDll();

};

// EOF

