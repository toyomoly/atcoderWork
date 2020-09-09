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

            for (int i = 0; i < M; i++)
            {
                var AB = Console.ReadLine().Split();
                int A = Int32.Parse(AB[0]);
                int B = Int32.Parse(AB[1]);

                bool a = hasFriend(A);
                bool b = hasFriend(B);

                if (a && b)
                {
                    int C = getParent(A);
                    int D = getParent(B);

                    if (C != D)
                    {
                        ls[C - 1] += ls[D - 1]; // 人数加算
                        setParent(D, C);
                    }
                }
                else if (a)
                {
                    int C = getParent(A);
                    int D = B;

                    ls[C - 1] -= 1; // 人数加算
                    setParent(D, C);
                }
                else if (b)
                {
                    int C = getParent(B);
                    int D = A;

                    ls[C - 1] -= 1; // 人数加算
                    setParent(D, C);
                }
                else
                {
                    ls[A - 1] = -1; // 人数加算
                    setParent(B, A);
                }
            }

            int max = 1;
            for (int i = 0; i < N; i++)
            {
                if (ls[i] < 0)
                {
                    max = Math.Max(max, -ls[i] + 1);
                }
            }

            Console.WriteLine(max);
        }

        static int getParent(int A)
        {
            if (ls[A - 1] > 0)
            {
                return getParent(ls[A - 1]);
            }
            return A;
        }

        static void setParent(int A, int B)
        {
            ls[A - 1] = B;
        }

        static bool hasFriend(int A)
        {
            return (ls[A - 1] != 0);
        }
    }
}
