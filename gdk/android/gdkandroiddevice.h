/*
 * Copyright (c) 2024 Florian "sp1rit" <sp1rit@disroot.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

#if !defined (__GDKANDROID_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gdk/android/gdkandroid.h> can be included directly."
#endif

#include <gdk/gdk.h>

G_BEGIN_DECLS

typedef struct _GdkAndroidDevice      GdkAndroidDevice;
typedef struct _GdkAndroidDeviceClass GdkAndroidDeviceClass;

#define GDK_TYPE_ANDROID_DEVICE       (gdk_android_device_get_type ())
#define GDK_ANDROID_DEVICE(object)    (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_ANDROID_DEVICE, GdkAndroidDevice))
#define GDK_IS_ANDROID_DEVICE(object) (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_ANDROID_DEVICE))

GDK_AVAILABLE_IN_4_18
GType gdk_android_device_get_type (void);

G_END_DECLS
