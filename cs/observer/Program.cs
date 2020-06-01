using System;
using System.Collections.Generic;

namespace observer
{
    public class Message
    {
        public int Temp { get; set; }
        public int Hum { get; set; }
    }

    interface IObserver
    {
        public void Update(Message message);
    }


    interface IPublisher
    {
        public void Notify();
        public void AddObserver(IObserver observer);
        public void RemoveObserver(IObserver observer);
    }


    class WeatherData : IPublisher
    {
        private int _temp = 0;
        private int _hum = 0;
        private readonly HashSet<IObserver> _observers = new HashSet<IObserver>();

        public void Notify()
        {
            var msg = new Message
            {
                Temp = _temp,
                Hum = _hum
            };
            foreach (var observer in _observers)
            {
                observer.Update(msg);
            }
        }

        public void UpdateData()
        {
            _temp += 1;
            _hum += 1;
            Notify();
        }

        public void AddObserver(IObserver observer)
        {
            _observers.Add(observer);
        }

        public void RemoveObserver(IObserver observer)
        {
            _observers.Remove(observer);
        }
    }


    class WeatherScreen : IObserver
    {
        public void Update(Message message)
        {
            Console.WriteLine($"{message.Hum} {message.Temp}");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var weatherData = new WeatherData();
            var screen1 = new WeatherScreen();
            var screen2 = new WeatherScreen();
            weatherData.AddObserver(screen1);
            weatherData.AddObserver(screen2);
            weatherData.UpdateData();
            weatherData.UpdateData();
            weatherData.RemoveObserver(screen1);
            weatherData.UpdateData();
        }
    }
}