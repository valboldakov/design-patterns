from abc import ABC


class IDevice(ABC):
    def enable(self):
        raise NotImplementedError()


class Remote:
    def __init__(self, device: IDevice):
        self._device = device

    def toggle_power(self):
        self._device.enable()


class Tv(IDevice):
    def enable(self):
        print("Enabling TV.")


class Radio(IDevice):
    def enable(self):
        print("Enabling Radio.")


def main():
    remote1 = Remote(Tv())
    remote2 = Remote(Radio())
    remote1.toggle_power()
    remote2.toggle_power()


if __name__ == '__main__':
    main()
