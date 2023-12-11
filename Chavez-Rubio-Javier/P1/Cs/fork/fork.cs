using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        Console.WriteLine("Código del proceso padre: " + Process.GetCurrentProcess().Id);

        // Obtener el nombre del programa actual (este programa)
        string currentProcessName = Process.GetCurrentProcess().MainModule.FileName;

        // Crear un proceso hijo que duplica el proceso padre
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
            // El proceso actual es el proceso padre
            Console.WriteLine("Código del proceso hijo duplicado: " + childProcess.Id);
        }
        else
        {
            // El proceso actual es el proceso hijo
            Console.WriteLine("Código del proceso padre duplicado.");
        }

        // Esperar un momento para que el proceso hijo se inicie
        System.Threading.Thread.Sleep(1000); // Esperar 1 segundo

        Console.WriteLine("Proceso padre ha terminado.");
    }
}

