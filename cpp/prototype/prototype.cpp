#include <iostream>
#include <memory>


class Prototype {
public:
    virtual std::shared_ptr<Prototype> clone() = 0;
};

class Shape : public Prototype {
public:
    Shape(int x, int y) : _x(x), _y(y) {
    }

    void show() {
        std::cout << _x << " " << _y << std::endl;
    }

    std::shared_ptr<Prototype> clone() override {
        return std::make_shared<Shape>(_x, _y);
    }

private:
    int _x;
    int _y;
};


int main() {
    Shape shape1(2, 31);
    auto shape2 = shape1.clone();
    shape1.show();
    reinterpret_cast<Shape *>(shape2.get())->show();
    return 0;
}
