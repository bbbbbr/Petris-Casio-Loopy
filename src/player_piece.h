// player_piece.h

#ifndef PLAYER_PIECE_H
#define PLAYER_PIECE_H

#define PLAYER_PIECE_SHOW 1
#define PLAYER_PIECE_HIDE 0

extern  INT8 player_x;
extern  INT8 player_y;
extern  INT8 player_rotate; // Uses wraparound, so allow negative nums
extern UINT8 player_piece;
extern UINT8 player_attrib;


// Update sprite to current coordinates
// Will reveal sprite if hidden at 0,0
#define PLAYER_PIECE_UPDATE_SHOWAT_XY() move_sprite(SPR_PLAYER, \
                        (player_x * BRD_UNIT_SIZE) + BRD_PIECE_X_OFFSET, \
                        (player_y * BRD_UNIT_SIZE) + BRD_PIECE_Y_OFFSET)
// Hide player sprite off-screen
#define PLAYER_PIECE_UPDATE_HIDE() move_sprite(SPR_PLAYER, 0,0)
//void  player_piece_update_xy(UINT8);

UINT8 player_piece_try_reload(void);
void  player_piece_set_on_board(void);
UINT8 player_piece_connect_get(UINT8, UINT8);

UINT8 player_piece_move(INT8, INT8);
void  player_piece_update_gfx(void);
void  player_piece_rotate_apply(UINT8);

void player_piece_cycle_pet_types(void);

#endif // PLAYER_PIECE_H
