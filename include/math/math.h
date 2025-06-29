#pragma once
#include <string>

namespace math {
struct Input {
  int first;
  int second;
  char action;


  Input() = default;
  Input(int _first, int _second, char _action){
    first = _first;
    second = _second;
    action = _action;
  }
};

template <typename T>
struct Output {
  
  T result;
  std::string status;

    Output() = default;
    Output(T _result, std::string _status) {
    result = _result;
    status = _status;
  }
};

class Math {

public:
  Math();
 // Output calculate(Input input);

//private:
  Output<int> add(Input input);
  Output<int> subtract(Input input);
  Output<int> multiply(Input input);
  Output<double> divide(Input input);
  Output<int> pow(Input input);
  Output<int> factorial(Input input);
};
} // namespace math