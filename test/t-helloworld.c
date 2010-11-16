#include <stdio.h>
#include <string.h>
#include <mylist.h>

static t_mylist_res callback(void *data)
{
    printf("[%s]\n", (char*)data);
    if (strcmp(data, "world") == 0)
	return (MYLIST_R_FOUND);
    return (MYLIST_R_CONTINUE);
}

int main(void)
{
    t_mylist *t;
    char hello[] = "hello";
    char world[] = "world";
    char dot[] = "!";

    mylist_init(&t);
    mylist_push(&t, (void*)dot);
    mylist_push(&t, (void*)world);
    mylist_push(&t, (void*)hello);
    mylist_delete(&t, (void*)hello);
    mylist_delete(&t, (void*)dot);
    printf("res [%d]\n", mylist_all(t, callback));
    mylist_free(&t);
    return (0);
}
