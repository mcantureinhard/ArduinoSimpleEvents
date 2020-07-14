#ifndef SIMPLEEVENTS_h
#define SIMPLEEVENTS_h

typedef struct {
    int id;
    void (*paramcb)(void*);
} idcb;

typedef struct {
    int topic;
    idcb * cb_s;
    int elements;
    
} topicsCallbacks;

class SimpleEvents {
    private:
    int numTopics;
    topicsCallbacks * topics;
    public:
    ~SimpleEvents();
    SimpleEvents(int);
    void publish(int, void*);
    void subscribe(int, int, void (*callback)(void*));
    //TODO: void unsubscribe(int, int)
};

#endif