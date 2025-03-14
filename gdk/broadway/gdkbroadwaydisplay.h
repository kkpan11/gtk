/* GDK - The GIMP Drawing Kit
 * Copyright (C) 2013 Alexander Larsson
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#if !defined (__GDKBROADWAY_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/broadway/gdkbroadway.h> can be included directly."
#endif

#include <gdk/gdk.h>

G_BEGIN_DECLS

#ifdef GTK_COMPILATION
typedef struct _GdkBroadwayDisplay GdkBroadwayDisplay;
#else
typedef GdkDisplay GdkBroadwayDisplay;
#endif
typedef struct _GdkBroadwayDisplayClass GdkBroadwayDisplayClass;

#define GDK_TYPE_BROADWAY_DISPLAY              (gdk_broadway_display_get_type())
#define GDK_BROADWAY_DISPLAY(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_BROADWAY_DISPLAY, GdkBroadwayDisplay))
#define GDK_BROADWAY_DISPLAY_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_BROADWAY_DISPLAY, GdkBroadwayDisplayClass))
#define GDK_IS_BROADWAY_DISPLAY(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_BROADWAY_DISPLAY))
#define GDK_IS_BROADWAY_DISPLAY_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_BROADWAY_DISPLAY))
#define GDK_BROADWAY_DISPLAY_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_BROADWAY_DISPLAY, GdkBroadwayDisplayClass))

GDK_AVAILABLE_IN_ALL
GType                   gdk_broadway_display_get_type            (void);

GDK_DEPRECATED_IN_4_18
void                    gdk_broadway_display_show_keyboard       (GdkBroadwayDisplay *display);
GDK_DEPRECATED_IN_4_18
void                    gdk_broadway_display_hide_keyboard       (GdkBroadwayDisplay *display);

GDK_DEPRECATED_IN_4_18
int                     gdk_broadway_display_get_surface_scale   (GdkDisplay *display);
GDK_DEPRECATED_IN_4_18
void                    gdk_broadway_display_set_surface_scale   (GdkDisplay *display,
                                                                  int         scale);

G_END_DECLS

