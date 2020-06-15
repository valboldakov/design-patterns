#include <iostream>
#include <memory>

class IChair {
public:
    virtual void sit_on() = 0;
};


class ITable {
public:
    virtual void eat_from() = 0;
};


class IFurnitureFactory {
public:
    virtual std::shared_ptr<IChair> create_chair() = 0;

    virtual std::shared_ptr<ITable> create_table() = 0;
};


class ArtChair : public IChair {
public:
    void sit_on() override {
        std::cout << "Sitting on art chair." << std::endl;
    }
};


class ArtTable : public ITable {
public:
    void eat_from() override {
        std::cout << "Eating from art table." << std::endl;
    }
};


class ArtFurnitureFactory : public IFurnitureFactory {
public:
    std::shared_ptr<IChair> create_chair() override {
        return std::make_shared<ArtChair>();
    }

    std::shared_ptr<ITable> create_table() override {
        return std::make_shared<ArtTable>();
    }
};


int main() {
    ArtFurnitureFactory factory;
    auto chair = factory.create_chair();
    auto table = factory.create_table();
    chair->sit_on();
    table->eat_from();
    return 0;
}
