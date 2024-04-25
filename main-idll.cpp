/*
** file: main-idll.cpp
**
** Integer Double Linked List
** UC: 21046 - EDAF @ UAb
** e-fólio A 2023-24
**
** Aluno: 2201211 - Henrique Alexandre Cortez Melo
*/

// Defina neste ficheiro:
//   A entrada/saída de dados
//   As instâncias da classe da estrutura de dados
//   A implementação dos comandos através dos métodos da classe
//   Código auxiliar
//   Não utilize variáveis globais!

#include <iostream>
#include <sstream>
#include "idll.h"
using namespace std;


int main() {
    IDll list;  
    string line;  

    //verificar cada linha
    while (getline(cin, line)) {
        //Check se a linha esta vazia/ se a linha é um comentario
        if (line.empty()) continue; 
        if(line[0] == '#') continue;  
        
        // Ler comandos
        istringstream stream(line);
        string command;
        stream >> command;  

        // Executar funções de acordo com os metodos disponiveis
        
        if (command == "insert_0") {
            int valor;
            while (stream >> valor) {
                list.insertFirst(valor);
            }
        } else if (command == "insert_end") {
            int valor;
            while (stream >> valor) {
                list.insertLast(valor);
            }
        } else if (command == "print_0") {
            list.printFirst();
        } else if (command == "print_end") {
            list.printLast();
        } else if (command == "print") {
            list.print();
        } else if (command == "delete_0") {
            list.deleteFirst();
        } else if (command == "delete_end") {
            list.deleteLast();
        } else if (command == "dim") {
            list.printN();
        } else if (command == "clear") {
            list.clear();
        } else if (command == "find") {
            int valor;
            stream >> valor;
            list.nodeCheck(valor);
        } else if (command == "find_max") {
            list.max();
        } else if (command == "delete_pos") {
            int position;
            stream >> position;
            list.deleteAt(position);
        } else if (command == "invert_range") {
            int x, y;
            stream >> x >> y;
            list.invertNodes(x, y);
        }
    }

    return 0;
}

// EOF

