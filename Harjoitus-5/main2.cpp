#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
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
  shared_ptr<Osoite> osoitePtr;

  Person(const std::string &setNimi, const int &setIka, shared_ptr<Osoite> setOsoite)
      : name(setNimi), age(setIka), osoitePtr(move(setOsoite))
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
  vector<std::unique_ptr<Person>> personVector;

  // Set up the first object Kalle
  shared_ptr<Osoite> osoite(new Osoite("Katuosoite 12 A 11", "Tampere"));
  unique_ptr<Person> kalle(new Person("Kalle", 30, osoite));

  // Set up the second object Antti
  unique_ptr<Person> antti(new Person("Antti", 24, osoite));

  // Set up the third object Pekka
  unique_ptr<Person> pekka(new Person("Pekka", 24, osoite));

  personVector.push_back(move(kalle));
  personVector.push_back(move(antti));
  personVector.push_back(move(pekka));

  return 0;
} // Olio poistetaan