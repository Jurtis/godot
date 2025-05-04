/**************************************************************************/
/*  test_style_box_flat.h                                                 */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

// Test cases are not completely functional

#pragma once

#include "scene/resources/style_box_flat.h"

#include "tests/test_macros.h"

namespace TestStyleBoxFlat {

TEST_CASE("[StyleBoxFlat] Constructor") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	CHECK(style_box_flat->get_h_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_STRETCH);
	CHECK(style_box_flat->get_v_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_STRETCH);
	CHECK(style_box_flat->is_draw_center_enabled() == true);

	CHECK(style_box_flat->get_expand_margin(SIDE_LEFT) == 0);
	CHECK(style_box_flat->get_expand_margin(SIDE_TOP) == 0);
	CHECK(style_box_flat->get_expand_margin(SIDE_RIGHT) == 0);
	CHECK(style_box_flat->get_expand_margin(SIDE_BOTTOM) == 0);

	CHECK(style_box_flat->get_modulate() == Color(1, 1, 1, 1));
	CHECK(style_box_flat->get_region_rect() == Rect2(0, 0, 0, 0));
	CHECK(style_box_flat->get_texture() == Ref<Texture2D>());

	CHECK(style_box_flat->get_texture_margin(SIDE_LEFT) == 0);
	CHECK(style_box_flat->get_texture_margin(SIDE_TOP) == 0);
	CHECK(style_box_flat->get_texture_margin(SIDE_RIGHT) == 0);
	CHECK(style_box_flat->get_texture_margin(SIDE_BOTTOM) == 0);
}

TEST_CASE("[StyleBoxFlat] set_texture, get_texture") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);
	Ref<Texture2D> texture = memnew(Texture2D);

	style_box_flat->set_texture(texture);
	CHECK(style_box_flat->get_texture() == texture);
}

TEST_CASE("[StyleBoxFlat] set_texture_margin, set_texture_margin_all, set_texture_margin_individual, get_texture_margin") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	SUBCASE("set_texture_margin, get_texture_margin") {
		style_box_flat->set_texture_margin(SIDE_LEFT, 1);
		style_box_flat->set_texture_margin(SIDE_TOP, 1);
		style_box_flat->set_texture_margin(SIDE_RIGHT, 1);
		style_box_flat->set_texture_margin(SIDE_BOTTOM, 1);

		CHECK(style_box_flat->get_texture_margin(SIDE_LEFT) == 1);
		CHECK(style_box_flat->get_texture_margin(SIDE_TOP) == 1);
		CHECK(style_box_flat->get_texture_margin(SIDE_RIGHT) == 1);
		CHECK(style_box_flat->get_texture_margin(SIDE_BOTTOM) == 1);
	}

	SUBCASE("set_texture_margin_all") {
		style_box_flat->set_texture_margin_all(2);

		CHECK(style_box_flat->get_texture_margin(SIDE_LEFT) == 2);
		CHECK(style_box_flat->get_texture_margin(SIDE_TOP) == 2);
		CHECK(style_box_flat->get_texture_margin(SIDE_RIGHT) == 2);
		CHECK(style_box_flat->get_texture_margin(SIDE_BOTTOM) == 2);
	}

	SUBCASE("set_texture_margin_individual") {
		style_box_flat->set_texture_margin_individual(3, 4, 5, 6);

		CHECK(style_box_flat->get_texture_margin(SIDE_LEFT) == 3);
		CHECK(style_box_flat->get_texture_margin(SIDE_TOP) == 4);
		CHECK(style_box_flat->get_texture_margin(SIDE_RIGHT) == 5);
		CHECK(style_box_flat->get_texture_margin(SIDE_BOTTOM) == 6);
	}
}

