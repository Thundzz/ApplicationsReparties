import java.rmi.Remote;
import java.rmi.RemoteException;
public interface Pi extends Remote
{
	 public int piDigit(int n) throws RemoteException; 
}
