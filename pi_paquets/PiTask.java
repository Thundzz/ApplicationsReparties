import java.lang.Thread;

public class PiTask extends Thread
{
	public int[] d;
	public int[] result;
	Pi slave;
	public PiTask(int[] decimals, Pi slave)
	{
		this.d = decimals;
		this.slave = slave;
		result = new int[decimals.length];
	}
	public void run() {
		try{
			int l= result.length;
			for (int i=0; i<l; i++){
				result[i] = slave.piDigit(i);
			}
		}
		catch(Exception e)
		{
		 System.out.println("PiTask exception: " + e.getMessage()); 
		 e.printStackTrace();
		}
    }
}
