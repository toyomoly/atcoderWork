using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC179D
    {
        // https://atcoder.jp/contests/abc179/tasks/abc179_d

        const long m = 998244353;
        static long[] a = new long[200001];
        static SortedSet<long> S = new SortedSet<long>();
        static int N = 0;

        static void Main(string[] args)
        {
            var NK = Console.ReadLine().Split();
            N = Int32.Parse(NK[0]);
            int K = Int32.Parse(NK[1]);

            for (int i = 0; i < K; i++)
            {
                var LR = Console.ReadLine().Split();
                long L = Int64.Parse(LR[0]);
                long R = Int64.Parse(LR[1]);
                for (long j = L; j <= R; j++)
                {
                    S.Add(j);
                }
            }

            for (int i = N; i > 0; i--)
            {
                a[i] = sub(i);
            }

            Console.WriteLine(a[1]);
        }

        static long sub(int x)
        {
            long result = 0;

            foreach (var d in S)
            {
                if (x + d == N)
                {
                    result++;
                }
                else if (x + d < N)
                {
                    result += a[x + d];
                    result %= m;
                }
            }

            return result % m;
        }
    }
}
