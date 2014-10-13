import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class PiImpl implements Pi
{

  private static long powMod(long a, long b, long m)
  {
    long tempo;
    if (b == 0)
      tempo = 1;
    else if (b == 1)
      tempo = a;    
    else 
      {
	long temp = powMod(a, b / 2, m);
	if (b % 2 == 0)
	  tempo = (temp * temp) % m;
	else
	  tempo = ((temp * temp) % m) * a % m;
      }
    return tempo;
  }
  
  /**
   * Computes the nth digit of Pi in base-16.
   * 
   * If n < 0, return -1.
   * 
   * @param n The digit of Pi to retrieve in base-16.
   * @return The nth digit of Pi in base-16.
   */
  public int piDigit(int n) throws RemoteException
  {
    if (n < 0) return -1;
    n -= 1;
    double x = 4 * piTerm(1, n) - 2 * piTerm(4, n) - piTerm(5, n) - piTerm(6, n);
    x = x - Math.floor(x);
    return (int)(x * 16);
  }
  
  private static double piTerm(int j, int n)
  {
    // Calculate the left sum
    double s = 0;
    for (int k = 0; k <= n; ++k)
      {
        int r = 8 * k + j;
        s += powMod(16, n-k, r) / (double) r;
        s = s - Math.floor(s);
      }
    // Calculate the right sum
    double t = 0;
    int k = n+1;
    // Keep iterating until t converges (stops changing)
    while(true)
      {
        int r = 8 * k + j;
        double newt = t + Math.pow(16, n-k) / r;
        if (t == newt) {
	  break;
        } else {
	  t = newt;
        }
        ++k;
      }
    return s + t;
  }
  /*
  public static void main(String args[])
  {
    int N = 10000;
    int i;
    for(i = 0; i < N; i++)
      {
	long result = piDigit(i);
	System.out.format("digit #%4d: %X\n", i, result);
	System.out.flush();
      }
  }
  */
}
