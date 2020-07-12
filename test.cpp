#include <iostream>
#include "SimpleEvents.h"

#define TOPIC1 1
#define TOPIC2 2
#define TOPIC3 3

int val_a, val_b, val_c;
SimpleEvents events = SimpleEvents(TOPIC3);

void func_a(void * data){
    val_a = *static_cast<int*>(data);
}

void func_b(void * data){
    val_b = *static_cast<int*>(data);
}

void func_c(void * data){
    val_c = *static_cast<int*>(data);
}

void test_one_topic_two_subs(){
    events.subscribe(TOPIC1, 1, &func_a);
    events.subscribe(TOPIC1, 2, &func_b);
    int x = 5;
    void * data = &x;
    events.publish(TOPIC1, data);
    if(val_a != 5){
        throw "Sub func_a was not called";
    }
    if(val_b != 5){
        throw "Sub func_b was not called";
    }
}

void test_another_topic_two_subs(){
    events.subscribe(TOPIC2, 1, &func_b);
    events.subscribe(TOPIC2, 2, &func_c);
    int x = 22;
    void * data = &x;
    events.publish(TOPIC2, data);
    if(val_a != 5){
        throw "Sub func_a was called and should not have";
    }
    if(val_b != 22){
        throw "Sub func_b was not called";
    }
    if(val_c !=22){
        throw "Sub func_c was not called";
    }
}

int main() {
  test_one_topic_two_subs();
  test_another_topic_two_subs();
  std::cout << "All good!\n";
}