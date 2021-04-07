checkAndDel(int countFirst)
{
	int i,j,k, count;
	char paramName[100];
	
	if (countFirst == 0) {
		lr_output_message("Ѕилетов первого класса нет, удал€ть нечего");
		return 0;
	}
	
	j = rand()%countFirst + 1;
	
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
		
	web_reg_save_param_ex(
		"ParamName=classesTicket",
		"LB=A ",
		"RB= class ticket",
		"Ordinal=all",
		LAST);
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

    count = atoi(lr_eval_string("{classesTicket_count}"));

//	собираем набор параметров дл€ удалени€
	lr_save_string("","param");
	k = 1;
	for (i = 1; i <= count; i++)
       {
    		sprintf(paramName, "{classesTicket_%d}", i);

       		if (strcmp(lr_eval_string(paramName),"First") == 0) {
				if (k == j) {
					lr_param_sprintf("param","%d=on&", i);
					break;
				}
				k++;
       		}
       }	
    
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

	lr_save_string(lr_eval_string("{param}removeFlights.x=36&removeFlights.y=4"), "c_wcr");
		
    web_custom_request("itinerary.pl_2",
	    "URL=http://localhost:1080/cgi-bin/itinerary.pl",
	    "Method=POST",
	    "Resource=0",
	    "RecContentType=text/html",
	    "Referer==http://localhost:1080/cgi-bin/itinerary.pl",
	    "Snapshot=t4.inf",
	    "Mode=HTTP",
	    "Body={c_wcr}",
	    LAST);

	return 0;
}
