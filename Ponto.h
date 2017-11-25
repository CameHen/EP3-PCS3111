#ifndef PONTO_H
#define PONTO_H


class Ponto
{
public:
  Ponto(double x, double y);
  virtual ~Ponto();
  double getX();
  double getY();
  void imprimir();
  bool eIgual(Ponto* outro);
protected:

private:
  double x, y;
};

#endif // PONTO_H
