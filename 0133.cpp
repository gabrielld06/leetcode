#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
	map<int, Node*> visited;
	
    Node* cloneGraph(Node* node) {
        if(node != nullptr) {
			Node* newNode = new Node(node->val);
			visited[newNode->val] = newNode;
			for(auto at : node->neighbors) {
				if(visited[at->val] == 0) {
					newNode->neighbors.push_back(cloneGraph(at));
				} else {
					newNode->neighbors.push_back(visited[at->val]);
				}
			}
			return newNode;
		}
		return nullptr;
    }
};


int main() {
	//Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
	//Output: [[2,4],[1,3],[2,4],[1,3]]
	
	Node* a = new Node(1);
	Node* b = new Node(2);
	Node* c = new Node(3);
	Node* d = new Node(4);
	
	a->neighbors = vector<Node*>({b, d});
	b->neighbors = vector<Node*>({a, c});
	c->neighbors = vector<Node*>({b, d});
	d->neighbors = vector<Node*>({a, c});
	
	Node* s = Solution().cloneGraph(a);
	cout << s->val << endl;
	for(auto nd : s->neighbors) {
		cout << nd->val << endl;
	}
	
	return 0;
}
