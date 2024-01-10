/*
	$ javac fork.java
	$ java fork
*/
import java.util.concurrent.TimeUnit;
import java.io.IOException;

public class fork {
	public static void main(String[] args) {
	try {
		
		long parentPid = ProcessHandle.current().pid();
		System.out.println("Proceso padre: Mi PID es " + parentPid);
		
		ProcessBuilder processBuilder = new ProcessBuilder("java", "-cp", System.getProperty("java.class.path"), ForkedProcess.class.getName());
		
		Process process = processBuilder.start();
		
		long childPid = process.pid();
		System.out.println("Proceso padre: PID del proceso hijo es " + childPid);
		
		int exitCode = process.waitFor();
		System.out.println("Proceso padre: El proceso hijo terminó con código de salida " + exitCode);
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }

	public static class ForkedProcess {
		public static void main(String[] args) {
			
			long pid = ProcessHandle.current().pid();

			
			System.out.println("Proceso hijo: Mi PID es " + pid);
			try {
				
				TimeUnit.SECONDS.sleep(10);
			}catch (InterruptedException e) {
				e.printStackTrace();
        	}
        }
    }
}