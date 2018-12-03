/*
** EPITECH PROJECT, 2018
** yo csfml header
** File description:
** yo csfml header
*/

#include <SFML/Audio/Music.h>

#ifndef YCSFML_H
#define YCSFML_H

struct duck {
    sfSprite *duck;
    sfIntRect duck_rect;
    sfTime duck_anim;
    float duck_seconds;
    sfClock *duck_clock;
    float duck_speed;
    float difficulty;
} duck_t;
struct gun {
    sfSprite *gun_shoot;
    sfIntRect gun_rect;
    sfTime gun_shoot_clock;
    sfClock *gun_clock;
    float gun_seconds;
    sfSprite *heart_hud;
    sfSprite *score_hud;
    sfText *score_text;
    sfSprite *cursor;
} gun_t;
struct game_window {
    sfEvent game_events;
    sfRenderWindow *game_window;
    sfSprite *game_background;
    sfTexture *game_texture;
    sfClock *game_clock;
    sfTime game_time;
    float game_seconds;
    int hp;
    sfFont *duck_hunt_font;
    sfText *lives;
    int score;
    sfMusic *music;
    sfMusic *duck;
    sfMusic *duck_dies;
    sfMusic *headshot;
    sfMusic *shoot;
} gw_t;
struct parameters {
    int background_nb;
    int music_nb;
    int cursor_nb;
    int ducks_missed;
    int ducks_hit;
    int shots;
    int total_points;
    int games_played;
    int musics;
    int backgrounds;
    int cursors;
    int hiscore;
};
void analyse_events(struct game_window* window,struct duck* duck,
                    struct gun *gun, struct parameters *parameters);
void close_window(sfRenderWindow *window);
sfRenderWindow *my_window(char *window_name,
                          unsigned int width,
                          unsigned int height);
void duck_out_of_screen(struct game_window* window, struct duck* duck,
                        struct parameters *parameters);
void move_rect(sfIntRect *rect, int offset, int max_value);
void draw_all(struct game_window *game, struct gun *gun, struct duck *duck);
void hud_draw_two(struct game_window *game_window, struct gun *gun,
                  struct parameters *parameters);
void hud_draw(struct game_window *game_window, struct gun *gun,
              struct parameters *parameters);
void draw_man(struct game_window *game, struct gun *gun, struct duck *duck);
void cursor_handler(struct game_window *game_window, struct gun *gun,
                    struct duck *duck);
void draw_hud(struct game_window *game, struct gun *gun);
void game_start(struct game_window *game_window, struct duck *dk,
                struct gun *gun, struct parameters *parameters);
void game_create(struct game_window *game_window);
void duck_animate_loop(struct game_window *game, struct duck *duck);
void check_score(int *a, int *b, struct game_window *game_window);
struct game_window* clock_manager(struct game_window *game_window,
                                  struct duck *duck, struct gun *gun);
int game_loop(struct game_window *game, struct duck *first_duck,
              struct gun *gun, struct parameters *parameters);
long rando_cond(long min, long max, struct duck *duck);
void game_over(struct game_window *game_window,
               struct parameters *parameters);
int check_params(int argc, char **argv,
                 struct parameters *parameters);
void fetch_stats(struct parameters *parameters);
int my_strcounter(char const *str);
void disp_help(void);
int check_nbrs(struct parameters *parameters, char **argv, int argc);
void choose_music(struct game_window *game_window,
                  struct parameters *parameters);
void choose_bg(struct game_window *game_window,
               struct parameters *parameters);
void choose_cursor(struct game_window *game_window,
                   struct parameters *parameters);
void check_unlocked(struct parameters *parameters);
void rando_sound(struct game_window *game_window);
long randomiser(long min, long max);
void high_score(struct game_window *game_window,
                struct parameters *parameters);
void clean_all(struct game_window *game_window, struct parameters *parameters,
               struct duck *duck, struct gun *gun);
#endif /*YCSFML_H*/
