createTicket()
{	
	int randomNumber;
	
	tName = "8.1.01.Choice_City";
	lr_start_transaction(tName);
	
	randomNumber = rand()%2;

	status = web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	end_transaction(tName, status);
	lr_think_time(4);

	lr_save_string(lr_eval_string("{seatPref}"),"sPref");
//	lr_output_message(lr_eval_string("{sPref}"));
	lr_save_string(lr_eval_string("{seatType}"),"sType");
//	lr_output_message(lr_eval_string("{sType}"));
	
	if (randomNumber == 0) {
		tName = "8.1.02.Choice_Flight";
		lr_start_transaction(tName);

		web_reg_save_param_ex(
		    "ParamName=outFlight", 
		    "LB/IC=name=\"outboundFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		status = web_submit_form("reservations.pl", 
			"Snapshot=t4.inf", 
			ITEMDATA, 
			"Name=depart", "Value={city}", ENDITEM, 
			"Name=departDate", "Value={date1}", ENDITEM, 
			"Name=arrive", "Value={city}", ENDITEM, 
			"Name=returnDate", "Value={date2}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=<OFF>", ENDITEM, 
			"Name=seatPref", "Value={sPref}", ENDITEM, 
			"Name=seatType", "Value={sType}", ENDITEM, 
			"Name=findFlights.x", "Value=64", ENDITEM, 
			"Name=findFlights.y", "Value=11", ENDITEM, 
			LAST);
		
		end_transaction(tName, status);
		lr_think_time(4);

		tName = "8.1.03.Choice_Flight";
		lr_start_transaction(tName);

		lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket");
//		lr_output_message(lr_eval_string("{randomTicket}"));
	
		status = web_submit_form("reservations.pl_2", 
			"Snapshot=t5.inf", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={randomTicket}", ENDITEM, 
			"Name=reserveFlights.x", "Value=3", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);
	
		end_transaction(tName, status);
		lr_think_time(4);

		tName = "8.1.04.End_Booking";
		lr_start_transaction(tName);

		lr_save_string(lr_eval_string("{fName}"),"firstName");
//		lr_output_message(lr_eval_string("{firstName}"));
		lr_save_string(lr_eval_string("{sName}"),"secondName");
//		lr_output_message(lr_eval_string("{secondName}"));
		lr_save_string(lr_eval_string("{adress}"),"adr");
		lr_save_string(lr_eval_string("{home}"),"hom");
//		lr_output_message("Adress %s, %s", lr_eval_string("{adr}"),lr_eval_string("{hom}"));
		lr_save_string(lr_eval_string("{cCard}"),"creditCard");
		lr_save_string(lr_eval_string("{cDate}"),"creditDate");
//		lr_output_message("Credit card %s, %s", lr_eval_string("{creditCard}"),lr_eval_string("{creditDate}"));
	
		status = web_submit_form("reservations.pl_3", 
			"Snapshot=t6.inf", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={secondName}", ENDITEM, 
			"Name=address1", "Value={adr}", ENDITEM, 
			"Name=address2", "Value={hom}", ENDITEM, 
			"Name=pass1", "Value={firstName} {secondName}", ENDITEM, 
			"Name=creditCard", "Value={creditCard}", ENDITEM, 
			"Name=expDate", "Value={creditDate}", ENDITEM, 
			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
			"Name=buyFlights.x", "Value=49", ENDITEM, 
			"Name=buyFlights.y", "Value=14", ENDITEM, 
			LAST);
	
		end_transaction(tName, status);
		lr_think_time(4);

	}
	else {
		tName = "8.1.02.Choice_Flight";
		lr_start_transaction(tName);

		web_reg_save_param_ex(
		    "ParamName=outFlight", 
		    "LB/IC=name=\"outboundFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		web_reg_save_param_ex(
		    "ParamName=returnFlight", 
		    "LB/IC=name=\"returnFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		status = web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=depart", "Value={city}", ENDITEM, 
			"Name=departDate", "Value={date1}", ENDITEM, 
			"Name=arrive", "Value={city}", ENDITEM, 
			"Name=returnDate", "Value={date2}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=on", ENDITEM, 
			"Name=seatPref", "Value={sPref}", ENDITEM, 
			"Name=seatType", "Value={sType}", ENDITEM, 
			"Name=findFlights.x", "Value=64", ENDITEM, 
			"Name=findFlights.y", "Value=11", ENDITEM, 
			LAST);
		
		end_transaction(tName, status);
		lr_think_time(4);

		tName = "8.1.03.Choice_Flight";
		lr_start_transaction(tName);

		lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket1");
//		lr_output_message(lr_eval_string("{randomTicket1}"));
		lr_save_string(lr_eval_string(lr_paramarr_random("returnFlight")),"randomTicket2");
//		lr_output_message(lr_eval_string("{randomTicket2}"));
	
		status = web_submit_data("reservations.pl_2", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={randomTicket1}", ENDITEM, 
			"Name=returnFlight", "Value={randomTicket2}", ENDITEM, 
			"Name=reserveFlights.x", "Value=3", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);
	
		end_transaction(tName, status);
		lr_think_time(4);

		tName = "8.1.04.End_Booking";
		lr_start_transaction(tName);

		lr_save_string(lr_eval_string("{fName}"),"firstName");
//		lr_output_message(lr_eval_string("{firstName}"));
		lr_save_string(lr_eval_string("{sName}"),"secondName");
//		lr_output_message(lr_eval_string("{secondName}"));
		lr_save_string(lr_eval_string("{adress}"),"adr");
		lr_save_string(lr_eval_string("{home}"),"hom");
//		lr_output_message("Adress %s, %s", lr_eval_string("{adr}"),lr_eval_string("{hom}"));
		lr_save_string(lr_eval_string("{cCard}"),"creditCard");
		lr_save_string(lr_eval_string("{cDate}"),"creditDate");
//		lr_output_message("Credit card %s, %s", lr_eval_string("{creditCard}"),lr_eval_string("{creditDate}"));
	
		status = web_submit_data("reservations.pl_3", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t6.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={secondName}", ENDITEM, 
			"Name=address1", "Value={adr}", ENDITEM, 
			"Name=address2", "Value={hom}", ENDITEM, 
			"Name=pass1", "Value={firstName} {secondName}", ENDITEM, 
			"Name=creditCard", "Value={creditCard}", ENDITEM, 
			"Name=expDate", "Value={creditDate}", ENDITEM, 
			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
			"Name=buyFlights.x", "Value=49", ENDITEM, 
			"Name=buyFlights.y", "Value=14", ENDITEM, 
			LAST);
		
		end_transaction(tName, status);
		lr_think_time(4);

	}
	
	return 0;
}
