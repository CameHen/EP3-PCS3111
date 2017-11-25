#include "Eixo.h"

Eixo::Eixo(string titulo, double minimo, double maximo)
{
  this->titulo = titulo;
  this->minimo = minimo;
  this->maximo = maximo;
}

Eixo::~Eixo()
{
  //dtor
}
string Eixo::getTitulo() {
  return this->titulo;
}
double Eixo::getMinimo() {
  return this->minimo;
}
double Eixo::getMaximo() {
  return this->maximo;
}
