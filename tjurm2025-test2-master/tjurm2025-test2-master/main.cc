#include "tests.h"
#include "utils.h"
#include "log.h"

#include <cstdio>
#include <iostream>
#include <fstream>

#include <map>
#include <vector>

using std::cout;
using std::endl;

static int terminal_cols;

std::vector<std::string> default_tests = {
    "split", "threshold", "erode", "find_contours", "rect",
    "compute_iou", "compute_area_ratio", "roi_color",
    "resize"
};

std::map<std::string, TestFunction> name2test = {
    {"split",              test_split},
    {"threshold",          test_threshold},
    {"erode",              test_erode},
    {"find_contours",      test_find_contours},
    {"rect",               test_get_rect_by_contours},
    {"compute_iou",        test_compute_iou},
    {"compute_area_ratio", test_compute_area_ratio},
    {"roi_color",          test_roi_color},
    {"resize",             test_my_resize}
};

std::vector<std::string> load_tests() {
    // 读取测试点
    std::vector<std::string> tests;

    std::ifstream run_list;
    run_list.open("../run.list", std::ios_base::in);
    
    if (!run_list.is_open()) {
        LOG_WARN("无法打开run.list，请检查run.list文件是否存在");
        LOG_WARN("将按照默认顺序进行测试");
        tests = default_tests;
    } else {
        std::string s;
        while (getline(run_list, s)) {
            // skip empty line or line start with '//'
            if (s.empty()) {
                continue;
            }
            if (s == "stop") {
                break;
            }
            tests.push_back(s);
        }
    }

    LOG_MSG("将进行以下测试: ");
    print_line(terminal_cols, '*');
    for (int i = 0; i < tests.size(); i++) {
        cout << "<" << i + 1 << "> " << tests[i] << endl;
    }
    print_line(terminal_cols, '*');

    return tests;
}

void run_tests(std::vector<std::string>& tests) {
    cout << endl;
    
    for (const auto& name : tests) {
        if (name2test.find(name) == name2test.end()) {
            LOG_ERROR("不存在的测试点: %s", name.c_str());
            cout << endl;
            continue;
        }

        LOG_MSG("开始运行测试点: %s", name.c_str());
        print_line(terminal_cols, '*');
        bool pass = (name2test[name])();
        print_line(terminal_cols, '*');

        if (pass) {
            LOG_MSG("通过该测试点");
        } else {
            LOG_WARN("未通过该测试点");
        }
        cout << endl << endl;
    }
}


int main() {
    terminal_cols = get_terminal_width();

    // 读取测试点
    std::vector<std::string> tests = load_tests();

    // 运行测试点
    run_tests(tests);
    
    return 0;
}
