#include <iostream>
#include "Ponto.h"


Ponto::Ponto(double x, double y): x(x), y(y)
{
    //ctor
}

Ponto::~Ponto()
{
    //dtor
}
double Ponto::getX() {
  return this->x;
}

double Ponto::getY() {
  return this->y;
}
void Ponto::imprimir() {
  std::cout << "(" << x << ", "<< y << ")" << std::endl;
}
bool Ponto::eIgual(Ponto* outro) {
  double diffX, diffY;
  diffX = (this->x > outro->getX()) ? (this->x - outro->getX()) : (outro->getX() - this->x); //diffX precisa ser positivo
  diffY = (this->y > outro->getY()) ? (this->y - outro->getY()) : (outro->getY() - this->y); //analogo a diffX
  return (diffX < 1e-5) && (diffY < 1e-5);
}
