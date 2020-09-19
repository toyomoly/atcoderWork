using System;

namespace ConsoleApp1
{
    class ABC179A
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine();

            if (S.Substring(S.Length - 1).Equals("s"))
            {
                Console.WriteLine(S + "es");
            }
            else
            {
                Console.WriteLine(S + "s");
            }
        }
    }
}
