#include<bits/stdc++.h>
#include "errorPrinting.cpp"
#include "regexLogic.cpp"
#include "adjMatrix.cpp"
#include "parsingLogic.cpp"
#include "SATSolver.cpp"

int main()
{
	while(true)
	{
		std::string vString;
		std::string eString;
		adjMatrix aM;
		bool flag=false;
		bool vertexCoverFlag=false;
		getline(std::cin,vString);
		if(!std::cin || vString == "")
		{
			break;
		}
		else
		{
			if(checkInputSyntax(vString,'V'))
			{
				int V=parseAndGetVerticesCount(vString);
				aM.setV(V);
				std::string eString;
				getline(std::cin,eString);
				if(!std::cin || eString == "")
		 		{			
					break;
				}
				else
				{
					if(checkInputSyntax(eString,'E'))
					{
						aM.setEdges(eString);
						if(!checkEdgesInVerticeLimit(eString,V,aM))
						{
							errorMessage("Edges Input is not in vertices limit");
						}
						else
							flag=true;
					}
					else
					{
						std::cout<<""<<std::endl;
					}
				}
			}
			else
			{
				errorMessage("Syntax Error in Vertices Input");
			}
			if(flag == true)
			{
				std::vector<int> temp = parseEdgesString(aM.getEdges());
				std::vector<int> adj[aM.getV()];
				for (std::vector<int>::iterator it = temp.begin() ; it != temp.end(); it=it+2)
				{
					addEdge(adj, *it, *(it+1)); 
				}
				std::vector<int> vertexCoverVector=makeClause(aM,adj);
				vertexCoverFlag = true;
				for(unsigned i=0;i<vertexCoverVector.size();i++)
	    		{
	    			if(i == vertexCoverVector.size() - 1)
				    	std::cout<<vertexCoverVector[i];
				    else
				    	std::cout<<vertexCoverVector[i]<<" ";
				}
				if(vertexCoverFlag == true)
					std::cout<<std::endl;
			}
		}	
	}
	return 0;
}