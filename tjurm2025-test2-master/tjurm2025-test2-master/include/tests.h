#ifndef TJURM_TUTORIAL_INCLUDE_TEST_H_
#define TJURM_TUTORIAL_INCLUDE_TEST_H_

#include <string>

typedef bool (*TestFunction)();

bool test_split();

bool test_threshold();

bool test_erode();

bool test_find_contours();

bool test_get_rect_by_contours();

bool test_compute_iou();

bool test_compute_area_ratio();

bool test_roi_color();

bool test_my_resize();

#endif
