#include <iostream>
#include <memory>
#include <utility>

class SumHandler {
public:
    virtual int sum(int a, int b) = 0;

    void set_next_handler(std::shared_ptr<SumHandler> handler) {
        _next_handler = std::move(handler);
    }

protected:
    std::shared_ptr<SumHandler> _next_handler;
};

class PositiveSumHandler : public SumHandler {
public:
    int sum(int a, int b) override {
        if (a > 0 && b > 0) {
            return a + b;
        }
        if (_next_handler != nullptr) {
            return _next_handler->sum(a, b);
        }
        return 0;
    }
};

class StrangeSumHandler : public SumHandler {
public:
    int sum(int a, int b) override {
        return 42;
    }
};

int main() {
    auto handler1 = std::make_shared<PositiveSumHandler>();
    auto handler2 = std::make_shared<PositiveSumHandler>();
    auto handler3 = std::make_shared<StrangeSumHandler>();
    handler1->set_next_handler(handler2);
    handler2->set_next_handler(handler3);
    std::cout << handler1->sum(-1, 2) << std::endl;
    std::cout << handler1->sum(3, 2) << std::endl;
    return 0;
}
