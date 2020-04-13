#include "minisat/core/SolverTypes.h"
#include "minisat/core/Solver.h"
std::vector<int> makeClause(adjMatrix aM,std::vector<int> adj[])
{
	std::vector<int> C;
    std::unique_ptr<Minisat::Solver> solver(new Minisat::Solver());
    int k = 0;
    bool res;
    while (k <= aM.getV() - 1)
    {
		std::vector<std::vector<Minisat::Lit>> nk_matrix(aM.getV());
        for (int i = 0; i < aM.getV(); i++)
            for (int j = 0; j < k; j++) {
                Minisat::Lit l = Minisat::mkLit(solver->newVar());
                nk_matrix[i].push_back(l);
            }
        for (int i = 0; i < k; i++) {
            Minisat::vec<Minisat::Lit> save_literal;
            for (int j = 0; j < aM.getV(); j++) {
                save_literal.push(nk_matrix[j][i]);
            }
            solver->addClause(save_literal);
        }
        for (int m = 0; m < aM.getV(); m++)
            for (int p = 0; p < k; p++)
                for (int q = p + 1; q < k; q++) {
                    solver->addClause(~nk_matrix[m][p], ~nk_matrix[m][q]);
                }
        for (int m = 0; m < k; m++)
            for (int p = 0; p < aM.getV(); p++)
                for (int q = p + 1; q < aM.getV(); q++) {
                    solver->addClause(~nk_matrix[p][m], ~nk_matrix[q][m]);
                }
        for(int v1 = 0 ; v1 < aM.getV(); ++v1) {
            for (auto v2 : adj[v1]) {
                if(v2 < v1) continue;
                Minisat::vec<Minisat::Lit> edge_lit;
                for (int w = 0; w < k; w++) {
                    edge_lit.push(nk_matrix[v1][w]);
                    edge_lit.push(nk_matrix[v2][w]);
                }
                solver->addClause(edge_lit);
            }
        }
        res = solver->solve();
        if (res )
        {
            for (int i = 0; i < aM.getV(); i++)
                for (int j =0; j < k; j++)
                    if ( Minisat::toInt(solver->modelValue(nk_matrix[i][j])) == 0)
                    {
                        C.push_back(i);
                    }
            break;
        }
        else {
            solver.reset(new Minisat::Solver());
        }
        k++;
    }
	std::sort( C.begin(), C.end(), std::less<int>());
	return C;
}
