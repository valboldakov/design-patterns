#include <iostream>

class Pool {
public:
    static Pool &get_instance() {
        static Pool p;
        return p;
    }

    Pool(const Pool &pool) = delete;

    Pool &operator=(const Pool &pool) = delete;

    void inc() {
        _i += 1;
    }

    int get_i() const {
        return _i;
    }

private:
    Pool() = default;

    int _i = 0;
};

int main() {
    std::cout << Pool::get_instance().get_i() << std::endl;
    Pool::get_instance().inc();
    Pool::get_instance().inc();
    std::cout << Pool::get_instance().get_i() << std::endl;
    return 0;
}
