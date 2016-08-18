/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _TTM_FENCE_API_H_
#define _TTM_FENCE_API_H_
#include <linux/list.h>
#include <linux/kref.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <linux/version.h>
#define TTM_FENCE_FLAG_EMIT (1 << 0)
#define TTM_FENCE_TYPE_EXE (1 << 0)
struct ttm_fence_device;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ttm_fence_info {
  uint32_t signaled_types;
  uint32_t error;
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ttm_fence_object {
  struct ttm_fence_device * fdev;
  struct kref kref;
  uint32_t fence_class;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t fence_type;
  struct list_head ring;
  struct ttm_fence_info info;
  unsigned long timeout_jiffies;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t sequence;
  uint32_t waiting_types;
  void(* destroy) (struct ttm_fence_object *);
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct ttm_fence_info ttm_fence_get_info(struct ttm_fence_object * fence);
#if LINUX_VERSION_CODE < ???
#else
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#if LINUX_VERSION_CODE < ???
#else
#endif
#if LINUX_VERSION_CODE < ???
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#else
#endif
#endif
