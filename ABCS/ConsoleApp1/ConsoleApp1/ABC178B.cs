using System;

namespace ConsoleApp1
{
    class ABC178B
    {
        // https://atcoder.jp/contests/abc177/tasks/abc177_b
        static void Main(string[] args)
        {
            var S = Console.ReadLine().ToCharArray();
            var T = Console.ReadLine().ToCharArray();

            var max = 0;

            for (int i = 0; i < S.Length - T.Length + 1; i++)
            {
                int a = comp(S, T, i);
                if (a > max)
                {
                    max = a;
                }
            }

            Console.WriteLine(T.Length - max);
        }

        static int comp(char[] S, char[] T, int i)
        {
            var c = 0;

            for (int j = 0; j < T.Length; j++)
            {
                if (S[j + i] == T[j])
                {
                    c++;
                }
            }

            return c;
        }
    }
}
