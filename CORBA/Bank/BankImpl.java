import java.util.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;
import org.omg.CosNaming.*;
import java.util.Properties;


public class BankImpl extends BankPOA
{
	Set<Account> accounts;
	POA rootpoa;

	public BankImpl()
	{
		accounts = new HashSet<Account>();
	}

	public BankImpl(POA p)
	{
		accounts = new HashSet<Account>();
		rootpoa = p;
	}
	
	public Account create (){
		Account accountRef = null;
		try{
			AccountImpl a = new AccountImpl();
			org.omg.CORBA.Object objRef = rootpoa.servant_to_reference(a);
			accountRef = AccountHelper.narrow(objRef);
			accounts.add(accountRef);
		}
		catch(Exception e){
			System.out.println("Account creation exception exception: " + e.getMessage());  
			e.printStackTrace();
		}
		return accountRef;	
	}

	public void destroy (Account a){
		Iterator<Account> iter = accounts.iterator();
		Account current;
		while (iter.hasNext()) {
			current = iter.next();
			if(current == a)
			{
				iter.remove();
				System.out.println("Account destroyed." + accounts.size() + " accounts remaining.");
				break;
			}
		}

	}
} 
