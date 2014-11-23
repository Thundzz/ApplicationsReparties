import mpi.*;
public class HelloWorld {

	public static void main(String[] args) throws Exception {
		MPI.Init(args);
		int size = MPI.COMM_WORLD.Size();
		int rank = MPI.COMM_WORLD.Rank();

		System.out.println("I am process <"+rank+">");

		MPI.Finalize();
	}
}