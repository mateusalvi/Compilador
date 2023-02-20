
typedef struct ItemContent
{
    int atLine;
    int type;
    union{
		int intValue;
		char charValue;
  }
	float size;
} content;

typedef struct Ht_item
{
    char* key;
    content** Ht_item_content;
} Ht_item;

// Defines the HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item** items;
    int size;
    int count;
} HashTable;