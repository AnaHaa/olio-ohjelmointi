#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
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

class ComparePersonsByAge
{
public:
  bool operator()(Person *a, Person *b)
  {
    return a->getAge() < b->getAge();
  }
};

class CompareUniquePersonsByAge
{
public:
  bool operator()(const unique_ptr<Person> &a, const unique_ptr<Person> &b)
  {
    return a->getAge() < b->getAge();
  }
};

int main()
{
  vector<Person *> persons;
  persons.push_back(new Person("Kalle", 30));
  persons.push_back(new Person("Kalle", 25));

  for (auto &h : persons)
  {
    h->tulostaTiedot();
  }

  std::cout << "Sort begins\n";
  sort(persons.begin(), persons.end(), ComparePersonsByAge());

  for (auto& h : persons)
  {
    h->tulostaTiedot();
  }

  std::cout << "Unique sorting\n";

  vector<unique_ptr<Person>> uniquePersons;

  uniquePersons.push_back(make_unique<Person>("Pekka", 24));
  uniquePersons.push_back(make_unique<Person>("Kalle", 30));

  for (auto &h : uniquePersons)
  {
    h->tulostaTiedot();
  }

  std::cout << "Sort begins\n";
  sort(uniquePersons.begin(), uniquePersons.end(), CompareUniquePersonsByAge());

  for (auto &h : uniquePersons)
  {
    h->tulostaTiedot();
  }

  uniquePersons.clear();

  return 0;
}