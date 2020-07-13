#include <iostream>
#include <memory>
#include <utility>

class Duck {
public:
    virtual void fly() {
        std::cout << "Flying!" << std::endl;
    }

    virtual void quack() {
        std::cout << "Quacking!" << std::endl;
    }

protected:
    Duck() = default;
};

class ITurkey {
public:
    virtual void fly() = 0;

    virtual void gobble() = 0;
};

class Turkey : public Duck {
    void quack() override {
        std::cout << "Gobbling!" << std::endl;
    }
};

class TurkeyAdapter : public ITurkey {
public:
    explicit TurkeyAdapter(std::shared_ptr<Duck> duck) {
        _duck = std::move(duck);
    }

    void fly() override {
        _duck->fly();
    }

    void gobble() override {
        _duck->quack();
    }

private:
    std::shared_ptr<Duck> _duck;
};

int main() {
    TurkeyAdapter adapter(std::make_shared<Turkey>());
    adapter.fly();
    adapter.gobble();
    return 0;
}