using System;

namespace abstract_factory
{
    interface IChair
    {
        void SitOn();
    }

    interface ITable
    {
        void EatFrom();
    }

    interface IFurnitureFactory
    {
        IChair CreateChair();
        ITable CreateTable();
    }

    class ArtChair : IChair
    {
        public void SitOn()
        {
            Console.WriteLine("Sitting on art chair.");
        }
    }

    class ArtTable : ITable
    {
        public void EatFrom()
        {
            Console.WriteLine("Eating from art table.");
        }
    }

    class ArtFurnitureFactory : IFurnitureFactory
    {
        public IChair CreateChair()
        {
            return new ArtChair();
        }

        public ITable CreateTable()
        {
            return new ArtTable();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IFurnitureFactory factory = new ArtFurnitureFactory();
            var chair = factory.CreateChair();
            var table = factory.CreateTable();
            chair.SitOn();
            table.EatFrom();
        }
    }
}