#include "data/scripts/dc_filmation/config.h"

/*
* Animation list. Pointer to array of animations.
*/

void dc_module_filmation_get_member_animation_list()
{
    char id;
    void result;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_ANIMATION_LIST;

    result = getlocalvar(id);

    if (!is_array(result))
    {
        result = DC_FILMATION_DEFAULT_ANIMATION_LIST;
    }

    return result;
}

void dc_module_filmation_set_member_animation_list(void value)
{
    char id;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_ANIMATION_LIST;

    if (value == DC_FILMATION_DEAFULT_ANIMATION_LIST)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

/*
* Animation ID. The element (aniamtion) in 
* animation list we are working with.
*/

int dc_filmation_get_member_animation_index()
{
    char id;
    void result;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_ANIMATION_INDEX;

    result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_FILMATION_DEFAULT_ANIMATION_INDEX;
    }

    return result;
}

int dc_filmation_set_member_animation_index(void value)
{
    char id;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_ANIMATION_INDEX;

    if (value == DC_FILMATION_DEFAULT_ANIMATION_INDEX)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

/*
* Frame list. Pointer to array of frames.
* 
* Note frame list is normally an animation
* property.
*/

void dc_module_filmation_get_member_frame_list()
{
    char id;
    void result;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_LIST;

    result = getlocalvar(id);

    if (!is_array(result))
    {
        result = DC_FILMATION_DEFAULT_FRAME_LIST;
    }

    return result;
}

void dc_module_filmation_set_member_frame_list(void value)
{
    char id;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_LIST;

    if (value == DC_FILMATION_DEFAULT_FRAME_LIST)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

/*
* Frame ID. The element (frame) in
* a frame list we are working with.
*/

int dc_filmation_get_member_frame_index()
{
    char id;
    void result;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_INDEX;

    result = getlocalvar(id);

    if (typeof(result) != openborconstant("VT_INTEGER"))
    {
        result = DC_FILMATION_DEFAULT_FRAME_INDEX;
    }

    return result;
}

int dc_filmation_set_member_frame_index(void value)
{
    char id;

    id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_INDEX;

    if (value == DC_FILMATION_DEFAULT_FRAME_INDEX)
    {
        value = NULL();
    }

    setlocalvar(id, value);
}

/*
* Caskey, Damon V.
* 2022-02-14
*
* Get and return pointer to current animation
* list, creating one if it does not exist.
*/
void dc_filmation_animation_list_getsert()
{
    void animation_list = dc_filmation_get_member_animation_list();

    /*
    * Verify animation list. Initialize
    * array if we don't have one and
    * update animation list member.
    */

    if (!animation_list)
    {
        animation_list = array(0);

        dc_filmation_set_member_animation_list(animation_list);
    }

    return animation_list;
}

/*
* Caskey, Damon V.
* 2022-02-14
*
* Get and return pointer to current animation
* list, creating one if it does not exist.
*/
void dc_filmation_animation_getsert()
{
    void animation_list = dc_filmation_animation_list_getsert();
    int animation_index = dc_filmation_get_member_animation_index();

    void animation_properties = get(animation_list, animation_index);
    
    /*
    * Every animation element is an array
    * of animation properties, so if this
    * is blank, there's no animation of
    * this index. Create new animation
    * property array and use it to
    * populate animation element.
    */

    animation_properties = get(animation_list, animation_index);

    if (!animation_properties)
    {
        animation_properties = array(0);
        set(animation_list, animation_index, animation_properties);
    }

    return animation_properties;
}


void dc_filmation_frame_upsert()
{
    int animation_index = dc_filmation_get_member_animation_index();
    void animation_list = dc_filmation_get_member_animation_list();
    void animation_properties = NULL();

    /*
    * Verify animation list. Initialize
    * array if we don't have one and
    * updat eanimation list member.
    */

    if (!animation_list)
    {
        animation_list = array(0);

        dc_filmation_set_member_animation_list(animation_list);
    }

    /*
    * Every animation element is an array
    * of animation properties, so if this
    * is blank, there's no animation of
    * this index. Create new animation
    * property array and use it to
    * populate animation element.
    */

    animation_properties = get(animation_list, animation_index);

    if (!animation_properties)
    {
        animation_properties = array(0);
        set(animation_list, animation_index, animation_properties);
    }
}

void dc_filmation_placeholder()
{
    /*
    * Animation set up.
    *
    * animation_list[{key}] -> animation[{index}] ->animation_poperties[index]
    *   frame_list[index] -> frame_properties[index]
    *
    */

    void segment_frame_sprite = NULL();

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