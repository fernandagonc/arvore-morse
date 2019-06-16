#include <iostream>
#include<string>
#include "arvore.hpp"

int main (int argc, char **argv){
    Arvore morse;
    string frase, codigoLetra;
    char codigo;

    morse.construirArvore();
    
    if(argc > 1){
        if(std::string(argv[1]) == "-a"){
            morse.imprimeArvore();
        }
    }

    while(std::getline(std::cin, frase)){  
        for (unsigned i=0; i < frase.length(); ++i){
            codigo = frase.at(i);
            if(codigo == '.' || codigo == '-')
                codigoLetra.push_back(codigo);
            else if (codigo == ' '){
                morse.decodifica(codigoLetra);
                codigoLetra.clear();
            }
            else if(codigo == ' / ')
                std::cout << ' ';
        }
        if(!codigoLetra.empty()){
            morse.decodifica(codigoLetra);
            codigoLetra.clear();
        }
        std::cout << '\n';
    }         
    
}