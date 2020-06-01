package main

import "fmt"

type Message struct {
	temp int
	hum  int
}

type IPublisher interface {
	AddObserver(observer IObserver)
	RemoveObserver(observer IObserver)
	Notify()
}

type IObserver interface {
	Update(msg Message)
}

type WeatherData struct {
	temp      int
	hum       int
	observers []IObserver
}

func (weatherData *WeatherData) AddObserver(observer IObserver) {
	weatherData.observers = append(weatherData.observers, observer)
}

func (weatherData *WeatherData) RemoveObserver(observer IObserver) {
	observerIdx := -1
	for i, observer_ := range weatherData.observers {
		if observer_ == observer {
			observerIdx = i
		}
	}
	if observerIdx != -1 {
		weatherData.observers[len(weatherData.observers)-1], weatherData.observers[observerIdx] = weatherData.observers[observerIdx], weatherData.observers[len(weatherData.observers)-1]
		weatherData.observers = weatherData.observers[:len(weatherData.observers)-1]
	}
}

func (weatherData *WeatherData) Notify() {
	msg := Message{
		temp: weatherData.temp,
		hum:  weatherData.hum,
	}
	for _, observer := range weatherData.observers {
		observer.Update(msg)
	}
}

func (weatherData *WeatherData) UpdateData() {
	weatherData.temp += 1
	weatherData.hum += 1
	weatherData.Notify()
}

type WeatherScreen struct {
}

func (screen WeatherScreen) Update(msg Message) {
	fmt.Println(msg.temp, msg.hum)
}

func main() {
	weatherData := WeatherData{
		temp:      0,
		hum:       0,
		observers: make([]IObserver, 0),
	}
	screen1 := WeatherScreen{}
	screen2 := WeatherScreen{}
	weatherData.AddObserver(screen1)
	weatherData.AddObserver(screen2)
	weatherData.UpdateData()
	weatherData.UpdateData()
	weatherData.RemoveObserver(screen1)
	weatherData.UpdateData()
}
