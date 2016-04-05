#include <iostream>
#include <string.h>
using namespace std;

class MaPetiteChaine {
public:

  MaPetiteChaine(const char* data = "");
  MaPetiteChaine(const MaPetiteChaine &chaine);
  virtual ~MaPetiteChaine();
  virtual const char* to_cstr() const;
private:
  char* m_dataP;
};

MaPetiteChaine::MaPetiteChaine(const char* dataP) :
  m_dataP(new char[strlen(dataP)+1000]) {
  strcpy(m_dataP,dataP);
}

MaPetiteChaine::MaPetiteChaine(const MaPetiteChaine &chaineIni) :
m_dataP(0) {
    if(chaineIni . m_dataP && strlen(chaineIni . m_dataP)) {
        m_dataP = new char[strlen(chaineIni . m_dataP)+1];
        strcpy(m_dataP,chaineIni . m_dataP);
    }
}

MaPetiteChaine::~MaPetiteChaine() {
  cout << "Effacement de m_dataP " << reinterpret_cast<long int>(m_dataP) << "\n";
  delete [] m_dataP;
}

const char* MaPetiteChaine::to_cstr() const {
  return m_dataP;
}

int main() {
  MaPetiteChaine salut("Bonjour tout le monde");
  cout << salut.to_cstr() << endl;

       // on en fait une copie dynamiquement
  MaPetiteChaine* reSalutP = new MaPetiteChaine(salut);

       // on utilise la copie et l'original, tout baigne
  cout << reSalutP->to_cstr() << endl;
  cout << salut.to_cstr()     << endl;

  delete reSalutP; // on nettoie la copie
  reSalutP = 0;    // pour etre bien clean

       // et on devrait pouvoir encore utiliser l'original....
  cout << salut.to_cstr() << endl; // a l'air ok, mais BOUM !
}      // et encore BADABOUM ! mais qu'est-ce qu'on a fait ?..
