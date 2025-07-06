#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class FileAudio {
 private:
  std::string title;
  double size;

 public:
  virtual FileAudio* clone() const = 0;
  virtual ~FileAudio() = 0;
  double getSize() const { return size; };
  virtual bool qualita() const = 0;
  virtual bool operator==(const FileAudio& f) {
    return typeid(*this) == typeid(f) && title == f.title && size == f.size;
  };
};

class Mp3 : public FileAudio {
 private:
  unsigned int bitRate;

 public:
  static const unsigned int sogliaQualita;
  Mp3* clone() const override { return new Mp3(*this); };
  bool qualita() const override { return bitRate >= sogliaQualita; };
  int getBitRate() const { return bitRate; };
  bool operator==(const FileAudio& f) {
    return FileAudio::operator==(f) &&
           bitRate == static_cast<const Mp3&>(f).bitRate;
  };
};

const unsigned int Mp3::sogliaQualita = 192;

class WAV : public FileAudio {
 private:
  unsigned int kHz;
  bool lossless;

 public:
  static const unsigned int sogliaQualita;
  bool qualita() const override { return kHz >= sogliaQualita; };
  WAV* clone() const override { return new WAV(*this); };
  int getkHz() const { return kHz; };
  bool getLossless() const { return lossless; };
  bool operator==(const FileAudio& f) {
    return FileAudio::operator==(f) && kHz == static_cast<const WAV&>(f).kHz &&
           lossless == static_cast<const WAV&>(f).lossless;
  };
};

const unsigned int WAV::sogliaQualita = 96;
//  Definire una classe iZod i cui oggetti rappresentano i brani memorizzati in
//  un iZod. La classe iZod deve soddisfare le seguenti specifiche:
// `
// 1. E definita una classe annidata Brano i cui oggetti rappresentano un brano
// memorizzato nell’iZod. Ogni oggetto Brano è rappresentato da un puntatore
// (super)polimorfo ad un FileAudio.

// • La classe Brano deve essere dotata di un opportuno costruttore
// Brano(FileAudio*) con il seguente comportamento: Brano(p) costruisce un
// oggetto Brano il cui puntatore polimorfo punta ad una copia dell’oggetto *p.

// • La classe Brano ridefinisce costruttore di copia profonda, assegnazione
// profonda e distruttore profondo.

// 2. Un oggetto di iZod è quindi caratterizzato da un vector di oggetti di tipo
// Brano che contiene tutti i brani memorizzati nell’iZod.

// 3. La classe iZod rende disponibili i seguenti metodi:

// • Un metodo vector<Mp3> mp3(double, int) con il seguente comportamento: una
// invocazione iz.mp3(dim,br) ritorna un vector di oggetti Mp3 contenente tutti
// e soli i file audio in formato mp3 memorizzati nell’iZod iz che: (i) hanno
// una dimensione ≥ dim e (ii) hanno un bitrate ≥ br.

// • Un metodo vector<FileAudio*> braniQual() con il seguente comportamento: una
// invocazione iz.braniQual() ritorna il vector dei puntatori ai FileAudio
// memorizzati nell’iZod iz che: (i) sono considerati di qualità e (ii) se sono
// dei file audio WAV allora devono essere lossless.

// • Un metodo void insert(Mp3*) con il seguente comportamento: una invocazione
// iz.insert(p) inserisce il nuovo oggetto Brano(p) nel vector dei brani
// memorizzati nell’iZod iz se il file audio mp3 *p non è già memorizzato in iz,
// mentre se il file audio *p risulta già memorizzato non provoca alcun effetto.

class iZod {
 private:
  class Brano {
   public:
    FileAudio* fileAudio;
    Brano(FileAudio* p) : fileAudio(p->clone()) {}
    Brano(const Brano& b) : fileAudio(b.fileAudio->clone()) {}
    Brano& operator=(const Brano& brano) {
      if (this != &brano) {
        delete (fileAudio);
        fileAudio = brano.fileAudio->clone();
      }
    }
    ~Brano() { delete fileAudio; }
  };
  std::vector<Brano> brani;

 public:
  std::vector<Mp3> mp3(double dim, unsigned int br) const {
    std::vector<Mp3> v;
    std::vector<Brano>::const_iterator i;
    for (i = brani.begin(); i != brani.end(); ++i) {
      Mp3* q = dynamic_cast<Mp3*>(i->fileAudio);
      if (q && q->getSize() >= dim && q->getBitRate() >= br) {
        v.push_back(*q);
      }
    }
    return v;
  }

  std::vector<FileAudio*> braniQual() const {
    std::vector<FileAudio*> v;
    std::vector<Brano>::const_iterator i;
    for (i = brani.begin(); i != brani.end(); ++i) {
      if (i->fileAudio && i->fileAudio->qualita() &&
          ((!dynamic_cast<WAV*>(i->fileAudio) ||
            dynamic_cast<WAV*>(i->fileAudio)->getLossless()))) {
        v.push_back(i->fileAudio);
      }
    }
  }

  void insert(Mp3* mp3) {
    std::vector<Brano>::iterator i;
    bool in = false;
    for (i = brani.begin(); i != brani.end() && !in; ++i) {
      in = *(i->fileAudio) == *mp3;
    }
    brani.push_back(mp3);
  }
};
