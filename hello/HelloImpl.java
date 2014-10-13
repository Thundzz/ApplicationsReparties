import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

class HelloImpl implements Hello
{ 
 public String sayHello(String msg) throws RemoteException
 {
	System.out.println("Remote Invokation of method sayHello()"); 
	return msg;
 }
}
