using System;

namespace ConsoleApp1
{
    class ABC117C
    {
        // https://atcoder.jp/contests/abc177/tasks/abc177_c
        static void Main(string[] args)
        {
            const UInt64 m = 1000000007;

            uint N = uint.Parse(Console.ReadLine());
            var items = Console.ReadLine().Split();

            UInt64[] A = Array.ConvertAll(items, UInt64.Parse);

            UInt64 p = 0;
            UInt64 sum = 0;

            for (var i = N - 1; i > 0; i--)
            {
                p = (p + A[i]) % m;
                sum = (sum + p * A[i - 1]) % m;
            }

            Console.WriteLine(sum);
        }
    }
}
