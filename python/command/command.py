from abc import ABC


class ICommand(ABC):
    def execute(self):
        pass


class NoCommand(ICommand):
    def execute(self):
        pass


class RemoteController:
    def __init__(self):
        self._onCommand: ICommand = NoCommand()
        self._offCommand: ICommand = NoCommand()

    def set_on_command(self, command: ICommand):
        self._onCommand = command

    def set_off_command(self, command: ICommand):
        self._offCommand = command

    def press_on_button(self):
        self._onCommand.execute()

    def press_off_button(self):
        self._offCommand.execute()


class Bulb:
    def light_on(self):
        print("Light On!")

    def light_off(self):
        print("Light Off!")


class LightOnCommand(ICommand):
    def __init__(self, bulb: Bulb):
        self._bulb = bulb

    def execute(self):
        self._bulb.light_on()


class LightOffCommand(ICommand):
    def __init__(self, bulb: Bulb):
        self._bulb = bulb

    def execute(self):
        self._bulb.light_off()


def main():
    bulb = Bulb()
    controller = RemoteController()
    controller.set_on_command(LightOnCommand(bulb))
    controller.set_off_command(LightOffCommand(bulb))
    controller.press_on_button()
    controller.press_off_button()


if __name__ == '__main__':
    main()
