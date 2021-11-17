#include <iostream>
#include <memory>
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
  shared_ptr<Person> kalle(new Person("Kalle", 30));
  shared_ptr<Person> kalle2 = kalle;
  shared_ptr<Person> kalle3 = kalle;

  // prints 3
  std::cout << "How many pointers to kalle object: " << kalle.use_count() << endl;

  return 0;
} // Olio poistetaan