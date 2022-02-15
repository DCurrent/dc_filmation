#include "data/scripts/dc_spinner/main.c"

#ifndef DC_FILMATION
#define DC_FILMATION

/** Library Name
*
* Used mainly as a base for member IDs. Must
* be unique vs all other libraries. Try to keep
* it short.
**/
#define DC_FILMATION_BASE_ID	"dcmhud"

/*
* Default values.
*/
#define DC_FILMATION_DEFAULT_INSTANCE		0
#define DC_FILMATION_DEFAULT_SINE_VALUE		0.0
#define DC_FILMATION_DEFAULT_SPRITE_LIST	NULL()
#define DC_FILMATION_DEFAULT_POSITION_X		0
#define DC_FILMATION_DEFAULT_POSITION_Y		0



/*
* Array keys.
*/


/* Default member values. */

#define DC_FILMATION_DEFAULT_ANIMATION_INDEX				0
#define DC_FILMATION_DEFAULT_ANIMATION_LIST					NULL()
#define DC_FILMATION_DEFAULT_FRAME_INDEX					0
#define DC_FILMATION_DEFAULT_FRAME_LIST						NULL()

/* Animation frame properties. */
#define DC_FILMATION_FRAME_PROPERTY_DELAY						0
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_COLOR_ADJUST_RED	1
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_COLOR_ADJUST_GREEN	2
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_COLOR_ADJUST_BLUE	3
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_COLOR_RED			4
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_COLOR_GREEN			5
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_COLOR_BLUE			6
#define DC_FILMATION_FRAME_PROPERTY_DM_TINT_MODE				7
#define DC_FILMATION_FRAME_PROPERTY_LOOP						8
#define DC_FILMATION_FRAME_PROPERTY_MARGIN_RIGHT				9
#define DC_FILMATION_FRAME_PROPERTY_POSITION_X					10
#define DC_FILMATION_FRAME_PROPERTY_POSITION_Y					11
#define DC_FILMATION_FRAME_PROPERTY_SPRITE						12
#define DC_FILMATION_FRAME_PROPERTY_THE_END						13




/*
* Member Variable keys.
*/
#define DC_FILMATION_MEMBER_INSTANCE			DC_FILMATION_BASE_ID + 0
#define DC_FILMATION_MEMBER_ANIMATION_INDEX		DC_FILMATION_BASE_ID + 1
#define DC_FILMATION_MEMBER_ANIMATION_LIST		DC_FILMATION_BASE_ID + 2
#define DC_FILMATION_MEMBER_FRAME_INDEX			DC_FILMATION_BASE_ID + 3
#define DC_FILMATION_MEMBER_FRAME_LIST			DC_FILMATION_BASE_ID + 4
#define DC_FILMATION_MEMBER_THE_END				DC_FILMATION_BASE_ID + 5

/** Instance control
*
* Instance control allows us to run more than
* one copy (instance) of a library without the
* instances conflicting with each other.
*
* To avoid repeat code, there is a library
* dedicated specifically to instance control.
* This section overrides local function names
* with instance control library functions to
* simplify use of the the instance control
* library.
**/
#define dc_filmation_get_instance()		dc_instance_get(DC_FILMATION_BASE_ID)
#define dc_filmation_set_instance(value)	dc_instance_set(DC_FILMATION_BASE_ID, value)
#define dc_filmation_reset_instance()		dc_instance_reset(DC_FILMATION_BASE_ID, DC_FILMATION_MEMBER_THE_END)
#define dc_filmation_free_instance()		dc_instance_free(DC_FILMATION_BASE_ID, DC_FILMATION_MEMBER_THE_END)
#define dc_filmation_dump_instance()		dc_instance_dump(DC_FILMATION_BASE_ID, DC_FILMATION_MEMBER_THE_END)
#define dc_filmation_export_instance()		dc_instance_export(DC_FILMATION_BASE_ID, DC_FILMATION_MEMBER_THE_END)
#define dc_filmation_import_instance()		dc_instance_import(DC_FILMATION_BASE_ID, DC_FILMATION_MEMBER_THE_END)
#define dc_filmation_free_export()			dc_instance_free_export(DC_FILMATION_BASE_ID, DC_FILMATION_MEMBER_THE_END)

#endif