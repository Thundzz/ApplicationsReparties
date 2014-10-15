all:
	javac *.java

globserv:
	tnameserv -ORBInitialPort 2810

serv:
	java BankServer -ORBInitRef NameService=corbaloc::localhost:2810/NameService

cli:
	java BankClient -ORBInitRef NameService=corbaloc::localhost:2810/NameService