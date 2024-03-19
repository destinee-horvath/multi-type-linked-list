#ifndef MTLL_H
#define MTLL_H

#include <stddef.h>

enum DataType {
    INT,
    FLOAT,
    STRING,      //nest considered string 
    CHAR
    // NEST 
};

enum ListType {
    LIST, 
    NESTED  
};

//node info
struct Node {
    void *data;            //store data (of any datatype)
    enum DataType type;    //store type of data 
    struct Node *next;   
}; 

//list info 
struct mtll {
    struct Node *head; 
    enum ListType type;  //type of list (list or nested)
    size_t id;           //give list a unique id 
};

extern struct mtll *mtll_create();

extern void mtll_free(struct mtll *);

extern void mtll_view(struct mtll *);

extern void mtll_view_all(struct mtll **, size_t);

extern void mtll_remove(struct mtll **, size_t, struct mtll *);

// You will likely need other functions for Parts 2 and 3,
// And for general input / output management


#endif
