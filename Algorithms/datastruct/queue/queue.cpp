#include "queue.h"
#include<iostream>


Queue::Queue():front(NULL),rear(NULL),size(0){std::cout<<"无参构造函数构造成功"<<std::endl;}


void Queue::enQueue(int item){
    node *newnode = new node;
    newnode->data = item;
    newnode->next = NULL;
    if(front==NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        std::cout<<"rear is"<<rear->data<<std::endl;
        front->next = newnode;
        front = newnode;
        std::cout<<"front is "<<front->data<<std::endl;
    }
    size++;
    std::cout<<"入队成功，size 为： "<<size<<std::endl;

}

void Queue::outQueue(){
    int flag = 0;
    if(rear == NULL){
        std::cout<<"队列为空，请勿出队"<<std::endl;
        return;
    }
    if(rear==front){
        std::cout<<"此时只剩下1个元素了"<<size<<std::endl;
        flag = 1;
    }
    node *temp = rear;
    rear = rear->next;
    delete temp;
    if(flag==1) front = NULL;
    size--;
}

void Queue::clear(){
    node *temp;
    if(size==0){
        std::cout<<"队列已经空了，就没必要清空了"<<std::endl;
        return;
    }
    while(size!=0){
        if(rear == front){
            std::cout<<"我们相等了"<<std::endl;
            front=NULL;
        }
        temp = rear;
        rear = rear->next;
        delete temp;
        size--;
        std::cout<<"clear 执行了..."<<std::endl;
    }
    std::cout<<"队列删除成功，长度为:"<<size<<std::endl;
    
}
Queue::~Queue(){
    std::cout<<"开始调用析构函数了"<<"\n";
    clear();
    std::cout<<"析构函数调用结束了"<<"\n";   
}
Queue::Queue(const Queue &otherQueue){
    std::cout<<"此处调用拷贝构造函数"<<std::endl;
    node *current = otherQueue.rear;
    while(current!=NULL){
        node *newNode = new node;
        newNode->data = current->data;
        newNode->next = NULL;
        if(size==0){
            front = newNode;
            rear = newNode;
        }
        else{
            front->next = newNode;
            front = newNode;
        }
    }
    size = otherQueue.size;
    std::cout<<"拷贝构造函数执行完毕，队列的长度为:"<<size<<std::endl;
}

Queue& Queue::operator=(const Queue &otherQueue){
    std::cout<<"此处调用拷贝赋值函数"<<std::endl;
    if(this==&otherQueue) return *this;
    clear();
    node *current = otherQueue.rear;
    while(current!=NULL){
        node *newNode = new node;
        newNode->data = current->data;
        newNode->next = NULL;
        if(size==0){
            front = newNode;
            rear = newNode;
        }
        else{
            front->next = newNode;
            front = newNode;
        }
    }
    size = otherQueue.size;
    std::cout<<"拷贝赋值函数执行完毕，队列的长度为:"<<size<<std::endl;
    return *this;
}
int main(){
    Queue q;
    Queue q1 = q;
  //  std::cout<<"队列创建成功"<<std::endl;
    return 0;
}