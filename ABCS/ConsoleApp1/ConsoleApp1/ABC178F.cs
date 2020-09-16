using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC178F
    {
        // https://atcoder.jp/contests/abc178/tasks/abc178_f

        const long m = 1000000007;
        static int[] A = new int[200001];
        static int[] B = new int[200001];

        static int[] CA = new int[200001];
        static int[] CB = new int[200001];

        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());
            var itemsA = Console.ReadLine().Split();
            var itemsB = Console.ReadLine().Split();

            for (int i = 0; i < N; i++)
            {
                A[i] = Int32.Parse(itemsA[i]);
                B[i] = Int32.Parse(itemsB[i]);

                CA[A[i]] += 1;
                CB[B[i]] += 1;
            }

            for (int i = 1; i <= N; i++)
            {
                if (CA[i] + CB[i] > N)
                {
                    Console.WriteLine("No");
                    return;
                }
            }

            int max = 0;

            for (int i = 1; i <= N; i++)
            {
                CA[i] += CA[i - 1];
                CB[i] += CB[i - 1];

                max = Math.Max(max, CA[i] - CB[i - 1]);
            }

            Console.WriteLine("Yes");

            for (int i = 0; i < N - 1; i++)
            {
                int index = (i + N - max) % N;
                Console.Write(B[index] + " ");
            }

            int index2 = (N - 1 + N - max) % N;
            Console.WriteLine(B[index2]);
        }
    }
}
