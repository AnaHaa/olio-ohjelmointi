#include <iostream>
using namespace std;

class Osoite
{
public:
  std::string katu;
  std::string kunta;

  Osoite(const std::string &setKatu, const std::string &setKunta)
      : katu(setKatu), kunta(setKunta)
  {
    std::cout << "Osoite luotu" << std::endl;
  }

  ~Osoite()
  {
    std::cout << "Osoite tuhottu" << std::endl;
  }
};

class Person
{
public:
  std::string name;
  int age;
  Osoite *osoitePtr;

  Person(const std::string &setNimi, const int &setIka, Osoite *setOsoite)
      : name(setNimi), age(setIka), osoitePtr(setOsoite)
  {
    std::cout << "Henkilo luotu" << std::endl;
  }

  ~Person()
  {
    std::cout << "Henkilo tuhottu" << std::endl;
  }

  void tulostaTiedot()
  {
    std::cout << "Henkilo: " << name << " : " << age << " : " << osoitePtr->katu << " : " << osoitePtr->kunta << std::endl;
  }
};

int main()
{
  Osoite pekanOsoite("Katuosoite 12 A 11", "Tampere");
  Person pekka("Pekka", 24, &pekanOsoite);

  pekka.tulostaTiedot();

  // Destructors activating when in Henkilo then Osoite
  return 0;
}