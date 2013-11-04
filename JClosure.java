class JClosure
{
	private static interface Closure
	{
		public void printSomething();

	}

	private static Closure makeIt()
	{
		final Integer fuck=1337;
		return new Closure(){public void printSomething(){System.out.println(fuck);}};
	}

	public static void main(String[]args)
	{
		Closure closure = makeIt();
		closure.printSomething();
	}
}
