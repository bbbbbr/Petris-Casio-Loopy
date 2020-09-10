
main()// <void main (void) at src/main.c:158>:
{
    init()// <void init (void) at src/main.c:133>:
    {
        handle_non_cgb()// <void handle_non_cgb () at src/main.c:64>:
        {
            enable_interrupts()
            set_bkg_data()
            PRINT()
        }
        cpu_fast()
        init_link()// <void init_link (void) at src/serial_link.c:123>:
        {
            disable_interrupts()
            add_SIO()
            link_isr()// <void link_isr (void) at src/serial_link.c:179>:
            {
                LINK_SEND()
                link_update_status_icon()// <void link_update_status_icon (void) at src/serial_link.c:422>:
                    {
                        set_bkg_tiles()
                        ARRAY_LEN()
                }
            }
            enable_interrupts()
        }
        init_sound()// <void init_sound (void) at src/main.c:108>:
        init_interrupts()// <void init_interrupts () at src/main.c:114>:
        {
            disable_interrupts()
            add_VBL()
            vbl_update()// <void vbl_update () at src/main.c:83>:
            {
                update_gbt_music()// <void update_gbt_music () at src/sound.c:127>:
                {
                    gbt_update()
                }
                gbt_enable_channels()
            }
            set_interrupts()
            enable_interrupts()
        }
    }
    magic_code_reset()// <void magic_code_reset (void) at src/magic_code.c:27>:
    intro_splash()// <void intro_splash (void) at src/intro_splash.c:67>:
    {
        fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
        set_bkg_data()
        set_bkg_tiles()
        fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
        {
            set_bkg_palette()
            set_sprite_palette()
            delay()
        }
        disable_interrupts()
        add_LCD()
        hblank_effect_isr()// <void hblank_effect_isr () at src/intro_splash.c:37>:
        set_interrupts()
        enable_interrupts()
        wait_vbl_done()
        delay()
    }
    wait_vbl_done()
    UPDATE_KEYS()
    UPDATE_KEY_REPEAT()
    intro_screen_init()// <void intro_screen_init (void) at src/intro_screen.c:162>:
    {
        intro_clouds_init()// <void intro_clouds_init (void) at src/intro_screen.c:97>:
        {
            fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
            set_sprite_data()
            set_sprite_tile()
            set_sprite_prop()
            move_sprite()
        }
        set_bkg_data()
        set_bkg_tiles()
        fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
        PRINT()
        fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
        {
            set_bkg_palette()
            set_sprite_palette()
            delay()
        }
    }
    MusicPlay()// <void MusicPlay (const unsigned char music_compressed[], const unsigned int music_seq_offset[], unsigned char loop) at src/sound.c:81>:
    {
        gbt_stop()
        UNAPACK()
        gbt_play()
        gbt_loop()
    }
    intro_screen_handle()// <void intro_screen_handle (void) at src/intro_screen.c:195>:
    {
        intro_clouds_update()// <void intro_clouds_update (void) at src/intro_screen.c:118>:
        {
            move_sprite()
        }
        magic_code_update()// <void magic_code_update (void) at src/magic_code.c:32>:
        {
            KEY_TICKED()
            ARRAY_LEN()
        }
        PRINT()
    }
    KEY_TICKED()
    fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
    {
        set_bkg_palette()
        set_sprite_palette()
        delay()
    }
    intro_clouds_cleanup()// <void intro_clouds_cleanup (void) at src/intro_screen.c:149>:
    {
        move_sprite()
    }
    options_screen_init()// <void options_screen_init (void) at src/options_screen.c:281>:
    {
        fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
        set_bkg_data()
        options_screen_draw()// <void options_screen_draw (void) at src/options_screen.c:223>:
        {
            set_bkg_tiles()
            PRINT()
        }
        options_screen_setting_draw()// <void options_screen_setting_draw (INT8 option_id) at src/options_screen.c:194>:
        {
            PRINT_PAL()
            PRINT()
            print_text()// <void print_text (const char *txt, unsigned char delay_time) at src/gfx_print.c:92>:
            {
                set_bkg_tiles()
                set_win_tiles()
                UPDATE_KEYS()
                KEY_PRESSED()
                delay()
            }
        }
        options_screen_sprites_init()// <void options_screen_sprites_init (void) at src/options_screen.c:255>:
        {
            fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
            set_sprite_data()
            set_sprite_tile()
            set_sprite_prop()
        }
        options_screen_cursor_update()// <void options_screen_cursor_update (INT8 dir) at src/options_screen.c:130>:
        fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
        {
            set_bkg_palette()
            set_sprite_palette()
            delay()
        }
        MusicUpdateStatus()// <void MusicUpdateStatus () at src/sound.c:115>:
        {
            MusicPlay()// <void MusicPlay (const unsigned char music_compressed[], const unsigned int music_seq_offset[], unsigned char loop) at src/sound.c:81>:
            {
                gbt_stop()
                UNAPACK()
                gbt_play()
                gbt_loop()
            }
            MusicStop()// <void MusicStop (void) at src/sound.c:52>:
            {
                gbt_stop()
            }
        }
        link_start_detect()// <void link_start_detect (void) at src/serial_link.c:169>:
        {
            link_reset()// <void link_reset (void) at src/serial_link.c:135>:
            link_enable()// <void link_enable (void) at src/serial_link.c:149>:
            {
                disable_interrupts()
                set_interrupts()
                enable_interrupts()
            }
        }
    }
    options_screen_handle()// <void options_screen_handle (void) at src/options_screen.c:345>:
    {
        options_screen_exit_cleanup()// <void options_screen_exit_cleanup (void) at src/options_screen.c:272>:
        {
            fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
            {
                set_bkg_palette()
                set_sprite_palette()
                delay()
            }
        }
        link_check_connect()// <void link_check_connect (void) at src/serial_link.c:317>:
        {
            LINK_SEND()
            link_update_status_icon()// <void link_update_status_icon (void) at src/serial_link.c:422>:
            {
                set_bkg_tiles()
                ARRAY_LEN()
            }
        }
        KEY_TICKED()
        options_screen_cursor_update()// <void options_screen_cursor_update (INT8 dir) at src/options_screen.c:130>:
        options_screen_setting_update()// <void options_screen_setting_update (INT8 dir) at src/options_screen.c:154>:
        {
            options_screen_setting_draw()// <void options_screen_setting_draw (INT8 option_id) at src/options_screen.c:194>:
            {
                PRINT_PAL()
                PRINT()
                print_text()// <void print_text (const char *txt, unsigned char delay_time) at src/gfx_print.c:92>:
                {
                    set_bkg_tiles()
                    set_win_tiles()
                    UPDATE_KEYS()
                    KEY_PRESSED()
                    delay()
                }
            }
            MusicUpdateStatus()// <void MusicUpdateStatus () at src/sound.c:115>:
            {
                MusicPlay()// <void MusicPlay (const unsigned char music_compressed[], const unsigned int music_seq_offset[], unsigned char loop) at src/sound.c:81>:
                {
                    gbt_stop()
                    UNAPACK()
                    gbt_play()
                    gbt_loop()
                }
                MusicStop()// <void MusicStop (void) at src/sound.c:52>:
                {
                    gbt_stop()
                }
            }
        }
        options_screen_try_gamestart()// <void options_screen_try_gamestart (void) at src/options_screen.c:320>:
        {
            link_try_gamestart()// <void link_try_gamestart (void) at src/serial_link.c:345>:
            {
                status_win_popup_init()// <void status_win_popup_init (void) at src/status_win.c:51>:
                {
                    set_win_tiles()
                }
                status_win_popup_show()// <void status_win_popup_show (UINT8 y_min) at src/status_win.c:81>:
                {
                    delay()
                }
                SET_PRINT_TARGET()
                PRINT()
                LINK_SEND()
                UPDATE_KEYS()
                KEY_TICKED()
                wait_vbl_done()
                waitpadticked_lowcpu()// <void waitpadticked_lowcpu (UINT8 button_mask, volatile UINT8 *loop_control) at src/input.c:14>:
                {
                    wait_vbl_done()
                    UPDATE_KEYS()
                    KEY_TICKED()
                }
                status_win_popup_hide()// <void status_win_popup_hide (void) at src/status_win.c:95>:
                {
                    delay()
                }
            }
            link_disable()// <void link_disable (void) at src/serial_link.c:159>:
            {
                disable_interrupts()
                set_interrupts()
                enable_interrupts()
                link_reset()// <void link_reset (void) at src/serial_link.c:135>:
            }
            options_screen_exit_cleanup()// <void options_screen_exit_cleanup (void) at src/options_screen.c:272>:
            {
                fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
                {
                    set_bkg_palette()
                    set_sprite_palette()
                    delay()
                }
            }
        }
        move_sprite()
    }
    gameplay_init()// <void gameplay_init (void) at src/gameplay.c:163>:
    {
        fade2pal_init()// <void fade2pal_init (void) at src/fade2pal.c:46>:
        random_init()// <void random_init (void) at src/gameplay.c:140>:
        {
            initrand()
            swaprand()
        }
        game_types_init()// <void game_types_init (void) at src/game_types.c:39>:
        board_init()// <void board_init (void) at src/game_board.c:83>:
        board_gfx_init()// <void board_gfx_init (void) at src/game_board_gfx.c:77>:
        {
            pet_tiles_prepare()// <void pet_tiles_prepare () at src/gfx.c:129>:
            board_gfx_init_pettiles()// <void board_gfx_init_pettiles (void) at src/game_board_gfx.c:103>:
            {
                fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
                set_bkg_palette()
                set_bkg_data()
                set_sprite_palette()
                set_sprite_data()
            }
            board_gfx_init_background()// <void board_gfx_init_background (void) at src/game_board_gfx.c:145>:
            {
                fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
                set_bkg_data()
                set_bkg_tiles()
                PRINT()
                options_difficulty_abbrev_text_get()// <const char *options_difficulty_abbrev_text_get (void) at src/options.c:51>:
                link_update_status_icon()// <void link_update_status_icon (void) at src/serial_link.c:422>:
                {
                    set_bkg_tiles()
                    ARRAY_LEN()
                }
            }
            board_gfx_init_sprites()// <void board_gfx_init_sprites (void) at src/game_board_gfx.c:132>:
            {
                fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
                set_sprite_data()
            }
            gameover_message_reset()// <void gameover_message_reset (void) at src/gameover_message.c:142>:
            {
                move_sprite()
                set_sprite_prop()
            }
            fade_start()// <void fade_start (INT8 fade_dir) at src/fade.c:57>:
            {
                set_bkg_palette()
                set_sprite_palette()
                delay()
            }
        }
        hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
        {
            move_sprite()
            set_sprite_tile()
            set_sprite_prop()
        }
        stats_maxpet_reset()// <void stats_maxpet_reset (void) at src/game_stats.c:59>:
        options_player_settings_apply()// <void options_player_settings_apply (void) at src/options.c:99>:
        player_info_newgame_reset()// <void player_info_newgame_reset (void) at src/player_info.c:215>:
        {
            score_reset()// <void score_reset (void) at src/player_info.c:169>:
            level_counters_reset()// <void level_counters_reset (void) at src/player_info.c:206>:
            gameplay_drop_speed_update()// <void gameplay_drop_speed_update (void) at src/gameplay.c:70>:
            {
                options_frames_per_drop_get()// <UINT8 options_frames_per_drop_get (UINT8 level) at src/options.c:57>:
                {
                    ARRAY_LEN()
                }
            }
            game_type_long_pet_set_pet_size()// <void game_type_long_pet_set_pet_size (UINT8 player_level) at src/game_types.c:159>:
            {
                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                {
                    set_bkg_tiles()
                }
            }
            level_show()// <void level_show (void) at src/player_info.c:199>:
            {
                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                {
                    set_bkg_tiles()
                }
            }
            player_info_display()// <void player_info_display (void) at src/player_info.c:48>:
            {
                PRINT()
                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                {
                    set_bkg_tiles()
                }
            }
        }
        board_flash_message()// <void board_flash_message (UINT8 start_x, UINT8 start_y, char *text, char *ctext, UINT8 repeat) at src/game_board.c:252>:
        {
            board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
            {
                set_bkg_tiles()
                delay()
            }
            PRINT()
            delay()
        }
        gameplay_prepare_board()// <void gameplay_prepare_board (void) at src/gameplay.c:227>:
        {
            board_reset()// <void board_reset (void) at src/game_board.c:235>:
            {
                board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                {
                    set_bkg_tiles()
                }
            }
            swaprand()
            game_board_fill_random_tails()// <void game_board_fill_random_tails (UINT8 piece_count, INT8 board_min_y, UINT8 add_mode) at src/game_board.c:422>:
            {
                rand()
                board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
                {
                    game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                    {
                        print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                        {
                            set_bkg_tiles()
                        }
                    }
                    board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                    {
                        set_bkg_tiles()
                    }
                }
                player_piece_connect_get()// <UINT8 player_piece_connect_get (UINT8 piece, UINT8 rotate) at src/player_piece.c:111>:
                delay()
            }
            game_type_pet_cleanup_get_tail_count()// <UINT8 game_type_pet_cleanup_get_tail_count (void) at src/game_types.c:107>:
            delay()
            game_type_long_pet_set_pet_size()// <void game_type_long_pet_set_pet_size (UINT8 player_level) at src/game_types.c:159>:
            {
                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                {
                    set_bkg_tiles()
                }
            }
            game_piece_next_reset()// <void game_piece_next_reset (void) at src/game_piece.c:33>:
            game_piece_next_generate()// <void game_piece_next_generate (void) at src/game_piece.c:49>:
            {
                rand()
                game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
            }
            player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
            {
                move_sprite()
            }
            game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
            {
                set_sprite_tile()
                set_sprite_prop()
                move_sprite()
            }
        }
        magic_code_reset()// <void magic_code_reset (void) at src/magic_code.c:27>:
    }
    MusicUpdateStatus()// <void MusicUpdateStatus () at src/sound.c:115>:
    {
        MusicPlay()// <void MusicPlay (const unsigned char music_compressed[], const unsigned int music_seq_offset[], unsigned char loop) at src/sound.c:81>:
        {
            gbt_stop()
            UNAPACK()
            gbt_play()
            gbt_loop()
        }
        MusicStop()// <void MusicStop (void) at src/sound.c:52>:
        {
            gbt_stop()
        }
    }
    gameplay_update()// <void gameplay_update (void) at src/gameplay.c:432>:
    {
        player_piece_try_reload()// <UINT8 player_piece_try_reload (void) at src/player_piece.c:61>:
        {
            board_check_open_xy()// <UINT8 board_check_open_xy (INT8 x, INT8 y) at src/game_board.c:305>:
            game_piece_next_get()// <UINT8 game_piece_next_get (void) at src/game_piece.c:114>:
            game_piece_next_generate()// <void game_piece_next_generate (void) at src/game_piece.c:49>:
            {
                rand()
                game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
            }
            game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
            {
                set_sprite_tile()
                set_sprite_prop()
                move_sprite()
            }
            player_piece_update_gfx()// <void player_piece_update_gfx () at src/player_piece.c:212>:
            {
                set_sprite_tile()
                set_sprite_prop()
            }
            player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
            {
                move_sprite()
            }
            player_hinting_special_update_gfx()// <void player_hinting_special_update_gfx () at src/player_hinting.c:137>:
            {
                set_sprite_prop()
            }
            player_hinting_special_move()// <void player_hinting_special_move (void) at src/player_hinting.c:115>:
            {
                move_sprite()
            }
            player_hinting_special_show()// <void player_hinting_special_show (UINT8 do_show) at src/player_hinting.c:87>:
            {
                set_sprite_tile()
            }
            player_hinting_drop_show()// <void player_hinting_drop_show (UINT8 do_show) at src/player_hinting.c:167>:
            {
                set_sprite_tile()
                set_sprite_prop()
            }
            player_hinting_drop_update()// <void player_hinting_drop_update (void) at src/player_hinting.c:185>:
            {
                board_find_lowest_open_in_column()// <INT8 board_find_lowest_open_in_column (INT8 x, INT8 y_st) at src/game_board.c:278>:
                move_sprite()
                player_hinting_drop_show()// <void player_hinting_drop_show (UINT8 do_show) at src/player_hinting.c:167>:
                {
                    set_sprite_tile()
                    set_sprite_prop()
                }
            }
        }
        gameplay_handle_input()// <void gameplay_handle_input (void) at src/gameplay.c:328>:
        {
            KEY_PRESSED()
            player_piece_move()// <UINT8 player_piece_move (INT8 dir_x, INT8 dir_y) at src/player_piece.c:178>:
            {
                board_check_open_xy()// <UINT8 board_check_open_xy (INT8 x, INT8 y) at src/game_board.c:305>:
                player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                {
                    move_sprite()
                }
                player_hinting_special_move()// <void player_hinting_special_move (void) at src/player_hinting.c:115>:
                {
                    move_sprite()
                }
                player_hinting_drop_update()// <void player_hinting_drop_update (void) at src/player_hinting.c:185>:
                {
                    board_find_lowest_open_in_column()// <INT8 board_find_lowest_open_in_column (INT8 x, INT8 y_st) at src/game_board.c:278>:
                    move_sprite()
                    player_hinting_drop_show()// <void player_hinting_drop_show (UINT8 do_show) at src/player_hinting.c:167>:
                    {
                        set_sprite_tile()
                        set_sprite_prop()
                    }
                }
            }
            RESET_KEY_REPEAT()
            KEY_TICKED()
            player_piece_rotate_apply()// <void player_piece_rotate_apply (UINT8 dir) at src/player_piece.c:153>:
            {
                player_piece_update_gfx()// <void player_piece_update_gfx () at src/player_piece.c:212>:
                {
                    set_sprite_tile()
                    set_sprite_prop()
                }
            }
            board_gfx_change_pettiles()// <void board_gfx_change_pettiles (void) at src/game_board_gfx.c:91>:
            {
                pet_tiles_prepare()// <void pet_tiles_prepare () at src/gfx.c:129>:
                board_gfx_init_pettiles()// <void board_gfx_init_pettiles (void) at src/game_board_gfx.c:103>:
                {
                    fade_set_pal()// <void fade_set_pal (UINT8 start_pal, UINT8 num_pal, UWORD *p_SrcPal, UINT8 which_pal) at src/fade.c:32>:
                    set_bkg_palette()
                    set_bkg_data()
                    set_sprite_palette()
                    set_sprite_data()
                }
            }
            player_piece_cycle_pet_types()// <void player_piece_cycle_pet_types (void) at src/player_piece.c:245>:
            {
                player_piece_update_gfx()// <void player_piece_update_gfx () at src/player_piece.c:212>:
                {
                    set_sprite_tile()
                    set_sprite_prop()
                }
            }
            LINK_SEND()
            gameplay_handle_pause()// <void gameplay_handle_pause (void) at src/gameplay.c:272>:
            {
                gbt_pause()
                game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
                {
                    set_sprite_tile()
                    set_sprite_prop()
                    move_sprite()
                }
                player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                {
                    move_sprite()
                }
                player_hinting_special_show()// <void player_hinting_special_show (UINT8 do_show) at src/player_hinting.c:87>:
                {
                    set_sprite_tile()
                }
                player_hinting_drop_show()// <void player_hinting_drop_show (UINT8 do_show) at src/player_hinting.c:167>:
                {
                    set_sprite_tile()
                    set_sprite_prop()
                }
                PRINT()
                waitpadticked_lowcpu()// <void waitpadticked_lowcpu (UINT8 button_mask, volatile UINT8 *loop_control) at src/input.c:14>:
                {
                    wait_vbl_done()
                    UPDATE_KEYS()
                    KEY_TICKED()
                }
                LINK_SEND()
                board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                {
                    set_bkg_tiles()
                }
            }
            hinting_petlength_turn_on()// <void hinting_petlength_turn_on (void) at src/player_hinting.c:264>:
            {
                hinting_petlength_showhide()// <void hinting_petlength_showhide (void) at src/player_hinting.c:356>:
                {
                    set_sprite_tile()
                }
            }
        }
        gameplay_gravity_update()// <void gameplay_gravity_update (void) at src/gameplay.c:506>:
        {
            player_piece_move()// <UINT8 player_piece_move (INT8 dir_x, INT8 dir_y) at src/player_piece.c:178>:
            {
                board_check_open_xy()// <UINT8 board_check_open_xy (INT8 x, INT8 y) at src/game_board.c:305>:
                player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                {
                    move_sprite()
                }
                player_hinting_special_move()// <void player_hinting_special_move (void) at src/player_hinting.c:115>:
                {
                    move_sprite()
                }
                player_hinting_drop_update()// <void player_hinting_drop_update (void) at src/player_hinting.c:185>:
                {
                    board_find_lowest_open_in_column()// <INT8 board_find_lowest_open_in_column (INT8 x, INT8 y_st) at src/game_board.c:278>:
                    move_sprite()
                    player_hinting_drop_show()// <void player_hinting_drop_show (UINT8 do_show) at src/player_hinting.c:167>:
                    {
                        set_sprite_tile()
                        set_sprite_prop()
                    }
                }
            }
        }
        player_hinting_flicker_update()// <void player_hinting_flicker_update () at src/player_hinting.c:65>:
        {
            player_hinting_special_show()// <void player_hinting_special_show (UINT8 do_show) at src/player_hinting.c:87>:
            {
                set_sprite_tile()
            }
        }
        player_piece_set_on_board()// <void player_piece_set_on_board (void) at src/player_piece.c:127>:
        {
            player_piece_connect_get()// <UINT8 player_piece_connect_get (UINT8 piece, UINT8 rotate) at src/player_piece.c:111>:
            player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
            {
                move_sprite()
            }
            board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
            {
                game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                {
                    print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                    {
                        set_bkg_tiles()
                    }
                }
                board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                {
                    set_bkg_tiles()
                }
            }
            board_handle_new_piece()// <void board_handle_new_piece (INT8 x, INT8 y, UINT8 piece, UINT8 connect) at src/game_board.c:391>:
            {
                board_handle_special_bomb()// <void board_handle_special_bomb (INT8 x, INT8 y) at src/game_board_special_pieces.c:32>:
                {
                    ARRAY_LEN()
                    board_piece_get_xy()// <UINT8 board_piece_get_xy (INT8 x, INT8 y, UINT8 *p_piece, UINT8 *p_connect) at src/game_board.c:492>:
                    board_check_completed_pet_xy()// <void board_check_completed_pet_xy (INT8 start_x, INT8 start_y, UINT8 piece, UINT8 connect, UINT8 flags) at src/game_board.c:611>:
                    {
                        hinting_petlength_remove()// <void hinting_petlength_remove (INT8 board_x, INT8 board_y) at src/player_hinting.c:401>:
                        {
                            set_sprite_tile()
                            move_sprite()
                        }
                        board_check_connected_xy()// <UINT8 board_check_connected_xy (INT8 x, INT8 y, UINT8 piece, UINT8 *p_this_connect, UINT8 flags) at src/game_board.c:512>:
                        {
                            board_piece_get_xy()// <UINT8 board_piece_get_xy (INT8 x, INT8 y, UINT8 *p_piece, UINT8 *p_connect) at src/game_board.c:492>:
                        }
                        board_handle_pet_completed()// <void board_handle_pet_completed (UINT8 flags) at src/game_board.c:540>:
                        {
                            stats_maxpet_copy_iflongest()// <void stats_maxpet_copy_iflongest (void) at src/game_stats.c:67>:
                            board_clear_tile_xy()// <void board_clear_tile_xy (INT8 x, INT8 y) at src/game_board.c:312>:
                            {
                                ARRAY_LEN()
                                board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                                {
                                    set_bkg_tiles()
                                }
                                delay()
                                game_type_pet_cleanup_decrement_tail_count()// <void game_type_pet_cleanup_decrement_tail_count (void) at src/game_types.c:140>:
                            }
                            score_update()// <void score_update (UINT16 num_tiles) at src/player_info.c:87>:
                            {
                                game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
                                player_info_display()// <void player_info_display (void) at src/player_info.c:48>:
                                {
                                    PRINT()
                                    print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                    {
                                        set_bkg_tiles()
                                    }
                                }
                                LINK_SEND()
                                level_increment()// <void level_increment (void) at src/player_info.c:176>:
                                {
                                    gameplay_drop_speed_update()// <void gameplay_drop_speed_update (void) at src/gameplay.c:70>:
                                    {
                                        options_frames_per_drop_get()// <UINT8 options_frames_per_drop_get (UINT8 level) at src/options.c:57>:
                                        {
                                            ARRAY_LEN()
                                        }
                                    }
                                    game_types_handle_level_transition()// <void game_types_handle_level_transition (void) at src/game_types.c:46>:
                                    {
                                        level_show()// <void level_show (void) at src/player_info.c:199>:
                                        {
                                            print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                            {
                                                set_bkg_tiles()
                                            }
                                        }
                                        fade2pal_start_next()// <void fade2pal_start_next (void) at src/fade2pal.c:53>:
                                        {
                                            fade2pal_prep_fade()// <void fade2pal_prep_fade (UINT8 *p_dest_pal_gbr) at src/fade2pal.c:88>:
                                            {
                                                fade2pal_calc_entry()// <void fade2pal_calc_entry (UINT8 color_from, UINT8 color_to, UINT8 c) at src/fade2pal.c:129>:
                                            }
                                            wait_vbl_done()
                                            fade2pal_update_entry()// <void fade2pal_update_entry (void) at src/fade2pal.c:154>:
                                            {
                                                set_bkg_palette()
                                            }
                                        }
                                        hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
                                        {
                                            move_sprite()
                                            set_sprite_tile()
                                            set_sprite_prop()
                                        }
                                        board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                                        {
                                            set_bkg_tiles()
                                            delay()
                                        }
                                        PRINT()
                                        board_flash_message()// <void board_flash_message (UINT8 start_x, UINT8 start_y, char *text, char *ctext, UINT8 repeat) at src/game_board.c:252>:
                                        {
                                            board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                                            {
                                                set_bkg_tiles()
                                                delay()
                                            }
                                            PRINT()
                                            delay()
                                        }
                                        gameplay_prepare_board()// <void gameplay_prepare_board (void) at src/gameplay.c:227>:
                                        {
                                            board_reset()// <void board_reset (void) at src/game_board.c:235>:
                                            {
                                                board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                                                {
                                                    set_bkg_tiles()
                                                }
                                            }
                                            swaprand()
                                            game_board_fill_random_tails()// <void game_board_fill_random_tails (UINT8 piece_count, INT8 board_min_y, UINT8 add_mode) at src/game_board.c:422>:
                                            {
                                                rand()
                                                board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
                                                {
                                                    game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                                                    {
                                                        print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                                        {
                                                            set_bkg_tiles()
                                                        }
                                                    }
                                                    board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                                                    {
                                                        set_bkg_tiles()
                                                    }
                                                }
                                                player_piece_connect_get()// <UINT8 player_piece_connect_get (UINT8 piece, UINT8 rotate) at src/player_piece.c:111>:
                                                delay()
                                            }
                                            game_type_pet_cleanup_get_tail_count()// <UINT8 game_type_pet_cleanup_get_tail_count (void) at src/game_types.c:107>:
                                            delay()
                                            game_type_long_pet_set_pet_size()// <void game_type_long_pet_set_pet_size (UINT8 player_level) at src/game_types.c:159>:
                                            {
                                                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                                {
                                                    set_bkg_tiles()
                                                }
                                            }
                                            game_piece_next_reset()// <void game_piece_next_reset (void) at src/game_piece.c:33>:
                                            game_piece_next_generate()// <void game_piece_next_generate (void) at src/game_piece.c:49>:
                                            {
                                                rand()
                                                game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
                                            }
                                            player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                                            {
                                                move_sprite()
                                            }
                                            game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
                                            {
                                                set_sprite_tile()
                                                set_sprite_prop()
                                                move_sprite()
                                            }
                                        }
                                    }
                                    print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                    {
                                        set_bkg_tiles()
                                    }
                                }
                            }
                            LINK_SEND()
                            game_type_long_pet_check_size()// <void game_type_long_pet_check_size (UINT8 tile_count) at src/game_types.c:175>:
                        }
                        hinting_petlength_add()// <void hinting_petlength_add (INT8 board_x, INT8 board_y, UINT8 length, UINT8 piece) at src/player_hinting.c:275>:
                        {
                            set_sprite_prop()
                            move_sprite()
                            set_sprite_tile()
                        }
                    }
                    board_clear_tile_xy()// <void board_clear_tile_xy (INT8 x, INT8 y) at src/game_board.c:312>:
                    {
                        ARRAY_LEN()
                        board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                        {
                            set_bkg_tiles()
                        }
                        delay()
                        game_type_pet_cleanup_decrement_tail_count()// <void game_type_pet_cleanup_decrement_tail_count (void) at src/game_types.c:140>:
                    }
                }
                board_handle_pet_completed()// <void board_handle_pet_completed (UINT8 flags) at src/game_board.c:540>:
                {
                    stats_maxpet_copy_iflongest()// <void stats_maxpet_copy_iflongest (void) at src/game_stats.c:67>:
                    board_clear_tile_xy()// <void board_clear_tile_xy (INT8 x, INT8 y) at src/game_board.c:312>:
                    {
                        ARRAY_LEN()
                        board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                        {
                            set_bkg_tiles()
                        }
                        delay()
                        game_type_pet_cleanup_decrement_tail_count()// <void game_type_pet_cleanup_decrement_tail_count (void) at src/game_types.c:140>:
                    }
                    score_update()// <void score_update (UINT16 num_tiles) at src/player_info.c:87>:
                    {
                        game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
                        player_info_display()// <void player_info_display (void) at src/player_info.c:48>:
                        {
                            PRINT()
                            print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                            {
                                set_bkg_tiles()
                            }
                        }
                        LINK_SEND()
                        level_increment()// <void level_increment (void) at src/player_info.c:176>:
                        {
                            gameplay_drop_speed_update()// <void gameplay_drop_speed_update (void) at src/gameplay.c:70>:
                            {
                                options_frames_per_drop_get()// <UINT8 options_frames_per_drop_get (UINT8 level) at src/options.c:57>:
                                {
                                    ARRAY_LEN()
                                }
                            }
                            game_types_handle_level_transition()// <void game_types_handle_level_transition (void) at src/game_types.c:46>:
                            {
                                level_show()// <void level_show (void) at src/player_info.c:199>:
                                {
                                    print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                    {
                                        set_bkg_tiles()
                                    }
                                }
                                fade2pal_start_next()// <void fade2pal_start_next (void) at src/fade2pal.c:53>:
                                {
                                    fade2pal_prep_fade()// <void fade2pal_prep_fade (UINT8 *p_dest_pal_gbr) at src/fade2pal.c:88>:
                                    {
                                        fade2pal_calc_entry()// <void fade2pal_calc_entry (UINT8 color_from, UINT8 color_to, UINT8 c) at src/fade2pal.c:129>:
                                    }
                                    wait_vbl_done()
                                    fade2pal_update_entry()// <void fade2pal_update_entry (void) at src/fade2pal.c:154>:
                                    {
                                        set_bkg_palette()
                                    }
                                }
                                hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
                                {
                                    move_sprite()
                                    set_sprite_tile()
                                    set_sprite_prop()
                                }
                                board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                                {
                                    set_bkg_tiles()
                                    delay()
                                }
                                PRINT()
                                board_flash_message()// <void board_flash_message (UINT8 start_x, UINT8 start_y, char *text, char *ctext, UINT8 repeat) at src/game_board.c:252>:
                                {
                                    board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                                    {
                                        set_bkg_tiles()
                                        delay()
                                    }
                                    PRINT()
                                    delay()
                                }
                                gameplay_prepare_board()// <void gameplay_prepare_board (void) at src/gameplay.c:227>:
                                {
                                    board_reset()// <void board_reset (void) at src/game_board.c:235>:
                                    {
                                        board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                                        {
                                            set_bkg_tiles()
                                        }
                                    }
                                    swaprand()
                                    game_board_fill_random_tails()// <void game_board_fill_random_tails (UINT8 piece_count, INT8 board_min_y, UINT8 add_mode) at src/game_board.c:422>:
                                    {
                                        rand()
                                        board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
                                        {
                                            game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                                            {
                                                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                                {
                                                    set_bkg_tiles()
                                                }
                                            }
                                            board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                                            {
                                                set_bkg_tiles()
                                            }
                                        }
                                        player_piece_connect_get()// <UINT8 player_piece_connect_get (UINT8 piece, UINT8 rotate) at src/player_piece.c:111>:
                                        delay()
                                    }
                                    game_type_pet_cleanup_get_tail_count()// <UINT8 game_type_pet_cleanup_get_tail_count (void) at src/game_types.c:107>:
                                    delay()
                                    game_type_long_pet_set_pet_size()// <void game_type_long_pet_set_pet_size (UINT8 player_level) at src/game_types.c:159>:
                                    {
                                        print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                        {
                                            set_bkg_tiles()
                                        }
                                    }
                                    game_piece_next_reset()// <void game_piece_next_reset (void) at src/game_piece.c:33>:
                                    game_piece_next_generate()// <void game_piece_next_generate (void) at src/game_piece.c:49>:
                                    {
                                        rand()
                                        game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
                                    }
                                    player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                                    {
                                        move_sprite()
                                    }
                                    game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
                                    {
                                        set_sprite_tile()
                                        set_sprite_prop()
                                        move_sprite()
                                    }
                                }
                            }
                            print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                            {
                                set_bkg_tiles()
                            }
                        }
                    }
                    LINK_SEND()
                    game_type_long_pet_check_size()// <void game_type_long_pet_check_size (UINT8 tile_count) at src/game_types.c:175>:
                }
                board_check_completed_pet_xy()// <void board_check_completed_pet_xy (INT8 start_x, INT8 start_y, UINT8 piece, UINT8 connect, UINT8 flags) at src/game_board.c:611>:
                {
                    hinting_petlength_remove()// <void hinting_petlength_remove (INT8 board_x, INT8 board_y) at src/player_hinting.c:401>:
                    {
                        set_sprite_tile()
                        move_sprite()
                    }
                    board_check_connected_xy()// <UINT8 board_check_connected_xy (INT8 x, INT8 y, UINT8 piece, UINT8 *p_this_connect, UINT8 flags) at src/game_board.c:512>:
                    {
                        board_piece_get_xy()// <UINT8 board_piece_get_xy (INT8 x, INT8 y, UINT8 *p_piece, UINT8 *p_connect) at src/game_board.c:492>:
                    }
                    board_handle_pet_completed()// <void board_handle_pet_completed (UINT8 flags) at src/game_board.c:540>:
                    {
                        stats_maxpet_copy_iflongest()// <void stats_maxpet_copy_iflongest (void) at src/game_stats.c:67>:
                        board_clear_tile_xy()// <void board_clear_tile_xy (INT8 x, INT8 y) at src/game_board.c:312>:
                        {
                            ARRAY_LEN()
                            board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                            {
                                set_bkg_tiles()
                            }
                            delay()
                            game_type_pet_cleanup_decrement_tail_count()// <void game_type_pet_cleanup_decrement_tail_count (void) at src/game_types.c:140>:
                        }
                        score_update()// <void score_update (UINT16 num_tiles) at src/player_info.c:87>:
                        {
                            game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
                            player_info_display()// <void player_info_display (void) at src/player_info.c:48>:
                            {
                                PRINT()
                                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                {
                                    set_bkg_tiles()
                                }
                            }
                            LINK_SEND()
                            level_increment()// <void level_increment (void) at src/player_info.c:176>:
                            {
                                gameplay_drop_speed_update()// <void gameplay_drop_speed_update (void) at src/gameplay.c:70>:
                                {
                                    options_frames_per_drop_get()// <UINT8 options_frames_per_drop_get (UINT8 level) at src/options.c:57>:
                                    {
                                        ARRAY_LEN()
                                    }
                                }
                                game_types_handle_level_transition()// <void game_types_handle_level_transition (void) at src/game_types.c:46>:
                                {
                                    level_show()// <void level_show (void) at src/player_info.c:199>:
                                    {
                                        print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                        {
                                            set_bkg_tiles()
                                        }
                                    }
                                    fade2pal_start_next()// <void fade2pal_start_next (void) at src/fade2pal.c:53>:
                                    {
                                        fade2pal_prep_fade()// <void fade2pal_prep_fade (UINT8 *p_dest_pal_gbr) at src/fade2pal.c:88>:
                                        {
                                            fade2pal_calc_entry()// <void fade2pal_calc_entry (UINT8 color_from, UINT8 color_to, UINT8 c) at src/fade2pal.c:129>:
                                        }
                                        wait_vbl_done()
                                        fade2pal_update_entry()// <void fade2pal_update_entry (void) at src/fade2pal.c:154>:
                                        {
                                            set_bkg_palette()
                                        }
                                    }
                                    hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
                                    {
                                        move_sprite()
                                        set_sprite_tile()
                                        set_sprite_prop()
                                    }
                                    board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                                    {
                                        set_bkg_tiles()
                                        delay()
                                    }
                                    PRINT()
                                    board_flash_message()// <void board_flash_message (UINT8 start_x, UINT8 start_y, char *text, char *ctext, UINT8 repeat) at src/game_board.c:252>:
                                    {
                                        board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                                        {
                                            set_bkg_tiles()
                                            delay()
                                        }
                                        PRINT()
                                        delay()
                                    }
                                    gameplay_prepare_board()// <void gameplay_prepare_board (void) at src/gameplay.c:227>:
                                    {
                                        board_reset()// <void board_reset (void) at src/game_board.c:235>:
                                        {
                                            board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                                            {
                                                set_bkg_tiles()
                                            }
                                        }
                                        swaprand()
                                        game_board_fill_random_tails()// <void game_board_fill_random_tails (UINT8 piece_count, INT8 board_min_y, UINT8 add_mode) at src/game_board.c:422>:
                                        {
                                            rand()
                                            board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
                                            {
                                                game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                                                {
                                                    print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                                    {
                                                        set_bkg_tiles()
                                                    }
                                                }
                                                board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                                                {
                                                    set_bkg_tiles()
                                                }
                                            }
                                            player_piece_connect_get()// <UINT8 player_piece_connect_get (UINT8 piece, UINT8 rotate) at src/player_piece.c:111>:
                                            delay()
                                        }
                                        game_type_pet_cleanup_get_tail_count()// <UINT8 game_type_pet_cleanup_get_tail_count (void) at src/game_types.c:107>:
                                        delay()
                                        game_type_long_pet_set_pet_size()// <void game_type_long_pet_set_pet_size (UINT8 player_level) at src/game_types.c:159>:
                                        {
                                            print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                            {
                                                set_bkg_tiles()
                                            }
                                        }
                                        game_piece_next_reset()// <void game_piece_next_reset (void) at src/game_piece.c:33>:
                                        game_piece_next_generate()// <void game_piece_next_generate (void) at src/game_piece.c:49>:
                                        {
                                            rand()
                                            game_piece_next_set()// <void game_piece_next_set (UINT8 override_piece) at src/game_piece.c:120>:
                                        }
                                        player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                                        {
                                            move_sprite()
                                        }
                                        game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
                                        {
                                            set_sprite_tile()
                                            set_sprite_prop()
                                            move_sprite()
                                        }
                                    }
                                }
                                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                                {
                                    set_bkg_tiles()
                                }
                            }
                        }
                        LINK_SEND()
                        game_type_long_pet_check_size()// <void game_type_long_pet_check_size (UINT8 tile_count) at src/game_types.c:175>:
                    }
                    hinting_petlength_add()// <void hinting_petlength_add (INT8 board_x, INT8 board_y, UINT8 length, UINT8 piece) at src/player_hinting.c:275>:
                    {
                        set_sprite_prop()
                        move_sprite()
                        set_sprite_tile()
                    }
                }
            }
        }
        board_gfx_tail_animate()// <void board_gfx_tail_animate (void) at src/game_board_gfx.c:208>:
        {
            set_bkg_data()
        }
        hinting_petlength_showhide()// <void hinting_petlength_showhide (void) at src/player_hinting.c:356>:
        {
            set_sprite_tile()
        }
        gameplay_crunchup_update()// <void gameplay_crunchup_update (void) at src/gameplay.c:532>:
        {
            swaprand()
            board_crunch_up()// <void board_crunch_up (void) at src/game_board.c:152>:
            {
                board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                {
                    set_bkg_tiles()
                }
                player_piece_move()// <UINT8 player_piece_move (INT8 dir_x, INT8 dir_y) at src/player_piece.c:178>:
                {
                    board_check_open_xy()// <UINT8 board_check_open_xy (INT8 x, INT8 y) at src/game_board.c:305>:
                    player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
                    {
                        move_sprite()
                    }
                    player_hinting_special_move()// <void player_hinting_special_move (void) at src/player_hinting.c:115>:
                    {
                        move_sprite()
                    }
                    player_hinting_drop_update()// <void player_hinting_drop_update (void) at src/player_hinting.c:185>:
                    {
                        board_find_lowest_open_in_column()// <INT8 board_find_lowest_open_in_column (INT8 x, INT8 y_st) at src/game_board.c:278>:
                        move_sprite()
                        player_hinting_drop_show()// <void player_hinting_drop_show (UINT8 do_show) at src/player_hinting.c:167>:
                        {
                            set_sprite_tile()
                            set_sprite_prop()
                        }
                    }
                }
                game_board_fill_random_tails()// <void game_board_fill_random_tails (UINT8 piece_count, INT8 board_min_y, UINT8 add_mode) at src/game_board.c:422>:
                {
                    rand()
                    board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
                    {
                        game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                        {
                            print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                            {
                                set_bkg_tiles()
                            }
                        }
                        board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                        {
                            set_bkg_tiles()
                        }
                    }
                    player_piece_connect_get()// <UINT8 player_piece_connect_get (UINT8 piece, UINT8 rotate) at src/player_piece.c:111>:
                    delay()
                }
            }
            hinting_petlength_scrollup()// <void hinting_petlength_scrollup (void) at src/player_hinting.c:445>:
            {
                scroll_sprite()
            }
            hinting_petlength_refreshxy()// <void hinting_petlength_refreshxy (void) at src/player_hinting.c:470>:
            {
                move_sprite()
            }
        }
    }
    GAMEOVER_MESSAGE_SET()
    LINK_SEND()
    gameplay_handle_gameover_screen()// <void gameplay_handle_gameover_screen (void) at src/gameplay.c:102>:
    {
        MusicStop()// <void MusicStop (void) at src/sound.c:52>:
        {
            gbt_stop()
        }
        GAMEOVER_MESSAGE_CHK()
        gameplay_ended_cleanup()// <void gameplay_ended_cleanup (void) at src/gameplay.c:91>:
        {
            player_piece_update_xy()// <void player_piece_update_xy (UINT8 do_show) at src/player_piece.c:45>:
            {
                move_sprite()
            }
            game_piece_next_show()// <void game_piece_next_show (UINT8 do_show) at src/game_piece.c:133>:
            {
                set_sprite_tile()
                set_sprite_prop()
                move_sprite()
            }
            player_hinting_drop_reset()// <void player_hinting_drop_reset (void) at src/player_hinting.c:161>:
            {
                move_sprite()
            }
            player_hinting_special_reset()// <void player_hinting_special_reset (void) at src/player_hinting.c:76>:
            {
                move_sprite()
            }
            hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
            {
                move_sprite()
                set_sprite_tile()
                set_sprite_prop()
            }
        }
        gameover_message_animate()// <void gameover_message_animate (void) at src/gameover_message.c:93>:
        {
            set_sprite_tile()
            wait_vbl_done()
            move_sprite()
        }
        link_reset()// <void link_reset (void) at src/serial_link.c:135>:
        waitpadticked_lowcpu()// <void waitpadticked_lowcpu (UINT8 button_mask, volatile UINT8 *loop_control) at src/input.c:14>:
        {
            wait_vbl_done()
            UPDATE_KEYS()
            KEY_TICKED()
        }
        gameover_message_reset()// <void gameover_message_reset (void) at src/gameover_message.c:142>:
        {
            move_sprite()
            set_sprite_prop()
        }
        stats_display()// <void stats_display (void) at src/game_stats.c:139>:
        {
            stats_maxpet_draw()// <void stats_maxpet_draw (void) at src/game_stats.c:97>:
            {
                board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
                {
                    set_bkg_tiles()
                    delay()
                }
                board_reset()// <void board_reset (void) at src/game_board.c:235>:
                {
                    board_redraw_all()// <void board_redraw_all (void) at src/game_board.c:127>:
                    {
                        set_bkg_tiles()
                    }
                }
                PRINT()
                board_set_tile_xy()// <void board_set_tile_xy (INT8 x, INT8 y, UINT8 piece, UINT8 attrib, UINT8 connect) at src/game_board.c:363>:
                {
                    game_type_pet_cleanup_increment_tail_count()// <void game_type_pet_cleanup_increment_tail_count (void) at src/game_types.c:124>:
                    {
                        print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                        {
                            set_bkg_tiles()
                        }
                    }
                    board_draw_tile_xy()// <void board_draw_tile_xy (INT8 x, INT8 y, UINT8 tile_index) at src/game_board.c:219>:
                    {
                        set_bkg_tiles()
                    }
                }
                delay()
                hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
                {
                    move_sprite()
                    set_sprite_tile()
                    set_sprite_prop()
                }
                hinting_petlength_add()// <void hinting_petlength_add (INT8 board_x, INT8 board_y, UINT8 length, UINT8 piece) at src/player_hinting.c:275>:
                {
                    set_sprite_prop()
                    move_sprite()
                    set_sprite_tile()
                }
                hinting_petlength_turn_on()// <void hinting_petlength_turn_on (void) at src/player_hinting.c:264>:
                {
                    hinting_petlength_showhide()// <void hinting_petlength_showhide (void) at src/player_hinting.c:356>:
                    {
                        set_sprite_tile()
                    }
                }
                hinting_petlength_showhide()// <void hinting_petlength_showhide (void) at src/player_hinting.c:356>:
                {
                    set_sprite_tile()
                }
            }
            waitpadticked_lowcpu()// <void waitpadticked_lowcpu (UINT8 button_mask, volatile UINT8 *loop_control) at src/input.c:14>:
            {
                wait_vbl_done()
                UPDATE_KEYS()
                KEY_TICKED()
            }
            hinting_petlength_reset()// <void hinting_petlength_reset (void) at src/player_hinting.c:215>:
            {
                move_sprite()
                set_sprite_tile()
                set_sprite_prop()
            }
            board_hide_all()// <void board_hide_all (UINT16 delay_amount) at src/game_board.c:90>:
            {
                set_bkg_tiles()
                delay()
            }
            stats_show_var()// <void stats_show_var (UINT8 x, UINT8 y, const char *text, UINT16 value) at src/game_stats.c:174>:
            {
                PRINT()
                print_num_u16()// <void print_num_u16 (UINT8 x, UINT8 y, UINT16 num, UINT8 print_digits) at src/gfx_print.c:43>:
                {
                    set_bkg_tiles()
                }
                UPDATE_KEYS()
                KEY_PRESSED()
                delay()
            }
        }
    }
}
