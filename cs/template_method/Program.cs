using System;

namespace template_method
{
    abstract class CaffeineBeverage
    {
        protected virtual void AddComponents()
        {
            throw new NotImplementedException();
        }

        protected virtual void BoilWater()
        {
            Console.WriteLine("Boiling Water!");
        }

        public void Prepare()
        {
            BoilWater();
            AddComponents();
        }
    }

    class Tea : CaffeineBeverage
    {
        protected override void AddComponents()
        {
            Console.WriteLine("Adding Lemons!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var tea = new Tea();
            tea.Prepare();
        }
    }
}