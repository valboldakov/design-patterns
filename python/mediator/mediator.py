from abc import ABC
from typing import Dict, Optional


class Mediator:
    def __init__(self):
        self._handlers: Dict[str, Handler] = {}

    def handle(self, handler_name):
        self._handlers[handler_name].handle()

    def add_handler(self, handler):
        self._handlers[handler.name] = handler


class Handler(ABC):
    def __init__(self, name: str):
        self.name: str = name
        self._mediator: Optional[Mediator] = None

    def set_mediator(self, mediator: Mediator):
        self._mediator = mediator

    def handle(self):
        raise NotImplementedError


class WeatherHandler(Handler):
    def handle(self):
        print(self.name)
        self._mediator.handle("HomeHandler")


class HomeHandler(Handler):
    def handle(self):
        print(self.name)


def main():
    mediator = Mediator()
    home = HomeHandler("HomeHandler")
    weather = WeatherHandler("WeatherHandler")
    mediator.add_handler(home)
    mediator.add_handler(weather)
    weather.set_mediator(mediator)
    home.set_mediator(mediator)
    weather.handle()


if __name__ == '__main__':
    main()
