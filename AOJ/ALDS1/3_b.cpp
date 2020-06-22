#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
  int consumed_time {0};
  int n, q;
  cin >> n >> q;
  queue<pair<string, int>> finished_queue;
  queue<pair<string, int>> unfinished_queue;

  for (int i = 0; i < n; i++) {
    string name;
    int task {0};
    cin >> name >> task;
    pair<string, int> worker;
    worker.first = name;
    worker.second = task;
    unfinished_queue.push(worker);
  }

  while(!unfinished_queue.empty()) {
    pair<string, int> current_worker = unfinished_queue.front(); unfinished_queue.pop();
    if (current_worker.second <= q) {
      consumed_time += current_worker.second;
      pair<string, int> finished_worker {current_worker.first, consumed_time};
      finished_queue.push(finished_worker);
    } else {
      current_worker.second -= q;
      unfinished_queue.push(current_worker);
      consumed_time += q;
    }
  }

  while(!finished_queue.empty()) {
    pair<string, int> finished_worker = finished_queue.front(); finished_queue.pop();
    cout << finished_worker.first << " " << finished_worker.second << endl;
  }
}
