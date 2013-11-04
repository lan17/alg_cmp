/*
*/

import java.util.*;
public class Time {
	public String whatTime(int seconds) 
	{
	    String ret = "";
	    int hours = seconds / 3600;
	    seconds -= hours * 3600;
	    int minutes = seconds / 60;
	    seconds -= minutes * 60;
	    
	    ret = hours + ":" + minutes + ":" + seconds;
	    
	    return ret;
		
	}
	
}


// Powered by FileEdit
