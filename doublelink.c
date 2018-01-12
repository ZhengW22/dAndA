#include <stdio.h>
#include <stdlib.h>
#include "doublelink.h"
#include <stdint.h>
 dllist_t *dl_create(){
     dllist_t *l=(dllist_t*)calloc(1, sizeof(dllist_t));
     return l;
 }
 int8_t dl_destroy(dllist_t **l){
     if(*l == (dllist_t *)NULL){
         return ERR_NO_LIST;
     }
     if((*l)->head == (node_t *)NULL){
         return ERR_EMPTY_LIST;
     }

     node_t *p=(*l)->head;

    while(p != (node_t *)NULL){
        (*l)->head = (*l)->head->next;
        free(p);
        p=(*l)->head;
    }
    (*l)->tail = (node_t *)NULL;
    *l = (dllist_t *)NULL;
    return SUCCESS;
 }
int8_t dl_insert_beginning(dllist_t *l, int32_t value){
    if(l == (dllist_t *)NULL){
        return ERR_NO_LIST;
    }
    node_t *nn = (node_t *)calloc(1, sizeof(node_t));
    if(nn == (node_t *)NULL){
        return ERR_MALLOC_FAIL;
    }
    nn->id = l->tail_id++;
    nn->data = value;
    nn->prev = NULL;
    node_t *p = l->head;
    if(l->head == (node_t*)NULL){
        l->tail = nn;
    }
    else{
        nn->next = p;
        p->prev = nn;
    }
    l->len++;
    l->head = nn;
    return SUCCESS;
}
int8_t dl_insert_end(dllist_t *l, int32_t value){
    if(l == (dllist_t *)NULL){
        return ERR_NO_LIST;
    }
    node_t *nn = (node_t *)calloc(1, sizeof(node_t));
    if(nn == (node_t *)NULL){
        return ERR_MALLOC_FAIL;
    }
    nn->data = value;
    nn->id = l->tail_id++;
    nn->next = (node_t*)NULL;
    node_t *p = l->tail;
    if(l->head == (node_t*)NULL){
        l->head = nn;
    }
    else{
        nn->prev = p;
        p->next = nn;
    }
    l->len++;
    l->tail = nn;
    return SUCCESS;
}
int8_t dl_insert_after(dllist_t *l, int32_t key, int32_t value){
    if(l == (dllist_t*)NULL){
        return ERR_NO_LIST;
    }
    if(l->head == (node_t*)NULL){
        return ERR_EMPTY_LIST;
    }
    node_t *nn = (node_t*)calloc(1, sizeof(node_t));
    if(nn == (node_t*)NULL){
        return ERR_MALLOC_FAIL;
    }
    nn->data = value;
    nn->id = l->tail_id++;
    node_t *p = l->head;
    while(p!=(node_t*)NULL){
        if(p->data == key){
            nn->next = p->next;
            nn->prev = p;
            if(p == l->tail){
                l->tail = nn;
                p->next = nn;
            }
            else{
                p->next->prev = nn;
                p->next = nn;
            }
            break;
        }
        p = p->next;
    }
    return SUCCESS;
}
int8_t dl_insert_before(dllist_t *l, int32_t key, int32_t value){
    if(l == (dllist_t*)NULL){
        return ERR_NO_LIST;
    }
    if(l->head == (node_t*)NULL){
        return ERR_EMPTY_LIST;
    }
    node_t *nn = (node_t*)calloc(1, sizeof(node_t));
    if(nn == (node_t*)NULL){
        return ERR_MALLOC_FAIL;
    }
    nn->data = value;
    nn->id = l->tail_id++;
    node_t *p = l->head;
    while(p!=(node_t*)NULL){
        if(p->data == key){
            nn->next = p;
            nn->prev = p->prev;
            if(p == l->head){
                l->head = nn;
                p->prev = nn;
            }
            else{
                p->prev->next = nn;
                p->prev = nn;
            }
        break;
        }
        p = p->next;
    }
    return SUCCESS;
}
int8_t dl_remove_beginning (dllist_t *l){
    if(l==(dllist_t*)NULL){
        return ERR_NO_LIST;
    }
    if(l->head==(node_t*)NULL){
        return ERR_EMPTY_LIST;
    }
    node_t *p = l->head;
    if(p == l->tail){
        l->head = l->tail = (node_t*)NULL;
    }
    else{
        l->head = p->next;
        p->next->prev = (node_t*)NULL;
    }
    free(p);
    l->len--;
    return SUCCESS;
}
int8_t dl_remove_end(dllist_t *l){
    if(l==(dllist_t*)NULL){
        return ERR_NO_LIST;
    }
    if(l->head==(node_t*)NULL){
        return ERR_EMPTY_LIST;
    }
    node_t *p = l->tail;
    if(p==l->head){
        l->head = l->tail = (node_t*)NULL;
    }
    else{
        l->tail = p->prev;
        p->prev->next = (node_t*)NULL;
    }
    free(p);
    l->len--;
    return SUCCESS;
}
int8_t dl_remove_next(dllist_t *l, int32_t key){
    if(l==(dllist_t*)NULL){
        return ERR_NO_LIST;
    }
    if(l->head==(node_t*)NULL){
        return ERR_EMPTY_LIST;
    }
    node_t *p = l->head;
    node_t *r;
    // this is important.
    while(p->next!=(node_t*)NULL){
        if(p->data==key){
            r = p->next;
            if(r==l->tail){
                l->tail = p;
                p->next = (node_t*)NULL;
            }
            else{
                p->next = r->next;
                r->next->prev = p;
            }
            free(r);
            l->len--;
            break;
        }
        p = p->next;
    }
    return SUCCESS;
}
int8_t dl_remove_prev(dllist_t *l, int32_t key){
    if(l==(dllist_t*)NULL){
        return ERR_NO_LIST;
    }
    if(l->head==(node_t*)NULL){
        return ERR_EMPTY_LIST;
    }
    node_t *p = l->head;
    node_t *r;
    while(p->next!=(node_t*)NULL){
        if(p->data==key){
            r = p->prev;
            if(r==l->head){
                l->head = p;
                p->prev = (node_t*)NULL;
            }
            else{
                p->prev = r->prev;
                r->prev->next = p;
            }
            free(r);
            l->len--;
            break;
        }
        p=p->next;
    }
    return SUCCESS;
}
int main(void)
{
    dllist_t *dl = dl_create();
    dl_insert_beginning(dl, 11);
    printf("%d\n", dl->head->data);
    dl_remove_beginning(dl);
    dl_destroy(&dl);
}
