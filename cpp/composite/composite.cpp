#include <string>
#include <utility>
#include <memory>
#include <iostream>
#include <vector>


class MenuElement {
public:
    explicit MenuElement(std::string descr) : _descr(std::move(descr)) {
    }

    virtual std::string get_descr() {
        return _descr;
    }

protected:
    std::string _descr;
};

class Menu : public MenuElement {
public:
    explicit Menu(std::string descr) : MenuElement(std::move(descr)) {
    }

    void add_element(const std::shared_ptr<MenuElement> &elem) {
        elements.push_back(elem);
    }

    std::string get_descr() override {
        std::string res;
        res += _descr + "\n";
        for (size_t i = 0; i < elements.size() - 1; ++i) {
            res += elements[i]->get_descr() + "\n";
        }
        return res + elements[elements.size() - 1]->get_descr();
    }

private:
    std::vector<std::shared_ptr<MenuElement>> elements;
};

class MenuItem : public MenuElement {
public:
    explicit MenuItem(std::string descr) : MenuElement(std::move(descr)) {}
};

int main() {
    auto sub_menu = std::make_shared<Menu>("Submenu");
    sub_menu->add_element(std::make_shared<MenuItem>("Ice Cream"));
    sub_menu->add_element(std::make_shared<MenuItem>("Apple"));
    Menu menu("Menu");
    menu.add_element(std::make_shared<MenuItem>("Meat"));
    menu.add_element(sub_menu);
    menu.add_element(std::make_shared<MenuItem>("Pineapple"));
    std::cout << menu.get_descr() << std::endl;
    return 0;
}
