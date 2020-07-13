#include <stdbool.h>

typedef struct _PRA
{
    int total_frames;
    int total_pages;
    int total_page_faults;
    int frame_update;

    int *list_pages;
    int *page_table;
    char *page_faults;

    bool (*IsPageExisted)(struct _PRA *, int);
    bool (*IsFramesFull)(struct _PRA *, int);
    void (*CopyLastFrames)(struct _PRA *, int);
    void (*UpdatePageFrame)(struct _PRA *, int);

    void (*StartPaging)(struct _PRA *);
    void (*DisplayPages)(struct _PRA *);
    void (*DisplayPageTable)(struct _PRA *);
    void (*DisplayPageFaults)(struct _PRA *);
} PRA;
