#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include "util.hpp"
using namespace std;

class Pessoa
{
private:
    string nome;
    string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    string estadoCivil;
    int qtdFilhos;

public:
    Pessoa() {}
    Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,string estadoCivil, int qtdFilhos);
    ~Pessoa() {}
    // Getters e setters
    string getNome() const;
    void setNome(string nome) ;

    string getCPF() const ;
    void setCPF(string cpf) ;

    Data getDataNascimento() const ;
    void setDataNascimento(Data dataNascimento) ;

    Endereco getEnderecoPessoal() const ;
    void setEnderecoPessoal(Endereco enderecoPessoal) ;

    string getEstadoCivil() const ;
    void setEstadoCivil(string estadoCivil) ;
    
    int getQtdFilhos() const ;
    void setQtdFilhos(int qtdFilhos) ;
};

#endif