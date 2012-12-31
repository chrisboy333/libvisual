/* Libvisual - The audio visualisation framework cli tool
 *
 * Copyright (C) 2012      Libvisual team
 *               2004-2006 Dennis Smit
 *
 * Authors: Daniel Hiepler <daniel@niftylight.de>
 *          Chong Kai Xiong <kaixiong@codeleft.sg>
 *          Dennis Smit <ds@nerds-incorporated.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


#ifndef _LV_TOOL_DISPLAY_HPP
#define _LV_TOOL_DISPLAY_HPP

#include <libvisual/libvisual.h>
#include <memory>
#include <string>

class DisplayDriver;

class Display {
public:

    explicit Display (std::string const& driver_name);

    Display (Display const&) = delete;

    ~Display ();

    Display& operator= (Display const&) = delete;

    LV::VideoPtr create (VisVideoDepth depth,
                         VisVideoAttrOptions const* vidoptions,
                         unsigned int width,
                         unsigned int height,
                         bool resizable = true);

    void close ();

    void lock ();

    void unlock ();

    void update_all ();

    void update_rect (LV::Rect const& rect);

    LV::VideoPtr get_video () const;

    void set_title(std::string const& title);

    void set_fullscreen (bool fullscreen, bool autoscale);

    void drain_events (VisEventQueue& eventqueue);

private:

    class Impl;
    const std::unique_ptr<Impl> m_impl;
};

#endif // _LV_TOOL_DISPLAY_HPP
