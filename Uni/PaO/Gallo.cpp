#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class GalloFile {
 private:
  double dimMB;

 public:
  virtual GalloFile* clone() const = 0;
  virtual bool highQuality() const = 0;
  double getDim() { return dimMB; };
  virtual ~GalloFile() = default;
};

class Foto : public GalloFile {
 private:
  unsigned int iso;
  bool flash;

 public:
  Foto(unsigned int i = 0, bool fl = false) : iso(i), flash(fl) {};
  static const unsigned int sogliaQualita;
  unsigned int getIso() const { return iso; };
  bool getFlash() const { return flash; };
  Foto* clone() const override { return new Foto(*this); };
  bool highQuality() const override { return iso >= sogliaQualita; };
};

const unsigned int Foto::sogliaQualita = 500;

class Video : public GalloFile {
 private:
  unsigned int durata;
  bool fullHD;

 public:
  Video(unsigned int dur = 0, bool hd = false) {
    durata = dur;
    fullHD = hd;
  };
  Video(unsigned int dur = 0, bool hd = false) : durata(dur), fullHD(hd) {};
  unsigned int getDurata() const { return durata; };
  Video* clone() const override { return new Video(*this); };
  bool highQuality() const override { return fullHD; };
};

class Gallo {
 private:
  std::vector<GalloFile*> files;

 public:
  void insertFile(GalloFile* file) { files.push_back(file); };
  void removeNonFoto(double size) {
    std::vector<GalloFile*>::iterator i;
    for (i = files.begin(); i != files.end(); ++i) {
      Video* q = dynamic_cast<Video*>(*i);
      if (q && q->getDim() > size) {
      }
    }
  };
  std::vector<GalloFile*> selectHQ() const {
    std::vector<GalloFile*> v;
    std::vector<GalloFile*>::const_iterator i;
    for (i = files.begin(); i != files.end(); ++i) {
      Foto* q = dynamic_cast<Foto*>(*i);
      if ((*i)->highQuality() && (!q || q->getFlash())) {
        v.push_back(*i);
      }
    }
    return v;
  };
};

int main() {
  Video f(3, true);
  Gallo g;
  g.insertFile(new Video(3, true));
  g.insertFile(new Foto(500, true));
  std::vector<GalloFile*> files = g.selectHQ();
  if (dynamic_cast<Video*>(files[1])) {
    std::cout << dynamic_cast<Video*>(files[1])->getDurata();
  } else {
    std::cout << dynamic_cast<Foto*>(files[1])->getIso();
  }
}