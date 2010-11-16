#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mylist.h>

typedef struct	s_info
{
    int		id;
    char	*name;
}		t_info;

static t_mylist_res fillout(void *data)
{
    t_info *info = (t_info*)data;

    info->id = 42;
    info->name = strdup("Super computer");

    return (MYLIST_R_CONTINUE);
}

static t_mylist_res printout(void *data)
{
    t_info *info = (t_info*)data;

    printf("{id: %d, name: %s}\n", info->id, info->name);
    return (MYLIST_R_CONTINUE);
}

static t_mylist_res removeall(void *data)
{
    t_info *info = (t_info*)data;

    free(info->name);
    free(info);
    return (MYLIST_R_CONTINUE);
}

int main(void)
{
    t_mylist *t;
    unsigned int i;

    mylist_init(&t);

    for (i = 0; i < 100; i++)
	{
	    mylist_push(&t, (void*)malloc(sizeof(t_info)));
	}

    printf("mylist_all for each fillout returns [%d]\n",
	   mylist_all(t, fillout));
    printf("mylist_all for each printout returns [%d]\n",
	   mylist_all(t, printout));
    printf("mylist_all for each removeall returns [%d]\n",
	   mylist_all(t, removeall));

    mylist_free(&t);
    return (0);
}
