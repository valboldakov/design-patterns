using System;

namespace decorator
{
    public interface IBeverage
    {
        public float get_cost();
    }

    public class Coffee : IBeverage
    {
        public float get_cost()
        {
            return 2.0f;
        }
    }

    public abstract class BeverageDecorator : IBeverage
    {
        protected IBeverage Beverage;

        public BeverageDecorator(IBeverage beverage)
        {
            Beverage = beverage;
        }

        public virtual float get_cost()
        {
            throw new NotImplementedException();
        }
    }

    public class Mocha : BeverageDecorator
    {
        public Mocha(IBeverage beverage) : base(beverage)
        {
        }

        public override float get_cost()
        {
            return Beverage.get_cost() + 0.2f;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var coffee = new Coffee();
            Console.WriteLine(coffee.get_cost());
            var coffeeWithMocha = new Mocha(coffee);
            Console.WriteLine(coffeeWithMocha.get_cost());
            coffeeWithMocha = new Mocha(coffeeWithMocha);
            Console.WriteLine(coffeeWithMocha.get_cost());
        }
    }
}