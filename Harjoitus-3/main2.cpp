#include <iostream>
using namespace std;

class Osoite
{
public:
  // Parametriton rakentaja (oletusrakentaja)
  Osoite()
  {
    std::cout << "Empty Osoite created!" << endl;
  }

  // Parametriton tuhoaja
  ~Osoite()
  {
    std::cout << "Osoite destroyed!" << endl;
  }

  // Parametrillinen rakentaja (katuosoite ja paikkakunta annetaan oliota luodessa)
  Osoite(const string setKatuosoite, const string setPaikkakunta)
  {
    std::cout << "Parameter Osoite created!" << endl;
    katuosoite = setKatuosoite;
    paikkakunta = setPaikkakunta;
  }

  // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
  Osoite(const Osoite &origin)
  {
    std::cout << "Copy Osoite created!" << endl;
    katuosoite = origin.katuosoite;
    paikkakunta = origin.paikkakunta;
  }

  // Setter for katuosoite
  void setKatuosoite(const string setKatuosoite)
  {
    katuosoite = setKatuosoite;
  }

  // Getter for katuosoite
  string getKatuosoite()
  {
    return katuosoite;
  }

  // Setter for paikkakunta
  void setPaikkakunta(const string setPaikkakunta)
  {
    paikkakunta = setPaikkakunta;
  }

  // Getter for paikkakunta
  string getPaikkakunta()
  {
    return paikkakunta;
  }

  void tulostaTiedot()
  {
    std::cout << "Osoite: " << getKatuosoite() << " " << getPaikkakunta() << endl;
  }

private:
  // Attribuutit
  string katuosoite;
  string paikkakunta;
};

class Person
{
public:
  // Parametriton rakentaja (oletusrakentaja)
  Person()
  {
    std::cout << "Empty person created!" << endl;
  }

  // Parametriton tuhoaja
  ~Person()
  {
    std::cout << "Person destroyed!" << endl;
  }

  // Parametrillinen rakentaja (nimi ja ikä annetaan oliota luodessa)
  Person(const string setName, const int setAge, const Osoite &setOsoite)
  {
    std::cout << "Parameter person created!" << endl;
    name = setName;
    age = setAge;
    katuosoite = setOsoite;
  }

  // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
  Person(const Person &origin)
  {
    std::cout << "Copy person created!" << endl;
    name = origin.name;
    age = origin.age;
    katuosoite = origin.katuosoite;
  }

  // Setter for name
  void setName(const string setName)
  {
    name = setName;
  }

  // Getter for name
  string getName()
  {
    return name;
  }

  // Setter for age
  void setAge(const int setAge)
  {
    age = setAge;
  }

  // Getter for age
  int getAge()
  {
    return age;
  }

  void tulostaTiedot()
  {
    std::cout << "Person: " << getName() << " " << getAge() << " " << katuosoite.getKatuosoite() << " " << katuosoite.getPaikkakunta() << endl;
  }

private:
  // Attribuutit
  string name;
  int age;
  Osoite katuosoite;
};

int main()
{
  // Create parameter person
  Person parameterPerson("Antti", 24, {"Katu", "Tampere"});
  parameterPerson.tulostaTiedot();

  // Destructor activating when ending
  return 0;
}