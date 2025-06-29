#include "math/math.h"
#include <functional>

namespace math {

math::Math::Math() {}
// Output Math::calculate(Input input) { return Output{}; }

math::Output<int> math::Math::add(math::Input input) {
  return math::Output<int>((input.first + input.second), "OK");
}

math::Output<int> math::Math::subtract(math::Input input) {
  return math::Output<int>((input.first - input.second), "OK");
}

math::Output<int> math::Math::multiply(math::Input input) {
  return math::Output<int>((input.first * input.second), "OK");
}

math::Output<double> math::Math::divide(math::Input input) {
  if (input.second == 0)
    return math::Output<double>(0, "ERROR");

  // double doubleRes = static_cast<double>(input.first) / input.second;
  return math::Output<double>(static_cast<double>(input.first) / input.second, "OK");
}

math::Output<int> math::Math::pow(math::Input input) {
  if (input.second == 0)
    return math::Output<int>(1, "OK");
  if (input.second < 0)
    return math::Output<int>(0, "ERROR");
  int result = input.first;
  for (int i = 0; i < input.second - 1; ++i) {
    result *= input.first;
  }

  return math::Output<int>(result, "OK");
}

math::Output<int> math::Math::factorial(math::Input input) {
  if (input.first < 0)
    return math::Output<int>(0, "ERROR");

  std::function<int(int)> factorial = [&](int n) -> int {
    return (n <= 1) ? 1 : n * factorial(n - 1);
  };
  int result = factorial(input.first);
  return math::Output<int>(result, "OK");
}
} // namespace math