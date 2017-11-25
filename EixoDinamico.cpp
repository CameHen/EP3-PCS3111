#include "EixoDinamico.h"

EixoDinamico::EixoDinamico(double minimoPadrao, double maximoPadrao, Serie* base, bool orientacaoHorizontal):
  Eixo(base->getNomeDoCanalY(), minimoPadrao, maximoPadrao)
{
  if(base->getQuantidade() > 1){
    if((base->getLimiteSuperior()->getX() - base->getLimiteInferior()->getX() >= 1e-5) && (orientacaoHorizontal)){
      this->titulo = base->getNomeDoCanalX();
      this->minimo = base->getLimiteInferior()->getX();
      this->maximo = base->getLimiteSuperior()->getX();
    }
    if((base->getLimiteSuperior()->getY() - base->getLimiteInferior()->getY() >= 1e-5) && (!orientacaoHorizontal)){
      this->minimo = base->getLimiteInferior()->getY();
      this->maximo = base->getLimiteSuperior()->getY();
    }
  }
}

EixoDinamico::~EixoDinamico()
{
  //dtor
}
