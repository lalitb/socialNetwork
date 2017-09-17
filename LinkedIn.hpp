#pragma once

#include <map>
#include <vector>
#include <string>
#include <queue>

struct LevelConnection {
	int connId;
  int level;
};

class LinkedIn {
	std::map<std::string, int> connMap;
	std::map<int, std::vector<int>> connGraph;
	int totalConnections;
	int isReachable(int, int);

public:
	LinkedIn();
	void addConnection(std::string);
	void addFriend(std::string, std::string);
	int findHop(std::string, std::string);
};
