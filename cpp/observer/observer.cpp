#include <iostream>
#include <memory>
#include <set>


struct Message {
    int temp;
    int hum;
};


class IObserver {
public:
    virtual void update(const Message &message) = 0;
};


class IPublisher {
public:
    virtual void addObserver(std::shared_ptr<IObserver> observer) = 0;

    virtual void removeObserver(std::shared_ptr<IObserver> observer) = 0;

protected:

    virtual void notify() = 0;
};


class WeatherData : public IPublisher {
public:
    void addObserver(std::shared_ptr<IObserver> observer) override {
        observers.insert(observer);
    }

    void removeObserver(std::shared_ptr<IObserver> observer) override {
        observers.erase(observer);
    }

    void updateData() {
        temp += 1;
        hum += 1;
        notify();
    }

protected:
    void notify() override {
        Message msg{temp, hum};
        for (auto &observer : observers) {
            observer->update(msg);
        }
    }

private:
    std::set<std::shared_ptr<IObserver>> observers;
    int temp = 0;
    int hum = 0;
};


class WeatherScreen : public IObserver {
public:
    void update(const Message &message) override {
        std::cout << message.temp << ' ' << message.hum << std::endl;
    }
};


int main() {
    WeatherData data;
    auto screen1 = std::make_shared<WeatherScreen>();
    auto screen2 = std::make_shared<WeatherScreen>();
    data.addObserver(screen1);
    data.addObserver(screen2);
    data.updateData();
    data.removeObserver(screen2);
    data.updateData();
    data.removeObserver(screen1);
    return 0;
}
