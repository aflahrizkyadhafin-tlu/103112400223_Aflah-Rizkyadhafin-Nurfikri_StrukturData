#include "graphLat.h"

int main()
{
     Graph G;
     CreateGraph(G);

     InsertNode(G, 'A');
     InsertNode(G, 'B');
     InsertNode(G, 'C');
     InsertNode(G, 'D');
     InsertNode(G, 'E');
     InsertNode(G, 'F');
     InsertNode(G, 'G');
     InsertNode(G, 'H');

     adrNode NodeA = FindNode(G, 'A');
     adrNode NodeB = FindNode(G, 'B');
     adrNode NodeC = FindNode(G, 'C');
     adrNode NodeD = FindNode(G, 'D');
     adrNode NodeE = FindNode(G, 'E');
     adrNode NodeF = FindNode(G, 'F');
     adrNode NodeG = FindNode(G, 'G');
     adrNode NodeH = FindNode(G, 'H');

     ConnectNode(NodeA, NodeB);
     ConnectNode(NodeA, NodeC);
     ConnectNode(NodeB, NodeD);
     ConnectNode(NodeB, NodeE);
     ConnectNode(NodeC, NodeF);
     ConnectNode(NodeC, NodeG);
     ConnectNode(NodeD, NodeH);
     ConnectNode(NodeE, NodeH);
     ConnectNode(NodeF, NodeH);
     ConnectNode(NodeG, NodeH);

     cout << "==== PRINT INFO GRAPH ====" << endl;
     PrintInfoGraph(G);

     // Soal 2
     cout << endl
          << "==== PRINT DFS ====" << endl;
     PrintDFS(G, NodeE);

     // Soal 3
     cout << endl
          << "==== PRINT BFS ====" << endl;
     PrintBFS(G, NodeB);
     return 0;
}