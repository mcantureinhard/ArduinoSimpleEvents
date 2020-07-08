#ifndef SIMPLEEVENTS_h
#define SIMPLEEVENTS_h

typedef struct {
    int id;
    void (*paramcb)(void*);
} idcb;

typedef struct {
    int topic;
    idcb * cb_s;
    
} topicsCallbacks;

class SimpleEvents {
    private:
    topicsCallbacks * topics;
    public:
    SimpleEvents(int);
    void publish(int, void*);
    void subscribe(int, int, void (*callback)(void*));
};

#endif