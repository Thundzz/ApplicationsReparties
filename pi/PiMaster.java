import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.*;

public class PiMaster
{
 public static void main(String args[])
 {
 try
 { 
	int N = 10000;
	int result;
	int completed = 0;
	// recherche de l'objet distribué dans le registre de nom
	int nbSlaves = args.length -1;
	
	Pi[] slave = new  Pi[nbSlaves];
	Registry registry = LocateRegistry.getRegistry(args[0]); // machine serveur
	for (int i = 0; i < nbSlaves; i++)
	{	 
		slave[i] = (Pi) registry.lookup(args[i]);
	}
	// appel de méthode à distance
	Set<PiTask> tasks = new HashSet<PiTask>();
	while(completed < N){
		for (int i=0;  i<nbSlaves; i++)
		{
			tasks.add(new PiTask(completed+i, slave[i]));

		}
		Iterator<PiTask> iter = tasks.iterator();
		while (iter.hasNext()) {
		  iter.next().start();
		}
		
		iter = tasks.iterator();
		while(iter.hasNext()){
			PiTask current = iter.next();
			System.out.format("digit #%4d: %X\n", current.d, current.result);
			System.out.flush();
			iter.remove();
			completed+= 1;
		}
		while (iter.hasNext()) {
			iter.next();
		}
	}

 }
 catch (Exception e)
	 { 
		 System.out.println("PiMaster exception: " + e.getMessage()); 
		 e.printStackTrace(); 
	 } 
 } 
}
