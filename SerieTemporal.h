#ifndef SERIETEMPORAL_H
#define SERIETEMPORAL_H

#include "Serie.h"

class SerieTemporal : public Serie
{
public:
  SerieTemporal(string nome, string nomeDoCanalY);
  virtual ~SerieTemporal();
  virtual void adicionar(double valor);
  virtual void adicionar(double x, double y);

protected:

private:
  int tempo;
};

#endif // SERIETEMPORAL_H
