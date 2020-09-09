using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC117D
    {
        // https://atcoder.jp/contests/abc177/tasks/abc177_d

        static int[] ls;

        static void Main(string[] args)
        {
            var NM = Console.ReadLine().Split();
            int N = Int32.Parse(NM[0]);
            int M = Int32.Parse(NM[1]);

            ls = new int[N];
            for (int i = 0; i < N; i++)
            {
                ls[i] = -1;
            }

            for (int i = 0; i < M; i++)
            {
                var AB = Console.ReadLine().Split();
                int A = Int32.Parse(AB[0]) - 1;
                int B = Int32.Parse(AB[1]) - 1;

                bool a = hasFriend(A);
                bool b = hasFriend(B);

                int C = A;
                int D = B;

                if (a && b)
                {
                    C = getParent(A);
                    D = getParent(B);

                    if (C == D)
                    {
                        continue;
                    }
                }
                else if (a)
                {
                    C = getParent(A);
                }
                else if (b)
                {
                    C = getParent(B);
                    D = A;
                }

                ls[C] += ls[D]; // 人数加算
                ls[D] = C; // setParent
            }

            int max = 1;
            for (int i = 0; i < N; i++)
            {
                max = Math.Max(max, -ls[i]);
            }

            Console.WriteLine(max);
        }

        static int getParent(int A)
        {
            if (ls[A] > -1)
            {
                ls[A] = getParent(ls[A]);
                return ls[A];
            }
            return A;
        }

        static bool hasFriend(int A)
        {
            return (ls[A] != -1);
        }
    }
}
