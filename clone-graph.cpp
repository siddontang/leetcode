#include "leetcode.h"

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }

        UndirectedGraphNode dummy(0);

        map<UndirectedGraphNode*, UndirectedGraphNode*> ns;
        clone(node, &dummy, ns);

        return dummy.neighbors[0];
    }

    void clone(UndirectedGraphNode* srcNode, UndirectedGraphNode* p, map<UndirectedGraphNode*, UndirectedGraphNode*> &ns) {
        map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it = ns.find(srcNode);
        if(it != ns.end()) {
            p->neighbors.push_back(it->second);
            return;
        } 
        UndirectedGraphNode* node = new UndirectedGraphNode(srcNode->label);
        p->neighbors.push_back(node);

        ns[srcNode] = node;
        
        for(size_t i = 0; i < srcNode->neighbors.size(); i++) {
            clone(srcNode->neighbors[i], node, ns);
        }
    }
};

int main() {
    return 0;
}