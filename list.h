
typedef struct ListHead* List;

typedef struct ListHead {
	int s;
	void* first;
	void* last;
} ListHead;

typedef struct ListNode {
	struct ListNode *next;
} ListNode;

typedef struct ListHead {
	int s;
	void* first;
	void* last;
} ListHead;

typedef struct PointerListNode {
	struct PointerListNode *next;
	void *value;
} PointerListNode;
