#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
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
  string getName() const
  {
    return name;
  }

  // Setter for age
  void setAge(const int setAge)
  {
    age = setAge;
  }

  // Getter for age
  int getAge() const
  {
    return age;
  }

  void tulostaTiedot() const
  {
    std::cout << "Person: " << getName() << " " << getAge() << endl;
  }

private:
  // Attribuutit
  string name;
  int age;
};

class PersonSingletonObserver
{
  public:
    virtual void personAdded(const int& aAge) = 0;

};

class PersonSingleton final
{
public:
  static shared_ptr<PersonSingleton> getInstance();

  void addPerson(const Person &aPerson);
  void getPerson(const string &aName);
  void printPersons() const;
  void registerObserver(const shared_ptr<PersonSingletonObserver>& aObserver);
  void registerObserverLambda(function<void(const int&)> aObserver);

private:
  static shared_ptr<PersonSingleton> instance;

  PersonSingleton() = default;
  PersonSingleton(const PersonSingleton &aPersonSingleton) = delete;
  vector<shared_ptr<Person>> persons;
  vector<shared_ptr<PersonSingletonObserver>> personSingletonObserver;
  vector<function<void(const int&)>> personSingletonObserverLambda;
};

shared_ptr<PersonSingleton> PersonSingleton::instance = nullptr;

void PersonSingleton::registerObserver(const std::shared_ptr<PersonSingletonObserver> &aObserver)
{
  personSingletonObserver.push_back(aObserver);
}

void PersonSingleton::registerObserverLambda(std::function<void (const int &)> aObserver)
{
  personSingletonObserverLambda.push_back(aObserver);
}

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

  for(auto& observer : personSingletonObserver)
  {
    observer->personAdded(aPerson.getAge());
  }

  for(auto& observer : personSingletonObserverLambda)
  {
    observer(aPerson.getAge());
  }
}

void PersonSingleton::printPersons() const
{
  for_each(persons.begin(), persons.end(), [](auto &h)
           { h->tulostaTiedot(); });
}

class MyObserver : public PersonSingletonObserver
{
  public:
    MyObserver() = default;
    virtual void personAdded(const int& aAge)
    {
      std::cout << "Event got: " << aAge << endl;
    }
};

int main()
{
  auto myLambdaObsercer = [](const int& aAge)
  {
    std::cout << "Got lambda event: " << aAge << endl;
  };

  PersonSingleton::getInstance()->registerObserverLambda(myLambdaObsercer);

  PersonSingleton::getInstance()->addPerson(Person{"Antti", 24});
  PersonSingleton::getInstance()->printPersons();

  return EXIT_SUCCESS;
}