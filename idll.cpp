/*
** file: idll.cpp
**
** Integer Double Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2023-24
**
** Aluno: 2201211 - Henrique Alexandre Cortez Melo
*/

// Defina:
//   Em idll.h as classes da estrutura de dados
//   Em idll.cpp a implementação dos métodos das classes da estrutura de dados

#include "idll.h"
#include <iostream>
using namespace std;

// Construtor e destrutor

IDll::IDll() : n(0),first(nullptr),last(nullptr) {
}

IDll::~IDll() {}
///////////////// Inserçoes
void IDll::insertLast(int valor) {
    //Criaçao novo node
    INode* newNode = new INode(valor);
    //Check se a lis ta esta vazia
    if(last == nullptr && first == nullptr){
       last = first = newNode;
   }
   else {
        //Insercao
       last->next = newNode;
       newNode->before = last;
       last = newNode;
   }
   n++;
}

void IDll::insertFirst(int valor) {
    //Criaçao novo node
    INode* newNode = new INode(valor);
    //Check se a lis ta esta vazia
    if(last == nullptr && first == nullptr){
       last = first = newNode;
    } else {
        //Insercao
        newNode-> next = first;
        
        if(first !=nullptr) {
            first ->before = newNode;
        }
        first = newNode;
    }
    //Aumentar o tamanho da lista
    n++;
}

//////////////// Eliminações
void IDll::deleteLast() {
    //Verificação se a lista está vazia
    if (first == nullptr && last == nullptr) {
    cout << "Comando delete_end: Lista vazia!\n";
    return;
    }
    //Verificaçao se existe apenas um Node
    if (first == last) {
        delete first;
        last = first = nullptr;
        n = 0;
        return;
    }
    //Elliminar ultimo
    INode* temp = last -> before;
    temp -> next = nullptr;
    delete last;
    last = temp;
    n--;
}

void IDll::deleteFirst() {
    //Verificação se a lista está vazia
    if (first == nullptr) {
        cout << "Comando delete_0: Lista vazia!\n";
        return;
        
    }
    //Verificaçao se existe apenas um Node
    if (first == last) {
        delete first;
        last = first = nullptr;
        n = 0;
        return;
    }
     //Eliminar primeiro
    INode* temp = first;
    first = first->next;
    first->before = nullptr;
    delete temp;
    n--;
}

void IDll::deleteAt(int posicao) {
    //Verificar se caso invalido
    if ( posicao < 0 || posicao >= n) {
        cout << "Comando delete_pos: Posicao invalida!\n";
        return;
    }
    //percorer a lista
    INode* current = first;
    for(int temp = 0; temp < posicao; temp++) {
        current = current->next;
    }
    if (current == last) deleteLast();
    else if (current == first) deleteFirst();
    else {
        //Eliminacao
        n--;
        current->before->next = current->next;
        current->next->before = current->before;
        delete current;
    }
    
}

void IDll::clear() {
    //Verificaçao se lista vazia
    if(last == nullptr && first == nullptr) {
        cout <<"Comando clear: Lista vazia!\n";
        return;
    }
    while (first != nullptr) {
        INode* temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
    n = 0;
}


//////////////////// Outros
void IDll::nodeCheck(int valor){
    //Verificação da posição onde procuramos atualmente
    int position = 0;
    //Começar pelo inicio da lista
    INode* current = first;
    for(; current != nullptr; current = current -> next, position++){
        if(current->item == valor) {
            cout << "Item " << valor << " na posicao " << position << "\n";
            return;
        }
    }
    cout << "Item " << valor << "nao encontrado\n";
}

void IDll::print() {
    //Verificaçao se lista vazia
    if(first ==nullptr && last == nullptr) {
        cout << "Comando print: Lista vazia!\n";
        return;
    }
    //Imprimir primeiro Node na lista
    cout << "Lista= " <<first->item;
    // Imprimir o resto da lista
    for(INode* current = first -> next; current != nullptr; current = current->next){
        cout <<" "<< current->item;
    }
    cout << endl;
}

void IDll::printLast() {
    //Verificaçao se lista vazia
    if(last == nullptr) {
        cout << "Lista vazia!\n";
    }
    //Impressao do ultimo elemento
    if(last != nullptr) {
        cout << "Lista(end)= " << last->item <<"\n";
    }
}

void IDll::printFirst() {
    //Verificaçao se lista vazia
    if(first == nullptr) {
        cout << "Lista vazia!\n";
    }
    //Impressao de primeiro item
    if(first != nullptr) {
        cout << "Lista(0)= " << first->item <<"\n";
    }
}

void IDll::printN() {
    cout <<"Lista tem " <<n<< " itens\n";
}

void IDll::max() {
    //Verificaçao se lista vazia
    if (first == nullptr && last == nullptr) {
        cout << "lista vazia\n";
        return;
    }
    // Variaveis para guardar o valor maximo e o seu index
    int indexMax = 0;
    int index = 0;
    int maximum = first ->item;
    
    //Loop que atravesa a lista
    for(INode* current = first; current != nullptr; current = current -> next) {
        // Actualizaçao do valor maximo
        if(current->item > maximum) {
            indexMax = index;
            maximum = current ->item;
        }
        index++;
    }
    cout << "Max Item " <<maximum<<" na posicao "<<indexMax<<"\n";
    
}

INode* IDll::getNodeAt(int posicao) {
    INode* node = first;
    //Ciclo até encontrar Node
    for (int i = 0; node != nullptr && i < posicao; i++) {
        node = node->next;
    }
    return node;
}

void IDll::invertNodes(int x, int y) {
    //Verificaçao se posiçoes invalidas
    if(x < 0 || y < 0 || x >= n || y >= n || x >= y ) {
        cout << "Posicoes invalidas\n";
        return;
    }
    //Verificaçao se lista vazia
    if (first == nullptr && last == nullptr) {
        cout << "Lista vazia\n";
        return;
    }
    // Selecionar os Nodes na posições escolhidas
    INode* currentX = getNodeAt(x);
    INode* currentY = getNodeAt(y);
    
    //Ciclo até o encontro de pointers
    while(currentX != currentY && currentX->before != currentY) {
        //Mudança dos items
        int temp = currentX -> item;
        currentX -> item = currentY -> item;
        currentY ->item = temp;
        currentX = currentX -> next;
        currentY = currentY -> before;
        
    }
    
    
    
}





// EOF

