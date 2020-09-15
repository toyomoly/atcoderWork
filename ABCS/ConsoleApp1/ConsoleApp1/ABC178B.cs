using System;

namespace ConsoleApp1
{
    class ABC178B
    {
        // https://atcoder.jp/contests/abc178/tasks/abc178_b
        static void Main(string[] args)
        {
            var items = Console.ReadLine().Split();
            Int64 a = Int64.Parse(items[0]);
            Int64 b = Int64.Parse(items[1]);
            Int64 c = Int64.Parse(items[2]);
            Int64 d = Int64.Parse(items[3]);

            Int64 max = Math.Max(a * c, a * d);
            max = Math.Max(max, b * c);
            max = Math.Max(max, b * d);

            Console.WriteLine(max);
        }
    }
}
