import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
public class HelloClient
{
 public static void main(String args[])
 {
 try
 { 
	// recherche de l'objet distribué dans le registre de nom
	Registry registry = LocateRegistry.getRegistry(args[0]); // machine serveur ←
	Hello hello = (Hello) registry.lookup("hello");
	Hello bye= (Hello) registry.lookup("bye");
	// appel de méthode à distance
	String s = hello.sayHello("Quinn, it's in!"); 
	String s2 = bye.sayHello("Quout, it's out!");
	System.out.println(s);
	System.out.println(s2);
 }
 catch (Exception e)
	 { 
		 System.out.println("HelloClient exception: " + e.getMessage()); 
		 e.printStackTrace(); 
	 } 
 } 
}
