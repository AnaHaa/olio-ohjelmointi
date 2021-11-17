#include <iostream>

class HelloWorldFunktor
{
public:
  template <typename Functor>
  void operator()(Functor functor, int a)
  {
    for (int i = 0; i < a; i++)
    {
      functor();
    }
  }
};

main()
{
  auto helloWorldLambda = []()
  {
    std::cout << "Hello World!\n";
  };

  HelloWorldFunktor func;
  func(helloWorldLambda, 5);

  return EXIT_SUCCESS;
}