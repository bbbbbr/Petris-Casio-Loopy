// game_types.h

#ifndef GAME_TYPES_H
#define GAME_TYPES_H

extern UINT8 game_type_cleanup_tail_count;
extern UINT8 game_type_collect_dog_count;
extern UINT8 game_type_collect_cat_count;
extern UINT8 game_type_collect_fish_count;
extern UINT8 game_type_collect_snake_count;

void game_types_init(void);
void game_types_handle_level_transition(void);

void game_type_collect_set_level_counts(UINT8);
void game_type_collect_decrement_pet_count(UINT8);

UINT8 game_type_pet_cleanup_get_tail_count(UINT8);
void game_type_pet_cleanup_increment_tail_count(void);
void game_type_pet_cleanup_decrement_tail_count(void);

#endif