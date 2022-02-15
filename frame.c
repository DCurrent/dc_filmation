#include "data/scripts/dc_filmation/config.h"

/*
* Frame index. Deetermines which frame of animation we
* are working with.
*/

int dc_filmation_get_member_frame_index()
{
	char id;
	void result;

	id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_INDEX;

	result = getlocalvar(id);

	if (typeof(result) != openborconstant("VT_INT"))
	{
		result = DC_FILMATION_FRAME_INDEX;
	}

	return result;
}

int dc_filmation_get_member_frame_index(int value)
{
	char id;

	id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_INDEX;

	if (value == DC_FILMATION_FRAME_INDEX)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Frame list. Pointer to array of frames.
*/

int dc_filmation_get_member_frame_list()
{
	char id;
	void result;

	id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_LIST;

	result = getlocalvar(id);

	if (!is_array(result))
	{
		result = DC_FILMATION_FRAME_LIST;
	}

	return result;
}

int dc_filmation_get_member_frame_list(void value)
{
	char id;

	id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_LIST;

	if (value == DC_FILMATION_FRAME_LIST)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}

/*
* Frame properties. Frame property list is an
* array pointed to by an element in frame list.
*/

int dc_filmation_get_frame_property_list()
{
	char id;
	void result;

	id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_LIST;

	result = getlocalvar(id);

	if (!is_array(result))
	{
		result = DC_FILMATION_FRAME_LIST;
	}

	return result;
}

int dc_filmation_get_frame_property_list(void value)
{
	char id;

	id = dc_filmation_get_instance() + DC_FILMATION_MEMBER_FRAME_LIST;

	if (value == DC_FILMATION_FRAME_LIST)
	{
		value = NULL();
	}

	setlocalvar(id, value);
}


