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
#ifndef _TTM_FENCE_DRIVER_H_
#define _TTM_FENCE_DRIVER_H_
#include <linux/kref.h>
#include <linux/spinlock.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <linux/wait.h>
#include "psb_ttm_fence_api.h"
#include "ttm/ttm_memory.h"
struct ttm_fence_class_manager {
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t wrap_diff;
  uint32_t flush_diff;
  uint32_t sequence_mask;
  rwlock_t lock;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct list_head ring;
  uint32_t pending_flush;
  uint32_t waiting_types;
  wait_queue_head_t fence_queue;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t latest_queued_sequence;
};
struct ttm_fence_device {
  struct ttm_mem_global * mem_glob;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  struct ttm_fence_class_manager * fence_class;
  uint32_t num_classes;
  atomic_t count;
  const struct ttm_fence_driver * driver;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct ttm_fence_class_init {
  uint32_t wrap_diff;
  uint32_t flush_diff;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  uint32_t sequence_mask;
};
struct ttm_fence_driver {
  bool(* has_irq) (struct ttm_fence_device * fdev, uint32_t fence_class, uint32_t flags);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int(* emit) (struct ttm_fence_device * fdev, uint32_t fence_class, uint32_t flags, uint32_t * breadcrumb, unsigned long * timeout_jiffies);
  void(* flush) (struct ttm_fence_device * fdev, uint32_t fence_class);
  void(* poll) (struct ttm_fence_device * fdev, uint32_t fence_class, uint32_t types);
  uint32_t(* needed_flush) (struct ttm_fence_object * fence);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
  int(* wait) (struct ttm_fence_object * fence, bool lazy, bool interruptible, uint32_t mask);
  void(* signaled) (struct ttm_fence_object * fence);
  void(* lockup) (struct ttm_fence_object * fence, uint32_t fence_types);
};
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#endif
