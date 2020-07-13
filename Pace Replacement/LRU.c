#include "PRA.c"

int PageIndexInPast(PRA *const self, int page_index, int mem_value)
{
    for (int i = page_index - 1; i >= 0; i--)
        if (self->list_pages[i] == mem_value)
            return i;
    return -1;
}

void StartLRU(PRA *const self)
{
    for (int i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
        {
            int last_past_index = i;
            if (self->IsFramesFull(self, i))
            {
                for (int j = 0; j < self->total_frames; ++j)
                {
                    int last_mem_index = self->total_pages * j + i - 1;
                    int last_mem_value = self->page_table[last_mem_index];
                    int past_index = PageIndexInPast(self, i, last_mem_value);

                    if (past_index == -1)
                    {
                        self->frame_update = j;
                        break;
                    }
                    else if (past_index < last_past_index)
                    {
                        self->frame_update = j;
                        last_past_index = past_index;
                    }
                }
            }
            self->UpdatePageFrame(self, i);
        }
    }
}

PRA *new_LRU(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartLRU;
    return pra;
}