#include "vendedor.hpp"

Vendedor::Vendedor(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
                   string estadoCivil, int qtdFilhos, string salario, string matricula,
                   Data ingressoEmpresa, int diasFaltas, char tipoVendedor)
            : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
            Funcionario(salario, matricula, ingressoEmpresa, diasFaltas),
            tipoVendedor(tipoVendedor) {}

// Getters e setters
char Vendedor::getTipoVendedor() const {
    return tipoVendedor;
}

void Vendedor::setTipoVendedor(char tipoVendedor) {
    this->tipoVendedor = tipoVendedor;
}

// Implementação dos métodos abstratos
float Vendedor::calcularSalario() {
    float salario = stof(getSalario());
    float salarioDiario = salario / 30;
    salario -= salarioDiario * getDiasFaltas();

    switch (getTipoVendedor())
    {
    case 'A':
        salario += salario * 0.25;
        break;
    case 'B':
        salario += salario * 0.10;
        break;
    case 'C':
        salario += salario * 0.05;
        break;
    default:
        break;
    }

    salario += 100 * getQtdFilhos();
    return salario;
}

float Vendedor::calcularRecisao(Data desligamento) {
    float anosTt = (desligamento.ano - getIngressoEmpresa().ano) * 365;
    anosTt += (desligamento.mes - getIngressoEmpresa().mes) * 30;
    anosTt += (desligamento.dia - getIngressoEmpresa().dia);
    anosTt = anosTt / 365;
    return anosTt * stof(getSalario());
}