#include "arvore.hpp"
#include <fstream> //ler arquivo

//https://gist.github.com/toboqus/def6a6915e4abd66e922
Arvore::Arvore(){
    this->raiz = new Node;
    raiz->letra = ' ';
    raiz->codigo = " ";
    raiz->esquerda = NULL;
    raiz->direita = NULL;
}

void Arvore::construirArvore(){
    std::ifstream codigoMorse;
    char entrada, codigo, letra = ' ';
    string codigoLetra;
    Node* posicao = raiz;
    codigoMorse.open("morse.txt");

    if (!codigoMorse) {
        std::cout << "Unable to open file morse.txt";
    }

    while(1){
        codigoMorse >> entrada;
        if(codigoMorse.eof()) {
            posicao->letra = letra;
            posicao->codigo = codigoLetra;
            break;
        }

        if(entrada != '.' && entrada != '-'){ 
            posicao->letra = letra;
            posicao->codigo = codigoLetra;
            codigoLetra.clear();
            letra = entrada;   
            posicao = raiz;
        }
        else{
            codigo = entrada;
            posicao = adicionaNo(codigo, posicao);
            codigoLetra.push_back(codigo);
        }
    }

    codigoMorse.close();
}
 
Node* Arvore::adicionaNo(char codigo, Node* node){
    if(codigo == '.'){
        if(node->esquerda != NULL){
            return node->esquerda;
		}else{
			node->esquerda = new Node;
			node->esquerda->esquerda = NULL;
			node->esquerda->direita = NULL;
            return node->esquerda;
		}
    }
    else if(codigo == '-'){
       if(node->direita != NULL){
           return node->direita;
		}else{
			node->direita = new Node;
			node->direita->direita = NULL;
			node->direita->esquerda = NULL;
            return node->direita;
		}
    }    
    return NULL;
}

void Arvore::imprimeArvore(){
	imprimePreOrdem(raiz);
	std::cout << "\n";
}

void Arvore::imprimePreOrdem(Node* node){
    if(node != NULL){
		std::cout << node->letra << " " << node->codigo << "\n" ;
		imprimePreOrdem(node->esquerda);
		imprimePreOrdem(node->direita);
	}
}

Node* Arvore::percorreArvore(char codigo, Node* node){
    if(codigo == '.'){
        if(node->esquerda != NULL){
            return node->esquerda;
		}else{
            return node;
		}
    }
    else if(codigo == '-'){
       if(node->direita != NULL){
           return node->direita;
		}else{
            return node;
		}
    }    
    return NULL;
}

void Arvore::decodifica(string codigoLetra){
    char codigo;
    Node* posicao = raiz;
    for (unsigned i=0; i < codigoLetra.length(); ++i){
        codigo = codigoLetra.at(i);
        posicao = percorreArvore(codigo, posicao);
    }
    std::cout << posicao->letra;
}