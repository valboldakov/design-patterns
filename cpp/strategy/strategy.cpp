#include <iostream>
#include <memory>
#include <utility>


class IFlyBehaviour {
public:
    virtual void fly() = 0;
};


class LowFlyBehaviour : public IFlyBehaviour {
public:
    void fly() override {
        std::cout << "Flying low!" << std::endl;
    }
};


class HighFlyBehaviour : public IFlyBehaviour {
public:
    void fly() override {
        std::cout << "Flying high!" << std::endl;
    }
};


class Duck {
public:
    void fly() {
        _behaviour->fly();
    }

protected:
    explicit Duck(std::shared_ptr<IFlyBehaviour> behaviour) {
        _behaviour = std::move(behaviour);
    }

private:

    std::shared_ptr<IFlyBehaviour> _behaviour;
};


class LittleDuck : public Duck {
public:
    LittleDuck() : Duck(std::shared_ptr<IFlyBehaviour>(new LowFlyBehaviour)) {
    }
};


class BigDuck : public Duck {
public:
    BigDuck() : Duck(std::shared_ptr<IFlyBehaviour>(new HighFlyBehaviour)) {
    }
};


int main() {
    LittleDuck littleDuck;
    littleDuck.fly();
    BigDuck bigDuck;
    bigDuck.fly();  
    return 0;
}
