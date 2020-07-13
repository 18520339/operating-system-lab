#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PRA.h"

bool IsPageExisted(PRA *const self, int page_index)
{
    int page_value = self->list_pages[page_index];
    for (int i = 0; i < self->total_frames; ++i)
    {
        int last_mem_index = self->total_pages * i + page_index - 1;
        if (self->page_table[last_mem_index] == page_value)
            return true;
    }
    return false;
}

bool IsFramesFull(PRA *const self, int page_index)
{
    for (int i = 0; i < self->total_frames; ++i)
    {
        int mem_index = self->total_pages * i + page_index;
        if (self->page_table[mem_index] == -1)
            return false;
    }
    return true;
}

void CopyLastFrames(PRA *const self, int page_index)
{
    for (int i = 0; i < self->total_frames; ++i)
    {
        int last_mem_index = self->total_pages * i + page_index - 1;
        int last_mem_value = self->page_table[last_mem_index];
        self->page_table[self->total_pages * i + page_index] = last_mem_value;
    }
}

void UpdatePageFrame(PRA *const self, int page_index)
{
    int mem_index = self->total_pages * self->frame_update + page_index;
    self->page_table[mem_index] = self->list_pages[page_index];
    self->page_faults[page_index] = '*';
    self->total_page_faults++;

    self->frame_update++;
    if (self->frame_update >= self->total_frames)
        self->frame_update = 0;
}

void StartPaging(PRA *const self) {}

void DisplayPages(PRA *const self)
{
    printf("\n--------------");
    for (int i = 0; i < self->total_pages; ++i)
        printf("----");

    printf("\n|    Page    |");
    for (int i = 0; i < self->total_pages; ++i)
        printf(" %d |", self->list_pages[i]);

    printf("\n--------------");
    for (int i = 0; i < self->total_pages; ++i)
        printf("----");
}

void DisplayPageTable(PRA *const self)
{
    for (int i = 0; i < self->total_frames; ++i)
    {
        printf("\n|  Frame 0%d  |", i + 1);
        for (int j = 0; j < self->total_pages; ++j)
        {
            int value = self->page_table[i * self->total_pages + j];
            if (value == -1) printf("   |");
            else printf(" %d |", value);
        }
    }
}

void DisplayPageFaults(PRA *const self)
{
    printf("\n--------------");
    for (int i = 0; i < self->total_pages; ++i)
        printf("----");

    printf("\n| Page Fault |");
    for (int i = 0; i < self->total_pages; ++i)
        printf(" %c |", self->page_faults[i]);

    printf("\n--------------");
    for (int i = 0; i < self->total_pages; ++i)
        printf("----");

    printf("\nNumber of Page Faults: %d", self->total_page_faults);
}

void delete_PRA(PRA *self)
{
    free(self->list_pages);
    free(self->page_table);
    self = NULL;
}

PRA *new_PRA(int total_frames, char str_processes[20])
{
    PRA *pra = NULL;
    pra = (PRA *)malloc(sizeof(PRA));
    if (pra == NULL) return NULL;

    pra->total_frames = total_frames;
    pra->total_pages = strlen(str_processes);
    pra->total_page_faults = 0;
    pra->frame_update = 0;

    pra->list_pages = (int *)malloc(pra->total_pages * sizeof(int));
    if (pra->list_pages == NULL) return NULL;

    pra->page_table = (int *)malloc(pra->total_frames * pra->total_pages * sizeof(int));
    if (pra->page_table == NULL) return NULL;

    pra->page_faults = (char *)malloc(pra->total_pages * sizeof(char));
    if (pra->page_faults == NULL) return NULL;

    for (int i = 0; i < pra->total_pages; ++i)
    {
        *(pra->list_pages + i) = str_processes[i] - '0';
        *(pra->page_faults + i) = ' ';
    }

    for (int i = 0; i < pra->total_frames; ++i)
        for (int j = 0; j < pra->total_pages; ++j)
            pra->page_table[i * pra->total_pages + j] = -1;

    pra->IsPageExisted = &IsPageExisted;
    pra->IsFramesFull = &IsFramesFull;
    pra->CopyLastFrames = &CopyLastFrames;
    pra->UpdatePageFrame = &UpdatePageFrame;

    pra->StartPaging = &StartPaging;
    pra->DisplayPages = &DisplayPages;
    pra->DisplayPageTable = &DisplayPageTable;
    pra->DisplayPageFaults = &DisplayPageFaults;

    return pra;
}