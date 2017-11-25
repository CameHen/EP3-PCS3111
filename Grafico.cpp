#include "Grafico.h"

Grafico::Grafico(Eixo* x, Eixo* y, Serie* serie) :
  eixoX(x), eixoY(y), serie(serie)
{
  //ctor
}

Grafico::~Grafico()
{
  //dtor
}

Eixo* Grafico::getEixoX(){
  return eixoX;
}

Eixo* Grafico::getEixoY(){
  return eixoY;
}

Serie* Grafico::getSerie(){
  return serie;
}

void Grafico::desenhar(){
    Tela * t = new Tela();
    t->setEixoX(eixoX->getTitulo(), eixoX->getMinimo(), eixoX->getMaximo());
    t->setEixoY(eixoY->getTitulo(), eixoY->getMinimo(), eixoY->getMaximo());

    for(int i = 0; i < serie->getQuantidade(); i++){
        Ponto* p = serie->getPosicao(i);
        t->plotar(serie->getNome(), p->getX(), p->getY());
    }
    t->mostrar();
    delete t;
}
