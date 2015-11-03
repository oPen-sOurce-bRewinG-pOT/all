char* week(int i)
{
	char* result="Weekdays!";
	//i++; //adjust to 01/01/01 == Monday
	//if (i<0)
	//	i=-i;
	i++;
	i=i%7;
	if (i<0)
		i+=7;
	if (i==0)
		result = "Sunday";
	if (i==1)
		result = "Monday";
	if (i==2)
		result = "Tuesday";
	if (i==3)
		result = "Wednesday";
	if (i==4)
		result = "Thursday";
	if (i==5)
		result = "Friday";
	if (i==6)
		result = "Saturday";
	return result;
}	
