
/**
* EchoHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from Echo.idl
* mercredi 15 octobre 2014 10 h 49 CEST
*/

public final class EchoHolder implements org.omg.CORBA.portable.Streamable
{
  public Echo value = null;

  public EchoHolder ()
  {
  }

  public EchoHolder (Echo initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = EchoHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    EchoHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return EchoHelper.type ();
  }

}
