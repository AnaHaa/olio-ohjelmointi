#include <iostream>
using namespace std;

class Person
{
public:
  // Parametriton rakentaja (oletusrakentaja)
  Person()
  {
    std::cout << "Empty person created!" << endl;
  }

  // Parametriton rakentaja (oletusrakentaja)
  ~Person()
  {
    std::cout << "Person destroyed!" << endl;
  }

  // Parametrillinen rakentaja (nimi ja ikä annetaan oliota luodessa)
  Person(const string setName, const int setAge)
  {
    std::cout << "Parameter person created!" << endl;
    name = setName;
    age = setAge;
  }

  // Kopiorakentaja (jolla voit luoda toisen olion olemassa olevan pohjalta)
  Person(const Person &origin)
  {
    std::cout << "Copy person created!" << endl;
    name = origin.name;
    age = origin.age;
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
    std::cout << "Person: " << getName() << " " << getAge() << endl;
  }

private:
  // Attribuutit
  string name;
  int age;
};

int main()
{
  // Create default empty person
  Person defaultPerson;

  // Create parameter person
  Person parameterPerson("Antti", 24);
  parameterPerson.tulostaTiedot();

  // Create copy person
  parameterPerson.setName("Pekka");
  parameterPerson.setAge(25);
  parameterPerson.tulostaTiedot();

  Person copyPerson = parameterPerson;
  copyPerson.tulostaTiedot();

  // Destructor activating when ending
  return 0;
}