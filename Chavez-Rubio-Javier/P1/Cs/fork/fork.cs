using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        Console.WriteLine("Código del proceso padre: " + Process.GetCurrentProcess().Id);

        string currentProcessName = Process.GetCurrentProcess().MainModule.FileName;

        Process childProcess = new Process();
        childProcess.StartInfo.FileName = currentProcessName;

        try
        {
            childProcess.Start();
        }
        catch (Exception)
        {
            Console.WriteLine("Error de creación del proceso hijo");
        }

        if (childProcess.Id != Process.GetCurrentProcess().Id)
        {
            Console.WriteLine("Código del proceso hijo duplicado: " + childProcess.Id);
        }
        else
        {
            Console.WriteLine("Código del proceso padre duplicado.");
        }

        System.Threading.Thread.Sleep(1000);

        Console.WriteLine("Proceso padre ha terminado.");
    }
}

