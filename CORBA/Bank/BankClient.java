import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;


public class BankClient
{
	public static void main(String args[])
	{
		try{
			org.omg.CORBA.Object objRef;
			ORB orb = ORB.init(args, null); // create and initialize the ORB
			// get the naming service
			objRef = orb.resolve_initial_references("NameService");
			NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
			// resolve the object reference from the naming service
			objRef = ncRef.resolve_str("bank.bank");
			// convert the CORBA object reference into Bank reference
			Bank bankRef = BankHelper.narrow(objRef);
			// remote method invocation
			
			Account bankplank = bankRef.create();
			Account leona = bankRef.create();

			bankplank.deposit(329); // First Blood
			leona.deposit(150); //Assist on first blood

			leona.withdraw(150); // Bought two wards
			bankplank.deposit(1500); // He farmed well

			bankplank.withdraw(1550); // BF

			System.out.println( "bankplank: " + bankplank.balance() + " gold");
			System.out.println( "leona: " + leona.balance() + " gold");

			bankRef.destroy(leona); //She is AFK
		}
		catch(Exception e){
			System.out.println("BankClient exception: " + e.getMessage());  
			e.printStackTrace();
		}
	}
}