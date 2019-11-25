/******************************************************************************
 * MIT License

 * Copyright (c) 2019 Saumil Shah, Aman Virmani, Naman Gupta

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 ******************************************************************************/

/**
 * @file      DetectHuman.cpp
 * @author    Naman Gupta (namangupta98) Driver
 * @author    Saumil Shah (SaumilShah66) Design Keeper
 * @author    Aman Virmani (AmanVirmani) Navigator
 * @copyright MIT License
 * @brief     DetectHuman Class declaration
 * @detail    Implementation of class methods to detect humans using an SVM model
 *            trained on HOG features
 */
#include <DetectHuman.hpp>

DetectHuman::DetectHuman() {
}

void DetectHuman::setDefaultSVM() {
  /// Setting default detector
  hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
  std::cout << "Default detector has been set. Ready to use" << std::endl;
}

void DetectHuman::setCustomSVM(std::string customSVMFile) {
  if (fileExist(customSVMFile)) {
    std::cout << "Loading SVM from " << customSVMFile << std::endl;
    /// getting SVM classifier
    svm = svm->load(customSVMFile);
    std::cout << "SVM loaded successfully " << std::endl;
    hog.setSVMDetector(svm->getSupportVectors());
  } else {
    std::cout << "File does not exixt. Unable to load SVM" << std::endl;
  }
}

bool DetectHuman::fileExist(const std::string& filename) {
  struct stat info;
  return (stat(filename.c_str(), &info) == 0);
}

DetectHuman::~DetectHuman() {
  std::cout << "destroyed detector";
}
