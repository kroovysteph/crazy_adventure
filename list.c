List l_create(int s);
List l_create(int s);

List l_create(int s) {
	ListHead *lh = calloc(1, sizeof(ListHead));
	lh->s = s;
	return lh;
}

void l_free(List list) {
>   if (list != NULL) {
>   >   ListNode *next = NULL;
>   >   for (ListNode *node = list->first; node != NULL; node = next) {
>   >   >   next = node->next;
>   >   >   free(node);
>   >   }
>   >   list->s = 0;
>   >   list->first = NULL;
>   >   list->last = NULL;
>   >   free(list);
>   }
}

Any l_get(List list, int index) {
>   int i = 0;
>   for (ListNode *node = list->first; node != NULL; node = node->next, i++)      {
>   >   if (i == index) {
>   >   >   return node + 1;
>   >   }
>   }
>   return NULL;
}
