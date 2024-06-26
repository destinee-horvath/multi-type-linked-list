#ifndef MTLL_H
#define MTLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include <errno.h>

#define MAX_INPUT 128
#define BUFFER 256

enum DataType {
    INT,
    FLOAT,
    STRING,      //nest considered string 
    CHAR, 
    REF
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

    union {                //store converted data 
        int type_int; 
        float type_float; 
        char type_char;
        char *type_string;
    };

    struct Node *next;   
    struct Node *prev;     //mainly used for nested lists
}; 

//list info 
struct mtll {
    struct Node *head; 
    struct mtll *next;
    enum ListType type;  //type of list (list or nested)
    size_t id;           //give list a unique id 
};


//helper functions 
extern void clearBuff();

extern void *convertData(char *, enum DataType);

extern void printInvalidCommand(char *);

enum DataType checkType(char *); 

extern size_t sizeList(struct Node *);

extern size_t size_all_lists(struct mtll **);

size_t upwrap_nest(char *);

size_t list_exists(struct mtll **, size_t);

//Logic functions 
extern struct mtll *mtll_create();

extern size_t make_list(struct mtll **, struct mtll *, size_t); 

extern void mtll_free(struct mtll *);

extern void mtll_view(struct mtll *);

extern void mtll_type(struct mtll *);

extern void mtll_view_all(struct mtll **, size_t);

extern size_t mtll_remove(struct mtll **, struct mtll *);

extern void mtll_insert(struct mtll **, struct mtll *, ssize_t, char *); 

extern void mtll_delete(struct mtll *, ssize_t); 

extern void mtll_view_nested(struct mtll **, struct mtll *, size_t);

extern void nested_view(struct mtll *); 

extern struct mtll *nested_view_id(struct mtll **, size_t);

#endif
