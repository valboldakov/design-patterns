using System;

namespace factory_method
{
    abstract class Pizza
    {
        public virtual void Bake()
        {
            throw new NotImplementedException();
        }
    }

    enum PizzaType
    {
        Cheese
    }

    class CheesePizza : Pizza
    {
        public override void Bake()
        {
            Console.WriteLine("Baking cheese pizza!");
        }
    }

    abstract class PizzaStore
    {
        protected virtual Pizza CreatePizza(PizzaType type)
        {
            throw new NotImplementedException();
        }

        public Pizza OrderPizza(PizzaType type)
        {
            var pizza = CreatePizza(type);
            pizza.Bake();
            return pizza;
        }
    }

    class NyPizzaStore : PizzaStore
    {
        protected override Pizza CreatePizza(PizzaType type)
        {
            if (type == PizzaType.Cheese)
            {
                return new CheesePizza();
            }

            throw new ArgumentException();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            PizzaStore store = new NyPizzaStore();
            store.OrderPizza(PizzaType.Cheese);
        }
    }
}