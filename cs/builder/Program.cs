using System;

namespace builder
{
    class House
    {
        private bool _wasAddedSomething;
        public string Description { get; private set; }

        public House()
        {
            Description = "House";
            _wasAddedSomething = false;
        }

        public void AddThing(string thing)
        {
            if (!_wasAddedSomething)
            {
                _wasAddedSomething = true;
                Description += $" with {thing}";
            }
            else
            {
                Description += $" and {thing}";
            }
        }
    }

    interface IBuilder
    {
        void Reset();
        void AddGarden();
        void AddGarage();
    }

    class Builder : IBuilder
    {
        public House House { get; private set; }

        public Builder()
        {
            House = new House();
        }

        public void Reset()
        {
            House = new House();
        }

        public void AddGarden()
        {
            House.AddThing("garden");
        }

        public void AddGarage()
        {
            House.AddThing("garage");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var builder = new Builder();
            builder.AddGarage();
            builder.Reset();
            builder.AddGarden();
            builder.AddGarage();
            Console.WriteLine(builder.House.Description);
        }
    }
}