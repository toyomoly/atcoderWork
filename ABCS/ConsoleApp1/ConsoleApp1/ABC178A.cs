using System;

namespace ConsoleApp1
{
    class ABC178A
    {
        static void Main(string[] args)
        {
            var DTS = Console.ReadLine().Split();
            int D = Int32.Parse(DTS[0]);
            int T = Int32.Parse(DTS[1]);
            int S = Int32.Parse(DTS[2]);

            // Dメートル、T分後、分速Sメートル
            if (D <= T * S)
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");
            }
        }
    }
}
