#include <iostream>


struct Memento {
    int state;
    int hidden_state;
};


class Originator {
public:
    void change_state(int state) {
        _state = state;
        _hidden_state += 1;
    }

    void show() {
        std::cout << _state << " " << _hidden_state << std::endl;
    }

    Memento save() {
        return Memento{_state, _hidden_state};
    }

    void load(const Memento &memento) {
        _state = memento.state;
        _hidden_state = memento.hidden_state;
    }

private:
    int _state = 0;
    int _hidden_state = 2;
};


int main() {
    Originator originator;
    originator.show();
    auto mem = originator.save();
    originator.change_state(3);
    originator.change_state(4);
    originator.show();
    originator.load(mem);
    originator.show();
    return 0;
}
