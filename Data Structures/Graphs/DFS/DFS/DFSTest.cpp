#include "DFS.h"
#include "Graph.h"
#include <vector>
#include <gtest/gtest.h>

class graphTest : public ::testing::Test {
public:
	virtual void SetUp() {
		g = *(new Graph(20));
	}
	Graph g;
};

TEST_F(graphTest, checkNeighboursForMultipleParent) {
	g.add_node(1, 2);
	g.add_node(3, 4);
	EXPECT_EQ(g.get_neighbour(3)[0], 4);
}

TEST_F(graphTest, checkNeighboursForSingleParent) {
	int  parent = 1;
	std::vector<int> neighbours{ 2,3 };
	for (size_t i = 0; i < neighbours.size(); i++)
	{
		g.add_node(parent, neighbours[i]);
	}
	std::vector<int> output = g.get_neighbour(1);
	EXPECT_EQ(neighbours.size(), output.size());
	for (size_t i = 0; i < output.size(); i++)
	{
		EXPECT_EQ(neighbours[i],output[i]);
	}
}

TEST_F(graphTest, checkReverseRelation) {
	int  parent = 1;
	std::vector<int> neighbours{ 2,3 };
	for (size_t i = 0; i < neighbours.size(); i++)
	{
		g.add_node(parent, neighbours[i]);
	}
	std::vector<int> output = g.get_neighbour(2);
	EXPECT_EQ(1, output.size());
	EXPECT_EQ(1, output[0]);
}

class islandTest : public ::testing::Test {
public:
	virtual void SetUp() {
		g = *(new Graph(20));
		g.add_node(1, 1);
	}
	Graph g;
};

TEST_F(islandTest, callCountIsland) {
	int islands = g.countIslands();
}

TEST_F(islandTest, checkIslandCount) {
	int islands = g.countIslands();
	EXPECT_EQ(islands, 1);
}

TEST_F(islandTest, checkMultipleIslandCount) {
	g.add_node(2, 3);
	int islands = g.countIslands();
	EXPECT_EQ(islands, 2);
}

TEST_F(islandTest, checkMultipleIslandWithCycleCount) {
	g.add_node(2, 3);
	g.add_node(4, 3);
	g.add_node(2, 4);
	g.add_node(7, 12);
	g.add_node(11, 8);
	g.add_node(7, 8);
	g.add_node(7, 9);
	g.add_node(10, 9);
	g.add_node(8, 9);
	int islands = g.countIslands();
	EXPECT_EQ(islands, 3);
}