using System;
using System.Collections.Generic;

namespace iterator
{
    interface IIterator<T>
    {
        bool HasNext();
        T Next();
    }

    class MenuItem
    {
        public string Name { get; private set; }

        public MenuItem(string name)
        {
            Name = name;
        }
    }


    interface IMenu
    {
        string Description { get; }
        void AddItem(MenuItem item);
        IIterator<MenuItem> GetIterator();
    }

    class MenuIterator : IIterator<MenuItem>
    {
        private List<MenuItem> _items;
        private int _currentPosition;

        public MenuIterator(List<MenuItem> items)
        {
            _items = items;
            _currentPosition = 0;
        }

        public bool HasNext()
        {
            return _currentPosition < _items.Count;
        }

        public MenuItem Next()
        {
            return _items[_currentPosition++];
        }
    }

    class Menu : IMenu
    {
        private List<MenuItem> _items;

        public Menu(string description)
        {
            Description = description;
            _items = new List<MenuItem>();
        }

        public string Description { get; }

        public void AddItem(MenuItem item)
        {
            _items.Add(item);
        }

        public IIterator<MenuItem> GetIterator()
        {
            return new MenuIterator(_items);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var menu = new Menu("New Menu");
            menu.AddItem(new MenuItem("Ice Cream"));
            menu.AddItem(new MenuItem("Soup"));
            var it = menu.GetIterator();
            while (it.HasNext())
            {
                Console.WriteLine(it.Next().Name);
            }
        }
    }
}