# Page Replacement Algorithms
![demo](https://github.com/18520339/os-practice/blob/master/Pace%20Replacement/demo.png)

The algorithms is written according to the structure of OOP using C language (class replaced by struct)

### 7 properties:

-   `total_frames`: total number of frames entered
-   `total_pages`: total number of pages in the list (list_pages)
-   `total_page_faults`: total number of page errors found
-   `frame_update`: the order of the next frame will be updated
-   `list_pages`: list of pages
-   `page_table`: paging table
-   `page_faults`: list the page error results for each page in the page list

### 8 methods:

-   `IsPageExisted`
-   `IsFrameFull`
-   `CopyLastFrames`
-   `UpdatePageFrame`
-   `StartPaging`
-   `DisplayPage`
-   `DisplayTable`
-   `DisplayPageFaults`

### 2 functions are equivalent to *constructor* and *destructor*
-   `new_PRA` (_constructor_)
-   `delete_PRA` (_destructor_)
