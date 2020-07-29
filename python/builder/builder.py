class House:
    def __init__(self):
        self._description: str = "House"
        self._was_added = False

    def get_description(self) -> str:
        return self._description

    def add_thing(self, thing: str):
        if not self._was_added:
            self._description += " with "
            self._was_added = True
        else:
            self._description += " and "
        self._description += thing


class Builder:
    def __init__(self):
        self._house = House()

    def reset(self):
        self._house = House()

    def add_garage(self):
        self._house.add_thing("garage")

    def add_garden(self):
        self._house.add_thing("garden")

    def get_house(self):
        return self._house


def main():
    builder = Builder()
    builder.add_garage()
    builder.reset()
    builder.add_garden()
    builder.add_garage()
    print(builder.get_house().get_description())


if __name__ == '__main__':
    main()
