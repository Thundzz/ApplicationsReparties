import java.lang.Thread;

public class PiTask extends Thread
{
	public int d;
	public int result;
	Pi slave;
	public PiTask(int d, Pi slave)
	{
		this.d = d;
		this.slave = slave;
	}
	public void run() {
		try{
			result = slave.piDigit(d);
		}
		catch(Exception e)
		{
		 System.out.println("PiTask exception: " + e.getMessage()); 
		 e.printStackTrace();
		}
    }
}
