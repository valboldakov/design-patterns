#include <iostream>
#include <memory>

class Element;

class Visitor {
public:
    void process_element(Element &element) {
        std::cout << "Processing element!" << std::endl;
    }
};

class Element {
public:
    void accept_visitor(Visitor &visitor) {
        visitor.process_element(*this);
    }
};

int main() {
    Visitor visitor;
    Element element;
    element.accept_visitor(visitor);
    return 0;
}
