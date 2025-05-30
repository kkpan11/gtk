#pragma once

#include <gdk/gdk.h>
#include "gsk/gskenums.h"

#include "gdk/gdkmemoryformatprivate.h"

typedef struct _GskGpuBuffer            GskGpuBuffer;
typedef struct _GskGpuCache             GskGpuCache;
typedef struct _GskGpuCachePrivate      GskGpuCachePrivate;
typedef struct _GskGpuClip              GskGpuClip;
typedef guint32                         GskGpuColorStates;
typedef struct _GskGpuDevice            GskGpuDevice;
typedef struct _GskGpuFrame             GskGpuFrame;
typedef struct _GskGpuGlobalsInstance   GskGpuGlobalsInstance;
typedef struct _GskGpuImage             GskGpuImage;
typedef struct _GskGpuOp                GskGpuOp;
typedef struct _GskGpuOpClass           GskGpuOpClass;
typedef guint32                         GskGpuShaderFlags;
typedef struct _GskGpuShaderImage       GskGpuShaderImage;
typedef struct _GskGpuShaderOp          GskGpuShaderOp;
typedef struct _GskGpuShaderOpClass     GskGpuShaderOpClass;
typedef struct _GskVulkanSemaphores     GskVulkanSemaphores;

#define GSK_GPU_SHADER_OP_SHIFT 4
#define GSK_GPU_SHADER_OP_MASK ((1 << GSK_GPU_SHADER_OP_SHIFT) - 1)

typedef enum {
  GSK_GPU_IMAGE_EXTERNAL       = (1 << 0),
  GSK_GPU_IMAGE_TOGGLE_REF     = (1 << 1),
  GSK_GPU_IMAGE_BLIT           = (1 << 2),
  GSK_GPU_IMAGE_CAN_MIPMAP     = (1 << 3),
  GSK_GPU_IMAGE_MIPMAP         = (1 << 4),
  GSK_GPU_IMAGE_FILTERABLE     = (1 << 5),
  GSK_GPU_IMAGE_RENDERABLE     = (1 << 6),
  GSK_GPU_IMAGE_DOWNLOADABLE   = (1 << 7),
} GskGpuImageFlags;

typedef enum {
  GSK_GPU_CONVERSION_NONE,
  GSK_GPU_CONVERSION_SRGB,
  GSK_GPU_CONVERSION_BT601,
  GSK_GPU_CONVERSION_BT601_NARROW,
  GSK_GPU_CONVERSION_BT709,
  GSK_GPU_CONVERSION_BT709_NARROW,
  GSK_GPU_CONVERSION_BT2020,
  GSK_GPU_CONVERSION_BT2020_NARROW,
} GskGpuConversion;

typedef enum {
  GSK_GPU_SAMPLER_DEFAULT,
  GSK_GPU_SAMPLER_TRANSPARENT,
  GSK_GPU_SAMPLER_REPEAT,
  GSK_GPU_SAMPLER_NEAREST,
  GSK_GPU_SAMPLER_MIPMAP_DEFAULT,
  /* add more */
  GSK_GPU_SAMPLER_N_SAMPLERS
} GskGpuSampler;

typedef enum {
  GSK_GPU_SHADER_CLIP_NONE,
  GSK_GPU_SHADER_CLIP_RECT,
  GSK_GPU_SHADER_CLIP_ROUNDED
} GskGpuShaderClip;
#define GSK_GPU_SHADER_CLIP_SHIFT 2
#define GSK_GPU_SHADER_CLIP_MASK ((1 << GSK_GPU_SHADER_CLIP_SHIFT) - 1)

typedef enum {
  GSK_GPU_BLEND_NONE,
  GSK_GPU_BLEND_OVER,
  GSK_GPU_BLEND_ADD,
  GSK_GPU_BLEND_CLEAR
} GskGpuBlend;

/* We only need this for the final VkImageLayout, but don't tell anyone */
typedef enum
{
  GSK_RENDER_PASS_OFFSCREEN,
  GSK_RENDER_PASS_PRESENT,
  GSK_RENDER_PASS_EXPORT
} GskRenderPassType;

typedef enum
{
  GSK_GPU_LOAD_OP_LOAD,
  GSK_GPU_LOAD_OP_CLEAR,
  GSK_GPU_LOAD_OP_DONT_CARE
} GskGpuLoadOp;

