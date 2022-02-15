# DC Filmation

Animation in OpenBOR without models or entities. Primarily for HUD, cut scenes, or other single use items.

# Name Origin 

Named in honor of Filmation, a studio responsible for the production of various memerable animated series (Star Trek, He-Man, etc.) from the 1962 through 1993.

# Structure

Animation data is contained in a multi-dimensional array which for purposes of population and design we can divide into two parts: Animation, and frame. Both animation and frames consist of list arrays where each element is a list of properties for the animation or frame respectivly. In the case of animations, one of the properties (DC_FILMATION_ANIMATION_PROPERTY_FRAMES) contains a pointer to the list of frames for that animation, creating the four dimensional array.

`frame_property_value = animation[Animation ID][Animation Property ID][Frame Index][Frame property ID]`

Animation List[`Animation ID`]
- Animation Properties[`DC_FILMATION_ANIMATION_PROPERTY_FRAMES`]
- ...

Frame List[`Frame`]
- Frame Properties[`DC_FILMATION_FRAME_PROPERTY_DELAY`] 
- Frame Properties[`DC_FILMATION_FRAME_PROPERTY_SPRITE`]
- ... 

