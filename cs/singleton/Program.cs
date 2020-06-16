using System;
using System.Threading;

namespace singleton
{
    class Pool
    {
        private static readonly Lazy<Pool> Instance = new Lazy<Pool>(() => new Pool());
        public int I { get; private set; }

        private Pool()
        {
            I = 0;
        }

        public void Inc()
        {
            I += 1;
        }

        public static Pool GetInstance()
        {
            return Instance.Value;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Pool.GetInstance().I);
            Pool.GetInstance().Inc();
            Pool.GetInstance().Inc();
            Console.WriteLine(Pool.GetInstance().I);
        }
    }
}