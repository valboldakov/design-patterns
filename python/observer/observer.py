from abc import ABC


class Message:
    def __init__(self, temp: int, hum: int):
        self.temp = temp
        self.hum = hum

    def __str__(self):
        return f"{self.temp} {self.hum}"


class IObserver(ABC):
    def update(self, message: Message):
        pass


class IPublisher(ABC):
    def add_observer(self, observer: IObserver):
        pass

    def remove_observer(self, observer: IObserver):
        pass

    def notify(self):
        pass


class WeatherData(IPublisher):
    def __init__(self):
        self._temp = 0
        self._hum = 0
        self._observers = set()

    def add_observer(self, observer: IObserver):
        self._observers.add(observer)

    def remove_observer(self, observer: IObserver):
        self._observers.remove(observer)

    def notify(self):
        msg = Message(temp=self._temp, hum=self._hum)
        for observer in self._observers:
            observer.update(msg)

    def update_data(self):
        self._temp = self._temp + 1
        self._hum = self._hum + 1
        self.notify()


class WeatherScreen(IObserver):
    def update(self, message: Message):
        print(message)


if __name__ == '__main__':
    weatherData = WeatherData()
    screen1 = WeatherScreen()
    screen2 = WeatherScreen()
    weatherData.add_observer(screen1)
    weatherData.add_observer(screen2)
    weatherData.update_data()
    weatherData.update_data()
    weatherData.remove_observer(screen1)
    weatherData.update_data()
