#include "../filler.h"

int		which_can_place(s_board *start)
{
	// if ((can_place_both_offsets(start) == 0) || (can_place_row_offset(start) == 0) || (can_place_offset(start) == 0) || (can_place(start) == 0))
	// 	return (0);
	/*else */if (start->row_offset > 0 && start->offset > 0)
		fprintf(stderr, "can_place_both_offsets: %d\n", can_place_both_offsets(start));
	else if (start->row_offset > 0)
		fprintf(stderr, "can_place_row_offset: %d\n", can_place_row_offset(start));
	else if (start->offset > 0)
		fprintf(stderr, "can_place_offset: %d\n", can_place_offset(start));
	else if (start->offset == 0 && start->row_offset == 0)
		fprintf(stderr, "can_place: %d\n", can_place(start));
	// else if ((can_place_both_offsets(start) == 1) || (can_place_row_offset(start) == 1) || (can_place_offset(start) == 1) || (can_place(start) == 1))
	// {
	// 	start->offset += 1;
	// 	which_can_place(start);
	// }
	// return (1);
	return (0);
}