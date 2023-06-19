#pragma once
#include <unordered_map>

class Graph {
public:
	Graph(){}
	Graph(int);
	void add_node(int, int);
	const std::vector<int>& get_neighbour(int);
	int countIslands();
private:
	int max_nodes;
	void dfs(int, std::vector<bool>&);
	std::unordered_map<int, std::vector<int>> graph;
};