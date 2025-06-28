#pragma once
#include <string>

namespace math {
struct Input {
  int first;
  int second;
  char action;

  Input(int _first, int _second, char _action){
    first = _first;
    second = _second;
    action = _action;
  }
};

struct Output {
  double result;
  std::string status;

    Output(int _result, std::string _status) {
    result = _result;
    status = _status;
  }
};

class Math {

public:
  Math();
 // Output calculate(Input input);

//private:
  Output add(Input input);
  Output subtract(Input input);
  Output multiply(Input input);
  Output divide(Input input);
  Output pow(Input input);
  Output factorial(Input input);
};
} // namespace math