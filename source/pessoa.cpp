#include "pessoa.hpp"

Pessoa::Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,string estadoCivil, int qtdFilhos) {
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->enderecoPessoal = enderecoPessoal;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
    }

// Getters e setters
string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getCPF() const {
    return cpf;
}

void Pessoa::setCPF(string cpf) {
    this->cpf = cpf;
}

Data Pessoa::getDataNascimento() const {
    return dataNascimento;
}

void Pessoa::setDataNascimento(Data dataNascimento) {
    this->dataNascimento = dataNascimento;
}

Endereco Pessoa::getEnderecoPessoal() const {
    return enderecoPessoal;
}

void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal) {
    this->enderecoPessoal = enderecoPessoal;
}

string Pessoa::getEstadoCivil() const {
    return estadoCivil;
}

void Pessoa::setEstadoCivil(string estadoCivil) {
    this->estadoCivil = estadoCivil;
}

int Pessoa::getQtdFilhos() const {
    return qtdFilhos;
}

void Pessoa::setQtdFilhos(int qtdFilhos) {
    this->qtdFilhos = qtdFilhos;
}