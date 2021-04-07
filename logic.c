logic()
{
	int allOrOnce = rand()%10;
	vuser_init();
	createTicket();
	
	checkAndDel(allOrOnce);

	vuser_end();
	
	return 0;
}
