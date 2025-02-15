#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D, N, U, T;
int maxNode;
vector<bool> brokenEdge; // brokenEdge[i] = true면 i번 방과 floor(i/2)번 방 사이의 길목이 파손됨

// twintail 방식의 탐색 시간 계산 함수
// v: 현재 노드, k: 지금까지 누적된 분기 횟수 (즉, 추가 비용이 k*T씩 붙음)
int twintail(int v, int k) {
    bool hasLeft = (2*v <= maxNode && !brokenEdge[2*v]);
    bool hasRight = (2*v+1 <= maxNode && !brokenEdge[2*v+1]);
    
    // 리프면 더 이상 진행할 곳이 없음
    if (!hasLeft && !hasRight)
        return 0;
    
    // 자식이 한쪽만 있는 경우: 분기 발생 없음
    if (hasLeft && !hasRight) {
        return (U + k * T) + twintail(2*v, k);
    }
    if (!hasLeft && hasRight) {
        return (U + k * T) + twintail(2*v+1, k);
    }
    
    // 두 자식 모두 있는 경우: 분기 발생 → 각 자식으로 갈 때 추가 비용 T가 붙음 (k+1)
    int timeLeft = (U + (k+1) * T) + twintail(2*v, k+1);
    int timeRight = (U + (k+1) * T) + twintail(2*v+1, k+1);
    return max(timeLeft, timeRight);
}

// DFS 방식에 필요한 정보를 (subtree의 노드 개수, DFS로 탐색했을 때 마지막 방문 노드까지의 깊이)를 반환
pair<int,int> dfsInfo(int v) {
    bool hasLeft = (2*v <= maxNode && !brokenEdge[2*v]);
    bool hasRight = (2*v+1 <= maxNode && !brokenEdge[2*v+1]);
    
    // 리프 노드: 자기 자신만 있으므로 크기 1, 마지막 방문 깊이는 0
    if (!hasLeft && !hasRight)
        return {1, 0};
    
    // 한쪽 자식만 있는 경우: 그쪽 자식 DFS 진행
    if (hasLeft && !hasRight) {
        auto leftPair = dfsInfo(2*v);
        return {1 + leftPair.first, 1 + leftPair.second};
    }
    if (!hasLeft && hasRight) {
        auto rightPair = dfsInfo(2*v+1);
        return {1 + rightPair.first, 1 + rightPair.second};
    }
    
    // 두 자식 모두 있는 경우: 왼쪽을 먼저 방문하고, 마지막 방문은 오른쪽 서브트리에서 결정됨
    auto leftPair = dfsInfo(2*v);
    auto rightPair = dfsInfo(2*v+1);
    return {1 + leftPair.first + rightPair.first, 1 + rightPair.second};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> D >> N >> U >> T;
    maxNode = (1 << D) - 1; // 완전 이진 트리의 노드 수
    
    // 1번 노드는 부모가 없으므로, 인덱스 1부터 maxNode까지 사용 (0번 인덱스는 사용하지 않음)
    brokenEdge.assign(maxNode+1, false);
    
    // N개의 파손된 길목 정보 입력 (s, e: s가 부모, e가 자식임이 보장)
    for (int i = 0; i < N; i++){
        int s, e;
        cin >> s >> e;
        // e번 방과 floor(e/2)번 방 사이의 길목 파손 표시
        brokenEdge[e] = true;
    }
    
    // 양갈래 블롭의 탐색 시간 (루트에서 시작하며, 초기 분기 횟수 k=0)
    int timeTwintail = twintail(1, 0);
    
    // 포니테일 블롭의 DFS 탐색: DFS 정보 (노드 수, 마지막 방문 노드까지의 깊이) 구하기
    auto [nodeCount, lastDepth] = dfsInfo(1);
    // DFS에서는 모든 간선을 기본 비용 U로 지나며,
    // 모든 간선은 기본적으로 두 번(전진+후진) 지나지만, 마지막 방문한 경로는 한 번만 지나므로
    // 총 비용 = U * (2*(노드수-1) - (마지막 방문 노드의 깊이))
    int timePonytail = U * (2 * (nodeCount - 1) - lastDepth);
    
    // 두 탐색 시간이 어느 쪽이 더 빠른지에 따라 이모티콘 출력
    if(timeTwintail < timePonytail)
        cout << ":blob_twintail_aww:";
    else if(timeTwintail > timePonytail)
        cout << ":blob_twintail_sad:";
    else
        cout << ":blob_twintail_thinking:";
    
    return 0;
}
