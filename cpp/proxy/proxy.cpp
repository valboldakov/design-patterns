#include <iostream>
#include <memory>

class IPhone {
public:
    virtual void call() = 0;
};

class Phone : public IPhone {
public:
    void call() override {
        std::cout << "Calling!" << std::endl;
    }
};

class PhoneProxy : public IPhone {
public:
    void call() override {
        if (_phone == nullptr) {
            std::cout << "Creating phone!" << std::endl;
            _phone = std::make_shared<Phone>();
        }
        _phone->call();
    }

private:
    std::shared_ptr<IPhone> _phone;
};

int main() {
    PhoneProxy phoneProxy;
    phoneProxy.call();
    phoneProxy.call();
    return 0;
}
