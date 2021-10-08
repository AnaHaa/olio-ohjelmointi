#include <iostream>
using namespace std;

class Person
{
public:
  Person(const std::string &setName, const int &setAge)
      : name(setName), age(setAge)
  {
    std::cout << "Person created" << std::endl;
    count++;
  }

  ~Person()
  {
    std::cout << "Person destroyed" << std::endl;
  }

  void printInformation()
  {
    std::cout << "Person: " << name << " : " << age << std::endl;
  }

  static int returnCount()
  {
    return count;
  }

private:
  static int count;
  std::string name;
  int age;
};

// Initialize the counter on program startup
int Person::count = 0;

int main()
{
  Person antti("Antti", 24);
  antti.printInformation();

  std::cout << "The current count: " << Person::returnCount() << std::endl;

  Person pekka("Pekka", 24);
  pekka.printInformation();

  std::cout << "The current count: " << Person::returnCount() << std::endl;

  return 0;
}