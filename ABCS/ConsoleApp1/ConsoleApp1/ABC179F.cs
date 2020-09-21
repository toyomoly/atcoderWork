using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC179F
    {
        // https://atcoder.jp/contests/abc179/tasks/abc179_f

        static int[] X = new int[200001];
        static int[] Y = new int[200001];
        static int minX;
        static int minY;
        static long N;

        static void Main(string[] args)
        {
            var items = Console.ReadLine().Split();
            N = Int32.Parse(items[0]);
            long Q = Int64.Parse(items[1]);

            long sum = N * N - (N * 4) + 4;
            minX = (int)N;
            minY = (int)N;

            for (int i = 0; i < N; i++)
            {
                X[i] = (int)N;
                Y[i] = (int)N;
            }

            for (int i = 0; i < Q; i++)
            {
                items = Console.ReadLine().Split();
                int Q1 = Int32.Parse(items[0]);
                int Q2 = Int32.Parse(items[1]);

                if (Q1 == 1)
                {
                    sum -= reverseCol(Q2);
                }
                else
                {
                    sum -= reverseRow(Q2);
                }
            }

            Console.WriteLine(sum);
        }

        static int reverseCol(int x)
        {
            int count = Math.Max(Y[x] - 2, 0);

            if (x < minX)
            {
                count = Math.Max(minY - 2, 0);

                for (int i = x; i < minX; i++)
                {
                    Y[i] = minY;
                }

                minX = x;
            }

            return count;
        }

        static int reverseRow(int y)
        {
            int count = Math.Max(X[y] - 2, 0);

            if (y < minY)
            {
                count = Math.Max(minX - 2, 0);

                for (int i = y; i < minY; i++)
                {
                    X[i] = minX;
                }

                minY = y;
            }

            return count;
        }
    }
}
