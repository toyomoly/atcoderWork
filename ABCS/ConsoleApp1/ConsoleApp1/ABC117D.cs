using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC117D
    {
        // https://atcoder.jp/contests/abc177/tasks/abc177_d
        static void Main(string[] args)
        {
            var NM = Console.ReadLine().Split();
            int N = Int32.Parse(NM[0]);
            int M = Int32.Parse(NM[1]);

            if (M > 0)
            {
                var hs = new HashSet<int>();
                var ns = new HashSet<(int, int)>();

                var AB = Console.ReadLine().Split();
                int A = Int32.Parse(AB[0]);
                int B = Int32.Parse(AB[1]);

                hs.Add(A);
                hs.Add(B);

                for (int i = 1; i < M; i++)
                {
                    AB = Console.ReadLine().Split();
                    A = Int32.Parse(AB[0]);
                    B = Int32.Parse(AB[1]);

                    if (hs.Contains(A) || hs.Contains(B))
                    {
                        hs.Add(A);
                        hs.Add(B);
                    }
                    else
                    {
                        ns.Add((A, B));
                    }
                }

                var max = hs.Count;
                while (max <= ns.Count)
                {
                    hs = new HashSet<int>();
                    var ns2 = new HashSet<(int, int)>();

                    foreach (var item in ns)
                    {
                        A = item.Item1;
                        B = item.Item2;
                        hs.Add(A);
                        hs.Add(B);
                        break;
                    }
                    foreach (var item in ns)
                    {
                        A = item.Item1;
                        B = item.Item2;

                        if (hs.Contains(A) || hs.Contains(B))
                        {
                            hs.Add(A);
                            hs.Add(B);
                        }
                        else
                        {
                            ns2.Add((A, B));
                        }
                    }

                    max = Math.Max(max, hs.Count);
                    ns = ns2;
                }

                Console.WriteLine(max);
            }
            else
            {
                Console.WriteLine(1);
            }
        }
    }
}
