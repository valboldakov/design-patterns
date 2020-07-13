using System;

namespace facade
{
    interface ITable
    {
        void GetFoodFrom();
    }

    class NormalTable : ITable
    {
        public void GetFoodFrom()
        {
            Console.WriteLine("Getting food from the table!");
        }
    }

    interface IChair
    {
        void SitOn();
    }

    class NormalChair : IChair
    {
        public void SitOn()
        {
            Console.WriteLine("Sitting on the chair!");
        }
    }

    class KitchenFacade
    {
        private ITable _table;
        private IChair _chair;

        public KitchenFacade(ITable table, IChair chair)
        {
            _table = table;
            _chair = chair;
        }

        public void Eat()
        {
            _chair.SitOn();
            _table.GetFoodFrom();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var facade = new KitchenFacade(new NormalTable(), new NormalChair());
            facade.Eat();
        }
    }
}