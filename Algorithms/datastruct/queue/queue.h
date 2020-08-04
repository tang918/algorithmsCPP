#ifndef QUEUE
#define QUEUE


struct node
{
    int data;
    node *next;
};


class Queue{
public:
    Queue();
    Queue(const Queue &ohterQueue);

    void enQueue(int item);
    void outQueue();
    void clear();
    Queue &operator=(const Queue &otherQueue);
    ~Queue();

private:
    node *front;
    node *rear;
    int size;
};

#endif