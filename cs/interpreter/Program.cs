using System;

namespace interpreter
{
    interface IExpression
    {
        bool Interpret(string str);
    }

    class Digit : IExpression
    {
        public bool Interpret(string str)
        {
            var isDigit = str switch
            {
                "0" => true,
                "1" => true,
                "2" => true,
                "3" => true,
                "4" => true,
                "5" => true,
                "6" => true,
                "7" => true,
                "8" => true,
                "9" => true,
                _ => false
            };
            return isDigit;
        }
    }

    class Number : IExpression
    {
        public bool Interpret(string str)
        {
            return new Digit().Interpret(str) ||
                   new Digit().Interpret(str[0].ToString()) && new Number().Interpret(str.Substring(1));
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(new Number().Interpret("123"));
            Console.WriteLine(new Number().Interpret("f123"));
            Console.WriteLine(new Number().Interpret("123f34"));
        }
    }
}