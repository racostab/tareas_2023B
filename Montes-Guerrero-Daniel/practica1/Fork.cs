/*
 * Alumno: Daniel Montes Guerrero
 * Compilar: mcs Fork.cs
 * Ejecutar: mono Fork.exe
 */

using System.Threading;
using System.Diagnostics;
using System;

class Fork{
	static void Main(string[] args){
		Process p = new Process();
		p.StartInfo.FileName = Process.GetCurrentProcess().MainModule.FileName;
		Console.WriteLine("Soy el padre " + Process.GetCurrentProcess().Id);
		try{
			p.Start();
		}
		catch(Exception){
			Console.WriteLine("Error al crear el proceso");
		}
		if(p.Id != Process.GetCurrentProcess().Id){
			Console.WriteLine("Soy el hijo " + p.Id);
		}
	}
}
