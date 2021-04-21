#include "FIFO.c"
#include "OPT.c"
#include "LRU.c"

int main()
{
	int choice, num_frames;
	char str_pages[20];
	PRA *pra;

	printf("\n--- Page Replacement Algorithm ---\n");
	printf("1. Default referenced sequence\n");
	printf("2. Manual input sequence\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		strcpy(str_pages, "18520339007");
		break;
	case 2:
		printf("Enter processes: ");
		scanf("%s", str_pages);
		break;
	default:
		return 1;
	}

	printf("\nSelect algorithm:\n");
	printf("1. FIFO algorithm\n");
	printf("2. OPT algorithm\n");
	printf("3. LRU algorithm\n");

	printf("Enter your choice: ");
	scanf("%d", &choice);
	printf("Input page frames: ");
	scanf("%d", &num_frames);

	switch (choice)
	{
	case 1:
		printf("\nFIFO algorithm:");
		pra = new_FIFO(num_frames, str_pages);
		break;
	case 2:
		printf("\nOPT algorithm:");
		pra = new_OPT(num_frames, str_pages);
		break;
	case 3:
		printf("\nLRU algorithm:");
		pra = new_LRU(num_frames, str_pages);
		break;
	default:
		return 1;
	}

	pra->StartPaging(pra);
	pra->DisplayPages(pra);
	pra->DisplayPageTable(pra);
	pra->DisplayPageFaults(pra);

	delete_PRA(pra);
	return 0;
}