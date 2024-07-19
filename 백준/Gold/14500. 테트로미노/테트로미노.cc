#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> p;
int board[501][501];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> board[i][j];
    }
  }
  int ans = 0;
  p a, b, c, d; // coord
  // long one 
  a = {1, 1};
  b = {1, 2};
  c = {1, 3};
  d = {1, 4};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m-3; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 1};
  b = {2, 1};
  c = {3, 1};
  d = {4, 1};
  for (int i = 0; i < n-3; ++i) {
    for (int j = 0; j < m; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // square one
  a = {1, 1};
  b = {1, 2};
  c = {2, 1};
  d = {2, 2};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // weird one 1, 4 types
  // type 1
  a = {1, 1};
  b = {2, 1};
  c = {3, 1};
  d = {3, 2};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }
  // type 2
  a = {1, 1};
  b = {1, 2};
  c = {1, 3};
  d = {2, 1};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }
  // type 3
  a = {1, 1};
  b = {1, 2};
  c = {2, 2};
  d = {3, 2};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }
  // type 4
  a = {1, 3};
  b = {2, 1};
  c = {2, 2};
  d = {2, 3};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // weird one 2
  // type 1
  a = {1, 1};
  b = {2, 1};
  c = {2, 2};
  d = {3, 2};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // type 2
  a = {2, 1};
  b = {2, 2};
  c = {1, 2};
  d = {1, 3};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // weird one 3
  // type 1
  a = {1, 1};
  b = {1, 2};
  c = {1, 3};
  d = {2, 2};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 2};
  b = {2, 1};
  c = {2, 2};
  d = {3, 2};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 2};
  b = {2, 1};
  c = {2, 2};
  d = {2, 3};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 1};
  b = {2, 1};
  c = {2, 2};
  d = {3, 1};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 2};
  b = {2, 2};
  c = {3, 1};
  d = {3, 2};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 1};
  b = {2, 1};
  c = {2, 2};
  d = {2, 3};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 1};
  b = {1, 2};
  c = {2, 1};
  d = {3, 1};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  a = {1, 1};
  b = {1, 2};
  c = {1, 3};
  d = {2, 3};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // fixed 1
  a = {1, 2};
  b = {2, 1};
  c = {2, 2};
  d = {3, 1};
  for (int i = 0; i < n-2; ++i) {
    for (int j = 0; j < m-1; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }

  // last one
  a = {1, 1};
  b = {1, 2};
  c = {2, 2};
  d = {2, 3};
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < m-2; ++j) {
      p na = {a.X + i, a.Y + j};
      p nb = {b.X + i, b.Y + j};
      p nc = {c.X + i, c.Y + j};
      p nd = {d.X + i, d.Y + j};
      ans = max(ans, board[na.X][na.Y] + board[nb.X][nb.Y] + board[nc.X][nc.Y] + board[nd.X][nd.Y]);
    }
  }
  
  cout << ans;
}