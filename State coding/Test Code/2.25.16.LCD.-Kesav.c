
task main()
{
	clearLCDLine(0);
	clearLCDLine(1);

	while(true)
	{
		displayLCDCenteredString(0, "Hello World");
	}
}
