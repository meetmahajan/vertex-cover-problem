class adjMatrix
{
	public:
		int V;
		std::string Edges;
		void setV(int v)
		{
			V=v;
		}
		int getV()
		{
			return V;
		}
		void setEdges(std::string edges)
		{
			Edges=edges;
		}
		std::string getEdges()
		{
			return Edges;
		}
};

void addEdge(std::vector<int> adj[], int src, int dest) 
{ 
    adj[src].push_back(dest); 
    adj[dest].push_back(src); 
} 

