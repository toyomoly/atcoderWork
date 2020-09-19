using System;

namespace ConsoleApp1
{
    class ABC179B
    {
        // https://atcoder.jp/contests/abc179/tasks/abc179_b
        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());

            int x = 0;
            bool result = false;

            for (int i = 0; i < N; i++)
            {
                var ab = Console.ReadLine().Split();
                int a = Int32.Parse(ab[0]);
                int b = Int32.Parse(ab[1]);

                if (a == b)
                {
                    x++;
                    if (x >= 3)
                    {
                        result = true;
                    }
                }
                else
                {
                    x = 0;
                }
            }
            Console.WriteLine(result ? "Yes" : "No");
        }
    }
}
