#include <pebble.h>

static Window *s_main_window;
static Layer *s_root_layer;
static GBitmap *s_bitmaps[1];
static const uint32_t s_bitmap_res_ids[1] = { RESOURCE_ID_UNTITLED_DESIGN_3 };




static GColor color_hex(uint32_t hex) {
  return GColorFromRGB((hex >> 16) & 0xFF, (hex >> 8) & 0xFF, hex & 0xFF);
}

static GFont font_for(const char *family, int size, bool bold) {
  if (strcmp(family, "MedodicaRegular") == 0 && size == 14 && bold == false) return fonts_get_system_font(FONT_KEY_GOTHIC_14);
  if (strcmp(family, "BoldPixels") == 0 && size == 14 && bold == true) return fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD);
  if (strcmp(family, "MedodicaRegular") == 0 && size == 18 && bold == false) return fonts_get_system_font(FONT_KEY_GOTHIC_18);
  if (strcmp(family, "BoldPixels") == 0 && size == 18 && bold == true) return fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  if (strcmp(family, "MedodicaRegular") == 0 && size == 24 && bold == false) return fonts_get_system_font(FONT_KEY_GOTHIC_24);
  if (strcmp(family, "BoldPixels") == 0 && size == 24 && bold == true) return fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD);
  if (strcmp(family, "MedodicaRegular") == 0 && size == 28 && bold == false) return fonts_get_system_font(FONT_KEY_GOTHIC_28);
  if (strcmp(family, "BoldPixels") == 0 && size == 28 && bold == true) return fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  if (strcmp(family, "Gotham Black") == 0 && size == 30 && bold == false) return fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK);
  if (strcmp(family, "Gotham Medium") == 0 && size == 34 && bold == false) return fonts_get_system_font(FONT_KEY_BITHAM_34_MEDIUM_NUMBERS);
  if (strcmp(family, "Gotham Bold") == 0 && size == 42 && bold == true) return fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD);
  if (strcmp(family, "Gotham Light") == 0 && size == 42 && bold == false) return fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);
  if (strcmp(family, "Gotham Medium") == 0 && size == 42 && bold == false) return fonts_get_system_font(FONT_KEY_BITHAM_42_MEDIUM_NUMBERS);
  if (strcmp(family, "Roboto Condensed") == 0 && size == 21 && bold == false) return fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);
  if (strcmp(family, "Roboto Bold") == 0 && size == 49 && bold == true) return fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49);
  if (strcmp(family, "Droid Serif Bold") == 0 && size == 28 && bold == true) return fonts_get_system_font(FONT_KEY_DROID_SERIF_28_BOLD);
  if (strcmp(family, "LECO 1976") == 0 && size == 20 && bold == true) return fonts_get_system_font(FONT_KEY_LECO_20_BOLD_NUMBERS);
  if (strcmp(family, "LECO 1976") == 0 && size == 26 && bold == true) return fonts_get_system_font(FONT_KEY_LECO_26_BOLD_NUMBERS_AM_PM);
  if (strcmp(family, "LECO 1976") == 0 && size == 28 && bold == false) return fonts_get_system_font(FONT_KEY_LECO_28_LIGHT_NUMBERS);
  if (strcmp(family, "LECO 1976") == 0 && size == 32 && bold == true) return fonts_get_system_font(FONT_KEY_LECO_32_BOLD_NUMBERS);
  if (strcmp(family, "LECO 1976") == 0 && size == 36 && bold == true) return fonts_get_system_font(FONT_KEY_LECO_36_BOLD_NUMBERS);
  if (strcmp(family, "LECO 1976") == 0 && size == 38 && bold == true) return fonts_get_system_font(FONT_KEY_LECO_38_BOLD_NUMBERS);
  if (strcmp(family, "LECO 1976") == 0 && size == 42 && bold == false) return fonts_get_system_font(FONT_KEY_LECO_42_NUMBERS);
  return fonts_get_system_font(FONT_KEY_GOTHIC_14);
}

static int32_t deg_to_trig(int32_t degrees) {
  int32_t d = degrees % 360;
  if (d < 0) d += 360;
  return (TRIG_MAX_ANGLE * d) / 360;
}

#define DESIGN_WIDTH 200
#define DESIGN_HEIGHT 228

static int map_axis(int position, int size, int source_size, int target_size) {
  return (((position * 2 + size) * target_size) / (source_size * 2)) - (size / 2);
}

static int map_x(int x, int width, GRect bounds) {
  return map_axis(x, width, DESIGN_WIDTH, bounds.size.w);
}

static int map_y(int y, int height, GRect bounds) {
  return map_axis(y, height, DESIGN_HEIGHT, bounds.size.h);
}

static GRect mapped_rect(int x, int y, int width, int height, GRect bounds) {
  return GRect(map_x(x, width, bounds), map_y(y, height, bounds), width, height);
}


static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  layer_mark_dirty(s_root_layer);
}

static const char *s_time_fmt_0 = "%H:%M:00:24";

static void layer_update_proc(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);
  graphics_context_set_fill_color(ctx, color_hex(0x000000));
  graphics_fill_rect(ctx, bounds, 0, GCornerNone);

  // Untitled design-3
  if (s_bitmaps[0]) {
    graphics_draw_bitmap_in_rect(ctx, s_bitmaps[0], mapped_rect(0, 0, 200, 228, bounds));
  }

  // Time 1
  {
    char time_buffer_0[32];
    time_t now_0 = time(NULL);
    struct tm *tick_0 = localtime(&now_0);
    strftime(time_buffer_0, sizeof(time_buffer_0), s_time_fmt_0, tick_0);
    graphics_context_set_text_color(ctx, color_hex(0xffffff));
    graphics_draw_text(ctx, time_buffer_0, font_for("BoldPixels", 28, true),
                       mapped_rect(25, 96, 150, 36, bounds), GTextOverflowModeFill, GTextAlignmentCenter, NULL);
  }
}

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  for (int i = 0; i < 1; i++) {
    s_bitmaps[i] = gbitmap_create_with_resource(s_bitmap_res_ids[i]);
  }




  s_root_layer = layer_create(bounds);
  layer_set_update_proc(s_root_layer, layer_update_proc);
  layer_add_child(window_layer, s_root_layer);
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

static void main_window_unload(Window *window) {
  tick_timer_service_unsubscribe();
  for (int i = 0; i < 1; i++) {
    if (s_bitmaps[i]) {
      gbitmap_destroy(s_bitmaps[i]);
      s_bitmaps[i] = NULL;
    }
  }

  layer_destroy(s_root_layer);


}

static void init(void) {
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers){
                                           .load = main_window_load,
                                           .unload = main_window_unload,
                                       });
  window_stack_push(s_main_window, true);
}

static void deinit(void) {
  window_destroy(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
