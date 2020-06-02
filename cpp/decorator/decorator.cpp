#include <iostream>
#include <memory>
#include <utility>


class Beverage {
public:
    virtual float get_cost() = 0;
};


class Coffee : public Beverage {
public:
    float get_cost() override {
        return _cost;
    }

private:
    float _cost = 2.0;
};


class BeverageDecorator : public Beverage {
protected:
    explicit BeverageDecorator(std::shared_ptr<Beverage> beverage_) {
        beverage = std::move(beverage_);
    };

    std::shared_ptr<Beverage> beverage;
};


class Mocha : public BeverageDecorator {
public:
    explicit Mocha(std::shared_ptr<Beverage> beverage_) : BeverageDecorator(std::move(beverage_)) {
    }

    float get_cost() override {
        return beverage->get_cost() + _cost;
    }

private:
    float _cost = 0.3;
};


int main() {
    auto coffee = std::make_shared<Coffee>();
    auto coffee_with_mocha = std::make_shared<Mocha>(coffee);
    std::cout << coffee_with_mocha->get_cost() << std::endl;
    auto coffee_with_2_mocha = std::make_shared<Mocha>(coffee_with_mocha);
    std::cout << coffee_with_2_mocha->get_cost() << std::endl;
    return 0;
}
