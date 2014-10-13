import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
public class HelloServer
{
 public static void main(String args[])
 { 
	 try
	 {
		 // activation de l'objet distribué
		 Hello hello = new HelloImpl();
		 Hello bye = new HelloImpl(); 
		 Hello stub = (Hello)UnicastRemoteObject.exportObject(hello, 0);
		 Hello stub2 = (Hello)UnicastRemoteObject.exportObject(bye, 0);
		 // binding de l'objet distribué dans le registre de nom
		 Registry registry = LocateRegistry.getRegistry();
		 registry.rebind("hello", stub);
		 registry.rebind("bye", stub2);
	 }
	 catch (Exception e)
	 { 
		 System.out.println("HelloServer Exception: " + e.getMessage()); 
		 e.printStackTrace(); 
	 }
 } 
}
