using System;

namespace ConsoleApp1
{
    class ABC178C
    {
        // https://atcoder.jp/contests/abc178/tasks/abc178_c
        static void Main(string[] args)
        {
            const long m = 1000000007;

            uint N = uint.Parse(Console.ReadLine());

            long result = 0;
            long r10 = 10;
            long r9 = 9;
            long r8 = 8;

            if (N > 1)
            {
                // 10^N - 9^N * 2 + 8^N

                for (int i = 1; i < N; i++)
                {
                    r10 = (r10 * 10) % m;
                    r9 = (r9 * 9) % m;
                    r8 = (r8 * 8) % m;
                }

                result = (r10 - r9 - r9 + r8 + m + m) % m;
            }

            Console.WriteLine(result);
        }
    }
}
