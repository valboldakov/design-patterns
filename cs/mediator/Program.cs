using System;
using System.Collections.Generic;

namespace mediator
{
    interface IHandler
    {
        string Name { get; }
        public void Handle();
    }

    class AHandler : IHandler
    {
        public string Name { get; private set; }
        public Mediator Mediator { private get; set; }

        public AHandler(string name)
        {
            Name = name;
        }

        public void Handle()
        {
            Console.WriteLine(Name);
            Mediator.Handle("WeatherHandler");
        }
    }

    class BHandler : IHandler
    {
        public string Name { get; private set; }
        public Mediator Mediator { private get; set; }

        public BHandler(string name)
        {
            Name = name;
        }

        public void Handle()
        {
            Console.WriteLine(Name);
        }
    }

    class Mediator
    {
        private Dictionary<string, IHandler> _handlers;

        public Mediator()
        {
            _handlers = new Dictionary<string, IHandler>();
        }

        public void AddHandler(IHandler handler)
        {
            _handlers.Add(handler.Name, handler);
        }

        public void Handle(string handlerName)
        {
            if (_handlers.ContainsKey(handlerName))
            {
                _handlers[handlerName].Handle();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var mediator = new Mediator();
            var weather = new BHandler("WeatherHandler");
            var home = new AHandler("HomeHandler");
            mediator.AddHandler(weather);
            mediator.AddHandler(home);
            weather.Mediator = mediator;
            home.Mediator = mediator;
            home.Handle();
        }
    }
}