using System;

namespace prototype
{
    class Program
    {
        interface IPrototype
        {
            IPrototype Clone();
        }

        class Shape : IPrototype
        {
            private int _x;
            private int _y;

            public Shape(int x, int y)
            {
                _x = x;
                _y = y;
            }

            public IPrototype Clone()
            {
                return new Shape(_x, _y);
            }

            public void Show()
            {
                Console.WriteLine(_x);
                Console.WriteLine(_y);
            }
        }


        static void Main(string[] args)
        {
            var shape1 = new Shape(0, 1);
            var shape2 = (Shape) shape1.Clone();
            shape1.Show();
            shape2.Show();
        }
    }
}