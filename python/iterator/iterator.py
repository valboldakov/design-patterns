from abc import ABC


class IIterator(ABC):
    def has_next(self) -> bool:
        pass

    def next(self):
        pass


class MenuItem:
    def __init__(self, description: str):
        self._description = description

    def get_description(self):
        return self._description


class MenuItemIterator(IIterator):
    def __init__(self, items):
        self._items = items
        self._current_position = 0

    def has_next(self) -> bool:
        return self._current_position < len(self._items)

    def next(self):
        next_item = self._items[self._current_position]
        self._current_position += 1
        return next_item


class IMenu(ABC):
    def get_iterator(self) -> IIterator:
        pass

    def add_item(self, item: MenuItem):
        pass


class Menu(IMenu):
    def __init__(self):
        self._items = []

    def get_iterator(self) -> IIterator:
        return MenuItemIterator(self._items)

    def add_item(self, item: MenuItem):
        self._items.append(item)


def main():
    menu = Menu()
    menu.add_item(MenuItem("Ice Cream"))
    menu.add_item(MenuItem("Soup"))
    it = menu.get_iterator()
    while it.has_next():
        print(it.next().get_description())


if __name__ == '__main__':
    main()
