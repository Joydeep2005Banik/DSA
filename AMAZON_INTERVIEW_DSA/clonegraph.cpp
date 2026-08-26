#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Node definition as struct
struct Node {
    int val;
    vector<Node*> neighbors;
    //Node(int _val) : val(_val) {}
};

Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
{
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
}
Node* cloneGraph(Node* node) 
{
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
}
int main() {
    // 1 -- 2
    // |    |
    // 4 -- 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Node* cloned = cloneGraph(n1);

    cout << "Original Node 1 addr: " << n1 << "\n";
    cout << "Cloned Node 1 addr:   " << cloned << "\n";
    cout << "Cloned Node 1 Val:    " << cloned->val << "\n";
    cout << "Cloned Neighbors:     ";
    for (Node* neighbor : cloned->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << "\n";

    return 0;
}