public class AccountImpl  extends AccountPOA
{
	private int balance;

	public AccountImpl()
	{
		balance = 0;
	}

	public void deposit (int amount)
	{
		balance += amount;
	}
	public void withdraw (int amount)
	{
		balance-= amount;
	}

	public int balance ()
	{
		return balance;
	}
} 
