#include <iostream>
#include <memory>

class Pizza {
public:
    virtual void bake() = 0;
};

class CheesePizza : public Pizza {
public:
    void bake() override {
        std::cout << "Baking cheese pizza!" << std::endl;
    }
};

enum PizzaType {
    Cheese
};

class PizzaStore {
public:
    std::shared_ptr<Pizza> order_pizza(PizzaType type) {
        auto pizza = create_pizza(type);
        pizza->bake();
        return pizza;
    }

protected:
    virtual std::shared_ptr<Pizza> create_pizza(PizzaType type) = 0;
};

class NYPizzaStore : public PizzaStore {
protected:
    std::shared_ptr<Pizza> create_pizza(PizzaType type) override {
        if (type == Cheese) {
            return std::make_shared<CheesePizza>();
        }
        throw std::invalid_argument("Incorrect pizza type");
    }
};

int main() {
    NYPizzaStore store;
    store.order_pizza(Cheese);
    return 0;
}
