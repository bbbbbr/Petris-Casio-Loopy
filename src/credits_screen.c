// Copyright 2026 (c) bbbbbr
//
// This software is licensed under:
//
// For the purposes of this project "Share Alike" shall also include
// distribution of the source code and any changes to it.
//
// CC-BY-NC-SA: Attribution Non-Commercial Share Alike Creative Commons
// Attribution-NonCommercial-ShareAlike 4.0 International License
// See: http://creativecommons.org/licenses/by-nc-sa/4.0/


#include <gbdk/platform.h>
#include <gbdk/metasprites.h>

#include <stdint.h>
#include <stdbool.h>

#include "common.h"
#include "sound.h"

#include "gfx.h"
#include "gfx_print.h"
#include "input.h"

#include "fade2pal.h"
#include "fade.h"

#include "intro_screen_out.h"  // For determining where to start loading font tiles

#include "credits_screen.h"



// The tile load start offset here is to skip past main background + transparent tile + the two tiles
// used during gameplay for filling/resetting under the board, so that when the font loads it won't
// overwrite the filled board (from end of gameplay) and turn that area transparent
#define TILE_LOAD_OFFSET_FONT_VRAM_ABS     (OBJ_TILEGROUP_BASE_512 + 0u)
#define TILE_LOAD_OFFSET_FONT_VRAM_OAM_REL (0u)


#define PAL_CREDITS      (PRINT_PAL_TILE_YELLOW)
#define PAL_LICENSE      (PRINT_PAL_TILE_GREY)

#define SCROLL_FAST (3u)
#define SCROLL_MED  (4u)
#define SCROLL_SLOW (8u)
#define FRAMES_PER_SCROLL_UPDATE_SPEED (SCROLL_FAST)

#define TEXT_DELAY 0


// These need to match what's in the LUT spreadsheet
#define CYLINDER_HEIGHT       (DEVICE_SCREEN_PX_HEIGHT / 2)
#define CYLINDER_HEIGHT_HALF  ((CYLINDER_HEIGHT) / 2)
#define CYLINDER_START        (32)
#define CYLINDER_END          ((CYLINDER_START) + (CYLINDER_HEIGHT))
// #define CYLINDER_START        ((DEVICE_SCREEN_PX_HEIGHT - CYLINDER_HEIGHT) / 2)


static uint8_t scroll_counter;
static uint16_t scroll_start_scy;
static bool    fade_start;

