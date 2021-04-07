int checkFirstClass()
{
	web_reg_find(
		"Text=A First class",
         "SaveCount=FirstClass_count", 
         LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t7.inf", 
		LAST);
	
	return atoi(lr_eval_string("{FirstClass_count}"));
}
