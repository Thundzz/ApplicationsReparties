import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
public class PiSlave
{
 public static void main(String args[])
 { 
	 try
	 {
		 // activation de l'objet distribué
		 Pi piDigit = new PiImpl();
		 Pi stub = (Pi)UnicastRemoteObject.exportObject(piDigit, 0);
		 // binding de l'objet distribué dans le registre de nom
		 Registry registry = LocateRegistry.getRegistry();
		 registry.rebind(args[0], stub);
	 }
	 catch (Exception e)
	 { 
		 System.out.println("PiSlave Exception: " + e.getMessage()); 
		 e.printStackTrace(); 
	 }
 } 
}