static const int16_t scy_offset_table[224] = {
    // Full size centered cylinder
    // 0,6,2,2,1,1,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,-1,0,0,0,0,0,0,-1,0,0,0,0,-1,0,0,0,-1,0,0,-1,0,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,-1,0,0,-1,0,-1,0,-1,0,0,-1,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,0,-1,0,0,-1,0,0,0,-1,0,0,0,0,-1,0,0,0,0,0,0,-1,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,1,2,2,7

    // Half size centered cylinder
    // 144 GB version
    // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,4,2,2,2,1,2,1,1,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,-1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,1,1,0,1,1,1,2,1,2,2,2,4,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

    // Loopy 224 pixels tall screen
    // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,5,3,3,2,2,2,1,2,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,1,-1,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,2,1,2,2,2,3,3,5,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

    // Starting at line: 32
        // .50 amplify ~2x, looks ok
        // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,6,2,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,-1,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,-1,0,0,0,-1,0,0,0,-1,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,2,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

        // .40 amplify, looks good!
        // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,1,0,0,1,0,0,0,-1,0,0,0,-1,0,0,-1,0,0,-1,0,-1,0,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,0,-1,0,-1,0,0,-1,0,0,-1,0,0,0,-1,0,0,0,1,0,0,1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

        // 0.35 amplify ~3x, looks good!
       0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,1,0,0,1,0,0,0,-1,0,0,0,-1,0,0,-1,0,0,-1,0,-1,0,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,-1,0,0,-1,0,-1,0,0,-1,0,0,-1,0,0,0,-1,0,0,0,1,0,0,1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

        // 0.20 amplify ~5x
        // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,0,0,-1,0,-1,0,-1,0,-1,0,-1,-1,0,-1,-1,0,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,0,-1,-1,0,-1,-1,-1,0,-1,0,-1,-1,0,-1,-1,0,-1,0,-1,0,-1,0,-1,0,0,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

        // 0.10 amplify ~10x
        // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,0,-1,-1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1

        // 0.05 amplify ~20x
        // 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};


static void credits_screen_exit_cleanup(void);
static void credits_screen_try_gamestart(void);

static void fx_cylinder_isr_vbl(void);
static void fx_cylinder_isr_lcd(void);
static void fx_cylinder_setup(void);
static void fx_cylinder_cleanup(void);

static void credits_screen_init_gfx_text(void);



// Controls the fades after Credits and then after Tools/Thx
// These numbers are just derived by adjusting them until
// they line up, but probably could be calculated
#define SCROLL_FADE_THRESHOLD_CREDITS 155
#define SCROLL_FADE_THRESHOLD_TOOLS   370

static void fx_cylinder_isr_vbl(void) {
    scroll_counter++;

    // Scroll the background every N frames
    if (scroll_counter == FRAMES_PER_SCROLL_UPDATE_SPEED) {
        scroll_counter = 0u;
        scroll_start_scy++;
        // Trigger the first fade after Credits section
        if ((scroll_start_scy & 0xFF) == SCROLL_FADE_THRESHOLD_CREDITS) {
            fade_start = true;
        }
        else if (scroll_start_scy > SCROLL_FADE_THRESHOLD_TOOLS) {
            // Restart the scrolling instead of waiting until 512 to roll over
            scroll_start_scy = 0;
            fade_start = true;
        }
    }
}


// Note: Not sure why the vram snow went away here, since
//       the timing surely didn't get *that* much better.
//       But I guess I'll take it for now, otherwise may
//       need to rewrite at least the main hblank isr in asm
static void fx_cylinder_isr_lcd(void) {

    uint16_t ly = LY_REG;

    // if (ly < 0) return;
    if (ly == CYLINDER_START) {
        // Set scroll to start of current scroll area
        SCY_BG0_REG = (scroll_start_scy - CYLINDER_HEIGHT_HALF);
    }
    else if ((ly < CYLINDER_START) || (ly > CYLINDER_END)) {
        // Above & Below Cylinder, scroll to empty line (0) with nothing showing
        SCY_BG0_REG = -ly;
    }
    else {
        // Inside Cylinder
        // Apply scroll offset relative to previous line scroll
        // which repeats some BG0 for a variable number of lines
        SCY_BG0_REG += scy_offset_table[ly];
    }
}


static void fx_cylinder_setup(void) {

    scroll_counter = 0u;
    scroll_start_scy = 0;
    fade_start = false;

    // Critical section
    volatile uint32_t status_register_saved = disable_interrupts();

        // Add interrupt handlers and enable them
        // * Expects irq1 VBlank to be enabled, which it is on main startup for OAM DMA copy
        add_vbl(&fx_cylinder_isr_vbl);
        add_irq0(&fx_cylinder_isr_lcd);
        enable_interrupt_irq0_hblank();

    enable_interrupts(status_register_saved);
}


static void fx_cylinder_cleanup(void) {

    // Critical section
    volatile uint32_t status_register_saved = disable_interrupts();

        // Disable and remove interrupt handlers
        disable_interrupt_irq0_hblank();
        remove_irq0(fx_cylinder_isr_lcd);
        remove_vbl(fx_cylinder_isr_vbl);

    enable_interrupts(status_register_saved);
}



static void credits_screen_exit_cleanup(void) {

    palette_fade_start(FADE_TO_BLACK);
    palette_fade_wait_completed();

    fx_cylinder_cleanup();

    // Clear BG0 (where the text is printed) and reset scroll
    fill_bkg_rect(0, 0, DEVICE_SCREEN_BUFFER_WIDTH, DEVICE_SCREEN_BUFFER_HEIGHT, SHARED_4BPP_TRANSP_TILE_ID_START);
    SCY_BG0_REG = 0;
}


static void credits_screen_init_gfx_text(void) {

    PRINT_PAL(PAL_CREDITS);

    #ifdef DEBUG_CREDITS_SHOW_LINENUMS
        for (uint16_t y = 0u; y < (512u / 8u); y += FONT_8x16_TILE_HEIGHT) {
            print_num_u16(2u, y, y, STR_DIGIT_LEN_2);
        }
    #endif

    PRINT_POS((DEVICE_SCREEN_WIDTH - 20u) / 2u, 8u);
    PRINT("CREDITS:\n", TEXT_DELAY);
    PRINT("CODE..........BBBBBR\n", TEXT_DELAY);
    PRINT("GFX...........BBBBBR\n", TEXT_DELAY);
    PRINT("MUSIC............TBD\n", TEXT_DELAY);
    PRINT("FONT......YUKIPIXELS\n", TEXT_DELAY);

    PRINT("\n", TEXT_DELAY);
    PRINT("\n", TEXT_DELAY);
    PRINT("\n", TEXT_DELAY);
    PRINT("\n", TEXT_DELAY);
    PRINT("\n", TEXT_DELAY);

    PRINT("TOOLS THX:\n", TEXT_DELAY);
    PRINT(".......LOOPY MEGADOC\n", TEXT_DELAY);
    PRINT("....LOOPY C TEMPLATE\n", TEXT_DELAY);
    PRINT("........FLOOPY DRIVE\n", TEXT_DELAY);
    PRINT(".WONDERFUL TOOLCHAIN\n", TEXT_DELAY);
    PRINT("............LOOPYMSE\n", TEXT_DELAY);
    PRINT("..............CLOOPY\n", TEXT_DELAY);
    PRINT("...LOOPY MISTER CORE\n", TEXT_DELAY);
}


// Assumes and relies on "intro_screen" (title) having run and initialized
void credits_screen_init(void) {

    fade2pal_init();

    // Rely on Title screen graphics loading for Background image and Font tiles / drawing setup
    load_8x16_font_tiles(TILE_LOAD_OFFSET_FONT_VRAM_ABS, TILE_LOAD_OFFSET_FONT_VRAM_OAM_REL);
    load_8x16_font_tilemap_palettes();
    load_8x16_font_sprite_palettes();

    // First fill entire BG1 tilemap with clear tiles to ensure
    // BG0 to shows through in transparent parts
    fill_bkg_rect(0, 0, DEVICE_SCREEN_BUFFER_WIDTH, DEVICE_SCREEN_BUFFER_HEIGHT, SHARED_4BPP_TRANSP_TILE_ID_START);

    SCY_BG0_REG = 256u;  // scroll print area offscreen during setup

    fx_cylinder_setup();
    // Wait a frame for it to take effect
    vsync();
    credits_screen_init_gfx_text();

    fade2pal_start_next();
    palette_fade_wait_completed();
    // palette_fade_start(FADE_TO_TARGET);
}


void credits_screen_handle(void) {

    if (fade_start) {
        fade_start = false;
        fade2pal_start_next();
        fade2pal_early_wrap_skip_night_pals();
    }

    if (KEY_TICKED(J_ANY)) {
        credits_screen_exit_cleanup();
        game_state = GAME_INTRO_INIT;
    }
}
