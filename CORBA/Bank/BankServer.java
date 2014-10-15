import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;
import org.omg.CosNaming.*;
import java.util.Properties;

public class BankServer
{
	public static void main(String args[])
	{
		try{
			ORB orb = ORB.init(args, null); // create and initialize the ORB
			// get reference to rootpoa & activate the POAManager
			org.omg.CORBA.Object objRef = orb.resolve_initial_references("RootPOA");
			POA rootpoa = POAHelper.narrow(objRef);
			rootpoa.the_POAManager().activate();
			// get the naming service
			objRef = orb.resolve_initial_references("NameService");
			NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);


			// get object reference from the servant
			BankImpl bankImpl = new BankImpl(rootpoa);
			objRef = rootpoa.servant_to_reference(bankImpl);
			// convert the CORBA object reference into Bank reference
			Bank bankRef = BankHelper.narrow(objRef);
			// bind the object reference in the naming service
			NameComponent path[ ] = ncRef.to_name("bank.bank"); // id.kind
			ncRef.rebind(path, bankRef);

			orb.run(); // start server...
		}
		catch(Exception e)
		{
			System.out.println("BankServer exception: " + e.getMessage());  
			e.printStackTrace();
		}

	}
}