#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include<string>

using std::string;
struct Node{
    Node* esquerda;
    Node* direita;
    char letra;
    string codigo;

};

class Arvore{
    private:
        Node* raiz;
        int elementos = 0;
        void imprimePreOrdem(Node* node);

    public:
        Arvore();
        void construirArvore();
        Node* adicionaNo(char codigo, Node* node);
        void imprimeArvore();
        Node* getRaiz();
        Node* percorreArvore(char codigo, Node* node);
        void decodifica(string codigoLetra);
        
  
};

#endif