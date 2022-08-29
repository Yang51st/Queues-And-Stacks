#include "circular-queue.h"
#include<iostream>
const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    size_=0;
    capacity_=16;
    items_=new QueueItem[capacity_];
    head_=0;
    tail_=0;
}

CircularQueue::CircularQueue(unsigned int capacity) {
    size_=0;
    capacity_=capacity;
    items_=new QueueItem[capacity_];
    head_=0;
    tail_=0;
}

CircularQueue::~CircularQueue() {
    delete [] items_;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}

bool CircularQueue::full() const {
    if(size()==capacity_){
        return true;
    }
    else{
        return false;
    }
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if(empty()){
        return EMPTY_QUEUE;
    }
    else{
        return items_[head_];
    }
}

bool CircularQueue::enqueue(QueueItem value) {
    if(full()){
        return false;
    }
    else{
        items_[tail_]=value;
        tail_=(tail_+1)%capacity_;
        size_++;
        return true;
    }
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if(empty()){
        return EMPTY_QUEUE;
    }
    else{
        QueueItem temp=items_[head_];
        head_=(head_+1)%capacity_;
        size_--;
        return temp;
    }
}

void CircularQueue::print() const {
    std::cout<<"{";
    for(int k=0;k<size();k++){
        std::cout<<items_[(head_+k)%capacity_]<<", ";
    }
    std::cout<<"}"<<std::endl;
}
