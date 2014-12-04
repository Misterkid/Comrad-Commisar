using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
namespace ArrayTest
{
    class Program
    {
        /*
        int[] array;
        int[][] jaggedArray;
        int[,] twoDArray;
         */
        static void Main(string[] args)
        {
            int size = 1000;
            int[] array = new int[size * size];
            int[][] jaggedArray = new int[size][];
            int[,] twoDArray = new int[size, size];
            int x,y;

            long timeArray = 0;
            long timeJagged = 0;
            long timeTwoD = 0;
            for (int i = 0; i < jaggedArray.Length; i++)
                jaggedArray[i] = new int[size];

            for (int i = 0; i < 1000; i++)
            {
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                for (x = 0; x < size; x++)
                {
                    for (y = 0; y < size; y++)
                    {
                        int fake = array[y * size + x];
                    }
                }
                stopWatch.Stop();
                timeArray += stopWatch.ElapsedMilliseconds;
                //Console.WriteLine("Single: " + stopWatch.ElapsedMilliseconds + " ms");
                stopWatch.Reset();
                stopWatch.Start();

                for (x = 0; x < size; x++)
                {
                    for (y = 0; y < size; y++)
                    {
                        int fake = jaggedArray[x][y];
                    }
                }
                stopWatch.Stop();
                timeJagged += stopWatch.ElapsedMilliseconds;
                //Console.WriteLine("Jagged: " + stopWatch.ElapsedMilliseconds + " ms");
                stopWatch.Reset();

                stopWatch.Start();
                for (x = 0; x < size; x++)
                {
                    for (y = 0; y < size; y++)
                    {
                        int fake = twoDArray[x, y];
                    }
                }
                stopWatch.Stop();
                timeTwoD += stopWatch.ElapsedMilliseconds;
                //Console.WriteLine("2d: " + stopWatch.ElapsedMilliseconds + " ms");
                stopWatch.Reset();
            }
            Console.WriteLine("normal: " + timeArray + " ms");
            Console.WriteLine("jagged: " + timeJagged + " ms");
            Console.WriteLine("2d: " + timeTwoD + " ms");

            Console.WriteLine("avg normal: " + timeArray/1000 + " ms");
            Console.WriteLine("avg jagged: " + timeJagged / 1000 + " ms");
            Console.WriteLine("avg 2d: " + timeTwoD / 1000 + " ms");
            Console.ReadKey();
        }
    }
}
