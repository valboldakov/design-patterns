#include <iostream>
#include <memory>
#include <utility>

class House {
public:
    void add_thing(const std::string &thing) {
        if (!_was_added) {
            _description += " with ";
            _was_added = true;
        } else {
            _description += " and ";
        }
        _description += thing;
    }

    std::string get_description() {
        return _description;
    }

private:
    std::string _description = "House";
    bool _was_added = false;
};

class Builder {
public:
    void add_garage() {
        _house->add_thing("garage");
    }

    void add_garden() {
        _house->add_thing("garden");
    }

    void reset() {
        _house = std::make_shared<House>();
    }

    std::shared_ptr<House> get_result() {
        return _house;
    }

private:
    std::shared_ptr<House> _house = std::make_shared<House>();
};

int main() {
    Builder builder;
    builder.add_garage();
    builder.reset();
    builder.add_garden();
    builder.add_garage();
    std::cout << builder.get_result()->get_description() << std::endl;
    return 0;
}
