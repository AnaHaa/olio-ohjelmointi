#include <iostream>
#include <memory>
#include <vector>
#include <string>
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

class PersonSingleton final
{
public:
  static shared_ptr<PersonSingleton> getInstance();

  void addPerson(const Person &aPerson);
  void getPerson(const string &aName);
  void printPersons() const;

private:
  static shared_ptr<PersonSingleton> instance;

  PersonSingleton() = default;
  PersonSingleton(const PersonSingleton &aPersonSingleton) = delete;
  vector<shared_ptr<Person>> persons;
};

shared_ptr<PersonSingleton> PersonSingleton::instance = nullptr;

shared_ptr<PersonSingleton> PersonSingleton::getInstance()
{
  if (!instance)
  {
    instance = shared_ptr<PersonSingleton>(new PersonSingleton());
    return instance;
  }

  return instance;
}

void PersonSingleton::addPerson(const Person &aPerson)
{
  persons.push_back(std::make_shared<Person>(aPerson));
}

void PersonSingleton::getPerson(const std::string &aName)
{
  for_each(persons.begin(), persons.end(), [aName](auto &h)
           {
             if (h->getName() == aName)
             {
                h->tulostaTiedot();
             }
           });
}

void PersonSingleton::printPersons() const
{
  for_each(persons.begin(), persons.end(), [](auto &h)
           { h->tulostaTiedot(); });
}

int main()
{
  bool loopMenu = true;
  do
  {
    std::cout << "Current persons:\n";
    PersonSingleton::getInstance()->printPersons();

    char choice;
    string name;
    int age;
    std::cout << "1: Save new user, 2: Get user using name, anything else: exit\n";
    std::cin >> choice;

    switch (choice)
    {
    case '1':
      std::cout << "Name: ";
      cin >> name;
      std::cout << "Age: ";
      cin >> age;
      PersonSingleton::getInstance()->addPerson(Person{name, age});
      break;
    case '2':
      std::cout << "Name: ";
      cin >> name;
      PersonSingleton::getInstance()->getPerson(name);
      break;
    default:
      loopMenu = false;
      break;
    }
  } while (loopMenu);

  return EXIT_SUCCESS;
}