#include <iostream>
#include <memory>
#include <utility>

class IDevice {
public:
    virtual void enable() = 0;
};

class Remote {
public:
    explicit Remote(std::shared_ptr<IDevice> device) : _device(std::move(device)) {
    }

    void toggle_power() {
        _device->enable();
    }

private:
    std::shared_ptr<IDevice> _device;
};

class Tv : public IDevice {
public:
    void enable() override {
        std::cout << "Enabling TV." << std::endl;
    }
};

class Radio : public IDevice {
public:
    void enable() override {
        std::cout << "Enabling Radio." << std::endl;
    }
};

int main() {
    Remote remote1(std::make_shared<Radio>());
    Remote remote2(std::make_shared<Tv>());
    remote1.toggle_power();
    remote2.toggle_power();
    return 0;
}
