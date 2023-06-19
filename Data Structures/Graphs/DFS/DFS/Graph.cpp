#include "Graph.h"

Graph::Graph(int max_nodes):max_nodes(max_nodes){}

void Graph::add_node(int x, int y) {
	graph[x].push_back(y);
	graph[y].push_back(x);
}

const std::vector<int>& Graph::get_neighbour(int x) {
	return graph[x];
}

void Graph::dfs(int node, std::vector<bool>& visited) {
	for (const auto& neighbour : graph[node]) {
		if (!visited[neighbour]) {
			visited[neighbour] = true;
			dfs(neighbour, visited);
		}
	}
}

int Graph::countIslands() {
	int islands{ 0 };
	std::vector<bool> visited(max_nodes,false);
	for (const auto& node : graph) {
		if (!visited[node.first]) {
			visited[node.first] = true;
			dfs(node.first,visited);
			++islands;
		}
	}
	return islands;
}