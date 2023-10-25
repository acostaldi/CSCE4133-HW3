#include <search.hpp>
#include <bst.hpp>

void bfs(Graph &G, int start, int destination) {
    BST bst;

    G.reset();

    G.distance(start) = 0;
    bst.insert(0, start);
    
    G.setTrace(start, -1);

    while (true) {
        BSTNode *node = bst.popMinimum();

        int u = node->meta;
        int dist = node->key;
        delete node;

        if (G.distance(u) != dist)
            continue;

        G.setVisited(u);

        if (u == destination)
            break;

        int numberOfAdjacencyNodes = G.e[u].size();
        LinkedListNode<std::pair<int, int> > *p = G.e[u].getRoot();
        for (int i = 0; i < numberOfAdjacencyNodes; i += 1, p = p->next) {
            int v = p->value.first;
            int w = p->value.second;
            if (G.isVisited(v))
                continue;
            if (dist + w < G.distance(v)) {
                G.distance(v) = dist  + w ;
                bst.insert(dist + w, v);
                G.setTrace(v, u);   
            }
        }
    }
}
