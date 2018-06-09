#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
class Logger{
public:
  Logger(T x)
  {
    // cout << " X is of type " <<typeid(x).name() << endl;
  }
};

int main() {
  Logger<int> log = make_unique<Logger<int>>(04);
   cout <<typeid(log).name() << endl;
  std::cout << "Hello World!\n";
}
