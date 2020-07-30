#include <iostream>
#include <memory>
#include <utility>
#include <map>

class Flyweight {
public:
    Flyweight(int id, int texture) : _id(id), _texture(texture) {
    }

    int get_id() const {
        return _id;
    }

    int get_texture() const {
        return _texture;
    }

private:
    int _id;
    int _texture;
};

class Car {
public:
    explicit Car(const Flyweight &flyweight) : _flyweight(flyweight) {}

    void draw() {
        std::cout << "Drawing texture " << _flyweight.get_texture() << " with id=" << _flyweight.get_id() << std::endl;
    }

private:
    const Flyweight &_flyweight;
};

class CarFactory {
public:
    Car create_car(int texture_config) {
        if (_flyweights.find(texture_config) == _flyweights.cend()) {
            _flyweights[texture_config] = std::make_shared<Flyweight>(rand(), texture_config);
        }
        return Car(*_flyweights[texture_config]);
    }

private:
    std::map<int, std::shared_ptr<Flyweight>> _flyweights;
};

int main() {
    CarFactory factory;
    Car car1 = factory.create_car(1);
    Car car2 = factory.create_car(1);
    Car car3 = factory.create_car(5);
    Car car4 = factory.create_car(1);
    car1.draw();
    car2.draw();
    car3.draw();
    car4.draw();
    return 0;
}
