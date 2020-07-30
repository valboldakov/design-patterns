using System;
using System.Collections.Generic;

namespace flyweight
{
    class Flyweight
    {
        public int BigTexture { get; private set; }
        public int Id { get; private set; }

        public Flyweight(int texture, int id)
        {
            BigTexture = texture;
            Id = id;
        }
    }

    class Car
    {
        private readonly Flyweight _flyweight;

        public Car(Flyweight flyweight)
        {
            _flyweight = flyweight;
        }

        public void Draw()
        {
            Console.WriteLine($"Drawing texture {_flyweight.BigTexture} with id={_flyweight.Id}");
        }
    }

    class CarFactory
    {
        private readonly Dictionary<int, Flyweight> _flyweights;
        private readonly Random _random;

        public CarFactory()
        {
            _flyweights = new Dictionary<int, Flyweight>();
            _random = new Random();
        }

        public Car Create(int textureConfig)
        {
            if (!_flyweights.ContainsKey(textureConfig))
            {
                _flyweights.Add(textureConfig, new Flyweight(textureConfig, _random.Next()));
            }

            return new Car(_flyweights[textureConfig]);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var factory = new CarFactory();
            var car1 = factory.Create(1);
            var car2 = factory.Create(2);
            var car3 = factory.Create(1);
            var car4 = factory.Create(3);
            car1.Draw();
            car2.Draw();
            car3.Draw();
            car4.Draw();
        }
    }
}