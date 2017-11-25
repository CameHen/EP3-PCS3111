#ifndef SERIE_H
#define SERIE_H

#define NUMERO_MAXIMO_VALORES 10

#include <string>
#include "Ponto.h"

using std::string;

class Serie
{
public:
  Serie(string nome, string nomeDoCanalX, string nomeDoCanalY);
  virtual ~Serie();
  virtual string getNome();
  virtual string getNomeDoCanalX();
  virtual string getNomeDoCanalY();
  virtual int getQuantidade();
  virtual bool estaVazia();
  virtual void adicionar(double x, double y);
  virtual Ponto* getLimiteSuperior();
  virtual Ponto* getLimiteInferior();
  virtual Ponto* getPosicao(int posicao);
  virtual void imprimir();
protected:
  int quantidadeDePontos = 0;  //quantidade de pontos dentro da serie
  Ponto* pontos[NUMERO_MAXIMO_VALORES];

private:
  string nome, nomeDoCanalX, nomeDoCanalY;


};

#endif // SERIE_H
