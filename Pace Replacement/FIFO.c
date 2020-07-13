#include "PRA.c"

void StartFIFO(PRA *const self)
{
    for (int i = 0; i < self->total_pages; ++i)
    {
        self->CopyLastFrames(self, i);
        if (!self->IsPageExisted(self, i))
            self->UpdatePageFrame(self, i);
    }
}

PRA *new_FIFO(int num_frames, char str_pages[20])
{
    PRA *pra = new_PRA(num_frames, str_pages);
    pra->StartPaging = &StartFIFO;
    return pra;
}
