#include <iostream>
#include <vector>
using namespace std;

class Person
{
public:
  std::string name;
  int age;

  Person(const std::string &setName, const int &setAge)
      : name(setName), age(setAge)
  {
  }

  ~Person()
  {
  }

  // Getter for name
  string getName() const
  {
    return name;
  }

  // Getter for age
  int getAge() const
  {
    return age;
  }

  void printInformation()
  {
    std::cout << "Person: " << name << " : " << age << std::endl;
  }

  bool operator==(const Person &aPerson) const;
};

bool Person::operator==(const Person &aPerson) const
{
  return getName() == aPerson.getName() && getAge() == aPerson.getAge();
}

template <class T>
bool equals(T x, T y)
{
  return (x == y) ? true : false;
}

main()
{
  int x = 5, y = 5;
  // 0 false, 1 true
  // In this case returns 1 true
  std::cout << "Boolean: " << equals<int>(x, y) << std::endl;

  Person first = Person("Antti", 24);
  Person second = Person("Antti", 24);
  // 0 false, 1 true
  // In this case returns 1 true
  bool samePerson = equals<Person>(first, second);
  std::cout << "Boolean: " << samePerson << std::endl;

  return 0;
}