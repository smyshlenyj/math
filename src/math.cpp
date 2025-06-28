#include "math.h"

namespace math {

Math::Math() {}
// Output Math::calculate(Input input) { return Output{}; }

Output Math::add(Input input) {
  return Output((input.first + input.second), "OK");
}

Output Math::subtract(Input input) {
  return Output((input.first - input.second), "OK");
}

Output Math::multiply(Input input) {
  return Output((input.first * input.second), "OK");
}
Output Math::divide(Input input) {
  if (input.second == 0)
    return Output(0, "ERROR");

  // double doubleRes = static_cast<double>(input.first) / input.second;
  return Output(input.first / input.second, "OK");
}
Output Math::pow(Input input) {
  if (input.second == 0)
    return Output(1, "OK");
  if (input.second < 0)
    return Output(0, "ERROR");
  int result = input.first;
  for (int i = 0; i < input.second - 1; ++i) {
    result *= input.first;
  }

  return Output(result,"OK");
}
/*
std::string Math::getFactorial(int n) {
  if (n < 0)
    return "Введите положительное число!";

  return "Факториал числа " + std::to_string(n) + " = " +
         std::to_string(math::countFactorial(n));
};

int Math::countFactorial(int n) {
  if (n == 0)
    return 1;
  return n * countFactorial(n - 1);
} 
};*/
} // namespace math