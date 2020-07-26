from abc import ABC


class IPhoneState(ABC):
    def lock_screen(self):
        raise NotImplementedError()

    def increase_audio(self):
        raise NotImplementedError()


class IPhone(ABC):
    def lock_screen(self):
        raise NotImplementedError()

    def increase_audio(self):
        raise NotImplementedError()

    def set_state(self, state: IPhoneState):
        raise NotImplementedError()


class UnlockedPhoneState(IPhoneState):
    def __init__(self, phone: IPhone):
        self._phone = phone

    def lock_screen(self):
        self._phone.set_state(LockedPhoneState(self._phone))

    def increase_audio(self):
        print("Increasing!")


class LockedPhoneState(IPhoneState):
    def __init__(self, phone: IPhone):
        self._phone = phone

    def lock_screen(self):
        self._phone.set_state(UnlockedPhoneState(self._phone))

    def increase_audio(self):
        print("Phone is locked!")


class Phone(IPhone):
    def __init__(self):
        self._state = LockedPhoneState(self)

    def lock_screen(self):
        self._state.lock_screen()

    def increase_audio(self):
        self._state.increase_audio()

    def set_state(self, state: IPhoneState):
        self._state = state


def main():
    phone = Phone()
    phone.increase_audio()
    phone.lock_screen()
    phone.increase_audio()
    phone.lock_screen()
    phone.increase_audio()


if __name__ == '__main__':
    main()
