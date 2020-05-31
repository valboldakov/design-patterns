using System;

namespace strategy
{
    public interface IFlyBehaviour
    {
        public void Fly();
    }

    public class LowFlyBehaviour : IFlyBehaviour
    {
        public void Fly()
        {
            Console.WriteLine("Flying low!");
        }
    }

    public class HighFlyBehaviour : IFlyBehaviour
    {
        public void Fly()
        {
            Console.WriteLine("Flying high!");
        }
    }

    public abstract class Duck
    {
        private IFlyBehaviour _behaviour;

        public Duck(IFlyBehaviour behaviour)
        {
            _behaviour = behaviour;
        }

        public void Fly()
        {
            _behaviour.Fly();
        }
    }

    public class LittleDuck : Duck
    {
        public LittleDuck() : base(new LowFlyBehaviour())
        {
        }
    }

    public class BigDuck : Duck
    {
        public BigDuck() : base(new HighFlyBehaviour())
        {
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var littleDuck = new LittleDuck();
            littleDuck.Fly();
            var bigDuck = new BigDuck();
            bigDuck.Fly();
        }
    }
}