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

main()
{
  Stack<int> intStack;
  Stack<double> doubleStack;

  intStack.push(1);
  doubleStack.push(2.33);

  int popIntStack = intStack.pop();

  std::cout << popIntStack << std::endl;

  double popDoubleStack = doubleStack.pop();

  std::cout << popDoubleStack << std::endl;

  return 0;
}