/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
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

/*
 * Modified by the GTK+ Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/. 
 */

#pragma once

#if !defined (__GDKX_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/x11/gdkx.h> can be included directly."
#endif

#include <gdk/gdk.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

G_BEGIN_DECLS

GDK_DEPRECATED_IN_4_18
int      gdk_x11_display_text_property_to_text_list (GdkDisplay   *display,
                                                     const char   *encoding,
                                                     int           format,
                                                     const guchar *text,
                                                     int           length,
                                                     char       ***list);
GDK_DEPRECATED_IN_4_18
void     gdk_x11_free_text_list                     (char        **list);
GDK_DEPRECATED_IN_4_18
int      gdk_x11_display_string_to_compound_text    (GdkDisplay   *display,
                                                     const char   *str,
                                                     const char  **encoding,
                                                     int          *format,
                                                     guchar      **ctext,
                                                     int          *length);
GDK_DEPRECATED_IN_4_18
gboolean gdk_x11_display_utf8_to_compound_text      (GdkDisplay   *display,
                                                     const char   *str,
                                                     const char  **encoding,
                                                     int          *format,
                                                     guchar      **ctext,
                                                     int          *length);
GDK_DEPRECATED_IN_4_18
void     gdk_x11_free_compound_text                 (guchar       *ctext);

G_END_DECLS

