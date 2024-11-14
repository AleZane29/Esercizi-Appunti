/*
ESERCIZIO. Definire una superclasse ContoBancario e due sue sottoclassi
ContoCorrente e ContoDiRisparmio che soddisfano le seguenti specifiche:

1) Ogni ContoBancario è caratterizzato da un saldo e rende disponibili due
funzionalità di deposito e prelievo: double deposita(double) e double
preleva(double) che ritornano il saldo aggiornato dopo l’operazione di
deposito/prelievo. 2) Ogni ContoCorrente è caratterizzato anche da una spesa
fissa uguale per ogni ContoCorrente che deve essere detratta dal saldo ad ogni
operazione di deposito e prelievo. 3) Ogni ContoDiRisparmio deve avere un saldo
non negativo e pertanto non tutti i prelievi sono permessi; d’altra parte, le
operazioni di deposito e prelievo non comportano costi aggiuntivi e
restituiscono il saldo aggiornato. 4) Si definisca inoltre una classe
ContoArancio derivata da ContoDiRisparmio. La classe ContoArancio deve avere un
ContoCorrente di appoggio: quando si deposita una somma S su un ContoArancio, S
viene prelevata dal ContoCorrente di appoggio; d’altra parte, i prelievi di una
somma S da un ContoArancio vengono depositati nel ContoCorrente di appoggio.
*/

class ContoBancario {
 private:
  double saldo;

 public:
  ContoBancario(double x = 0.0) { saldo = x < 0 ? 0 : x; }
  double deposita(double x) {
    if (x > 0) {
      saldo += x;
    }
    return saldo;
  };
  double preleva(double x) {
    if (x > 0) {
      saldo -= x;
    }
    return saldo;
  };
  double getSaldo() { return saldo; };
};

class ContoCorrente : public ContoBancario {
 private:
  static double spesaFissa;

 public:
  ContoCorrente(double x = 0.0) { ContoBancario(x); };
  double deposita(double x) { return ContoBancario::deposita(x - spesaFissa); };
  double preleva(double x) { return ContoBancario::preleva(x - spesaFissa); };
};

class ContoDiRisparmio : public ContoBancario {
 public:
  ContoDiRisparmio(double x = 0.0) { ContoBancario(x); };
  double preleva(double x) {
    if (getSaldo() >= x) {
      ContoBancario::preleva(x);
    }
    return getSaldo();
  };
};

class ContoArancio : public ContoDiRisparmio {
 private:
  ContoCorrente &cca;

 public:
  ContoArancio(ContoCorrente &c, double x = 0.0)
      : ContoDiRisparmio(x), cca(c) {}
  double deposita(double x) {
    cca.preleva(x);
    return ContoDiRisparmio::deposita(x);
  };
  double preleva(double x) {
    if (getSaldo() >= ContoDiRisparmio::preleva(x)) {
      cca.deposita(x);
    };
    return getSaldo();
  };
};