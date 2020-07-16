#include <gb/gb.h>
#include <gb/cgb.h> // Include cgb functions

#include "fade.h"

// https://github.com/Zal0/ZGB/blob/b8cc0c0b9459bf41d84160069bcd35e4ccde6c4f/common/src/Fade_b.c

#define FADE_IN_START 5
#define FADE_OUT_START 0
                        //   xRRRRRGGGGGBBBBB
// const UWORD FADE_LUT[6] = {0b0000000000000000,  // No white present to mix
//                            0b0000010000100001,
//                            0b0000110001100011,
//                            0b0001110011100111,
//                            0b0011110111101111,
//                            0b0111111111111111}; // Full white present to mix

// Fade palette pointers needs to be initialized to something
// So just point them at the Fade LUT (which will have a gradient of greys)
// const UWORD * p_FadePalBg[8]     = {FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT};
// const UWORD * p_FadePalSprite[8] = {FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT, FADE_LUT};

//////////////////////////////////////////////

                        //   xRRRRRGGGGGBBBBB
const UWORD FADE_LUT[6] = {0b0000000000000000,  // No white present to mix
                           0b0000010000100001,
                           0b0000110001100011,
                           0b0001110011100111,
                           0b0011110111101111,
                           0b0111111111111111}; // Full white present to mix

INT16 DespRight(INT16 a, INT16 b) {
    return a >> b;
}
/*
#define RGB2(r, g, b) ((UINT16)(r)) | (((UINT16)(g)) <<  5) | ((((UINT16)(b)) << 8) << 2);

#define PAL_RED(C)   (((C)      ) & 0x1F)
#define PAL_GREEN(C) (((C) >>  5) & 0x1F)
#define PAL_BLUE(C)  (((C) >> 10) & 0x1F)


UWORD UpdateColor(UINT8 i, UWORD col) {
    //return RGB2(DespRight(PAL_RED(col), i), DespRight(PAL_GREEN(col), i), DespRight(PAL_BLUE(col), i));
    return RGB2(
        PAL_RED(col)
            | DespRight(0x1F, 5 - i),

        PAL_GREEN(col)
            | DespRight(0x1F, 5 - i),

        PAL_BLUE(col)
            | DespRight(0x1F, 5 - i));
}

*/
UWORD ZGB_Fading_BPal[32];
UWORD ZGB_Fading_SPal[32];



void FadeStepColor(UINT8 i) {
    UINT8 pal, c;
    UWORD palette[4];
    UWORD palette_s[4];
    UWORD* col = ZGB_Fading_BPal;
    UWORD* col_s = ZGB_Fading_SPal;

    for(pal = 0; pal < 8; pal ++) {
        for(c = 0; c < 4; ++c, ++col, ++col_s) {
                // palette[c] =  UpdateColor(i, *col);
                // palette_s[c] =  UpdateColor(i, *col_s);
            // Optimize using LUT
            palette[c] = *col | FADE_LUT[i];
            palette_s[c] = *col_s | FADE_LUT[i];

        };
        set_bkg_palette(pal, 1, palette);
        set_sprite_palette(pal, 1, palette_s);
    }
    wait_vbl_done();
    // delay(20); // expects cpu_fast
    // delay(7);  // zgb non-cpu_cast
    delay(20); // optimized zgb needs a larger delay
}



// void FadeInCOLOR() {
//     UINT8 i;
//     for(i = 0; i != 6; i ++) {
//         FadeStepColor(i);
//     }
// }

// void FadeOutColor() {
//     UINT8 i;
//     for(i = 5; i != 0xFF; -- i) {
//         FadeStepColor(i);
//     }
// }

void fade_start(INT8 fade_dir) {
    UINT8 i;

    if (fade_dir == FADE_IN) {
    //if (fade_dir == FADE_OUT) {

        for(i = 5; i != 0xFF; -- i) {
            FadeStepColor(i);
        }

    }
    else {

        for(i = 0; i != 6; i ++) {
            FadeStepColor(i);
        }

    }
}


