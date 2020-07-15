using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace composite
{
    interface IMenu
    {
        string GetDescription();
    }

    class MenuItem : IMenu
    {
        private string _description;

        public MenuItem(string description)
        {
            _description = description;
        }

        public string GetDescription()
        {
            return _description;
        }
    }

    class Menu : IMenu
    {
        private List<IMenu> _menus;
        private string _description;

        public Menu(string description)
        {
            _menus = new List<IMenu>();
            _description = description;
        }

        public void AddMenu(IMenu menu)
        {
            _menus.Add(menu);
        }

        public string GetDescription()
        {
            var strBuilder = new StringBuilder();
            strBuilder.AppendLine(_description);
            for (var i = 0; i < _menus.Count - 1; ++i)
            {
                strBuilder.AppendLine(_menus[i].GetDescription());
            }

            return strBuilder.Append(_menus.Last().GetDescription()).ToString();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var subMenu = new Menu("Submenu");
            subMenu.AddMenu(new MenuItem("Ice Cream"));
            subMenu.AddMenu(new MenuItem("Soup"));
            var menu = new Menu("Menu");
            menu.AddMenu(new MenuItem("Meat"));
            menu.AddMenu(new MenuItem("Apple"));
            menu.AddMenu(subMenu);
            menu.AddMenu(new MenuItem("Pineapple"));
            Console.WriteLine(menu.GetDescription());
        }
    }
}