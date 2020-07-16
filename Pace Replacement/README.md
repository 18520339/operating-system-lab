# Page Replacement Algorithms

> The algorithms is written according to the structure of OOP using C language (class replaced by struct)

```C
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
```

#### 7 properties:

-   `total_frames`: total number of frames entered
-   `total_pages`: total number of pages in the list (list_pages)
-   `total_page_faults`: total number of page errors found
-   `frame_update`: the order of the next frame will be updated
-   `list_pages`: list of pages
-   `page_table`: paging table
-   `page_faults`: list the page error results for each page in the page list

#### 8 methods:

-   `IsPageExisted`:
-   `IsFrameFull`:
-   `CopyLastFrames`:
-   `UpdatePageFrame`:
-   `StartPaging`: .
-   `DisplayPage`:
-   `DisplayTable`:
-   `DisplayPageFaults`:

#### 2 functions are equivalent to _constructor_ and _destructor_ defined in `PRA.c`

-   `new_PRA` (_constructor_)
-   `delete_PRA` (_destructor_)
