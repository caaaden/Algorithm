#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
vector<pair<int,int>> cur_pos(100);
vector<int> stage(100, 1);
void move(int &goal_r, int &goal_c, int &cur_r, int &cur_c)
{
    if(goal_r < cur_r)
    {
        cur_r-=1;
    }
    else if(goal_r > cur_r)
    {
        cur_r+=1;
    }
    else if(goal_c < cur_c)
    {
        cur_c-=1;
    }
    else if(goal_c > cur_c)
    {
        cur_c+=1;
    }

}
int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int clock = 0;
    int arrived_robots = 0;
    int num_robots = routes.size();
    int n = points.size();
    int m = routes[0].size();
    map<int, int> conflict_pos1;
    for(int i = 0;i < num_robots;i++)
    {
        int route = routes[i][0] - 1;
        int cur_r = points[route][0] - 1;
        int cur_c = points[route][1] - 1;
        cur_pos[i] = make_pair(cur_r, cur_c);
        int map_k = 100 * cur_r + cur_c;
        if(conflict_pos1.find(map_k) == conflict_pos1.end())
        {
            conflict_pos1[map_k] = 1;
        }
        else
        {
            conflict_pos1[map_k]++;
        }
        // cout << cur_pos[i].first<< " " << cur_pos[i].second << endl;
    }

    for(auto k: conflict_pos1)
    {
        if (k.second > 1)
        {
            answer += 1;
        }
    }

    while(arrived_robots != num_robots)
    {
        map<int, int> conflict_pos;
        for(int i = 0;i < num_robots;i++)
        {
            if(stage[i] == m) continue;
            int goal_idx = routes[i][stage[i]] - 1;
            int goal_r = points[goal_idx][0] - 1;
            int goal_c = points[goal_idx][1] - 1;

            int cur_r = cur_pos[i].first;
            int cur_c = cur_pos[i].second;

            if(goal_r == cur_r && goal_c == cur_c)
            {
                stage[i]++;
                if(stage[i] == m)
                {
                    arrived_robots++;
                    continue;
                }
                goal_idx = routes[i][stage[i]] - 1;
                goal_r = points[goal_idx][0] - 1;
                goal_c = points[goal_idx][1] - 1;
            }
            // cout << i << " - " << cur_r << " " << cur_c << endl;
            move(goal_r, goal_c, cur_r, cur_c);
            // cout << i << " - " << cur_r << " " << cur_c << endl;
            // cout << endl;
            cur_pos[i].first = cur_r;
            cur_pos[i].second = cur_c;
            int map_k = 100 * cur_r + cur_c;
            if(conflict_pos.find(map_k) == conflict_pos.end())
            {
                conflict_pos[map_k] = 1;
            }
            else
            {
                conflict_pos[map_k]++;
            }
//             for(int j = 0;j < i;j++)
//             {
//                 int other_r = cur_pos[j].first;
//                 int other_c = cur_pos[j].second;

//                 if(cur_r == other_r && cur_c == other_c) answer++;
//             }
        }
        // int conflicts = num_robots - conflict_pos.size();
        // cout << conflicts << endl;
        int cur_answer = 0;
        for(auto k: conflict_pos)
        {
            if (k.second > 1)
            {
                cur_answer += 1;
            }
        }
        // cout << cur_answer << endl;
        // if(clock == 2) break;
        answer += cur_answer;
        clock++;
    }
    return answer;
}