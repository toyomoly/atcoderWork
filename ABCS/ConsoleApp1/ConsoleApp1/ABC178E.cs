using System;
using System.Collections.Generic;

namespace ConsoleApp1
{
    class ABC178E
    {
        // https://atcoder.jp/contests/abc178/tasks/abc178_e

        const long m = 1000000007;

        const long LUX = 0;
        const long LUY = 1000000001;

        const long LDX = 0;
        const long LDY = 0;

        const long RUX = 1000000001;
        const long RUY = 1000000001;

        const long RDX = 1000000001;
        const long RDY = 0;

        static void Main(string[] args)
        {
            int N = Int32.Parse(Console.ReadLine());

            long lud = long.MaxValue;
            long lux = 0;
            long luy = 1000000001;

            long ldd = long.MaxValue;
            long ldx = 0;
            long ldy = 0;

            long rud = long.MaxValue;
            long rux = 1000000001;
            long ruy = 1000000001;

            long rdd = long.MaxValue;
            long rdx = 1000000001;
            long rdy = 0;

            for (int i = 0; i < N; i++)
            {
                var items = Console.ReadLine().Split();
                long x = Int64.Parse(items[0]);
                long y = Int64.Parse(items[1]);

                long d;
                d = dist(x, y, LUX, LUY);
                if (d < lud)
                {
                    lud = d;
                    lux = x;
                    luy = y;
                }
                d = dist(x, y, LDX, LDY);
                if (d < ldd)
                {
                    ldd = d;
                    ldx = x;
                    ldy = y;
                }
                d = dist(x, y, RUX, RUY);
                if (d < rud)
                {
                    rud = d;
                    rux = x;
                    ruy = y;
                }
                d = dist(x, y, RDX, RDY);
                if (d < rdd)
                {
                    rdd = d;
                    rdx = x;
                    rdy = y;
                }
            }

            Console.WriteLine(
                Math.Max(
                    dist(lux, luy, rdx, rdy),
                    dist(ldx, ldy, rux, ruy)
                )
            );
        }

        static long dist(long dx1, long dy1, long dx2, long dy2)
        {
            return Math.Max(dx1 - dx2, dx2 - dx1) + Math.Max(dy1 - dy2, dy2 - dy1);
        }
    }
}
