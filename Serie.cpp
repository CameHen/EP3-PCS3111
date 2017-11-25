#include <iostream>
#include "Serie.h"

using namespace std;

Serie::Serie(string nome, string nomeDoCanalX, string nomeDoCanalY)
{
  this->nome = nome;
  this->nomeDoCanalX = nomeDoCanalX;
  this->nomeDoCanalY = nomeDoCanalY;
}

Serie::~Serie()
{
  //dtor
}

string Serie::getNome() {
  return this->nome;
}

string Serie::getNomeDoCanalX() {
  return this->nomeDoCanalX;
}

string Serie::getNomeDoCanalY() {
  return this->nomeDoCanalY;
}

int Serie::getQuantidade() {
  return this->quantidadeDePontos;
}

bool Serie::estaVazia() {
  return this->quantidadeDePontos == 0;
}

void Serie::adicionar(double x, double y) {
  if (this->quantidadeDePontos < NUMERO_MAXIMO_VALORES) {
    this->pontos[this->quantidadeDePontos] = new Ponto(x, y);
    this->quantidadeDePontos++;
  }
}

Ponto* Serie::getLimiteSuperior() {
  if (this->estaVazia())
    return nullptr;
  double maiorX, maiorY;
  maiorX = this->pontos[0]->getX();
  maiorY = this->pontos[0]->getY();
  for(int i = 1; i < this->quantidadeDePontos; i++) {
    if (this->pontos[i]->getX() > maiorX)
      maiorX = this->pontos[i]->getX();
    if (this->pontos[i]->getY() > maiorY)
      maiorY = this->pontos[i]->getY();
  }
  Ponto* pontoLimiteSuperior = new Ponto(maiorX, maiorY);
  return pontoLimiteSuperior;
}

Ponto* Serie::getLimiteInferior() {
  if (this->estaVazia())
    return nullptr;
  double menorX, menorY;
  menorX = this->pontos[0]->getX();
  menorY = this->pontos[0]->getY();
  for(int i = 1; i < this->quantidadeDePontos; i++) {
    if (this->pontos[i]->getX() < menorX)
      menorX = this->pontos[i]->getX();
    if (this->pontos[i]->getY() < menorY)
      menorY = this->pontos[i]->getY();
  }
  Ponto* pontoLimiteInferior = new Ponto(menorX, menorY);
  return pontoLimiteInferior;
}

Ponto* Serie::getPosicao(int posicao) {
  if (posicao >= this->quantidadeDePontos || posicao < 0)
    return nullptr;
  else
    return this->pontos[posicao];
}

void Serie::imprimir() {
  cout << "Serie " << this->nome << endl;
  for(int i = 0; i < this->quantidadeDePontos; i++)
    this->pontos[i]->imprimir();
  cout << endl;
}
