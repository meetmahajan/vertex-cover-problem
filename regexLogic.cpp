bool checkInputSyntax(std::string inputString,char startCharacter)
{
	if(inputString[0] == 'V' && startCharacter == 'V')
	{
		if (regex_match (inputString,std::regex ("^[V]\\s\\d+$")))
			return true;
		else
			return false;
	}
	else if(inputString[0] == 'E' && startCharacter == 'E')
	{
		if (regex_match (inputString, std::regex("^[E]\\s\\{[\\<\\d+\\,\\d+\\>\\,]*\\<\\d+\\,\\d+\\>\\}$")))
			return true;
		else
			return false;		
	}
	else if(inputString[0] == 's' && startCharacter == 's')
	{
		if (regex_match (inputString,std::regex ("^[s]\\s\\d+\\s\\d+$")))
			return true;
		else
			return false;	
	}
	else
	{
		return false;	
	}
}
