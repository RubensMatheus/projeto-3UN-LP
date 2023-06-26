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
  float anos = (desligamento.ano - 1) - getIngressoEmpresa().ano; 
  float meses = (desligamento.mes + 11) - getIngressoEmpresa().mes;
  float dias = (desligamento.dia + 30) - getIngressoEmpresa().dia;
  float totalAnos = anos + (meses / 12) + (dias / 365);
  float valorRecisao = totalAnos * stof(getSalario());
  return valorRecisao;
}