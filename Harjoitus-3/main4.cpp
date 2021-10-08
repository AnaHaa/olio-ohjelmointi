#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;
template <class T>
class Stack
{
public:
  void push(T const &item);
  T pop();

  Stack()
  {
    top = 0;
  }

private:
  T data[SIZE];
  int top;
};

template <class T>
void Stack<T>::push(T const &item)
{
  data[top] = item;
  top++;
}

template <class T>
T Stack<T>::pop()
{
  top--;
  return data[top];
}

class Person
{
public:
  std::string name;
  int age;

  Person()
  {
  }

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
};

main()
{
  Stack<int> intStack;
  Stack<double> doubleStack;
  Stack<Person> personStack;

  intStack.push(1);
  doubleStack.push(2.33);
  personStack.push({"Antti", 24});

  int popIntStack = intStack.pop();

  std::cout << popIntStack << std::endl;

  double popDoubleStack = doubleStack.pop();

  std::cout << popDoubleStack << std::endl;

  Person popPersonStack = personStack.pop();

  popPersonStack.printInformation();

  return 0;
}