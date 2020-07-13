#include <iostream>
#include <memory>

class IChair {
public:
    virtual void sit_on() = 0;
};

class NormalChair : public IChair {
    void sit_on() override {
        std::cout << "Sitting on the chair!" << std::endl;
    }
};

class ITable {
public:
    virtual void eat_from() = 0;
};

class NormalTable : public ITable {
    void eat_from() override {
        std::cout << "Eating from the table!" << std::endl;
    }
};


class KitchenFacade {
public:
    KitchenFacade(std::shared_ptr<ITable> table, std::shared_ptr<IChair> chair) : _table(std::move(table)),
                                                                                  _chair(std::move(chair)) {
    }

    void eat() {
        _chair->sit_on();
        _table->eat_from();
    }

private:
    std::shared_ptr<ITable> _table;
    std::shared_ptr<IChair> _chair;
};


int main() {
    KitchenFacade facade(std::make_shared<NormalTable>(), std::make_shared<NormalChair>());
    facade.eat();
    return 0;
}
