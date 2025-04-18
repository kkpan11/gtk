#pragma once

#include "gskgpuopprivate.h"

G_BEGIN_DECLS

void                    gsk_gpu_download_op                             (GskGpuFrame                    *frame,
                                                                         GskGpuImage                    *image,
                                                                         GdkColorState                  *color_state,
                                                                         GdkTexture                    **out_texture);
void                    gsk_gpu_download_into_op                        (GskGpuFrame                    *frame,
                                                                         GskGpuImage                    *image,
                                                                         GdkColorState                  *image_color_state,
                                                                         guchar                         *data,
                                                                         const GdkMemoryLayout          *layout,
                                                                         GdkColorState                  *color_state);

G_END_DECLS

