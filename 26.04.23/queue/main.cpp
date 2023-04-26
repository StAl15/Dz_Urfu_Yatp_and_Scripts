#include "header.h"

int main() {
    Queue queue;
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(7);

    cout << "this queue empty:" << queue.empty() << endl;

    cout << "deque: " << queue.dequeue() << " " << endl;
    cout << "deque: " << queue.dequeue() << " " << endl;
    cout << "deque: " << queue.dequeue() << " " << endl;

    cout << "this queue empty:" << queue.empty() << endl;

    return 0;
}