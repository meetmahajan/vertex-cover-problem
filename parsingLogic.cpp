int convertStringToInt(std::string stringInt)
{
	int verticeCount;
	std::stringstream ss(stringInt);
	ss >> verticeCount;
	return verticeCount;
}
void converToCharArray(char* charArr,std::string str)
{
	for(unsigned i=0;i<str.length();i++)
	{
		charArr[i]=str[i];
	}
}
int parseAndGetVerticesCount(std::string verticesString)
{
	int verticeCount;
	std::string stringInt="";
	for(int i=2;verticesString[i]!='\0';i++)
	{
		stringInt = stringInt + verticesString[i];
	}
	verticeCount=convertStringToInt(stringInt);
	return verticeCount;
}

std::vector<int> parseEdgesString(std::string edgeStr)
{
	std::string tempStr="";
	int commaCount=0;
	std::vector<int> tempVector;
	for(unsigned i=0;i<edgeStr.length();i++)
	{
		if(i == edgeStr.length()-1)
			tempVector.push_back(convertStringToInt(tempStr));
		if(edgeStr[i] == 'E' || edgeStr[i] == ' ' || edgeStr[i] == '<' || edgeStr[i] == '>' || edgeStr[i] == '{' || edgeStr[i] == '}')
		{
		}
		else if(edgeStr[i] == ',')
		{
			if(commaCount % 2 != 0)
			{
				tempVector.push_back(convertStringToInt(tempStr));
				tempStr="";
			}
			else
			{
				if(commaCount == 0)
				{
					tempVector.push_back(convertStringToInt(tempStr));
					tempStr="";
				}
				commaCount = commaCount + 1;
			}
		}
		else
		{
			
			tempStr = tempStr + std::string(1,edgeStr[i]);
		}
	}
	return tempVector;
}
int parseAndGetSrc(char *srcDestCharString)
{
	
	char * pch;
  	pch = strtok (srcDestCharString," ");
  	int tempInt;
  	int count = 0;
  	while (pch != NULL)
  	{
  		if(count == 1)
  		{
  			tempInt=convertStringToInt(pch);
  			break;
		}
  		else{
    		pch = strtok (NULL, " ");
    		count++;
		}
  	}
  	return tempInt;
}

int parseAndGetDest(char *srcDestCharString)
{
	
	char * pch;
  	pch = strtok (srcDestCharString," ");
  	int tempInt;
  	int count = 0;
  	while (pch != NULL)
  	{
  		if(count == 2)
  		{
  			tempInt=convertStringToInt(pch);
  			break;
		}
  		else{
    		pch = strtok (NULL, " ");
    		count++;
		}
  	}
  	return tempInt;
}

bool checkSrcDestInVerticeLimit(int source,int dest,int V)
{
	if(source >=0 && source < V && dest >=0 && dest < V)
		return true;
	else
		return false;
}

bool checkEdgesInVerticeLimit(std::string cedgesStr,int V,adjMatrix aM)
{
	std::vector<int> tempVector=parseEdgesString(cedgesStr);
	for (std::vector<int>::iterator it = tempVector.begin() ; it != tempVector.end(); it=it+1)
	{
		if(*it < 0 || *it >= aM.getV())
			return false;
	}
	return true;	
}