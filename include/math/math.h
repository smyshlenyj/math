#pragma once
#include <string>

namespace math {
struct Input {
    int first;
    int second;
    char action;

    Input() = default;
    Input(int _first, int _second, char _action) {
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
    Output<int> add(const Input& input);
    Output<int> subtract(const Input& input);
    Output<int> multiply(const Input& input);
    Output<double> divide(const Input& input);
    Output<int> pow(const Input& input);
    Output<int> factorial(const Input& input);
};
}  // namespace math