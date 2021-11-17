#include <iostream>
using namespace std;

class Osoite
{
public:
  // Parametriton rakentaja (oletusrakentaja)
  Osoite() = default;

  // Parametriton tuhoaja
  ~Osoite() = default;

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
  virtual void setKatuosoite(const string setKatuosoite) final
  {
    katuosoite = setKatuosoite;
  }

  // Getter for katuosoite
  virtual string getKatuosoite() final
  {
    return katuosoite;
  }

  // Setter for paikkakunta
  virtual void setPaikkakunta(const string setPaikkakunta) final
  {
    paikkakunta = setPaikkakunta;
  }

  // Getter for paikkakunta
  virtual string getPaikkakunta()
  {
    return paikkakunta;
  }

  virtual void tulostaTiedot()
  {
    std::cout << "Osoite: " << getKatuosoite() << " " << getPaikkakunta() << endl;
  }

public:
  // Attribuutit
  string katuosoite;
  string paikkakunta;
};

class Person
{
public:
  // Parametriton rakentaja (oletusrakentaja)
  Person() = default;

  // Parametriton tuhoaja
  ~Person() = default;

  // Parametrillinen rakentaja
  Person(const string setName, const int setAge)
  {
    std::cout << "Parameter person created!" << endl;
    name = setName;
    age = setAge;
  }

  // Parametrillinen rakentaja
  Person(const string setName, const int setAge, const string katuosoite, const string paikkakunta)
  {
    std::cout << "Parameter person created!" << endl;
    name = setName;
    age = setAge;
    osoitetieto = {katuosoite, paikkakunta};
  }

  // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
  Person(const Person &origin)
  {
    std::cout << "Copy person created!" << endl;
    name = origin.name;
    age = origin.age;
    osoitetieto = origin.osoitetieto;
  }

  // Setter for name
  virtual void setName(const string setName) final
  {
    name = setName;
  }

  // Getter for name
  virtual string getName() final
  {
    return name;
  }

  // Setter for age
  virtual void setAge(const int setAge) final
  {
    age = setAge;
  }

  // Getter for age
  virtual int getAge() final
  {
    return age;
  }

  virtual void tulostaTiedot()
  {
    std::cout << "Person: " << getName() << " " << getAge() << " " << osoitetieto.getKatuosoite() << " " << osoitetieto.getPaikkakunta() << endl;
  }

public:
  string name;
  int age;
  Osoite osoitetieto;
};

class Opiskelija : public Person
{
public:
  // Parametriton rakentaja (oletusrakentaja)
  Opiskelija() = delete;

  // Parametriton tuhoaja
  ~Opiskelija() = delete;

  // Parametrillinen rakentaja
  Opiskelija(const string setName, const int setAge, const int setOpintopisteet)
    : Person(setName, setAge)
    , opintopisteet(setOpintopisteet)
  {
  }

  // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
  Opiskelija(Opiskelija &origin) : Person(origin)
  {
    std::cout << "Copy person created!" << endl;
    setName(origin.getName());
    setAge(origin.getAge());
    setAge(origin.getAge());
    setOpintopisteet(origin.getOpintopisteet());
  }

  // Setter for opintopisteet
  virtual void setOpintopisteet(const int setOpintopisteet)
  {
    opintopisteet = setOpintopisteet;
  }

  // Getter for opintopisteet
  virtual int getOpintopisteet() final
  {
    return opintopisteet;
  }

  virtual void tulostaTiedot() override
  {
    std::cout << "Opiskelija: " << getName() << " " << getAge() << " " << getOpintopisteet() << endl;
  }

private:
  int opintopisteet;
};

int main()
{
  Person kalle("Kalle", 30);
  kalle.tulostaTiedot();
  Person *maija = new Person("Maija", 24, "Hämeenpuisto 20", "Tampere");
  maija->tulostaTiedot();
  delete maija;

  Person persons[10] = {
      {"1", 1},
      {"2", 2},
      {"3", 3, "3", "3"},
      {"4", 4},
      {"5", 5, "5", "5"},
      {"6", 6},
      {"7", 7, "7", "7"},
      {"8", 8},
      {"9", 9, "9", "9"},
      {"10", 10}};

  for (int i = 0; i < 10; i++)
  {
    persons[i].tulostaTiedot();
  }

  Person *test = new Opiskelija("Menetan opintopisteet", 20, 45);
  test->tulostaTiedot();

  return 0;
}