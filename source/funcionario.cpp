#include "funcionario.hpp"

Funcionario::Funcionario(string salario, string matricula, Data ingressoEmpresa, int diasFaltas) {
  this->salario = salario;
  this->matricula = matricula;
  this->ingressoEmpresa = ingressoEmpresa;
  this->diasFaltas = diasFaltas;
}

string Funcionario::getSalario() const {
  return salario;
}

void Funcionario::setSalario(string salario) {
  this->salario = salario;
}

string Funcionario::getMatricula() const {
  return matricula;
}

void Funcionario::setMatricula(string matricula) {
  this->matricula = matricula;
}

Data Funcionario::getIngressoEmpresa() const {
  return ingressoEmpresa;
}

void Funcionario::setIngressoEmpresa(Data ingressoEmpresa) {
  this->ingressoEmpresa = ingressoEmpresa;
}

int Funcionario::getDiasFaltas() const {
  return diasFaltas;
}

void Funcionario::setDiasFaltas(int diasFaltas) {
  this->diasFaltas = diasFaltas;
}