using System;

namespace ConsoleApp1
{
    class ABC179C
    {
        // https://atcoder.jp/contests/abc179/tasks/abc179_c
        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());

            long result = 0;

            for (int A = 1; A < N; A++)
            {
                result += (N - 1) / A;
            }

            Console.WriteLine(result);
        }
    }
}
