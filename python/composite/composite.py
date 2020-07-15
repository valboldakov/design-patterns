from abc import ABC


class MenuElement(ABC):
    def __init__(self, description):
        self._description = description

    def get_description(self):
        return self._description


class MenuItem(MenuElement):
    pass


class Menu(MenuElement):
    def __init__(self, description):
        super().__init__(description)
        self._items = []

    def add_menu_element(self, element: MenuElement):
        self._items.append(element)

    def get_description(self):
        res = f"{self._description}\n"
        for el in self._items[:-1]:
            res += f"{el.get_description()}\n"
        res += self._items[-1].get_description()
        return res


def main():
    sub_menu = Menu("Submenu")
    sub_menu.add_menu_element(MenuItem("Ice Cream"))
    sub_menu.add_menu_element(MenuItem("Apple"))
    menu = Menu("Menu")
    menu.add_menu_element(MenuItem("Meat"))
    menu.add_menu_element(sub_menu)
    menu.add_menu_element(MenuItem("Pineapple"))
    print(menu.get_description())


if __name__ == '__main__':
    main()
