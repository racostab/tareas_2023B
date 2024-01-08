/*
	Autor: Cureño Contreras Erick Brandon
	Compilación: mcs fork.cs
	Ejecución: mono fork.exe
*/
using System;
using System.Threading;

class Program
{
    static void Main()
    {
        // Crear un nuevo hilo
        Thread newThread = new Thread(MyThreadMethod);
	Console.WriteLine($"Hilo principal: {GetThreadId()}");
        // Iniciar el hilo
        newThread.Start();
        newThread.Join();
        Console.WriteLine("Fin del programa.");
    }

    static void MyThreadMethod(){
        // Hacer algo en el nuevo hilo
	Console.WriteLine($"Proceso hijo: {GetThreadId()}");
	Thread.Sleep(10000);
    }

    // Método para obtener el identificador de hilo nativo
    [System.Runtime.InteropServices.DllImport("libc")]
    private static extern int syscall(int number);

    private static int GetThreadId(){
        return syscall(186); // 186 es el número de llamada al sistema para obtener el identificador de hilo en Linux
    }
}

