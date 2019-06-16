#include <iostream>
#include<string>
#include "arvore.hpp"

int main (int argc, char **argv){
    Arvore morse;
    string frase, codigoLetra;
    char codigo;

    morse.construirArvore();

    while(std::getline(std::cin, frase)){  
        for (unsigned i=0; i < frase.length(); ++i){
            codigo = frase.at(i);
            if(codigo == '.' || codigo == '-')
                codigoLetra.push_back(codigo);
            else if (codigo == ' '){
                if (!codigoLetra.empty()) {
                   morse.decodifica(codigoLetra);
                   codigoLetra.clear();
                }
                else{
                    std::cout << ' ';
                }   
            }
        }
        if(!codigoLetra.empty()){
            morse.decodifica(codigoLetra);
            codigoLetra.clear();
        }
        std::cout << '\n';
    }         

    if(argc > 1){
        if(std::string(argv[1]) == "-a"){
            morse.imprimeArvore();
        }
    }

    
}