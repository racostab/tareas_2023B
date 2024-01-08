/*
	Autor: Cureño Contreras Erick Brandon
	Compilación: mcs hilos.cs
	Ejecución: mono hilos.exe
*/
using System;
using System.Threading;

class Program{
	static void Main(){
		// Crear un nuevo hilo y pasar un método que se ejecutará en ese hilo
		Thread hilo = new Thread(NuevoHilo);
		// Iniciar el hilo
		hilo.Start();
		// El hilo principal sigue ejecutando su propio código
		Console.WriteLine("Hilo principal id: " + Thread.CurrentThread.ManagedThreadId);
		Thread.Sleep(500); // Hacer una pausa para que sea más fácil de observar
		// Esperar a que el nuevo hilo termine antes de que el programa principal termine
		hilo.Join();
		Console.WriteLine("Fin del programa");
	}

	static void NuevoHilo(){
			Console.WriteLine("Nuevo hilo id: " + Thread.CurrentThread.ManagedThreadId);
			Thread.Sleep(500); // Hacer una pausa para que sea más fácil de observar
	}
}

