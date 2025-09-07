#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  cout << "Front element is: " << q.front() << endl;
  cout << "Back element is: " << q.back() << endl;

  q.pop();
  cout << "Front element after pop: " << q.front() << endl;

  if (!q.empty()) {
    cout << "Queue is not empty" << endl;
  }

  cout << "Size of queue is: " << q.size() << endl;

  return 0;
}