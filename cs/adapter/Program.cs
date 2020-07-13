using System;

namespace adapter
{
    interface IDuck
    {
        void Quack();
        void Fly();
    }

    interface ITurkey
    {
        void Fly();
        void Gobble();
    }

    abstract class Duck : IDuck
    {
        public virtual void Quack()
        {
            Console.WriteLine("Quacking!");
        }

        public virtual void Fly()
        {
            Console.WriteLine("Flying!");
        }
    }

    class Turkey : Duck
    {
        public override void Quack()
        {
            Console.WriteLine("Gobbling!");
        }
    }

    class TurkeyAdapter : ITurkey
    {
        private IDuck _duck;

        public TurkeyAdapter(IDuck duck)
        {
            _duck = duck;
        }

        public void Fly()
        {
            _duck.Fly();
        }

        public void Gobble()
        {
            _duck.Quack();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var turkey = new Turkey();
            var adapter = new TurkeyAdapter(turkey);
            adapter.Fly();
            adapter.Gobble();
        }
    }
}