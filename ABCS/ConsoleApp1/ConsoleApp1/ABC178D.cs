using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC178D
    {
        // https://atcoder.jp/contests/abc178/tasks/abc178_d

        const long m = 1000000007;
        static long[] a = new long[2001];

        static void Main(string[] args)
        {
            int S = Int32.Parse(Console.ReadLine());

            if (S < 3)
            {
                Console.WriteLine(0);
            }
            else
            {
                Console.WriteLine(sub(S));
            }

            // 8 ->
            //   -0: [8]
            //   -3: [5]
            //   -4: [4]
            //   -5: [3]

            // 9 ->
            //   -0: [9]
            //   -3: [3, 3], [6]
            //   -4: [5]
            //   -5: [4]
            //   -6: [3]


            // 10 -> 
            //   -0: [10]
            //   -3: [3, 4], [4, 3], [7]
            //   -4: [3, 3], [6]
            //   -5: [5]
            //   -6: [4]
            //   -7: [3]
        }

        static long sub(int N)
        {
            if (a[N] > 0)
            {
                return a[N];
            }

            long result = 1;

            if (N >= 6)
            {
                for (int i = 3; i < N - 2; i++)
                {
                    result += sub(N - i);
                    result %= m;
                }
            }

            a[N] = result;
            return result;
        }
    }
}
