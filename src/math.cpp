#include "math/math.h"

#include <functional>
#include <limits>

namespace math {

constexpr int INT_MAX_VAL = std::numeric_limits<int>::max();
constexpr int INT_MIN_VAL = std::numeric_limits<int>::min();

math::Output<int> Math::add(const Input& input) {
    if ((input.second > 0 && input.first > INT_MAX_VAL - input.second) ||
        (input.second < 0 && input.first < INT_MIN_VAL - input.second)) {
        return Output<int>(0, "ERROR: переполнение при сложении");
    }

    return Output<int>(input.first + input.second, "OK");
}

math::Output<int> Math::subtract(const Input& input) {
    if ((input.second < 0 && input.first > INT_MAX_VAL + input.second) ||
        (input.second > 0 && input.first < INT_MIN_VAL + input.second)) {
        return Output<int>(0, "ERROR: переполнение при вычитании");
    }

    return Output<int>(input.first - input.second, "OK");
}

math::Output<int> Math::multiply(const Input& input) {
    if (input.first == 0 || input.second == 0) {
        return Output<int>(0, "OK");
    }

    long long temp = static_cast<long long>(input.first) * input.second;
    if (temp > INT_MAX_VAL || temp < INT_MIN_VAL) {
        return Output<int>(0, "ERROR: переполнение при умножении");
    }

    return Output<int>(static_cast<int>(temp), "OK");
}

math::Output<double> Math::divide(const Input& input) {
    if (input.second == 0)
        return Output<double>(0.0, "ERROR");

    return Output<double>(
        static_cast<double>(input.first) / input.second, "OK");
}

math::Output<int> Math::pow(const Input& input) {
    if (input.second == 0) return Output<int>(1, "OK");
    if (input.second < 0)
        return Output<int>(0, "ERROR: отрицательная степень не поддерживается");

    int result = 1;
    for (int i = 0; i < input.second; ++i) {
        long long temp = static_cast<long long>(result) * input.first;
        if (temp > INT_MAX_VAL || temp < INT_MIN_VAL) {
            return Output<int>(0, "ERROR: переполнение при возведении в степень");
        }
        result = static_cast<int>(temp);
    }

    return Output<int>(result, "OK");
}

math::Output<int> Math::factorial(const Input& input) {
    if (input.first < 0)
        return Output<int>(
            0, "ERROR: факториал может быть только нулевым и положительным");
    if (input.first > 12)
        return Output<int>(0, "ERROR: переполнение факториала");

    std::function<int(int)> factorial = [&](int n) -> int {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    };
    int result = factorial(input.first);
    return Output<int>(result, "OK");
}

}  // namespace math
