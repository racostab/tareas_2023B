/*
	$ mcs threads.cs
	$ mono threads.exe
*/

using System;
using System.Threading;

class Program
{
    static void Main()
    {
        Thread thread = new Thread(NewThread);
        thread.Start();
        Console.WriteLine("Thread principal: " + Thread.CurrentThread.ManagedThreadId);

        Thread.Sleep(200);
        thread.Join();

    }

    static void NewThread()
    {
        Console.WriteLine("Nuevo thread: " + Thread.CurrentThread.ManagedThreadId);
        Thread.Sleep(200);
    }
}
