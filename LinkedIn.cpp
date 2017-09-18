#include "LinkedIn.hpp"
#include "LinkedInException.hpp"
#include<iostream>
LinkedIn::LinkedIn(){
    totalConnections = 0;	
}

void LinkedIn::addConnection(std::string name){
	connMap[name] =	totalConnections++;
}

void LinkedIn::addFriend(std::string name, std::string frnd){
	if (connMap.find(name) == connMap.end()) {
		throw new LinkedInException(name + " not found as connection");
	}
	if (connMap.find(frnd) == connMap.end()) {
		throw new LinkedInException(frnd + " not found as connection");
	}
	//add bidirectional connection
	connGraph[connMap[name]].push_back(connMap[frnd]);
	connGraph[connMap[frnd]].push_back(connMap[name]);
}

int LinkedIn::findHop(std::string conn1, std::string conn2){
	if (connMap.find(conn1) == connMap.end()) {
		throw new LinkedInException(conn1 + " not found as connection");
	}
	if (connMap.find(conn2) == connMap.end()) {
		throw new LinkedInException(conn2 + " not found as connection");
	}
	int connid1 = connMap[conn1];
	int connid2 = connMap[conn2];
	return isReachable(connid1, connid2);														
}

int LinkedIn::isReachable(int conn1, int conn2){

	if (conn1 == conn2) return 0;

	std::vector<bool> isVisited(totalConnections, false);
	std::queue<LevelConnection> queueOfNodes;
	queueOfNodes.push({conn1, 0});
        isVisited[conn1] = true;
	while (!queueOfNodes.empty()){
            	LevelConnection lc = queueOfNodes.front();
	    	if (lc.connId == conn2) {
			return lc.level - 1;
		}
		for (auto conn: connGraph[lc.connId]){
                    if (isVisited[conn] == false) {
                          isVisited[conn] = true;
			  queueOfNodes.push({conn, lc.level + 1});
                    }
		}
		queueOfNodes.pop();
	}
        return -1 ; // not found
}
