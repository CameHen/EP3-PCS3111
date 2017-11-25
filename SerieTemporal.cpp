#include "SerieTemporal.h"
#include "Serie.h"



SerieTemporal::SerieTemporal(string nome, string nomeDoCanalY) :
Serie(nome, "Tempo", nomeDoCanalY)
{
  this->tempo = 0;
}

SerieTemporal::~SerieTemporal()
{
  //dtor
}

void SerieTemporal::adicionar(double valor) {
  double diffX(0);
  //verificando se ha dois pontos no mesmo tempo
  for (int i(0); i < this->quantidadeDePontos; i++) {
    diffX = (this->tempo + 1 > this->pontos[i]->getX()) ? (this->tempo + 1 - this->pontos[i]->getX()) : (this->pontos[i]->getX() - this->tempo + 1);
    if (diffX < 1e-5) {
      this->tempo++;
      delete this->pontos[i];  //chamei o destrutor
      this->pontos[i] = new Ponto(this->tempo, valor);
      return;
    }
  }
  if (this->quantidadeDePontos < NUMERO_MAXIMO_VALORES) {
    this->tempo++;
    Serie::adicionar(this->tempo, valor);
  }
}

void SerieTemporal::adicionar(double x, double y) {
  double diffX(0);
  //verificando se nao ha dois pontos iguais
  for (int i(0); i < this->quantidadeDePontos; i++) {
    diffX = (x > this->pontos[i]->getX()) ? (x - this->pontos[i]->getX()) : (this->pontos[i]->getX() - x);
    if (diffX < 1e-5){
      delete this->pontos[i];  //chamei o destrutor
      this->pontos[i] = new Ponto(x, y);
      return;
    }
  }
  if (x >= 1)
    Serie::adicionar(x, y);
}
