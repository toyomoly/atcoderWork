using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC179E
    {
        // https://atcoder.jp/contests/abc179/tasks/abc179_e

        static void Main(string[] args)
        {
            var items = Console.ReadLine().Split();
            long N = Int64.Parse(items[0]);
            long X = Int64.Parse(items[1]);
            long M = Int64.Parse(items[2]);

            long sum = X;
            long Ai = X;

            if (X < 1)
            {
                Console.WriteLine(0);
                return;
            }

            long[] mo = new long[M];
            long[] Si = new long[M];
            mo[Ai] = 1;
            Si[1] = Ai;

            for (int i = 2; i <= N; i++)
            {
                Ai = Ai * Ai % M;

                if (mo[Ai] > 0)
                {
                    long loopSize = i - mo[Ai];

                    if ((N - i + 1) % loopSize == 0)
                    {
                        long loopCount = (N - i + 1) / loopSize;
                        long loopSum = Si[i - 1] - Si[mo[Ai] - 1];
                        sum += loopSum * loopCount;

                        Console.WriteLine(sum);
                        return;
                    }
                }

                mo[Ai] = i;
                sum += Ai;
                Si[i] = sum;
            }

            Console.WriteLine(sum);
        }
    }
}
