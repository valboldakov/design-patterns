#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <iostream>

template<typename T>
class IIterator {
public:
    virtual T next() = 0;

    virtual bool has_next() = 0;
};

class MenuItem {
public:
    explicit MenuItem(std::string description) : _description(std::move(description)) {
    }

    std::string get_description() {
        return _description;
    }

private:
    std::string _description;
};

class MenuItemIterator : public IIterator<std::shared_ptr<MenuItem>> {
public:
    explicit MenuItemIterator(const std::vector<std::shared_ptr<MenuItem>> &arr) : _arr(arr) {
        _current_pos = 0;
    }

    std::shared_ptr<MenuItem> next() override {
        return _arr[_current_pos++];
    }

    bool has_next() override {
        return _current_pos < _arr.size();
    }

private:
    const std::vector<std::shared_ptr<MenuItem>> &_arr;
    uint32_t _current_pos;
};

class IMenu {
public:
    virtual std::shared_ptr<IIterator<std::shared_ptr<MenuItem>>> get_iterator() = 0;

    virtual void add_item(std::shared_ptr<MenuItem> item) = 0;
};

class Menu : IMenu {
public:
    std::shared_ptr<IIterator<std::shared_ptr<MenuItem>>> get_iterator() override {
        return std::make_shared<MenuItemIterator>(elements);
    }

    void add_item(std::shared_ptr<MenuItem> item) override {
        elements.push_back(item);
    }

private:
    std::vector<std::shared_ptr<MenuItem>> elements;
};

int main() {
    Menu menu;
    menu.add_item(std::make_shared<MenuItem>("Ice Cream"));
    menu.add_item(std::make_shared<MenuItem>("Soup"));
    auto itr = menu.get_iterator();
    while (itr->has_next()) {
        std::cout << itr->next()->get_description() << std::endl;
    }
    return 0;
}
