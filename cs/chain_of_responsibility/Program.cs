using System;

namespace chain_of_responsibility
{
    interface ISumHandler
    {
        ISumHandler Handler { set; }
        int Sum(int a, int b);
    }

    class PositiveSum : ISumHandler
    {
        public ISumHandler Handler { private get; set; }

        public int Sum(int a, int b)
        {
            if (a > 0 && b > 0)
            {
                return a + b;
            }

            return Handler?.Sum(a, b) ?? 0;
        }
    }

    class StrangeSum : ISumHandler
    {
        public ISumHandler Handler { private get; set; }

        public int Sum(int a, int b)
        {
            return -42;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var handler1 = new PositiveSum();
            var handler2 = new PositiveSum();
            var handler3 = new StrangeSum();
            handler1.Handler = handler2;
            handler2.Handler = handler3;
            Console.WriteLine(handler1.Sum(-1, 4));
        }
    }
}