
#ifndef CODAP_H_
#define CODAP_H_

template < class T > class CodaP {

public:
  typedef T tipoElem;

  virtual void creaPrioriCoda () = 0;
  virtual void inserisci (tipoElem) = 0;
  virtual tipoElem min () = 0;
  virtual void cancellaMin () = 0;
};


#endif /* _CODAP_H_ */
