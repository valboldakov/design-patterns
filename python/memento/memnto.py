class Memento:
    def __init__(self):
        self.state: int = 0
        self.hidden_state: int = 0


class Originator:
    def __init__(self):
        self._state: int = 0
        self._hidden_state: int = 2

    def change_state(self, state: int):
        self._state = state
        self._hidden_state += 1

    def save(self) -> Memento:
        memento = Memento()
        memento.state = self._state
        memento.hidden_state = self._hidden_state
        return memento

    def load(self, memento: Memento):
        self._state = memento.state
        self._hidden_state = memento.hidden_state

    def show(self):
        print(self._state)
        print(self._hidden_state)


def main():
    originator = Originator()
    originator.show()
    mem = originator.save()
    originator.change_state(3)
    originator.change_state(4)
    originator.load(mem)
    originator.show()


if __name__ == '__main__':
    main()
