#ifndef GRAFICO_H
#define GRAFICO_H

#include <string>
#include "Eixo.h"
#include "Serie.h"
#include "Tela.h"

using std::string;

class Grafico
{
public:
  Grafico(Eixo* x, Eixo* y, Serie* serie);
  virtual ~Grafico();

  Eixo* getEixoX();
  Eixo* getEixoY();
  Serie* getSerie();
  void desenhar();
protected:

private:
  Eixo* eixoX;  //Mesquita, arruma isso
  Eixo* eixoY;  //Mesquita, arruma isso
  Serie* serie;  //Mesquita, arruma isso
};

#endif // GRAFICO_H
