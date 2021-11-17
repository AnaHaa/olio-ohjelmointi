#include <iostream>
#include <functional>
#include <memory>

class Person
{
public:
  Person()
  {
    std::cout << "Empty person created!\n";
  }

  ~Person()
  {
    std::cout << "Person destroyed!\n";
  }

  Person(const std::string inputName, const int inputAge)
  {
    std::cout << "Parameter person created!\n";
    setName(inputName);
    setAge(inputAge);
  }

  Person(const Person &origin)
  {
    std::cout << "Copy person created!\n";
    name = origin.name;
    age = origin.age;
  }

  void setName(const std::string inputName)
  {
    name = inputName;
  }

  std::string getName()
  {
    return name;
  }

  void setAge(const int inputAge)
  {
    age = inputAge;
  }

  int getAge()
  {
    return age;
  }

  void setPersonPolicy(const std::function<void(int)> &inputPersonPolicy)
  {
    personPolicy = inputPersonPolicy;
  }

  void tulostaTiedot()
  {
    std::cout << "Person: " << getName() << " " << getAge() << std::endl;

    // Check if lambda exists
    if (personPolicy)
    {
      const int personAge = getAge();
      personPolicy(personAge);
    }
  }

private:
  std::string name;
  int age;
  std::function<void(int)> personPolicy = nullptr;
};

int main()
{
  std::unique_ptr<Person> antti(new Person("Antti", 24));
  // Print only name and age
  antti->tulostaTiedot();

  auto calculateDaysFromAge = [](const int inputAge)
  {
    const int ageDays = inputAge * 365.25;
    std::cout << "You are " << ageDays << " days old!\n";
  };

  antti->setPersonPolicy(calculateDaysFromAge);
  antti->tulostaTiedot();

  return EXIT_SUCCESS;
}
