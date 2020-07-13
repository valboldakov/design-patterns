#include <iostream>
#include <memory>

class CaffeineBeverage {
protected:
    void _boil_water() {
        std::cout << "Boiling Water!" << std::endl;
    }

    virtual void _add_components() {
        throw std::logic_error("Not implemented error.");
    }

public:
    virtual void prepare() {
        _boil_water();
        _add_components();
    }
};

class Tea : public CaffeineBeverage {
protected:
    void _add_components() override {
        std::cout << "Adding Lemons!" << std::endl;
    }
};

int main() {
    Tea tea;
    tea.prepare();
    return 0;
}