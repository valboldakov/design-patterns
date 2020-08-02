#include <iostream>

class Expression {
public:
    virtual bool interpret(const std::string &str) = 0;
};

class Digit : public Expression {
public:
    bool interpret(const std::string &str) override {
        if (str == "0") {
            return true;
        }
        if (str == "1") {
            return true;
        }
        if (str == "2") {
            return true;
        }
        if (str == "3") {
            return true;
        }
        if (str == "4") {
            return true;
        }
        if (str == "5") {
            return true;
        }
        if (str == "6") {
            return true;
        }
        if (str == "7") {
            return true;
        }
        if (str == "8") {
            return true;
        }
        if (str == "9") {
            return true;
        }
        return false;
    }
};

class Number : public Expression {
public:
    bool interpret(const std::string &str) override {
        if (str.empty()) {
            return false;
        }
        std::string first_digit(1, str[0]);
        std::string next_digits(str.substr(1));
        return Digit().interpret(str) || Digit().interpret(first_digit) && Number().interpret(next_digits);
    }
};

int main() {
    Number number;
    std::cout << number.interpret("101") << std::endl;
    std::cout << number.interpret("") << std::endl;
    std::cout << number.interpret("1f1") << std::endl;
    std::cout << number.interpret("101f") << std::endl;
    return 0;
}
