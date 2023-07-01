     L->last = L->last->next;
        L->last->key = value;
        L->last->next = NULL;
        L->size++;