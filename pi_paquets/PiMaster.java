import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.*;

public class PiMaster
{
 static int NBDIGITS= 5;
 public static void main(String args[])
 {
 try
 { 
	int N = 10000;
	int[] result= new int[N];
	int completed = 0;
	// recherche de l'objet distribué dans le registre de nom
	int nbSlaves = args.length -1;
	
	Pi[] slave = new  Pi[nbSlaves];
	Registry registry = LocateRegistry.getRegistry(args[0]); // machine serveur
	System.out.println("Number of slaves :" + nbSlaves);
	for (int i = 1; i <= nbSlaves; i++)
	{	
		slave[i-1] = (Pi) registry.lookup(args[i]);
		System.out.println("Adding for slave:" + args[i]);
	}
	// appel de méthode à distance
	Set<PiTask> tasks = new HashSet<PiTask>();
	while(completed < N){
		for (int i=0;  i<nbSlaves; i++)
		{
			int[] digits= new int[NBDIGITS];
			for(int j=0; j< NBDIGITS; j++)
			{
				digits[j]= completed +j +i;
			}
			tasks.add(new PiTask(digits, slave[i]));
		}
		Iterator<PiTask> iter = tasks.iterator();
		while (iter.hasNext()) {
		  iter.next().start();
		}

		iter = tasks.iterator();
		while (iter.hasNext()) {
		  iter.next().join();
		}
		
		iter = tasks.iterator();
		while(iter.hasNext()){
			PiTask current = iter.next();
			for(int i=0; i< NBDIGITS; i++)
			{
				result[current.d[i]] = current.result[i];  
				System.out.format("digit #%4d: %X\n", current.d[i], current.result[i]);
				System.out.flush();
			}
			iter.remove();
			completed+= NBDIGITS;
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
