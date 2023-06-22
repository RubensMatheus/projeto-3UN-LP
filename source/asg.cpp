#include "asg.hpp"

Asg::Asg(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal,
         string estadoCivil, int qtdFilhos, string salario, string matricula,
         Data ingressoEmpresa, int diasFaltas, float adicionalInsalubridade)
    : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos),
      Funcionario(salario, matricula, ingressoEmpresa, diasFaltas),
      adicionalInsalubridade(adicionalInsalubridade) {}

float Asg::getAdicionalInsalubridade() const {
  return adicionalInsalubridade;
}

void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) {
  this->adicionalInsalubridade = adicionalInsalubridade;
}

float Asg::calcularSalario() {
  float salario = stof(getSalario());
  float salarioDiario = salario / 30;
  salario -= salarioDiario * getDiasFaltas();
  salario += salario * adicionalInsalubridade;
  salario += 100 * getQtdFilhos();
  return salario;
}

float Asg::calcularRecisao(Data desligamento) {
  float anosTt = (desligamento.ano - getIngressoEmpresa().ano) * 365;
  anosTt += (desligamento.mes - getIngressoEmpresa().mes) * 30;
  anosTt += (desligamento.dia - getIngressoEmpresa().dia);
  anosTt = anosTt / 365;
  return anosTt * stof(getSalario());
}