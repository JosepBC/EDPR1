#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "skip_list.h"
#include "random.h"

int Crear(skip_list* sl) {
    sl->topLeft->bottom = NULL;
    sl->topLeft->top = NULL;
    sl->topLeft->left = NULL;
    sl->topLeft->right = NULL;
    sl->topLeft->elem = NULL;

    sl->elemNumber = 0;
    sl->height = 1;
}

int Destruir(skip_list* sl) {
    if (sl == NULL) return LLISTA_NO_CREADA;
    if (sl->elemNumber == 0) return LLISTA_BUIDA;

    if (sl->elemNumber == 1) {
        free(sl->topLeft);
        return SUCCESS;
    }

    //Delete all the lines
    Node_t *it = sl->topLeft, *line = sl->topLeft->bottom;
    while (it->bottom != NULL) {
        it = it->bottom;
        free(it->top);
        line = it;
        line = line->right;
        while (line != NULL) {
            line = line->right;
            free(line->left);
        }
    }

    //Delete the first column
    while (it->top != NULL) {
        it = it->top;
        free(it->bottom);
    }
    
    free(it);
}

//With this function I get in insPos the node that goes at the left side of the new node and it's in the last layer
int insertPos(skip_list *sl, int elem, Node_t *insPos) {
    if (sl == NULL) return LLISTA_NO_CREADA;

    insPos = sl->topLeft;
    while (insPos->bottom != NULL) { //Move down
        insPos = insPos->bottom;
        while (insPos->right != NULL && elem > insPos->right->elem) insPos = insPos->right; //Move right
    }

    return SUCCESS;
}

//Inserts newNode after prev
void insertAfter(Node_t *newNode, Node_t *prev) {
    //Right and left pointers
    Node_t *prevRight = prev->right;
    Node_t *prevLeft = prev->left;

    if(prevRight != NULL) prevRight->left = newNode;
    newNode->left = prev;
    prev->right = newNode;
    newNode->right = prevRight;

    Node_t *prevBot = prev->bottom;

    //bottom pointer, top MUST be NULL as I am inserting the highest element in the tower
    if (prevBot != NULL && prevBot->right != NULL && prevBot->right->elem == newNode->elem && prevBot->right->top == NULL) {
        prevBot->right->top = newNode;
        newNode->bottom = prevBot->right;
    }

}

//Creates a new layer under sl->topLeft
int newLayer(skip_list* sl) {
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    if (newNode == NULL) return MEMORIA_INSUFICIENT;

    sl->height++;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->top = sl->topLeft;
    newNode->bottom = sl->topLeft->bottom;
    if (newNode->bottom != NULL)  newNode->bottom->top = newNode;
    sl->topLeft->bottom = newNode;
}

int Inserir(skip_list* sl, int elem) {
    if (sl == NULL) return LLISTA_NO_CREADA;

    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
    if (newNode == NULL) return MEMORIA_INSUFICIENT;

    long seed1, seed2;

    phrtsd("HelloMyNameIsJosep", &seed1, &seed2);
    setall(seed1, seed2);

    newNode->elem = elem;
    newNode->top = NULL;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->bottom = NULL;

    Node_t* prev = NULL;
    if (sl->elemNumber == 0) {
        newLayer(sl);
        insertAfter(sl, newNode, sl->topLeft->bottom);
    }
    else {
        insertPos(sl, elem, prev);
        insertAfter(sl, newNode, prev);
    }

    int h = 1;
    while (ignuin(0, 1) == 1) {
        h++;
        if (h >= sl->height) {
            newLayer(sl);
        }

        while (prev->top == NULL) {
            prev = prev->left;
        }

        prev = prev->top;
        insertAfter(sl, newNode, prev);
    }
    

}

//Deletes the elem passed by parameter, this elem MUST be the highest elem in it's tower
int deleteElem(Node_t *n) {
    if (n->top != NULL) return OPERACIO_NO_PERMITIDA;

    Node_t *nPrev = n->left, *nPost = n->right;

    nPrev->right = nPost;
    if (nPost != NULL) nPost->left = nPrev;
    free(n);

}

int Esborrar(skip_list* sl, int elem) {
    if (sl == NULL) return LLISTA_NO_CREADA;
    if (sl->elemNumber == 0) return LLISTA_BUIDA;

    Node_t* leftElem = sl->topLeft;
    Node_t* toDelete = leftElem;

    do {
        insertPos(sl, elem, leftElem);
        toDelete = leftElem->right;
        //This should not happen, but....
        if (toDelete == NULL) return OPERACIO_NO_PERMITIDA;
        if (toDelete->elem != elem) return ERROR_ESBORRAR;
        deleteElem(toDelete);
    } while (toDelete->bottom != NULL);

}

int Longitud(skip_list sl, int* lon) {
    if (&sl == NULL) return LLISTA_NO_CREADA;

    *lon = sl.elemNumber;
    return SUCCESS;
}


int Buscar(skip_list sl, int elem, bool* trobat) {
    if (&sl == NULL) return LLISTA_NO_CREADA;
    if (sl.elemNumber == 0) return LLISTA_BUIDA;

    *trobat = false;

    Node_t *it = sl.topLeft;
    while (it->bottom != NULL) { //Move down
        it = it->bottom;
        while (elem > it->elem && it->right != NULL) it = it->right; //Move right
        if (elem == it->elem) {
            *trobat = true;
            return SUCCESS;
        }
    }
    return SUCCESS;
}

int Cost_Buscar(skip_list sl, int elem, int* cost) {
    if (&sl == NULL) return LLISTA_NO_CREADA;
    if (sl.elemNumber == 0) return LLISTA_BUIDA;

    Node_t* it = sl.topLeft;
    while (it->bottom != NULL) { //Move down
        it = it->bottom;
        (*cost)++;

        while (elem > it->elem && it->right != NULL) {
            it = it->right; //Move right
            (*cost)++;
        }
        if (elem == it->elem) return SUCCESS;
    }
    return SUCCESS;
}