typedef enum {
  GSK_GPU_PATTERN_DONE,
  GSK_GPU_PATTERN_COLOR,
  GSK_GPU_PATTERN_OPACITY,
  GSK_GPU_PATTERN_TEXTURE,
  GSK_GPU_PATTERN_STRAIGHT_ALPHA,
  GSK_GPU_PATTERN_COLOR_MATRIX,
  GSK_GPU_PATTERN_GLYPHS,
  GSK_GPU_PATTERN_LINEAR_GRADIENT,
  GSK_GPU_PATTERN_REPEATING_LINEAR_GRADIENT,
  GSK_GPU_PATTERN_RADIAL_GRADIENT,
  GSK_GPU_PATTERN_REPEATING_RADIAL_GRADIENT,
  GSK_GPU_PATTERN_CONIC_GRADIENT,
  GSK_GPU_PATTERN_CLIP,
  GSK_GPU_PATTERN_ROUNDED_CLIP,
  GSK_GPU_PATTERN_REPEAT_PUSH,
  GSK_GPU_PATTERN_POSITION_POP,
  GSK_GPU_PATTERN_PUSH_COLOR,
  GSK_GPU_PATTERN_POP_CROSS_FADE,
  GSK_GPU_PATTERN_POP_MASK_ALPHA,
  GSK_GPU_PATTERN_POP_MASK_INVERTED_ALPHA,
  GSK_GPU_PATTERN_POP_MASK_LUMINANCE,
  GSK_GPU_PATTERN_POP_MASK_INVERTED_LUMINANCE,
  GSK_GPU_PATTERN_AFFINE,
  GSK_GPU_PATTERN_BLEND_DEFAULT,
  GSK_GPU_PATTERN_BLEND_MULTIPLY,
  GSK_GPU_PATTERN_BLEND_SCREEN,
  GSK_GPU_PATTERN_BLEND_OVERLAY,
  GSK_GPU_PATTERN_BLEND_DARKEN,
  GSK_GPU_PATTERN_BLEND_LIGHTEN,
  GSK_GPU_PATTERN_BLEND_COLOR_DODGE,
  GSK_GPU_PATTERN_BLEND_COLOR_BURN,
  GSK_GPU_PATTERN_BLEND_HARD_LIGHT,
  GSK_GPU_PATTERN_BLEND_SOFT_LIGHT,
  GSK_GPU_PATTERN_BLEND_DIFFERENCE,
  GSK_GPU_PATTERN_BLEND_EXCLUSION,
  GSK_GPU_PATTERN_BLEND_COLOR,
  GSK_GPU_PATTERN_BLEND_HUE,
  GSK_GPU_PATTERN_BLEND_SATURATION,
  GSK_GPU_PATTERN_BLEND_LUMINOSITY,
} GskGpuPatternType;

G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_MULTIPLY == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_MULTIPLY);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_SCREEN == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_SCREEN);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_OVERLAY == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_OVERLAY);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_DARKEN == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_DARKEN);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_LIGHTEN == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_LIGHTEN);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_COLOR_DODGE == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_COLOR_DODGE);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_COLOR_BURN == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_COLOR_BURN);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_HARD_LIGHT == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_HARD_LIGHT);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_SOFT_LIGHT == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_SOFT_LIGHT);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_DIFFERENCE == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_DIFFERENCE);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_EXCLUSION == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_EXCLUSION);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_COLOR == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_COLOR);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_HUE == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_HUE);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_SATURATION == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_SATURATION);
G_STATIC_ASSERT (GSK_GPU_PATTERN_BLEND_LUMINOSITY == GSK_GPU_PATTERN_BLEND_DEFAULT + GSK_BLEND_MODE_LUMINOSITY);

typedef enum {
  GSK_GPU_OPTIMIZE_CLEAR                = 1 <<  0,
  GSK_GPU_OPTIMIZE_MERGE                = 1 <<  1,
  GSK_GPU_OPTIMIZE_BLIT                 = 1 <<  2,
  GSK_GPU_OPTIMIZE_GRADIENTS            = 1 <<  3,
  GSK_GPU_OPTIMIZE_MIPMAP               = 1 <<  4,
  GSK_GPU_OPTIMIZE_TO_IMAGE             = 1 <<  5,
  GSK_GPU_OPTIMIZE_OCCLUSION_CULLING    = 1 <<  6,
  GSK_GPU_OPTIMIZE_REPEAT               = 1 <<  7,
} GskGpuOptimizations;