TEST_CASE("[StyleBoxFlat] set_expand_margin, set_expand_margin_all, set_expand_margin_individual") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	SUBCASE("set_expand_margin, get_expand_margin") {
		style_box_flat->set_expand_margin(SIDE_LEFT, 1);
		style_box_flat->set_expand_margin(SIDE_TOP, 1);
		style_box_flat->set_expand_margin(SIDE_RIGHT, 1);
		style_box_flat->set_expand_margin(SIDE_BOTTOM, 1);

		CHECK(style_box_flat->get_expand_margin(SIDE_LEFT) == 1);
		CHECK(style_box_flat->get_expand_margin(SIDE_TOP) == 1);
		CHECK(style_box_flat->get_expand_margin(SIDE_RIGHT) == 1);
		CHECK(style_box_flat->get_expand_margin(SIDE_BOTTOM) == 1);
	}

	SUBCASE("set_expand_margin_all") {
		style_box_flat->set_expand_margin_all(2);

		CHECK(style_box_flat->get_expand_margin(SIDE_LEFT) == 2);
		CHECK(style_box_flat->get_expand_margin(SIDE_TOP) == 2);
		CHECK(style_box_flat->get_expand_margin(SIDE_RIGHT) == 2);
		CHECK(style_box_flat->get_expand_margin(SIDE_BOTTOM) == 2);
	}

	SUBCASE("set_expand_margin_individual") {
		style_box_flat->set_expand_margin_individual(3, 4, 5, 6);

		CHECK(style_box_flat->get_expand_margin(SIDE_LEFT) == 3);
		CHECK(style_box_flat->get_expand_margin(SIDE_TOP) == 4);
		CHECK(style_box_flat->get_expand_margin(SIDE_RIGHT) == 5);
		CHECK(style_box_flat->get_expand_margin(SIDE_BOTTOM) == 6);
	}
}

TEST_CASE("[StyleBoxFlat] set_region_rect, get_region_rect") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	style_box_flat->set_region_rect(Rect2(1, 1, 1, 1));
	CHECK(style_box_flat->get_region_rect() == Rect2(1, 1, 1, 1));
}

TEST_CASE("[StyleBoxFlat] set_draw_center, get_draw_center") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	style_box_flat->set_draw_center(false);
	CHECK(style_box_flat->is_draw_center_enabled() == false);
}

TEST_CASE("[StyleBoxFlat] set_h_axis_stretch_mode, set_v_axis_stretch_mode, get_h_axis_stretch_mode, get_v_axis_stretch_mode") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	SUBCASE("set_h_axis_stretch_mode, get_h_axis_stretch_mode") {
		style_box_flat->set_h_axis_stretch_mode(style_box_flat->AXIS_STRETCH_MODE_TILE);
		CHECK(style_box_flat->get_h_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_TILE);

		style_box_flat->set_h_axis_stretch_mode(style_box_flat->AXIS_STRETCH_MODE_TILE_FIT);
		CHECK(style_box_flat->get_h_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_TILE_FIT);

		style_box_flat->set_h_axis_stretch_mode(style_box_flat->AXIS_STRETCH_MODE_STRETCH);
		CHECK(style_box_flat->get_h_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_STRETCH);
	}

	SUBCASE("set_v_axis_stretch_mode, get_v_axis_stretch_mode") {
		style_box_flat->set_v_axis_stretch_mode(style_box_flat->AXIS_STRETCH_MODE_TILE);
		CHECK(style_box_flat->get_v_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_TILE);

		style_box_flat->set_v_axis_stretch_mode(style_box_flat->AXIS_STRETCH_MODE_TILE_FIT);
		CHECK(style_box_flat->get_v_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_TILE_FIT);

		style_box_flat->set_v_axis_stretch_mode(style_box_flat->AXIS_STRETCH_MODE_STRETCH);
		CHECK(style_box_flat->get_v_axis_stretch_mode() == style_box_flat->AXIS_STRETCH_MODE_STRETCH);
	}
}

TEST_CASE("[StyleBoxFlat] set_modulate, get_modulate") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	style_box_flat->set_modulate(Color(0, 0, 0, 0));
	CHECK(style_box_flat->get_modulate() == Color(0, 0, 0, 0));
}

TEST_CASE("[StyleBoxFlat] get_draw_rect") {
	Ref<StyleBoxFlat> style_box_flat = memnew(StyleBoxFlat);

	style_box_flat->set_expand_margin_all(5);
	CHECK(style_box_flat->get_draw_rect(Rect2(0, 0, 1, 1)) == Rect2(-5, -5, 11, 11));
}

}
