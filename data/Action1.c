Action1()
{

	/* Зачекали */

	lr_think_time(30);

	web_submit_data("itinerary.pl_2", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=41172263-120096-SS", ENDITEM, 
		"Name=flightID", "Value=41183078-1547-IP", ENDITEM, 
		"Name=flightID", "Value=82304915-2554724-SS", ENDITEM, 
		"Name=flightID", "Value=1234623376-3725564-SI", ENDITEM, 
		"Name=flightID", "Value=82313471-3902-SI", ENDITEM, 
		"Name=flightID", "Value=41174505-4746261-SI", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=63", ENDITEM, 
		"Name=removeFlights.y", "Value=14", ENDITEM, 
		LAST);

	/* удалили */

	return 0;
}