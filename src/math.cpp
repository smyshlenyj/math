#include "math/math.h"

namespace math {

math::Math::Math() {}
// Output Math::calculate(Input input) { return Output{}; }

math::Output math::Math::add(math::Input input) {
  return math::Output((input.first + input.second), "OK");
}

math::Output math::Math::subtract(math::Input input) {
  return math::Output((input.first - input.second), "OK");
}

math::Output math::Math::multiply(math::Input input) {
  return math::Output((input.first * input.second), "OK");
}
math::Output math::Math::divide(math::Input input) {
  if (input.second == 0)
    return math::Output(0, "ERROR");

  // double doubleRes = static_cast<double>(input.first) / input.second;
  return math::Output(input.first / input.second, "OK");
}
math::Output math::Math::pow(math::Input input) {
  if (input.second == 0)
    return math::Output(1, "OK");
  if (input.second < 0)
    return math::Output(0, "ERROR");
  int result = input.first;
  for (int i = 0; i < input.second - 1; ++i) {
    result *= input.first;
  }

  return math::Output(result,"OK");
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