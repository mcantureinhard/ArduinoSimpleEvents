#include "SimpleEvents.h"

SimpleEvents::SimpleEvents(int numTopics){
    this->numTopics = numTopics;
    topics = new topicsCallbacks[numTopics];
}

SimpleEvents::~SimpleEvents(){
    for(int i = 0; i < numTopics; i++){
        delete[] topics[i].cb_s;
    }
    delete[] topics;
}

void SimpleEvents::subscribe(int topic, int id, void (*callback)(void*)){
    //Not checking if topic is valid
    int elems = topics[topic].elements;
    if(!topics[topic].cb_s){
        topics[topic].cb_s = new idcb[1];
    } else {
        idcb * newCallbacks = new idcb[elems+1];
        //TODO: check id is not repeated
        for(int i = 0; i < elems; i++){
            newCallbacks[i].id = topics[topic].cb_s[i].id;
            newCallbacks[i].paramcb = topics[topic].cb_s[i].paramcb;
        }
        delete topics[topic].cb_s;
        topics[topic].cb_s = newCallbacks;
    }
    topics[topic].cb_s[elems].id = id;
    topics[topic].cb_s[elems].paramcb = callback;
    topics[topic].elements++;
}

void SimpleEvents::publish(int topic, void* data){
    if(topics[topic].cb_s){
        for(int i = 0; i < topics[topic].elements; i++){
            topics[topic].cb_s[i].paramcb(data);
        }
    }
};;