// void SetPalette(PALETTE_TYPE t, UINT8 first_palette, UINT8 nb_palettes, UINT16 *rgb_data, UINT8 bank) {
//     UWORD* pal_ptr = (t == BG_PALETTE) ? ZGB_Fading_BPal : ZGB_Fading_SPal;
//     PUSH_BANK(bank);
//     if(t == BG_PALETTE) {
//         set_bkg_palette(first_palette, nb_palettes, rgb_data);
//     } else {
//         set_sprite_palette(first_palette, nb_palettes, rgb_data);
//     }
//     memcpy(&pal_ptr[first_palette << 2], rgb_data, nb_palettes << 3);
//     POP_BANK;
// }


void fade_set_pal(UINT8 first_palette, UINT8 nb_palettes, UWORD /*UINT16*/ * rgb_data, UINT8 t) {
    int c;

    UWORD* pal_ptr = (t == FADE_PAL_BKG) ? ZGB_Fading_BPal : ZGB_Fading_SPal;

    // if(t == FADE_PAL_BKG) {
    //     set_bkg_palette(first_palette, nb_palettes, rgb_data);
    // } else {
    //     set_sprite_palette(first_palette, nb_palettes, rgb_data);
    // }

    //memcpy(&pal_ptr[first_palette << 2], rgb_data, nb_palettes << 3);
    pal_ptr += (first_palette << 2);
    for (c=0; c < (nb_palettes << 3); c++) {
        *pal_ptr++ = *rgb_data++;
    }
}

//////////////////////////////////////////////////////////////////


#define NUM_COLORS_PER_PAL 4 // (sizeof(UWORD) * 4)


/*
void fade_set_pal(UINT8 start_pal, UINT8 num_pal, UWORD * p_SrcPal, UINT8 which_pal) {
    int c;

    // // Pass palette update through to GBDK pal function
    // if (which_pal == FADE_PAL_BKG)
    //     set_bkg_palette(start_pal, num_pal, p_SrcPal);
    // else
    //     set_sprite_palette(start_pal, num_pal, p_SrcPal);

    // Now copy palette pointers into fade palette array slots
    for (c = start_pal; c < (start_pal + num_pal); c++) {

        if (which_pal == FADE_PAL_BKG)
            p_FadePalBg[c] = p_SrcPal;
        else
            p_FadePalSprite[c] = p_SrcPal;

        p_SrcPal += NUM_COLORS_PER_PAL;
    }
}


void fade_start(INT8 fade_dir) {

    INT8 i;
    UINT8 pal, c;
    UWORD palette_bg[4]; // Background Pal
    UWORD palette_sp[4]; // Sprite Pal
    const UWORD * p_bg;
    const UWORD * p_sp;

    i = (fade_dir == FADE_OUT) ? FADE_OUT_START : FADE_IN_START; // Set loop start (5 for fade in, 0 for fade out)

    while ((i != -1) && (i != 6)) {

        // TODO: There is some flickering since palette rewrite timing is not locked to Vblank (and seems to take too long to compelte)
        // while((STAT_REG & 0x03) != 0x01);
        for(pal = 0; pal < 8; pal++) {
            // Load pointer to palette from cached values
            p_bg = p_FadePalBg[pal];
            p_sp = p_FadePalSprite[pal];

            // Read colors from palette and get faded version
            for(c = 0; c < 4; ++c) {
                    // Fade in/out from White
                    palette_bg[c] = (*p_bg | FADE_LUT[i]);
                    palette_sp[c] = (*p_sp | FADE_LUT[i]);

                    // // Fade in/out from Black (if enabled, remove: = {FADE_LUT)
                    // palette_bg[c] = ((*p_bg) >> i) & FADE_LUT[5 - i];
                    // palette_sp[c] = ((*p_sp) >> i) & FADE_LUT[5 - i];

                    p_bg++;
                    p_sp++;
            };
            // Apply current step of faded palette colors
            set_bkg_palette(pal, 1, palette_bg);
            set_sprite_palette(pal, 1, palette_sp);
        }
        delay(20);
        i += fade_dir;
    }
}
*/