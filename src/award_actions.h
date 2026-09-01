#ifndef AWARD_ACTIONS_H
#define AWARD_ACTIONS_H

#define NUM_AWARDS 60

/* Array of award names (index 0..59) */
extern const char *award_names[NUM_AWARDS];

/* Apply the patch for a single award (1..60) */
void apply_award(int award_num, long shpid, long base_addr);

#endif