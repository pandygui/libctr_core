/*******************************************************************************
 * Copyright (C) 2016, 2017 Gabriel Marcano
 *
 * Refer to the COPYING.txt file at the top of the project directory. If that is
 * missing, this file is licensed under the GPL version 2.0 or later.
 *
 ******************************************************************************/

/** @file */

#ifndef CTR_CORE_WINDOW_H_
#define CTR_CORE_WINDOW_H_

#include <ctr_core/ctr_core_screen.h>
#include <ctr_core/ctr_core_surface.h>

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**	@brief Represents a single window within the screen.
 */
typedef struct ctr_core_window ctr_core_window;

/**	@brief Creates a new window object.
 *
 *	@param[in] parent Parent screen, to hold the window.
 *	@param[in] x X position in parent of the window.
 *	@param[in] y Y position in parent of the window.
 *	@param[in] width Width of the window in pixels.
 *	@param[in] height Height of the window in pixels.
 *
 *	@returns A new window object.
 */
ctr_core_window *ctr_core_window_initialize(ctr_core_screen *parent, size_t x, size_t y, size_t width, size_t height);

/**	@brief Destroys the given window object.
 *
 *	@param[in] window Window object to destroy.
 *
 *	@post Resources held by window object are freed. Any further use will lead
 *		to undefined behavior.
 */
void ctr_core_window_destroy(ctr_core_window *window);

#ifdef __cplusplus
}

namespace ctr_core
{
	template<class Parent, std::size_t Width, std::size_t Height>
	class window
	{
	public:
		typedef typename Parent::pixel_type pixel_type;

		window(Parent& parent, size_t x, size_t y);
		constexpr size_t width() const;
		constexpr size_t height() const;
		pixel_type& operator()(size_t x, size_t y);
		const pixel_type& operator()(size_t x, size_t y) const;
		Parent& get_parent();
		const Parent& get_parent() const;
		void clear(const pixel_type& pixel);
	private:
		Parent& parent_;
		size_t x_;
		size_t y_;
	};

	class generic_window : public generic_surface
	{
	public:
		generic_window(generic_surface& parent, size_t width, size_t height, size_t x, size_t y);
		virtual size_t width() const override;
		virtual size_t height() const override;
		virtual generic_pixel operator()(size_t x, size_t y) override;
		virtual const generic_pixel operator()(size_t x, size_t y) const override;
		virtual generic_surface& get_screen() override;
		virtual const generic_surface& get_screen() const override;
		virtual void clear(const pixel_type& pixel) override;
		pixel_format get_pixel_format() const;
		size_t pixel_size() const;

	public:
		generic_surface& parent_;
		size_t width_;
		size_t height_;
		size_t x_;
		size_t y_;
	};
}
#endif

#endif//CTR_CORE_WINDOW_H_

