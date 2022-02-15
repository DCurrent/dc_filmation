#include "data/scripts/dc_filmation/config.h"

void test_animation()
{
    /*
    * Animation set up.
    *
    * animation_list[{key}] -> animation[{index}] ->animation_poperties[index]
    *   frame_list[index] -> frame_properties[index]
    *
    */

    void segment_frame_sprite = dc_filmation_sprite_list_get("enemy_hp_segment_0");

    void animation_list = array(0);
    void animation_properties = array(0);
    char animation_id = "test";

    /* Prepare an aniamtion. */
    set(animation_list, animation_id, animation_properties);

    /* Prepare a frame list. */

    void frame_list = array(0);

    set(animation_properties, DC_HUD_ANIMATION_PROPERTY_FRAMES, frame_list);

    /* Prepare a frame. */

    void frame_properties = array(0);
    int frame = 0;

    set(frame_list, frame, frame_properties);

    /* Populate frame properties. */

    set(frame_properties, DC_HUD_FRAME_PROPERTY_MARGIN_RIGHT, 1);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_SPRITE, segment_frame_sprite);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_COLOR_RED, DC_MODULE_HUD_RGB_HP_BLOCK_BLUE_R);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_COLOR_GREEN, DC_MODULE_HUD_RGB_HP_BLOCK_BLUE_G);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_COLOR_BLUE, DC_MODULE_HUD_RGB_HP_BLOCK_BLUE_B);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_COLOR_ADJUST_RED, DC_MODULE_HUD_RGB_HP_BLOCK_ADJUST_RANGE);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_COLOR_ADJUST_GREEN, DC_MODULE_HUD_RGB_HP_BLOCK_ADJUST_RANGE);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_COLOR_ADJUST_BLUE, DC_MODULE_HUD_RGB_HP_BLOCK_ADJUST_RANGE);
    set(frame_properties, DC_HUD_FRAME_PROPERTY_DM_TINT_MODE, openborconstant("BLEND_MODE_ALPHA"));

    log("\n\n DC_HUD_FRAME_PROPERTY_MARGIN_RIGHT: " + get(get(get(get(animation_list, animation_id), DC_HUD_ANIMATION_PROPERTY_FRAMES), frame), DC_HUD_FRAME_PROPERTY_MARGIN_RIGHT) + "\n");
}