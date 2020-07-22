#include <stdbool.h>

typedef struct _PRA /* Page Replacement Algorithm */
{
    int total_frames;
    int total_pages;
    int total_page_faults;
    int frame_update;

    int *list_pages;
    int *page_table;
    char *page_faults;

    /* Get the current position of the page being reviewed and check if the value 
    of this page already exists in the previous position in the paging table */
    bool (*IsPageExisted)(struct _PRA *, int);

    /* Get the current position of the page being reviewed and check at this 
    position if the Frames are full. Used in 2 algorithms LRU and OPT. Can be 
    used in FIFO but this does not seem necessary */
    bool (*IsFramesFull)(struct _PRA *, int);

    /* Get the current position of the page being reviewed and assign the value 
    of the frames at this position equal to the value of the previous position */
    void (*CopyLastFrames)(struct _PRA *, int);

    /* Receives the current position of the page being reviewed and assigns the 
    value of the ordered frame by frame_update at this position by its value in 
    the page list. Next, proceed to mark the page error at this position while 
    increasing the total number of page errors and frame_update to 1 */
    void (*UpdatePageFrame)(struct _PRA *, int);

    /* The main function called to start running the algorithm is also a 
    virtual method that will be defined individually for each algorithm */
    void (*StartPaging)(struct _PRA *);

    /* Displays a list of pages */
    void (*DisplayPages)(struct _PRA *);

    /* Displays details of the value of frames in memory */
    void (*DisplayPageTable)(struct _PRA *);

    /* Displays the error results of each page and total number of page errors*/
    void (*DisplayPageFaults)(struct _PRA *);
} PRA;
