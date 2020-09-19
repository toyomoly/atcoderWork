using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC179D
    {
        // https://atcoder.jp/contests/abc179/tasks/abc179_d

        const int m = 998244353;
        static int[] a = new int[200001];
        static int[] sum = new int[200001];
        static int[] L = new int[10];
        static int[] R = new int[10];
        static int N = 0;

        static void Main(string[] args)
        {
            var NK = Console.ReadLine().Split();
            N = Int32.Parse(NK[0]);
            int K = Int32.Parse(NK[1]);

            for (int i = 0; i < K; i++)
            {
                var LR = Console.ReadLine().Split();
                L[i] = Int32.Parse(LR[0]);
                R[i] = Int32.Parse(LR[1]);
            }

            a[1] = 1;
            sum[1] = 1;
            for (int i = 2; i <= N; i++)
            {
                for (int j = 0; j < K; j++)
                {
                    int li = Math.Max(i - R[j] - 1, 0);
                    int ri = i - L[j];
                    if (ri < 0) continue;
                    a[i] = (a[i] + sum[ri] - sum[li]) % m;
                    a[i] = (a[i] + m) % m;
                }
                sum[i] = (sum[i - 1] + a[i]) % m;
            }

            Console.WriteLine(a[N]);
        }

    }
}
