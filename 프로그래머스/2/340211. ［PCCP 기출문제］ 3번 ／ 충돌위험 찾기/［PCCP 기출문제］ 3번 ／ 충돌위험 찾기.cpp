#include <string>
#include <vector>

using namespace std;
vector<vector<int>> robots;
vector<int> found;
int result = 0;
int routesize = 0;

bool Update(vector<vector<int>>& points, vector<vector<int>>& routes)
{
    for(int i=0; i<robots.size(); i++)
    {

        if(found[i] == routesize)
        {
            continue;
        }

        int round = found[i];
        auto goal = points[routes[i][round]-1];

        if(goal[0] == robots[i][0] && goal[1] == robots[i][1])
        {
            round++;
            found[i] = round;
            if(round == routesize)
                continue;
        }

        goal = points[routes[i][round]-1];

        int x = robots[i][0];
        int y = robots[i][1];

        if(x != goal[0])
        {
            int move;
            if(goal[0] > x)
                move = 1;
            else
                move = -1;
            robots[i][0] = x + move;
        }
        else
        {
            int move;
            if(goal[1] > y)
                move = 1;
            else
                move = -1;

            robots[i][1] = y + move;
        }
    }

    return true;
}

void Check()
{

    vector<vector<bool>> visited = vector<vector<bool>>(101, vector<bool>(101, false));
    for(int i=0; i<robots.size(); i++)
    {
        if(found[i] == routesize)
            continue;

        for(int j=i+1; j<robots.size(); j++)
        {
            if(found[j] == routesize)
                continue;

            if(robots[i][0] == robots[j][0] && robots[i][1] == robots[j][1])
            {
                visited[robots[i][0]][robots[i][1]] = true;
            }

        }
    }

    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            if(visited[i][j])
                result++;
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    found =vector<int>(routes.size(), 1);
    routesize = routes[0].size();
    for(int i=0; i<routes.size(); i++)
    {
        auto route = routes[i];
        robots.push_back(points[route[0]-1]);
    }

    Check();

    while(true)
    {

        Update(points, routes);
        Check();

        bool find = true;
        for(int i=0; i<robots.size(); i++)
        {
            if(found[i] != routesize)
            {
                find = false;
                break;
            }
        }

        if(find)
            break;
    }
    answer = result;
    return answer;
}