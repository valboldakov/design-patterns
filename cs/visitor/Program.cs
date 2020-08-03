using System;

namespace visitor
{
    class Program
    {
        class Visitor
        {
            public void ProcessElement(Element element)
            {
                Console.WriteLine("Processing element!");
            }
        }

        class Element
        {
            private int _data;

            public Element(int data)
            {
                _data = data;
            }

            public void AcceptVisitor(Visitor visitor)
            {
                visitor.ProcessElement(this);
            }
        }

        static void Main(string[] args)
        {
            var visitor = new Visitor();
            var element = new Element(33);
            visitor.ProcessElement(element);
        }
    }
}