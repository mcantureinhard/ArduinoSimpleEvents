#include "SimpleEvents.h"

SimpleEvents::SimpleEvents(int numTopics){
    topics = new topicsCallbacks[numTopics];
}

void SimpleEvents::subscribe(int topic, int id, void (*callback)(void*)){
    //Not checking if topic is valid
    int pos;
    if(!topics[topic].cb_s){
        topics[topic].cb_s = new idcb[1];
        pos = 0;
    } else {
        int size = sizeof(topics[topic].cb_s)/sizeof(idcb);
        idcb * newCallbacks = new idcb[size+1];
        //TODO: check id is not repeated
        for(int i = 0; i < size; i++){
            newCallbacks[i].id = topics[topic].cb_s[i].id;
            newCallbacks[i].paramcb = topics[topic].cb_s[i].paramcb;
        }
        delete topics[topic].cb_s;
        topics[topic].cb_s = newCallbacks;
        pos = size;
    }
    topics[topic].cb_s[pos].id = id;
    topics[topic].cb_s[pos].paramcb = callback;
}

void SimpleEvents::publish(int topic, void* data){
    if(topics[topic].cb_s){
        int size = sizeof(topics[topic].cb_s)/sizeof(idcb);
        for(int i = 0; i < size; i++){
            topics[topic].cb_s[i].paramcb(data);
        }
    }
}