#include "gerente.hpp"

// Construtor parametrizado
Gerente::Gerente(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
                 string estadoCivil, int qtdFilhos, string salario, string matricula,
                 Data ingressoEmpresa, int diasFaltas, float participacaoLucros)
    : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
      Funcionario(salario, matricula, ingressoEmpresa, diasFaltas),
      participacaoLucros(participacaoLucros) {}

// Getters e setters
float Gerente::getParticipacaoLucros() const {
    return participacaoLucros;
}

void Gerente::setParticipacaoLucros(float participacaoLucros) {
    this->participacaoLucros = participacaoLucros;
}

// Implementação dos métodos abstratos
float Gerente::calcularSalario() {
    float salario = stof(getSalario());
    float salarioDiario = salario / 30;
    salario -= salarioDiario * getDiasFaltas();
    
    salario += getParticipacaoLucros();

    salario += (100 * getQtdFilhos());
    return salario;
}

float Gerente::calcularRecisao(Data desligamento) {
    float anosTt = (desligamento.ano - getIngressoEmpresa().ano) * 365;
    anosTt += (desligamento.mes - getIngressoEmpresa().mes) * 30;
    anosTt += (desligamento.dia - getIngressoEmpresa().dia);
    anosTt = anosTt / 365;
    return anosTt * stof(getSalario());
}
