#include <iostream>
#include <string>
#include <utility>
using namespace std;

const int MAX = 100005;
pair<string, int> Q[MAX];
int head;
int tail;

void push(pair<string, int> task) {
  Q[tail++] = task;
  tail = tail % MAX;
}

pair<string, int> pop() {
  pair<string, int> x = Q[head++];
  head %= MAX;
  return x;
}

bool isEmpty() {
  return head == tail;
}

int main() {
  int n, q;
  int consumed_time {0};
  pair<string, int> finished_tasks[MAX];
  int current_index {0};
  cin >> n >> q;
  
  for (int i = 0; i < n; i++) {
    string s;
    int t;
    cin >> s >> t;
    push(make_pair(s, t));
  }

  while (!isEmpty()) {
    pair<string, int> current_task = pop();
    if (current_task.second <= q) {
      consumed_time += current_task.second;
      finished_tasks[current_index].first = current_task.first;
      finished_tasks[current_index].second = consumed_time;
      current_index++;
    } else {
      current_task.second -= q;
      push(current_task);
      consumed_time += q;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << finished_tasks[i].first << " " << finished_tasks[i].second << endl;
  }
}
