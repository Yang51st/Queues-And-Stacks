#include "dynamic-stack.h"
#include<iostream>
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    size_=0;
    capacity_=16;
    init_capacity_=16;
    items_=new StackItem[16];
}

DynamicStack::DynamicStack(unsigned int capacity){
    size_=0;
    capacity_=capacity;
    init_capacity_=capacity;
    items_=new StackItem[init_capacity_];
}

DynamicStack::~DynamicStack() {
    for(int k=0;k<size();k++){
        items_[k]=NULL;
    }
    delete[] items_;
}

unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}

DynamicStack::StackItem DynamicStack::peek() const {
    if(empty()){
        return EMPTY_STACK;
    }
    else{
        return items_[size()-1];
    }
}

void DynamicStack::push(StackItem value) {
    if(size()==capacity_){
        StackItem* temp=new StackItem[capacity_*2];
        for(int k=0;k<size();k++){
            temp[k]=items_[k];
        }
        delete items_;
        items_=temp;
        capacity_*=2;
    }
    if(size()<capacity_) {
        items_[size()] = value;
        size_++;
    }
}

DynamicStack::StackItem DynamicStack::pop() {
    if(empty()){
        return EMPTY_STACK;
    }
    else{
        size_--;
        if(4*size()<=capacity_ && capacity_>=2*init_capacity_){
            StackItem* temp=new StackItem[capacity_/2];
            for(int k=0;k<=size();k++){
                temp[k]=items_[k];
            }
            delete items_;
            items_=temp;
            capacity_/=2;
        }
        return items_[size()];
    }
}

void DynamicStack::print() const {
    std::cout<<"{";
    for(int k=0;k<size();k++){
        std::cout<<" "<<items_[k]<<", ";
    }
    std::cout<<"}"<<std::endl;
}
