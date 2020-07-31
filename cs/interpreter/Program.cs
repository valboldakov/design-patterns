using System;

namespace interpreter
{
    class Context
    {
        public int Result { get; set; }
        public int PositionMultiplier { get; set; }
        public string Str { get; set; }
    }

    interface IExpression
    {
        void Interpret(Context context);
    }

    class Digit : IExpression
    {
        public void Interpret(Context context)
        {
            if (context.Str == "")
            {
                throw new NotImplementedException();
            }

            var toAdd = context.Str[0] switch
            {
                '0' => 0,
                '1' => 1,
                '2' => 2,
                '3' => 3,
                '4' => 4,
                '5' => 5,
                '6' => 6,
                '7' => 7,
                '8' => 8,
                '9' => 9,
                _ => throw new NotImplementedException()
            };
            context.Str = context.Str.Remove(0, 1);

            context.Result += toAdd * context.PositionMultiplier;
        }
    }

    class Number : IExpression
    {
        public void Interpret(Context context)
        {
            if (context.Str == "")
            {
                throw new NotImplementedException();
            }

            new Digit().Interpret(context);
            context.PositionMultiplier *= 10;
            if (context.Str != "")
            {
                new Number().Interpret(context);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var context = new Context();
            Console.WriteLine(new Number().Interpret(new Context
            {
                PositionMultiplier = 1,
            });
        }
    }
}