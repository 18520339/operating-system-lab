#include "PRA.c"

int PageIndexInFuture(PRA *const self, int page_index, int mem_value)
{
    for (int i = page_index + 1; i < self->total_pages; ++i)
        if (self->list_pages[i] == mem_value)
            return i;
    return -1;
}

void StartOPT(PRA *const self)
{
    for (int i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
        {
            int last_future_index = 0;
            if (self->IsFramesFull(self, i))
            {
                for (int j = 0; j < self->total_frames; ++j)
                {
                    int last_mem_index = self->total_pages * j + i - 1;
                    int last_mem_value = self->page_table[last_mem_index];
                    int future_index = PageIndexInFuture(self, i, last_mem_value);

                    if (future_index == -1)
                    {
                        self->frame_update = j;
                        break;
                    }
                    else if (future_index > last_future_index)
                    {
                        self->frame_update = j;
                        last_future_index = future_index;
                    }
                }
            }
            self->UpdatePageFrame(self, i);
        }
    }
}

PRA *new_OPT(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartOPT;
    return pra;
}