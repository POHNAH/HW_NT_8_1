checkAndDel(int allAndOnce)
{
	int i, count;
	
	tName = "8.1.05.Itinerary";
	lr_start_transaction(tName);

//	«аходим в Itinerary
	web_reg_save_param_ex(
	    "ParamName=flightIDs", 
	    "LB/IC=name=\"flightID\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=all");
	
    web_reg_save_param("ccgifields",
	    "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
	    "rb=\"  />",
	    "ord=all",
	    LAST);
		
	status = web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	end_transaction(tName, status);
	lr_think_time(4);

	tName = "8.1.06.Del_Ticket";
	lr_start_transaction(tName);

    count = atoi(lr_eval_string("{flightIDs_count}"));

//	собираем набор параметров дл€ удалени€
	lr_save_string("","param");
	lr_param_sprintf("param","%d=on&", count);
    
	for(i = 1;i <= count; i++) {
        lr_param_sprintf("param",
	        "%sflightID=%s&",
	        lr_eval_string("{param}"),
	        lr_paramarr_idx("flightIDs",
	        i));

        lr_param_sprintf("param",
	        "%s.cgifields=%s&",
	        lr_eval_string("{param}"),
	        lr_paramarr_idx("ccgifields",
	        i));

	}

	if (allAndOnce < 3) {
		lr_save_string(lr_eval_string("{param}removeFlights.x=36&removeFlights.y=4"), "c_wcr");
	}
	else {
		lr_save_string(lr_eval_string("{param}removeAllFlights.x=36&removeAllFlights.y=4"), "c_wcr");
	}
	
		
    status = web_custom_request("itinerary.pl_2",
	    "URL=http://localhost:1080/cgi-bin/itinerary.pl",
	    "Method=POST",
	    "Resource=0",
	    "RecContentType=text/html",
	    "Referer==http://localhost:1080/cgi-bin/itinerary.pl",
	    "Snapshot=t4.inf",
	    "Mode=HTTP",
	    "Body={c_wcr}",
	    LAST);

	end_transaction(tName, status);
	lr_think_time(4);

	return 0;
}
